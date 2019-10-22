//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@class CUSystemMonitor, NEVPNConnection, NSData, NSURL, NSUUID, SDStatusMonitor, SFBLEScanner, SFDeviceDiscovery, SFDeviceRepairService, SFDeviceRepairSession, SFPINPairSession, SFService, SFWiFiHealthMonitor;
@protocol OS_dispatch_queue, OS_dispatch_source, PBSMediaRemoteServiceInterface;

__attribute__((visibility("hidden")))
@interface SDSetupAgent : NSObject
{
    NSData *_bleAuthTagFilter;	// 8 = 0x8
    _Bool _clientEnabled;	// 16 = 0x10
    SFDeviceDiscovery *_deviceDiscovery;	// 24 = 0x18
    struct NSMutableDictionary *_devices;	// 32 = 0x20
    _Bool _hsa2Enabled;	// 40 = 0x28
    id <PBSMediaRemoteServiceInterface> _pbsMediaService;	// 48 = 0x30
    id _pinPairDialogToken;	// 56 = 0x38
    SFService *_pinPairService;	// 64 = 0x40
    SFPINPairSession *_pinPairSession;	// 72 = 0x48
    NSUUID *_pinPairUUID;	// 80 = 0x50
    int _profilesNotifyToken;	// 88 = 0x58
    _Bool _pwsAutoGrantingEnabled;	// 92 = 0x5c
    _Bool _pwsGrantingEnabled;	// 93 = 0x5d
    _Bool _scanEligible;	// 94 = 0x5e
    int _scanSeconds;	// 96 = 0x60
    NSObject<OS_dispatch_source> *_scanTimer;	// 104 = 0x68
    _Bool _serverEnabled;	// 112 = 0x70
    NSURL *_setupURL;	// 120 = 0x78
    _Bool _shouldScan;	// 128 = 0x80
    SDStatusMonitor *_statusMonitor;	// 136 = 0x88
    CUSystemMonitor *_systemMonitor;	// 144 = 0x90
    struct NSMutableDictionary *_triggeredDevices;	// 152 = 0x98
    _Bool _triggeredUIAppleTVPair;	// 160 = 0xa0
    _Bool _triggeredUIAppleTVSetup;	// 161 = 0xa1
    _Bool _renableB238SetupAfterWiFi;	// 162 = 0xa2
    _Bool _triggeredUIB238Setup;	// 163 = 0xa3
    _Bool _triggeredUIiOSSetup;	// 164 = 0xa4
    _Bool _triggeredUIRepair;	// 165 = 0xa5
    _Bool _triggeredUIWatchSetup;	// 166 = 0xa6
    _Bool _triggeredUIWHASetup;	// 167 = 0xa7
    NEVPNConnection *_vpnCnx;	// 168 = 0xa8
    unsigned long long _watchFastScanLastEndTicks;	// 176 = 0xb0
    NSObject<OS_dispatch_source> *_watchFastScanTimer;	// 184 = 0xb8
    struct NSMutableDictionary *_watchSetupDevices;	// 192 = 0xc0
    _Bool _watchMigrationEnabled;	// 200 = 0xc8
    unsigned long long _watchMigrationLastTicks;	// 208 = 0xd0
    _Bool _watchSetupEnabled;	// 216 = 0xd8
    SFBLEScanner *_watchSetupScanner;	// 224 = 0xe0
    _Bool _airplayActive;	// 232 = 0xe8
    int _airplayNotifyToken;	// 236 = 0xec
    _Bool _cdpEnabled;	// 240 = 0xf0
    int _cfuNotifyToken;	// 244 = 0xf4
    int _iTunesNotifyToken;	// 248 = 0xf8
    CUSystemMonitor *_manateeMonitor;	// 256 = 0x100
    _Bool _manateeProblem;	// 264 = 0x108
    unsigned long long _problemFlags;	// 272 = 0x110
    int _problemNotifyToken;	// 280 = 0x118
    _Bool _repairEnabled;	// 284 = 0x11c
    SFDeviceRepairService *_repairService;	// 288 = 0x120
    SFDeviceRepairSession *_repairSession;	// 296 = 0x128
    _Bool _repairSilent;	// 304 = 0x130
    SFWiFiHealthMonitor *_wifiHealthMonitor;	// 312 = 0x138
    _Bool _wifiBad;	// 320 = 0x140
    _Bool _wifiBad8021x;	// 321 = 0x141
    _Bool _prefRepairAccounts;	// 322 = 0x142
    _Bool _prefRepairVPN;	// 323 = 0x143
    _Bool _prefRepairWiFi;	// 324 = 0x144
    _Bool _preventRepair;	// 325 = 0x145
    NSObject<OS_dispatch_queue> *_dispatchQueue;	// 328 = 0x148
}

+ (id)sharedSetupAgent;	// IMP=0x00000001001bc464
@property(nonatomic) _Bool preventRepair; // @synthesize preventRepair=_preventRepair;
@property(retain, nonatomic) NSObject<OS_dispatch_queue> *dispatchQueue; // @synthesize dispatchQueue=_dispatchQueue;
- (void).cxx_destruct;	// IMP=0x00000001001c9544
- (void)testUIAppleTVSetup:(id)arg1;	// IMP=0x00000001001c9288
- (void)testSetupUIWHA:(id)arg1;	// IMP=0x00000001001c8f4c
- (void)testSetupUIWatch:(id)arg1;	// IMP=0x00000001001c8dd4
- (void)testSetupUIPasswordSharing:(id)arg1;	// IMP=0x00000001001c8b40
- (void)testSetupUIiOS:(id)arg1;	// IMP=0x00000001001c8940
- (void)testSetupUIB238:(id)arg1;	// IMP=0x00000001001c8494
- (void)testRepairUI:(id)arg1;	// IMP=0x00000001001c8238
- (void)testPINHide;	// IMP=0x00000001001c81c8
- (void)testPINShow:(id)arg1;	// IMP=0x00000001001c8128
- (void)testPairUI:(id)arg1;	// IMP=0x00000001001c7ea0
- (void)testNFCUI:(id)arg1;	// IMP=0x00000001001c7d18
- (void)testHomeKitDeviceDetected:(id)arg1;	// IMP=0x00000001001c7be8
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;	// IMP=0x00000001001c7a74
- (void)_repairVPNError:(id)arg1;	// IMP=0x00000001001c7994
- (void)_repairUpdateIDSCache;	// IMP=0x00000001001c78e0
- (void)_repairSilentProgress:(unsigned int)arg1 info:(id)arg2;	// IMP=0x00000001001c7678
- (void)_repairSilentStart:(id)arg1;	// IMP=0x00000001001c74a4
- (void)_repairProblemFlagsChanged;	// IMP=0x00000001001c7380
- (void)_repairHandleManateeChanged;	// IMP=0x00000001001c72f4
- (void)_repairHandleCompletion;	// IMP=0x00000001001c7258
- (void)_repairHandleCFUItems:(id)arg1;	// IMP=0x00000001001c6d10
- (void)_repairHandleCFUItemsChanged;	// IMP=0x00000001001c6a98
- (void)_repairEnsuredStopped;	// IMP=0x00000001001c6888
- (void)_repairEnsuredStarted;	// IMP=0x00000001001c5994
- (void)_pwsHandleProgressEvent:(unsigned int)arg1 info:(id)arg2;	// IMP=0x00000001001c5754
- (void)_pwsHandleUserResponse:(int)arg1 device:(id)arg2 info:(id)arg3;	// IMP=0x00000001001c56dc
- (void)_pinPairHandleHidePIN;	// IMP=0x00000001001c5614
- (void)_pinPairHandleShowPIN:(id)arg1;	// IMP=0x00000001001c5140
- (void)_pinPairHandleRequest:(id)arg1;	// IMP=0x00000001001c4c74
- (void)_ensureServerStopped;	// IMP=0x00000001001c4aa0
- (void)_ensureServerStarted;	// IMP=0x00000001001c4634
- (void)_wifiStateChanged;	// IMP=0x00000001001c4570
- (void)_watchStartMigration:(id)arg1;	// IMP=0x00000001001c43cc
- (id)_watchMigrating:(id)arg1;	// IMP=0x00000001001c40a4
- (void)_watchFound:(id)arg1;	// IMP=0x00000001001c3af0
- (void)_watchFastScanStop;	// IMP=0x00000001001c3a18
- (void)_watchFastScanStartIfAllowed:(id)arg1;	// IMP=0x00000001001c3888
- (void)_uiStopIfNeededWithDevice:(id)arg1;	// IMP=0x00000001001c3810
- (void)_uiStartForMacWithDevice:(id)arg1 label:(id)arg2 extraInfo:(id)arg3;	// IMP=0x00000001001c3774
- (void)_uiStartWithDevice:(id)arg1 viewControllerName:(id)arg2 xpcEndpoint:(id)arg3 label:(id)arg4 extraInfo:(id)arg5;	// IMP=0x00000001001c3708
- (void)_uiStartWithDevice:(id)arg1 viewControllerName:(id)arg2 xpcEndpoint:(id)arg3 label:(id)arg4 unlessApps:(id)arg5 extraInfo:(id)arg6;	// IMP=0x00000001001c366c
- (void)_uiStartWithDevice:(id)arg1 viewControllerName:(id)arg2 label:(id)arg3 unlessApps:(id)arg4 extraInfo:(id)arg5;	// IMP=0x00000001001c35bc
- (void)_uiStartWiFiPasswordSharing:(id)arg1;	// IMP=0x00000001001c32d8
- (void)_uiStartSetupWHA:(id)arg1;	// IMP=0x00000001001c32b4
- (void)_uiStartSetupWatch:(id)arg1;	// IMP=0x00000001001c314c
- (void)_uiStartSetupiOS:(id)arg1 autoStart:(_Bool)arg2;	// IMP=0x00000001001c2f8c
- (void)_uiStartSetupB238:(id)arg1 extraInfo:(id)arg2;	// IMP=0x00000001001c2f28
- (void)_uiStartRepair:(id)arg1 flags:(unsigned int)arg2;	// IMP=0x00000001001c2e0c
- (void)_uiStartPair:(id)arg1 extraInfo:(id)arg2;	// IMP=0x00000001001c2d2c
- (void)_uiStartHomeKitDeviceDetectedWithURL:(id)arg1;	// IMP=0x00000001001c2bd8
- (void)_uiStartAppleTVSetup:(id)arg1 extraInfo:(id)arg2;	// IMP=0x00000001001c2b74
- (_Bool)_uiShowing;	// IMP=0x00000001001c2b6c
- (void)_uiLockStatusChanged:(id)arg1;	// IMP=0x00000001001c2a30
- (_Bool)_shouldOfferPassword:(id)arg1;	// IMP=0x00000001001c2448
- (void)_screenStateChanged:(id)arg1;	// IMP=0x00000001001c230c
- (void)_scanTimerFired;	// IMP=0x00000001001c2258
- (void)_resetTriggers;	// IMP=0x00000001001c21c4
- (void)_iTunesAccountsChanged;	// IMP=0x00000001001c2120
- (void)_hsa2Changed;	// IMP=0x00000001001c206c
- (void)_appleAccountSignIn:(id)arg1;	// IMP=0x00000001001c1f7c
- (void)_postDeviceSetupNotificationForDevice:(id)arg1 present:(_Bool)arg2;	// IMP=0x00000001001c1d3c
- (void)_launchAppWithMachServiceName:(id)arg1;	// IMP=0x00000001001c1aa4
- (void)_deviceLost:(id)arg1;	// IMP=0x00000001001c19b0
- (void)_deviceFound:(id)arg1;	// IMP=0x00000001001c05ec
- (void)_ensureClientStopped;	// IMP=0x00000001001c02e8
- (void)_ensureClientStarted;	// IMP=0x00000001001bf4f0
- (void)_update;	// IMP=0x00000001001bf434
@property(readonly, nonatomic) _Bool uiShowing;
- (void)triggerHomeKitDeviceDetectedWithURL:(id)arg1 completion:(CDUnknownBlockType)arg2;	// IMP=0x00000001001bf104
- (void)showDevicePickerWithInfo:(id)arg1 completion:(CDUnknownBlockType)arg2;	// IMP=0x00000001001bee88
- (void)setupDevice:(id)arg1 homeIdentifier:(id)arg2 completion:(CDUnknownBlockType)arg3;	// IMP=0x00000001001bed7c
- (void)retriggerProximitySetup:(CDUnknownBlockType)arg1;	// IMP=0x00000001001bea3c
- (void)repairDevice:(id)arg1 flags:(unsigned int)arg2 completion:(CDUnknownBlockType)arg3;	// IMP=0x00000001001be920
- (void)reenableProxCardType:(unsigned char)arg1;	// IMP=0x00000001001be4d0
- (void)prefsChanged;	// IMP=0x00000001001bdb8c
- (void)_openSetupURL:(id)arg1;	// IMP=0x00000001001bdb14
- (void)openSetupURL:(id)arg1;	// IMP=0x00000001001bda9c
- (void)nfcTagReaderUIActivateWithEndpoint:(id)arg1 params:(id)arg2 completion:(CDUnknownBlockType)arg3;	// IMP=0x00000001001bd7f0
- (void)_invalidate;	// IMP=0x00000001001bd738
- (void)invalidate;	// IMP=0x00000001001bd6c8
- (void)_activate;	// IMP=0x00000001001bd544
- (void)activate;	// IMP=0x00000001001bd4d4
- (id)descriptionWithLevel:(int)arg1;	// IMP=0x00000001001bc718
- (id)description;	// IMP=0x00000001001bc708
- (void)dealloc;	// IMP=0x00000001001bc598
- (id)init;	// IMP=0x00000001001bc4ec

@end

