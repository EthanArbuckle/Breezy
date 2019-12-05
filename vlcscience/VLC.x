#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface AppleTVAppDelegate: NSObject

- (void)importFileAtURL:(NSURL *)url;

@end

%hook AppleTVAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    %log;
    NSLog(@"BROOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
    NSURL *url = (NSURL *)[launchOptions valueForKey:UIApplicationLaunchOptionsURLKey];
    HBLogDebug(@"MY NAME IS URL: %@", url);
    if (url != nil){
        [self importFileAtURL:url];
    }
    return %orig;

}

%new - (void)importFileAtURL:(NSURL *)url {

        NSFileManager *man = [NSFileManager defaultManager];
        HBLogDebug(@"[VLC] host: %@ path: %@", url.host, url.path);
        NSArray* paths = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES);
        NSString *cache = [[paths objectAtIndex:0] stringByAppendingPathComponent:@"Upload"];
        if (![man fileExistsAtPath:cache]){
            HBLogDebug(@"this path wasnt found; %@",cache );
            NSDictionary *folderAttrs = @{NSFileGroupOwnerAccountName: @"staff",NSFileOwnerAccountName: @"mobile"};
            NSError *error = nil;
            [man createDirectoryAtPath:cache withIntermediateDirectories:YES attributes:folderAttrs error:&error];
            if (error){
                    HBLogDebug(@"error: %@", error);
            }
        }
        NSDictionary *attrs = [man attributesOfItemAtPath:cache error:nil];
        HBLogDebug(@"[VLC] cache attrs: %@", attrs);
        HBLogDebug(@"[VLC] cache path: %@", cache);

        NSString *newPath = [cache stringByAppendingPathComponent:url.path.lastPathComponent];
        NSString *originalPath = url.path;
        NSError *error = nil;
        [man copyItemAtPath:originalPath toPath:newPath error:&error];
        HBLogDebug(@"copy error: %@", error);
}

%new - (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary *)options {

    %log;
    NSFileManager *man = [NSFileManager defaultManager];
    HBLogDebug(@"[VLC] host: %@ path: %@", url.host, url.path);
    NSArray* paths = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES);
    NSString *cache = [[paths objectAtIndex:0] stringByAppendingPathComponent:@"Upload"];
    if ([man fileExistsAtPath:cache]){
        HBLogDebug(@"this path wasnt found; %@",cache );
        NSDictionary *folderAttrs = @{NSFileGroupOwnerAccountName: @"staff",NSFileOwnerAccountName: @"mobile"};
        NSError *error = nil;
        [man createDirectoryAtPath:cache withIntermediateDirectories:YES attributes:folderAttrs error:&error];
        if (error){
            HBLogDebug(@"error: %@", error);
        }
    }
    NSDictionary *attrs = [man attributesOfItemAtPath:cache error:nil];
    HBLogDebug(@"[VLC] cache attrs: %@", attrs);
    HBLogDebug(@"[VLC] cache path: %@", cache);

    NSString *newPath = [cache stringByAppendingPathComponent:url.path.lastPathComponent];
    NSString *originalPath = url.path;
    NSError *error = nil;
    [man copyItemAtPath:originalPath toPath:newPath error:&error];
    HBLogDebug(@"error: %@", error);

    return YES;
}

%end

%ctor {
//%init(AppDelegate = objc_getClass("Provenance.PVAppDelegate"));
}