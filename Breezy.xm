#import "FindProcess.h"
#import <UIKit/UIKit.h>
#import <objc/runtime.h>
#import <objc/message.h>
#import "breezy.h"
#import "CTBlockDescription.h"
#include <CoreFoundation/CoreFoundation.h>

@class BindingEvaluator, LSContext, LSBundleData;


static NSDictionary *blessPayload(NSDictionary *payload) {
    NSMutableDictionary *blessed = [payload mutableCopy];
    // Compiler will warn about NSKeyedArchiver being ios11+ without this guard
    if (@available(tvOS 11.0, *)) {
        // Create audittoken to verify identity
        id auditToken = ((id (*)(id, SEL))objc_msgSend)(NSClassFromString(@"BSAuditToken"), NSSelectorFromString(@"tokenForCurrentProcess"));
        NSData *token = [NSKeyedArchiver archivedDataWithRootObject:auditToken];
        [blessed setValue:token forKey:KBBreezyAuditToken];
    }

    return blessed;
}

static BOOL isPayloadBlessed(NSDictionary *payload, NSString *expectedEntitlement) {
    // Verify the authenticity of the notifications origin
    if (@available(tvOS 11.0, *)) {
        NSData *auditTokenArchive = (NSData *)payload[KBBreezyAuditToken];
        id auditToken = [NSKeyedUnarchiver unarchivedObjectOfClass:NSClassFromString(@"BSAuditToken") fromData:auditTokenArchive error:nil];

        BOOL senderHasEntitlement = ((BOOL * (*)(id, SEL, NSString *))objc_msgSend)(auditToken, NSSelectorFromString(@"hasEntitlement:"), expectedEntitlement);
        if (!senderHasEntitlement)
        {
            NSLog(@"failed to verify sender: %d, expected: %@", senderHasEntitlement, expectedEntitlement);
            return false;
        }
    }

    return true;
}

//start actual code
%group Sharingd
%hook SharingDaemon

- (_Bool)canAccessAirDropSettings:(id)arg1 {
    
    %log;
    //description of item looks like this <OS_xpc_connection: <connection: 0x133dc3790> { name = com.apple.sharingd.peer.0x133dc3790, listener = false, pid = 3731, euid = 501, egid = 501, asid = 0 }>
    //find the related pid by trimming it out of the description
    int pid = [FindProcess pidFromItemDescription:[arg1 description]];
    HBLogDebug(@"PID %i", pid);
    //exempting TVSettings from AirDrop entitlement checks so we can toggle it on and off there easier.
    boolean_t matches = [FindProcess process:pid matches:"TVSettings"];
    if (matches){
        return true;
    }
    //return true;
    return %orig;
}

%end


//all of this code is thoroughly documented in the README if you are having trouble understanding it.
%hook SDAirDropTransferManager

- (id)init {
    id _self = %orig;
    // Observer for responses from PineBoard - containing what the user selected on the alert
    id notificationCenter = [NSDistributedNotificationCenter defaultCenter];
    [notificationCenter addObserver:self  selector:NSSelectorFromString(@"handleBreezyAirdropPermissionResponse:") name:KBBreezyAirdropPresentAlert object:KBBreezyRespondToPermission];

    return _self;
}

- (id)determineHandlerForTransfer:(id)transfer { 
    %log;

    id genericHandler = [[%c(SDAirDropHandlerGenericFiles) alloc] initWithTransfer:transfer bundleIdentifier:@"com.nito.nitoTV4"];
    // [genericHandler prepareOrPerformOpenAction];
    // [genericHandler updatePossibleActions];
    ((void (*)(id, SEL))objc_msgSend)(genericHandler, NSSelectorFromString(@"prepareOrPerformOpenAction"));
    ((void (*)(id, SEL))objc_msgSend)(genericHandler, NSSelectorFromString(@"updatePossibleActions"));
    [genericHandler activate];
    
    return genericHandler;
}

- (void)askEventForRecordID:(id)recordID withResults:(id)results {
    
    %orig;

    SFAirDropTransfer *transfer = ((NSDictionary *(*)(id, SEL))objc_msgSend)(self, NSSelectorFromString(@"transferIdentifierToTransfer"))[recordID];
    // Requests from trusted devices don't need the alert
    if ([[[transfer metaData] valueForKey:@"_canAutoAccept"] boolValue] == true) {
        return;
    }

    // Sending device's name
    NSString *sender = [[transfer metaData] valueForKey:@"_senderComputerName"];

    NSArray *transferItems = [[[transfer metaData] valueForKey:@"_items"] allObjects];
    NSString *alertText;
    if ([transferItems count] == 1) {
        // One file being transfered. Try to determine what kind of file it is
        NSString *type = [transferItems[0] valueForKey:@"_type"];
        NSString *fileDescription = UTTypeCopyDescription(type);
        if (fileDescription) {
            alertText = [NSString stringWithFormat:@"\"%@\" would like to share a %@ file.", sender, fileDescription];
        }
        else {
            // Unknown file type
            alertText = [NSString stringWithFormat:@"\"%@\" would like to share a file.", sender];
        }
    }
    else {
        // Multiple files
        alertText = [NSString stringWithFormat:@"\"%@\" would like to share multiple files.", sender];
    }

    // Construct serializable preview image if needed
    NSData *previewImageData = [NSData new];
    CGImageRef previewImage = (__bridge CGImageRef)[[transfer metaData] valueForKey:@"_previewImage"];
    if (previewImage) {

        NSDictionary *properties;
        CFMutableDataRef newImageData = CFDataCreateMutable(NULL, 0);
        CFStringRef type = UTTypeCreatePreferredIdentifierForTag(CFSTR("public.mime-type"), (__bridge CFStringRef) @"image/png", CFSTR("public.image"));
        CGImageDestinationRef destination = CGImageDestinationCreateWithData(newImageData, type, 1, NULL);
        CGImageDestinationAddImage(destination, previewImage, (__bridge CFDictionaryRef) properties);
        CGImageDestinationFinalize(destination);
        previewImageData = (__bridge NSData *)newImageData;
    }

    // Construct the alert request
    NSDictionary *payload = @{
        KBBreezyAirdropTransferRecordID: recordID,
        KBBreezyAlertTitle: @"AirDrop",
        KBBreezyAlertDetail: alertText,
        KBBreezyAlertPreviewImage: previewImageData,
        KBBreezyButtonDefinitions: @[
            @{
                KBBreezyButtonTitle: @"Accept",
                KBBreezyButtonAction: KBBreezyButtonActionAccept,
            },
            @{
                KBBreezyButtonTitle: @"Decline",
                KBBreezyButtonAction: KBBreezyButtonActionDeny,
            }
        ]
    };
    payload = blessPayload(payload);

    // Ask Pineboard to present it
    [[NSDistributedNotificationCenter defaultCenter] postNotificationName:KBBreezyAirdropPresentAlert object:KBBreezyRequestPermission userInfo:payload];
}

-(void)finishedEventForRecordID:(id)recordID withResults:(id)arg
{
    SFAirDropTransfer *transfer = ((NSDictionary *(*)(id, SEL))objc_msgSend)(self, NSSelectorFromString(@"transferIdentifierToTransfer"))[recordID];
    NSArray <NSURL *> *items = arg[@"Items"];
    if (items.count > 0) {

        NSMutableArray *paths = [NSMutableArray new];
        NSMutableArray *URLS = [NSMutableArray new];
        for (NSURL *obj in items) {
            if ([obj respondsToSelector:(@selector(isFileURL))]) {
                if ([obj isFileURL]) {
                    [paths addObject:[obj path]];
                } else {
                    HBLogDebug(@"obj isnt a file path: %@", obj);
                    [URLS addObject:[obj absoluteString]];
                }
            } else {
                HBLogDebug(@"doesnt respond to isFileURL: %@", obj);
                [paths addObject:[obj path]];
            }
        }

        if (paths.count > 0 || URLS.count > 0) {
            
            // The container for the transferred files. In some scenarios, PineBoard will be responsible for
            // cleaning this up.
            NSURL *containerLocation = ((NSURL * (*)(id, SEL, id))objc_msgSend)(self, NSSelectorFromString(@"transferURLForTransfer:"), transfer);

            NSMutableDictionary *sent = [NSMutableDictionary new];
            sent[@"Files"] = arg[@"Files"];
            sent[@"LocalFiles"] = paths;
            sent[@"URLS"] = URLS;
            sent[KBBreezyAlertTitle] = @"AirDrop";
            sent[KBBreezyAirdropCustomDestination] = [containerLocation path];

            HBLogDebug(@"Breezy: sending user info: %@", sent);
            [[NSDistributedNotificationCenter defaultCenter] postNotificationName:KBBreezyAirdropPresentAlert object:KBBreezyOpenAirDropFiles userInfo:blessPayload((NSDictionary *)sent)];
        }
    }

    // when false, sharingd will not delete the transferred files.
    BOOL shouldCleanup = false;
    ((void (*)(id, SEL, id, BOOL))objc_msgSend)(self, NSSelectorFromString(@"removeTransfer:shouldCleanup:"), transfer, shouldCleanup);
    %orig;
}

%new
- (void)handleBreezyAirdropPermissionResponse:(id)notification {
    NSDictionary *payload = [notification userInfo];

    // Sharingd does not have the entitlement to perform this :(
    // i would like to figure out some sort of check, so rogue process can't send an accept request in
    // if (!isPayloadBlessed(payload, @"com.apple.backboard.client")) {
    //     return;
    // }

    NSString *recordID = payload[KBBreezyAirdropTransferRecordID];
    if (!recordID) {
        return;
    }

    NSString *selectedActionIdentifier = payload[KBBreezyAlertSelectedAction];
    id selectedAction = nil;

    SFAirDropTransfer *transfer = ((NSDictionary *(*)(id, SEL))objc_msgSend)(self, NSSelectorFromString(@"transferIdentifierToTransfer"))[recordID];
    NSArray *possibleActions = ((NSArray *(*)(id, SEL))objc_msgSend)(transfer, NSSelectorFromString(@"possibleActions"));

    // Determine which action is intended
    if ([selectedActionIdentifier isEqualToString:KBBreezyButtonActionAccept]) {
        // Accept is the first "possible action"
        selectedAction = possibleActions[0];
    }
    else if ([selectedActionIdentifier isEqualToString:KBBreezyButtonActionDeny]) {
        selectedAction = [transfer valueForKey:@"_cancelAction"];
    }

    // Perform selected action
    ((void (*)(id, SEL, id, id))objc_msgSend)(self, NSSelectorFromString(@"transfer:actionTriggeredForAction:"), transfer, selectedAction);
    ((void (*)(id, SEL, id))objc_msgSend)(self, NSSelectorFromString(@"transferUserResponseUpdated:"), transfer);
}

%end

%end //Sharingd Group

%group PineBoard

%hook LSApplicationWorkspace
/*
 the Breezy preferences (/var/mobile/Library/Preferences/com.nito.Breezy.plist) track whether or not
 AirDrop is on AND whether or not applications will 'mimic' another to shoe-horn in AirDrop support
 utilizing code injection rather than editing a file on device.
 
 In this default example we add VLC to mimic Ethereal's AirDrop advertising settings, that means
 any file that Ethereal can open, VLC will claim it can open as well!
 */

// Allow apps to support file extensions they don't usually work with
- (NSArray *)applicationsAvailableForOpeningDocument:(id)documentProxy {
    NSMutableArray *availableApplications = [(NSArray *)%orig mutableCopy];

    // Specify specific extensions that will be handled by new apps
    // Key: File extension
    // Value: list of (new) applications that can open the file
    NSDictionary *customExtensionMappings = @{
        @"ipa": @[@"com.matchstic.reprovision.tvos"]
    };
    
    NSString *documentExtension = [[documentProxy valueForKey:@"_name"] pathExtension];
    for (NSString *extension in customExtensionMappings) {
        if ([extension isEqualToString:documentExtension]) {
            // Document extension matches one of the custom extension mappings
            // Update the available applications to include the custom items
            for (NSString *customAppIdentifier in customExtensionMappings[extension]) {
                id customApplication = [LSApplicationProxy applicationProxyForIdentifier:customAppIdentifier];
                // Confirm its installed
                if ([customApplication localizedName]) {
                    [availableApplications addObject:customApplication];
                }
            }
        }
    }

    // Allow an app to impersonate another application's supported extensions (VLC will support everything Ethereal supports)
    // Key: Application to impersonate
    // Value: list of applications that will impersonate the key application's extension support
    NSDictionary *impersonationMappings = [self appMimicMap];
    if (impersonationMappings == nil) {
        //setup default
        impersonationMappings = @{
            @"com.nito.Ethereal": @[@"org.videolan.vlc-ios"]
        };
        [[self breezyPreferences] setObject:impersonationMappings forKey:@"appMimicMap"];
        [[self breezyPreferences] synchronize];
    }

    int availableAppsCount = [availableApplications count];
    for (int i = 0; i < availableAppsCount; i++) {
        // If the mapping contains the identifier of an app that legitimately supports this document
        NSString *applicationIdentifier = [availableApplications[i] valueForKey:@"_bundleIdentifier"];
        if ([impersonationMappings valueForKey:applicationIdentifier]) {
            // Create an LSApplicationProxy instance for each custom app the mapping defines
            for (NSString *customAppIdentifier in impersonationMappings[applicationIdentifier]) {
                id customApplication = [LSApplicationProxy applicationProxyForIdentifier:customAppIdentifier];
                // Confirm its installed
                if ([customApplication localizedName]) {
                    [availableApplications addObject:customApplication];
                }
            }
        }
    }

    return [availableApplications copy];     
}

%new - (id)appMimicMap {
    
    return [[self breezyPreferences] objectForKey:@"appMimicMap"];
}

%new - (id)breezyPreferences {
    id bp = objc_getAssociatedObject(self, @selector(breezyPreferences));
    if (bp == nil){
        [[NSBundle bundleWithPath:@"/System/Library/Frameworks/TVServices.framework/"] load];
        bp = [%c(TVSPreferences) preferencesWithDomain:@"com.nito.Breezy"];
        objc_setAssociatedObject(self, @selector(breezyPreferences), bp, OBJC_ASSOCIATION_RETAIN);
    }
    return bp;
}

%new -(void)setupPreferences {
    
    //dlopen("/System/Library/Frameworks/TVServices.framework/TVServices", RTLD_NOW);
    [[NSBundle bundleWithPath:@"/System/Library/Frameworks/TVServices.framework/"] load];
    id prefs = [%c(TVSPreferences) preferencesWithDomain:@"com.nito.Breezy"];
    BOOL airdropServerState = [prefs boolForKey:@"airdropServerState"];
    NSLog(@"[Breezy] airdropServerState: %i", airdropServerState);
}

%end

%hook PBAppDelegate

%new - (void)showSystemAlertFromAlert:(id)alert
{
    %log;
    NSDictionary *payload = [alert userInfo];
    NSString *alertContext = [alert object];

    if ([alertContext isEqualToString:KBBreezyRespondToPermission])
    {
        return;
    }

    // Only sharingd is expected to communicate
    if (!isPayloadBlessed(payload, @"com.apple.sharing.RemoteInteractionSession")) {
        return;
    }

    // Construct the alert
    id applicationAlert = [[%c(PBUserNotificationViewControllerAlert) alloc] initWithTitle:payload[KBBreezyAlertTitle] text:payload[KBBreezyAlertDetail]];
    __weak typeof(applicationAlert) weakApplicationAlert = applicationAlert;

    // Dismiss handler has special behavior depending on os version
    void (^dismissAlert)(void) = nil;
    void (^presentAlert)(void) = nil;

    if (kCFCoreFoundationVersionNumber > 1585.17)
    {
        // iOS 13+
        __block id ios13AlertContext = nil;
        presentAlert = ^(void) {
            ios13AlertContext = [%c(PBDialogContext) contextWithViewController:applicationAlert];
            [[%c(PBDialogManager) sharedInstance] presentDialogWithContext:ios13AlertContext options:@{@"PBDialogOptionPresentForcedKey": @1, @"PBDialogOptionPresentWhileScreenSaverActiveKey": @1} completion:nil];
        };

        dismissAlert = ^void(void) {
            [[%c(PBDialogManager) sharedInstance] dismissDialogWithContext:ios13AlertContext options:nil completion:nil];
        };
    }
    else
    {
        // iOS 12 and under
        id windowManager = [%c(PBWindowManager) sharedInstance];
        presentAlert = ^(void) {
            [windowManager presentDialogViewController:applicationAlert];
        };

        dismissAlert = ^void(void) {
            [windowManager dismissDialogViewController:weakApplicationAlert];
        };
    }
    
    if ([alertContext isEqualToString:KBBreezyRequestPermission]) {

        // Construct the buttons
        for (NSDictionary *buttonDefinition in payload[KBBreezyButtonDefinitions])
        {
            [applicationAlert addButtonWithTitle:buttonDefinition[KBBreezyButtonTitle] type:0 handler:^{
                // Send the answer back
                NSDictionary *responsePayload = @{
                    KBBreezyAirdropTransferRecordID: payload[KBBreezyAirdropTransferRecordID],
                    KBBreezyAlertSelectedAction: buttonDefinition[KBBreezyButtonAction]
                };
                [[NSDistributedNotificationCenter defaultCenter] postNotificationName:KBBreezyAirdropPresentAlert object:KBBreezyRespondToPermission userInfo:responsePayload];
                // Dismiss the alert
                dismissAlert();
            }];
        }

        // Handle preview image if needed
        NSData *previewImageData = payload[KBBreezyAlertPreviewImage];
        if (previewImageData) {

            // Construct UIImage from data
            CGDataProviderRef imgDataProvider = CGDataProviderCreateWithCFData((__bridge CFDataRef)previewImageData);
            CGImageRef imageRef = CGImageCreateWithPNGDataProvider(imgDataProvider, NULL, true, kCGRenderingIntentDefault);
            UIImage *previewImage = [[UIImage alloc] initWithCGImage:imageRef];

            // Add it to the alert
            // [applicationAlert setHeaderImage:previewImage];
            ((void (*)(id, SEL, id))objc_msgSend)(applicationAlert, NSSelectorFromString(@"setHeaderImage:"), previewImage);
        }

        dispatch_async(dispatch_get_main_queue(), ^{
            presentAlert();
        });
    }
    else if ([alertContext isEqualToString:KBBreezyOpenAirDropFiles]) {
        NSLog(@"[Breezy] CFVersion %.2f\n", kCFCoreFoundationVersionNumber);
        NSLog(@"[Breezy] showSystemAlertFromAlert: %@", alert);

        LSApplicationWorkspace *ws = [LSApplicationWorkspace defaultWorkspace];
        NSDictionary *userInfo = [alert userInfo];
        NSArray <NSDictionary *> *files = userInfo[@"Files"];
        NSArray <NSString *> *localFiles = userInfo[@"LocalFiles"];
        NSArray <NSString *> *URLS = userInfo[@"URLS"];

        // If the alert is cancelled or no compatible apps are installed, this handler will delete the airdropped files
        void (^cleanupFiles)(void) = ^void(void) {
            NSString *airdropContainer = payload[KBBreezyAirdropCustomDestination];
            if ([[NSFileManager defaultManager] fileExistsAtPath:airdropContainer]) {
                [[NSFileManager defaultManager] removeItemAtPath:airdropContainer error:nil];
            }
        };

        // EA: There may be multiple files, urls, or both files AND urls provided in the transfer.
        // For every item, determine if there are installed applications that can open it.
        // * if 1 file is provided and no applications can open it, present an error
        // * if 1 file is provided and 1 applications can open it, auto open it
        // * if 1 file is provided and multiple applications can open it, present alert asking which app
        // * if multiple files are provided and no applications can handle either of them, present an error
        // * if multiple files are provided and they can both be opened by the same application, and no other apps can open them, open them in that app
        // * if multiple files are provided and they each can be opened by multiple apps, but they have 1 app in common, open it in the common app
        // * if multiple files are provided and they each can be opened by multiple apps, and they have multiple apps in common, present alert asking which app
        // * if multiple files are provided and they each can be opened by multiple apps, but they dont have a common app, present an error
        // * if multiple files are provided and and 1 can be opened but 1 cannot, ???
        NSMutableDictionary *supportedAppsForItem = [[NSMutableDictionary alloc] init];
        for (NSDictionary *adFile in files) {
            // Determine which applications (if any) can open each provided file
            NSString *fileName = adFile[@"FileName"];
            NSString *fileType = adFile[@"FileType"];

            id documentProxy = [LSDocumentProxy documentProxyForName:fileName type:fileType MIMEType:nil];
            NSArray *supportedAppIdentifiers = [[ws applicationsAvailableForOpeningDocument:documentProxy] valueForKey:@"_bundleIdentifier"];
            supportedAppsForItem[fileName] = supportedAppIdentifiers;
        }

        // Same thing for urls.
        // An application may support opening a url and file at the same time
        for (NSString *url in URLS) {
            // Determine which applications (if any) can open each provided scheme
            NSString *scheme = [[NSURL URLWithString:url] scheme];
            NSLog(@"[Breezy] scheme: %@", scheme);
            NSArray *supportedApps = [ws applicationsAvailableForHandlingURLScheme:scheme];
            //PBLinkHandler is useless and we dont want to list it as an option.
            NSPredicate *pred = [NSPredicate predicateWithFormat:@"bundleIdentifier != 'com.apple.PBLinkHandler'"];
            supportedApps = [supportedApps filteredArrayUsingPredicate: pred];
            supportedAppsForItem[url] = [supportedApps valueForKey:@"_bundleIdentifier"];
        }

        // What should we call these items?
        NSString *itemName = @"item";
        if ([files count] > 0) {
            if ([URLS count] == 0) {
                // All files and no urls - refer to the item as a file
                itemName = @"file";
            }
        }
        else {
            if ([URLS count] > 0) {
                // Call it a link
                itemName = @"link";
            }
        }
        NSLog(@"%@", supportedAppsForItem);

        NSArray *allAppCandidates = [supportedAppsForItem allValues];
        NSArray *supportedApplications = @[];
        if ([allAppCandidates count] > 0) {
            // Find apps that support all of the provided files
            NSMutableSet *appCandidates = [NSMutableSet setWithArray:allAppCandidates[0]];
            for (int i = 1; i < [allAppCandidates count]; i++) {
                NSSet *applications = [NSSet setWithArray:allAppCandidates[i]];
                [appCandidates intersectSet:applications];
            }
            supportedApplications = [appCandidates allObjects];
        }

        // Build a string containing comma-seperated item names
        NSArray *allItems = [[files valueForKey:@"FileName"] arrayByAddingObjectsFromArray:URLS];
        NSString *itemNames = [allItems componentsJoinedByString:@", "];
        if (itemNames.length > 400) {
            itemNames = [NSString stringWithFormat:@"%@...", [itemNames substringToIndex:400]];
        }

        // Build a block that handles opening the airdropped files
        void (^openAirdroppedFiles)(NSString *) = ^void(NSString *appIdentifier) {
            id launchApp = [LSApplicationProxy applicationProxyForIdentifier:appIdentifier];
            if (URLS.count > 0) {
                //process URLs
                [self openItems:URLS ofType:KBBreezyFileTypeLink withApplication:launchApp];
            } else {
                //process files
                [self openItems:localFiles ofType:KBBreezyFileTypeLocal withApplication:launchApp];
            }
            // Make sure the entire airdrop container is cleaned up, not just the transferred files
            cleanupFiles();
        };

        NSString *alertBodyText = nil;
        NSString *cancelButtonTitle = nil;
        if ([supportedApplications count] == 0) {
            // No apps support opening the files
            if ([files count] == 1) {
                // No apps can open the provided file
                alertBodyText = [NSString stringWithFormat:@"No applications support opening \"%@\".", itemNames];
            }
            else {
                NSMutableArray *flattenedIdentifiers = [[NSMutableArray alloc] init];
                for (NSArray *identifiers in allAppCandidates) {
                    [flattenedIdentifiers addObjectsFromArray:identifiers];
                }
                if ([flattenedIdentifiers count] > 0) {
                    // Some files could be opened, but there isn't an app that supports every provided file
                    alertBodyText = [NSString stringWithFormat:@"No single application supports opening all of the provided %@s.", itemName];
                }
                else {
                    // None of the provided files had an app that supports them
                    alertBodyText = [NSString stringWithFormat:@"No application supports opening the provided %@.", itemName];
                }
            }
            cancelButtonTitle = @"OK";
        }
        else if ([supportedApplications count] == 1) {
            // Only 1 app supports these files; auto open it without showing an alert
            openAirdroppedFiles(supportedApplications[0]);
            return;
        }
        else {
            // The files can be opened my multiple apps
            alertBodyText = [NSString stringWithFormat:@"Open \"%@\" with...", itemNames];
            cancelButtonTitle = @"Cancel";
            for (NSString *applicationIdentifier in supportedApplications) {
                // Create a button for each app
                id application = [LSApplicationProxy applicationProxyForIdentifier:applicationIdentifier];
                [applicationAlert addButtonWithTitle:[application localizedName] type:0 handler:^{
                    
                    dismissAlert();
                    openAirdroppedFiles(applicationIdentifier);
                }];
            }
        }

        [applicationAlert setText:alertBodyText];   

        NSLog(@"[Breezy] available applications: %@", supportedApplications);
        // Build the dismiss button
        [applicationAlert addButtonWithTitle:cancelButtonTitle type:0 handler:^{
            dismissAlert();
            cleanupFiles();
        }];
        
        //done all our processing, time to show the alert!
        presentAlert();
    }
}

- (_Bool)application:(id)arg1 didFinishLaunchingWithOptions:(id)arg2 {
    
    _Bool orig = %orig;
    %log;
    
    // still need to get rid of this ugly eyesore
    id notificationCenter = [NSDistributedNotificationCenter defaultCenter];
    [notificationCenter addObserver:self  selector:@selector(showSystemAlertFromAlert:) name:KBBreezyAirdropPresentAlert object:nil];

    ((void (*)(id, SEL))objc_msgSend)([LSApplicationWorkspace defaultWorkspace], NSSelectorFromString(@"setupPreferences"));
    return orig;
    
}

//this never ended up being needed but im leaving it in as an example of how to hook a private C function
%new - (NSURL *)inboxForIdentifier:(NSString *)identifier {
    //dlopen("/System/Library/Frameworks/CoreServices.framework/CoreServices", RTLD_LAZY);
    MSImageRef cs = MSGetImageByName("/System/Library/Frameworks/CoreServices.framework/CoreServices");
    void *(*LSGetInboxURLForAppIdentifier)(id identifier);
    LSGetInboxURLForAppIdentifier = (void *(*)(id identifier)) MSFindSymbol(cs, "__LSGetInboxURLForAppIdentifier");
    NSLog(@"[Breezy] %p", LSGetInboxURLForAppIdentifier);
    if (LSGetInboxURLForAppIdentifier){
        NSURL *inbox = (__bridge NSURL *)(*LSGetInboxURLForAppIdentifier)(identifier);
        return inbox;
    }
    return nil;
}

/*
 
 Added this to make sure files are in a folder they can be accessed from.
 
 */

%new - (NSString *)importFile:(NSString *)inputFile withApp:(id)proxy {
    
    NSFileManager *man = [NSFileManager defaultManager];
    NSString *onePath = [[proxy dataContainerURL] path];
    if (onePath == nil){
        onePath = @"/";
    }
    NSString *cachePath = [[onePath stringByAppendingPathComponent:@"Library/Caches"] stringByAppendingPathComponent:[proxy bundleIdentifier]];
    if (![man fileExistsAtPath:cachePath]){
        NSDictionary *folderAttrs = @{NSFileGroupOwnerAccountName: @"admin",NSFileOwnerAccountName: @"mobile", NSFilePosixPermissions: @755};
        NSError *error = nil;
        [man createDirectoryAtPath:cachePath withIntermediateDirectories:YES attributes:folderAttrs error:&error];
        if (error){
            HBLogDebug(@"creating %@ had error: %@", cachePath, error);
        }
    }
    NSString *newPath = [cachePath stringByAppendingPathComponent:[inputFile lastPathComponent]];
    NSError *copyError = nil;
    if ([man fileExistsAtPath:newPath]){
        [man removeItemAtPath:inputFile error:nil];
        return newPath;
    } else {
        HBLogDebug(@"attempting to copy %@ to %@", inputFile, newPath);
        if ([man copyItemAtPath:inputFile toPath:newPath error:&copyError]) {
            [man removeItemAtPath:inputFile error:nil];
            return newPath;
        } else {
            HBLogDebug(@"failed to copy %@ to %@ with error: %@", inputFile, newPath, copyError);
            return inputFile;
        }
    }
    return inputFile;
}

/*
 
 Meat and potatoes of opening the applications on our own, this works better than their
 operations provided in LSApplicationWorkspace to open files.
 
 Use FrontBoardServices framework in conjunction with FBProcessManager, CoreServices and Launchservices
 to create an application launch request and process it.
 
 */

%new - (void)openItems:(NSArray *)items ofType:(KBBreezyFileType)fileType withApplication:(id)proxy {
    
    Class FBSOpenApplicationOptions = %c(FBSOpenApplicationOptions);
    Class FBSystemServiceOpenApplicationRequest = %c(FBSystemServiceOpenApplicationRequest);
    id pbProcMan = [%c(PBProcessManager) sharedInstance];
    id _fbProcMan = [%c(FBProcessManager) sharedInstance];
    NSString *bundleID = [proxy bundleIdentifier];
    __block id pbProcess = [_fbProcMan systemApplicationProcess]; //Our process reference to PineBoard
    [items enumerateObjectsUsingBlock:^(NSString * _Nonnull item, NSUInteger idx, BOOL * _Nonnull stop) {
        NSMutableDictionary *_options = [NSMutableDictionary new];
        _options[FBSOpenApplicationOptionKeyActivateSuspended] = @0;
        _options[FBSOpenApplicationOptionKeyDocumentOpen4LS] = @1;
        _options[@"LSBlockUntilComplete"] = @1; //13.0+ shouldnt hurt anything
        _options[FBSOpenApplicationOptionKeyPayloadAnnotation] = @{@"LSMoveDocumentOnOpen": @0, @"LSDocumentDropCount": [NSNumber numberWithInteger:items.count], @"LSDocumentDropIndex": [NSNumber numberWithInteger:idx]};
        _options[FBSOpenApplicationOptionKeyPayloadOptions] = @{@"UIApplicationLaunchOptionsSourceApplicationKey": @"com.apple.PineBoard"};
        if (fileType == KBBreezyFileTypeLink){
            _options[FBSOpenApplicationOptionKeyPayloadURL] = [NSURL URLWithString:item];
        } else {
            NSLog(@"[Breezy] og item: %@", item);
            //NSString *importedItem = [inbox stringByAppendingPathComponent:item.lastPathComponent];
            NSString *importedItem = [self importFile:item withApp:proxy];
            NSLog(@"[Breezy] imported item: %@", importedItem);
            _options[FBSOpenApplicationOptionKeyPayloadURL] = [NSURL fileURLWithPath:importedItem];
        }
        
        id options = [FBSOpenApplicationOptions optionsWithDictionary:_options];
        id openAppRequest = [FBSystemServiceOpenApplicationRequest request];
        [openAppRequest setTrusted:TRUE];
        [openAppRequest setBundleIdentifier:bundleID];
        [openAppRequest setOptions:options];
        [openAppRequest setClientProcess:pbProcess];
        CGFloat multiplier = 0.5;
        if ([_fbProcMan processesForBundleIdentifier:bundleID].count == 0){
            multiplier = 1;
            HBLogDebug(@"App isnt running yet, bumping up the multiplier so stuff gets processed successfully");
        }
        CGFloat offset = idx*multiplier;
        
        // staggers each open by 'offset' seconds
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, offset * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
            
            if ([pbProcMan respondsToSelector:@selector(_handleOpenApplicationRequest:bundleID:options:withResult:)]){
                [pbProcMan _handleOpenApplicationRequest:openAppRequest bundleID:bundleID options:_options withResult:^(NSError *error) {
                    HBLogDebug(@"open app finished with error: %@", error);
                    if (error != nil){
                        [pbProcMan activateApplication:bundleID openURL:_options[FBSOpenApplicationOptionKeyPayloadURL] options:_options suspended:FALSE completion:nil];
                    }
                }];
                
            } else if ([pbProcMan respondsToSelector:@selector(_openAppFromRequest:bundleIdentifier:URL:withResult:)]){ //13.0 -> ?
                [pbProcMan _openAppFromRequest:openAppRequest bundleIdentifier:bundleID URL:[NSURL fileURLWithPath:item] withResult:^(NSError *error) {
                    HBLogDebug(@"open app finished with error: %@", error);
                }];
            } else {
                [pbProcMan _openAppFromRequest:openAppRequest bundleIdentifier:bundleID URL:[NSURL fileURLWithPath:item] completion:^(NSError *error) {
                    HBLogDebug(@"open app finished with error: %@", error);
                }];
            }
        });
    }];
}

%end
%end //PineBoard Group

%ctor {
    
    NSString *processName = [[[[NSProcessInfo processInfo] arguments] lastObject] lastPathComponent];
    //HBLogDebug(@"Process name: %@", processName);
    if ([processName isEqualToString:@"PineBoard"]){
        %init(PineBoard);

    } else if ([processName isEqualToString:@"sharingd"]){
        %init(Sharingd);
    }
}
