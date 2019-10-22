//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

#import "IDSServiceDelegate-Protocol.h"

@class CUSystemMonitor, IDSService, NSArray, NSData, NSDictionary, NSMutableSet, NSSet, NSString, NSUUID, RPIdentity, SDStatusMonitor, SFBLEAdvertiser, SFBLEPipe, SFBLEScanner, SFSystemService, WPNearby;
@protocol OS_dispatch_queue, OS_dispatch_source;

__attribute__((visibility("hidden")))
@interface SDNearbyAgent : NSObject <IDSServiceDelegate>
{
    _Bool _activated;	// 8 = 0x8
    _Bool _activityCarPlayRegistered;	// 9 = 0x9
    _Bool _activityMultipleUsersRegistered;	// 10 = 0xa
    unsigned char _activityLevel;	// 11 = 0xb
    _Bool _activityMonitorStarted;	// 12 = 0xc
    int _activityPollSeconds;	// 16 = 0x10
    int _activityRecentSeconds;	// 20 = 0x14
    _Bool _activityScreenOn;	// 24 = 0x18
    NSObject<OS_dispatch_source> *_activityTimer;	// 32 = 0x20
    _Bool _activityUIUnlocked;	// 40 = 0x28
    _Bool _activityUserActive;	// 41 = 0x29
    NSData *_bleAdvertisingAddress;	// 48 = 0x30
    NSData *_bleAuthTag;	// 56 = 0x38
    NSData *_bleAuthTagOverride;	// 64 = 0x40
    struct NSMutableDictionary *_bleConnections;	// 72 = 0x48
    _Bool _bleDiagnosticAdvSuppressLogged;	// 80 = 0x50
    NSMutableSet *_bleDiagnosticModeClients;	// 88 = 0x58
    SFBLEAdvertiser *_bleNearbyActionAdvertiser;	// 96 = 0x60
    _Bool _bleNearbyActionAdvertiseActive;	// 104 = 0x68
    _Bool _bleNearbyActionAdvertiseDisabled;	// 105 = 0x69
    NSObject<OS_dispatch_source> *_bleNearbyActionAdvertiseLingerTimer;	// 112 = 0x70
    struct NSMutableDictionary *_bleNearbyActionDevices;	// 120 = 0x78
    _Bool _bleNearbyActionRSSILog;	// 128 = 0x80
    _Bool _bleNearbyActionScanAlways;	// 129 = 0x81
    _Bool _bleNearbyActionScanNever;	// 130 = 0x82
    SFBLEScanner *_bleNearbyActionScanner;	// 136 = 0x88
    _Bool _bleNearbyInfoAdvertiseAlways;	// 144 = 0x90
    _Bool _bleNearbyInfoAdvertiseDisabled;	// 145 = 0x91
    double _bleNearbyInfoAdvertiseLingerSecs;	// 152 = 0x98
    SFBLEAdvertiser *_bleNearbyInfoAdvertiser;	// 160 = 0xa0
    _Bool _bleNearbyInfoAdvertised;	// 168 = 0xa8
    NSObject<OS_dispatch_source> *_bleNearbyInfoAdvertiseLingerTimer;	// 176 = 0xb0
    struct NSMutableDictionary *_bleNearbyInfoDevices;	// 184 = 0xb8
    _Bool _bleNearbyInfoRSSILog;	// 192 = 0xc0
    _Bool _bleNearbyInfoWiFiP2P;	// 193 = 0xc1
    SFBLEScanner *_bleNearbyInfoScanner;	// 200 = 0xc8
    WPNearby *_bleWPNearby;	// 208 = 0xd0
    _Bool _bleProximityEnabled;	// 216 = 0xd8
    NSDictionary *_bleProximityInfo;	// 224 = 0xe0
    NSDictionary *_bleProximityInfoOverride;	// 232 = 0xe8
    SFBLEScanner *_bleProximityPairingScanner;	// 240 = 0xf0
    _Bool _bleProximityRSSILog;	// 248 = 0xf8
    _Bool _btPipeEnabled;	// 249 = 0xf9
    _Bool _btPipeForced;	// 250 = 0xfa
    SFBLEPipe *_btPipe;	// 256 = 0x100
    _Bool _caEnabled;	// 264 = 0x108
    int _caForce;	// 268 = 0x10c
    unsigned int _caMessageNoScans;	// 272 = 0x110
    unsigned int _caMessageScans;	// 276 = 0x114
    _Bool _caPhoneCalls;	// 280 = 0x118
    struct NSMutableSet *_caRequests;	// 288 = 0x120
    _Bool _caScanIfVeryActive;	// 296 = 0x128
    _Bool _caSingleDevice;	// 297 = 0x129
    NSData *_contactHashesCached;	// 304 = 0x130
    _Bool _contactHashesEnabled;	// 312 = 0x138
    unsigned long long _ddFastScanLastEndTicks;	// 320 = 0x140
    NSObject<OS_dispatch_source> *_ddFastScanTimer;	// 328 = 0x148
    struct NSMutableDictionary *_ddNearbyActionDevices;	// 336 = 0x150
    _Bool _ddNearbyActionEnabled;	// 344 = 0x158
    _Bool _ddNearbyActionScreenOff;	// 345 = 0x159
    struct NSMutableDictionary *_ddNearbyInfoDevices;	// 352 = 0x160
    _Bool _ddNearbyInfoEnabled;	// 360 = 0x168
    _Bool _ddNearbyInfoScreenOff;	// 361 = 0x169
    struct NSMutableDictionary *_ddProximityPairingDevices;	// 368 = 0x170
    _Bool _ddProximityPairingEnabled;	// 376 = 0x178
    _Bool _ddProximityPairingScreenOff;	// 377 = 0x179
    struct NSMutableSet *_ddRequests;	// 384 = 0x180
    unsigned long long _familyFlags;	// 392 = 0x188
    int _familyNotifyToken;	// 400 = 0x190
    int _idsAppleTVCountCache;	// 404 = 0x194
    NSArray *_idsBluetoothDevicesArray;	// 408 = 0x198
    NSSet *_idsBluetoothDevicesSet;	// 416 = 0x1a0
    NSArray *_idsBluetoothDeviceIDsForLEPipe;	// 424 = 0x1a8
    NSSet *_idsBluetoothDeviceIDsForMe;	// 432 = 0x1b0
    struct NSMutableDictionary *_idsBTtoIDSInfoMap;	// 440 = 0x1b8
    int _idsContinuityDeviceCountCache;	// 448 = 0x1c0
    NSArray *_idsDeviceArray;	// 456 = 0x1c8
    struct NSDictionary *_idsDeviceBTDictionary;	// 464 = 0x1d0
    int _idsHasActiveWatchCache;	// 472 = 0x1d8
    int _idsHomePodCountCache;	// 476 = 0x1dc
    int _idsIsSignedInCache;	// 480 = 0x1e0
    int _idsMacCountCache;	// 484 = 0x1e4
    int _idsShouldAdvertiseNearbyInfo;	// 488 = 0x1e8
    IDSService *_idsService;	// 496 = 0x1f0
    _Bool _logProxAdvFields;	// 504 = 0x1f8
    NSUUID *_remoteAppServiceUUID;	// 512 = 0x200
    struct NSMutableDictionary *_services;	// 520 = 0x208
    struct NSMutableDictionary *_sessions;	// 528 = 0x210
    struct NSMutableDictionary *_setupSessions;	// 536 = 0x218
    double _startTime;	// 544 = 0x220
    SDStatusMonitor *_statusMonitor;	// 552 = 0x228
    CUSystemMonitor *_systemMonitor;	// 560 = 0x230
    SFSystemService *_systemService;	// 568 = 0x238
    _Bool _unlockAdvertiseAlways;	// 576 = 0x240
    _Bool _unlockAdvertiseAggressive;	// 577 = 0x241
    _Bool _unlockAdvertiseEnabled;	// 578 = 0x242
    _Bool _unlockAdvertiseBackground;	// 579 = 0x243
    _Bool _unlockAdvertiseWatch;	// 580 = 0x244
    _Bool _unlockAdvertiseWatchLocked;	// 581 = 0x245
    NSObject<OS_dispatch_source> *_unlockTestClientTimer;	// 584 = 0x248
    struct NSMutableDictionary *_idDevices;	// 592 = 0x250
    _Bool _idEnabled;	// 600 = 0x258
    int _idIdentitiesChangedNotifyToken;	// 604 = 0x25c
    NSArray *_idIdentityArray;	// 608 = 0x260
    NSObject<OS_dispatch_source> *_idMaintenanceTimer;	// 616 = 0x268
    RPIdentity *_idSelfIdentity;	// 624 = 0x270
    _Bool _autoUnlockActive;	// 632 = 0x278
    _Bool _boostNearbyInfo;	// 633 = 0x279
    unsigned int _hotspotInfo;	// 636 = 0x27c
    NSObject<OS_dispatch_queue> *_dispatchQueue;	// 640 = 0x280
}

+ (id)sharedNearbyAgent;	// IMP=0x000000010018a6e8
@property(nonatomic) unsigned int hotspotInfo; // @synthesize hotspotInfo=_hotspotInfo;
@property(retain, nonatomic) NSObject<OS_dispatch_queue> *dispatchQueue; // @synthesize dispatchQueue=_dispatchQueue;
@property(nonatomic) _Bool boostNearbyInfo; // @synthesize boostNearbyInfo=_boostNearbyInfo;
@property(nonatomic) _Bool autoUnlockActive; // @synthesize autoUnlockActive=_autoUnlockActive;
- (void).cxx_destruct;	// IMP=0x00000001001aa82c
- (void)_testPipePing;	// IMP=0x00000001001aa618
- (void)testPipePing;	// IMP=0x00000001001aa5a8
- (void)unlockStopTestServer;	// IMP=0x00000001001aa548
- (void)unlockStartTestServer;	// IMP=0x00000001001aa4e8
- (void)unlockStopTestClient;	// IMP=0x00000001001aa454
- (void)unlockStartTestClientWithDevice:(id)arg1;	// IMP=0x00000001001aa0b8
- (void)unlockUpdateAdvertising:(unsigned int)arg1 mask:(unsigned int)arg2;	// IMP=0x00000001001a9e98
- (void)_unlockReceivedFrameData:(id)arg1 peer:(id)arg2 device:(id)arg3;	// IMP=0x00000001001a9bc0
- (void)_sendUnlockData:(id)arg1 toBLEDevice:(id)arg2 direct:(_Bool)arg3 completion:(CDUnknownBlockType)arg4;	// IMP=0x00000001001a9a08
- (void)sendUnlockDataDirect:(id)arg1 toBLEDevice:(id)arg2 completion:(CDUnknownBlockType)arg3;	// IMP=0x00000001001a9998
- (void)sendUnlockData:(id)arg1 toBLEDevice:(id)arg2 completion:(CDUnknownBlockType)arg3;	// IMP=0x00000001001a9878
- (void)_stopUnlockBLEConnectionWithDevice:(id)arg1;	// IMP=0x00000001001a974c
- (void)stopUnlockBLEConnectionWithDevice:(id)arg1;	// IMP=0x00000001001a96ac
- (void)_startUnlockBLEConnectionWithDevice:(id)arg1 encrypted:(_Bool)arg2;	// IMP=0x00000001001a9410
- (void)startUnlockBLEConnectionWithDevice:(id)arg1 encrypted:(_Bool)arg2;	// IMP=0x00000001001a935c
- (int)_setupSendData:(id)arg1 sessionIdentifier:(id)arg2 cnx:(id)arg3 clientSession:(id)arg4;	// IMP=0x00000001001a8d04
- (int)_setupSendCreateSession:(id)arg1 cnx:(id)arg2;	// IMP=0x00000001001a8958
- (int)_setupHandleSessionMessageType:(unsigned char)arg1 src:(const char *)arg2 end:(const char *)arg3 cnx:(id)arg4 session:(id)arg5;	// IMP=0x00000001001a816c
- (int)_setupHandleSessionEncryptedFrame:(id)arg1 type:(unsigned char)arg2 cnx:(id)arg3;	// IMP=0x00000001001a7c40
- (int)_setupHandleSessionCreated:(id)arg1 data:(id)arg2;	// IMP=0x00000001001a775c
- (int)_setupHandleCreateSession:(id)arg1 data:(id)arg2;	// IMP=0x00000001001a7198
- (int)_sendMessage:(id)arg1 frameType:(unsigned char)arg2 service:(id)arg3 session:(id)arg4;	// IMP=0x00000001001a64d8
- (void)sessionSendResponse:(id)arg1 session:(id)arg2;	// IMP=0x00000001001a6480
- (void)sessionSendRequest:(id)arg1 session:(id)arg2;	// IMP=0x00000001001a6228
- (void)sessionSendEvent:(id)arg1 session:(id)arg2;	// IMP=0x00000001001a5da0
- (void)sessionReceivedFrameType:(unsigned char)arg1 serviceType:(unsigned char)arg2 data:(id)arg3 peer:(id)arg4;	// IMP=0x00000001001a5ba8
- (void)sessionStop:(id)arg1;	// IMP=0x00000001001a593c
- (int)sessionStart:(id)arg1;	// IMP=0x00000001001a5370
- (void)serviceSendResponse:(id)arg1 service:(id)arg2;	// IMP=0x00000001001a5318
- (void)serviceSendRequest:(id)arg1 service:(id)arg2;	// IMP=0x00000001001a50c0
- (void)serviceSendEvent:(id)arg1 service:(id)arg2;	// IMP=0x00000001001a5068
- (void)serviceReceivedFrameType:(unsigned char)arg1 serviceType:(unsigned char)arg2 data:(id)arg3 peer:(id)arg4;	// IMP=0x00000001001a4ec4
- (void)serviceStop:(id)arg1;	// IMP=0x00000001001a4d80
- (int)serviceStart:(id)arg1;	// IMP=0x00000001001a4ab8
- (void)service:(id)arg1 devicesChanged:(id)arg2;	// IMP=0x00000001001a46a4
- (void)service:(id)arg1 connectedDevicesChanged:(id)arg2;	// IMP=0x00000001001a45cc
- (void)service:(id)arg1 activeAccountsChanged:(id)arg2;	// IMP=0x00000001001a449c
- (void)service:(id)arg1 account:(id)arg2 incomingMessage:(id)arg3 fromID:(id)arg4 context:(id)arg5;	// IMP=0x00000001001a438c
- (void)service:(id)arg1 account:(id)arg2 identifier:(id)arg3 hasBeenDeliveredWithContext:(id)arg4;	// IMP=0x00000001001a4298
- (void)service:(id)arg1 account:(id)arg2 identifier:(id)arg3 didSendWithSuccess:(_Bool)arg4 error:(id)arg5 context:(id)arg6;	// IMP=0x00000001001a417c
- (_Bool)_idsShouldAdvertiseNearbyInfo;	// IMP=0x00000001001a3e58
- (void)_idsMeDeviceChanged;	// IMP=0x00000001001a3ca4
- (int)_idsMacCount;	// IMP=0x00000001001a3b24
- (_Bool)idsIsSignedIn;	// IMP=0x00000001001a397c
- (int)_idsHomePodCount;	// IMP=0x00000001001a37bc
- (_Bool)_idsHasActiveWatch;	// IMP=0x00000001001a35a4
- (void)idsDevicesAppendDescription:(id *)arg1;	// IMP=0x00000001001a2d30
- (id)idsDeviceForBluetoothDeviceID:(id)arg1;	// IMP=0x00000001001a2aec
- (id)idsDeviceArray;	// IMP=0x00000001001a2a00
- (int)_idsContinuityDeviceCount;	// IMP=0x00000001001a288c
- (id)_idsBluetoothDeviceIDsForSMSRelay;	// IMP=0x00000001001a26a0
- (id)_idsBluetoothDeviceIDsForSharingLocked;	// IMP=0x00000001001a24f0
- (id)_idsBluetoothDeviceIDsForSharing;	// IMP=0x00000001001a2484
- (id)idsBluetoothDeviceIDsForSharing;	// IMP=0x00000001001a23b0
- (id)_idsBluetoothDeviceIDsForMe;	// IMP=0x00000001001a20b4
- (id)_idsBluetoothDeviceIDsForLEPipe;	// IMP=0x00000001001a1e34
- (id)idsBluetoothDeviceIDsForLEPipe;	// IMP=0x00000001001a1da0
- (id)_idsBluetoothDeviceIDsForiMessage;	// IMP=0x00000001001a1be8
- (id)_idsBluetoothDeviceIDsForHomePods;	// IMP=0x00000001001a1a10
- (id)idsBluetoothDeviceIDsForAppleTVs;	// IMP=0x00000001001a1838
- (int)_idsAppleTVCount;	// IMP=0x00000001001a16b8
- (void)idsAddCachedIDSIdentifierToDevice:(id)arg1;	// IMP=0x00000001001a1518
- (void)idsAddCachedIDSIdentifier:(id)arg1 device:(id)arg2;	// IMP=0x00000001001a1100
- (void)_idsEnsureStopped;	// IMP=0x00000001001a0fc8
- (void)_idsEnsureStarted;	// IMP=0x00000001001a0eec
- (void)_identificationIdentifyDevice:(id)arg1;	// IMP=0x00000001001a0cbc
- (void)_identificationReIdentify;	// IMP=0x00000001001a0bd8
- (void)_identificationMaintenanceTimer;	// IMP=0x00000001001a0940
- (void)_identificationHandleDiscoveryStop;	// IMP=0x00000001001a083c
- (void)_identificationHandleDeviceLost:(id)arg1 flags:(unsigned long long)arg2;	// IMP=0x00000001001a0770
- (void)_identificationHandleDeviceFound:(id)arg1 flags:(unsigned long long)arg2;	// IMP=0x00000001001a00f0
- (void)_identificationGetIdentities;	// IMP=0x000000010019fb88
- (void)_identificationEnsureStopped;	// IMP=0x000000010019fab0
- (void)_identificationEnsureStarted;	// IMP=0x000000010019f8e4
- (void)diagnosticMockLost:(id)arg1;	// IMP=0x000000010019f844
- (void)diagnosticMockFound:(id)arg1;	// IMP=0x000000010019f7a4
- (void)diagnosticMockChanged:(id)arg1;	// IMP=0x000000010019f700
- (void)diagnosticBLEModeStop:(id)arg1;	// IMP=0x000000010019f648
- (void)diagnosticBLEModeStart:(id)arg1;	// IMP=0x000000010019f550
- (void)_deviceDiscoveryBLEScanStateChanged:(long long)arg1 type:(long long)arg2;	// IMP=0x000000010019f3a0
- (void)_deviceDiscoveryBLEDeviceChanged:(id)arg1 type:(long long)arg2 changes:(unsigned int)arg3;	// IMP=0x000000010019eef8
- (void)_deviceDiscoveryBLEDeviceLost:(id)arg1 type:(long long)arg2;	// IMP=0x000000010019eb9c
- (void)_deviceDiscoveryBLEDeviceFound:(id)arg1 type:(long long)arg2;	// IMP=0x000000010019e630
- (void)_deviceDiscoveryFastScanStop:(id)arg1 reset:(_Bool)arg2 reason:(id)arg3;	// IMP=0x000000010019e3d0
- (void)_deviceDiscoveryFastScanStart:(id)arg1 device:(id)arg2 reason:(id)arg3;	// IMP=0x000000010019dffc
- (void)_deviceDiscoveryFastScanEvaluate:(id)arg1 device:(id)arg2;	// IMP=0x000000010019de04
- (void)deviceDiscoveryFastScanCancel:(id)arg1 reason:(id)arg2;	// IMP=0x000000010019dd68
- (void)deviceDiscoveryFastScanTrigger:(id)arg1 reason:(id)arg2;	// IMP=0x000000010019dcec
- (void)deviceDiscoveryRequestUpdate:(id)arg1;	// IMP=0x000000010019db64
- (void)deviceDiscoveryRequestStop:(id)arg1;	// IMP=0x000000010019d7c8
- (void)_deviceDiscoveryRequestStart:(id)arg1;	// IMP=0x000000010019d1c4
- (void)deviceDiscoveryRequestStart:(id)arg1;	// IMP=0x000000010019d124
- (void)coordinatedAlertRequestCancel:(id)arg1;	// IMP=0x000000010019d06c
- (void)coordinatedAlertRequestFinish:(id)arg1;	// IMP=0x000000010019c570
- (void)coordinatedAlertRequestStart:(id)arg1;	// IMP=0x000000010019bb14
- (void)nearbyDidUpdateState:(id)arg1;	// IMP=0x000000010019b964
- (void)nearby:(id)arg1 didReceiveData:(id)arg2 fromPeer:(id)arg3;	// IMP=0x000000010019b798
- (void)nearby:(id)arg1 didDisconnectFromPeer:(id)arg2 error:(id)arg3;	// IMP=0x000000010019ae60
- (void)nearby:(id)arg1 didConnectToPeer:(id)arg2 transport:(long long)arg3 error:(id)arg4;	// IMP=0x000000010019aa90
- (unsigned int)_bleProximityUpdateNearbyInfoDevice:(id)arg1;	// IMP=0x000000010019a92c
- (unsigned int)_bleProximityUpdateNearbyActionDevice:(id)arg1;	// IMP=0x000000010019a7e0
- (long long)bleProximityRSSIThreshold:(id)arg1;	// IMP=0x000000010019a72c
- (long long)bleProximityRSSIThresholdForType:(long long)arg1 device:(id)arg2;	// IMP=0x000000010019a464
- (id)bleProximityRSSIEstimatorInfo;	// IMP=0x000000010019a424
- (id)bleProximityInfoForType:(id)arg1 device:(id)arg2 allInfo:(id)arg3;	// IMP=0x0000000100199d00
- (id)bleProximityInfoForType:(id)arg1 device:(id)arg2;	// IMP=0x0000000100199c04
- (id)bleProximityInfoForActionType:(unsigned char)arg1 device:(id)arg2;	// IMP=0x0000000100199a5c
- (id)bleProximityInfo;	// IMP=0x000000010019713c
- (id)bleProximityEstimatorForActionType:(unsigned char)arg1 device:(id)arg2;	// IMP=0x00000001001970d0
- (void)_bleUpdateScanner:(id)arg1 typeFlag:(unsigned long long)arg2;	// IMP=0x0000000100196774
- (void)_bleUpdateAuthTagIfNeeded;	// IMP=0x00000001001965b4
- (void)_bleAdvertisingAddressChanged;	// IMP=0x000000010019638c
- (void)_btPipeHandleFrameType:(unsigned char)arg1 data:(id)arg2;	// IMP=0x0000000100196070
- (void)_btPipeEnsureStopped;	// IMP=0x0000000100195fd0
- (void)_btPipeEnsureStarted;	// IMP=0x0000000100195d78
- (_Bool)_bleProximityPairingScannerShouldScan;	// IMP=0x0000000100195ce4
- (void)_bleProximityPairingScannerEnsureStopped;	// IMP=0x0000000100195ad8
- (void)_bleProximityPairingScannerEnsureStarted;	// IMP=0x000000010019535c
- (_Bool)_bleNearbyInfoScannerShouldScan;	// IMP=0x000000010019512c
- (void)_bleNearbyInfoScannerEnsureStopped;	// IMP=0x0000000100194f28
- (void)_bleNearbyInfoScannerEnsureStarted;	// IMP=0x0000000100194888
- (int)bleNearbyInfoSendFrameType:(unsigned char)arg1 serviceType:(unsigned char)arg2 data:(id)arg3 peer:(id)arg4 isSession:(_Bool)arg5;	// IMP=0x0000000100193950
- (void)bleNearbyInfoStopConnectionToDevice:(id)arg1 owner:(id)arg2;	// IMP=0x00000001001937f8
- (int)bleNearbyInfoStartConnectionToDevice:(id)arg1 owner:(id)arg2 connected:(_Bool *)arg3;	// IMP=0x0000000100193510
- (int)_bleNearbyInfoReceivedFrameType:(unsigned char)arg1 src:(const char *)arg2 end:(const char *)arg3 cnx:(id)arg4;	// IMP=0x0000000100192880
- (void)_bleNearbyInfoReceivedData:(id)arg1 cnx:(id)arg2 peer:(id)arg3;	// IMP=0x0000000100191dd4
- (void)_bleNearbyInfoAdvertiserUpdate;	// IMP=0x0000000100191454
- (_Bool)_bleNearbyInfoAdvertiserShouldAdvertise;	// IMP=0x00000001001912d8
- (void)_bleNearbyInfoAdvertiserEnsureStopped;	// IMP=0x000000010019120c
- (void)_bleNearbyInfoAdvertiserEnsureStarted;	// IMP=0x0000000100191138
- (_Bool)_bleNearbyActionScannerShouldScan;	// IMP=0x0000000100190ee8
- (void)_bleNearbyActionScannerEnsureStopped;	// IMP=0x0000000100190ce4
- (void)_bleNearbyActionScannerEnsureStarted;	// IMP=0x0000000100190698
- (_Bool)_bleNearbyActionAdvertiserShouldAdvertise;	// IMP=0x0000000100190644
- (void)_bleNearbyActionAdvertiserEnsureStopped;	// IMP=0x000000010019056c
- (void)_bleNearbyActionAdvertiserEnsureStarted;	// IMP=0x000000010018f5f4
- (void)activityStateWithCompletion:(CDUnknownBlockType)arg1;	// IMP=0x000000010018f508
- (void)_activityMonitorWatchWristStateChanged:(id)arg1;	// IMP=0x000000010018f3d4
- (void)_activityMonitorUpdateUserActive:(_Bool)arg1;	// IMP=0x000000010018f1a0
- (void)_activityMonitorUILockStatusChanged:(id)arg1;	// IMP=0x000000010018f02c
- (void)_activityMonitorScreenStateChanged:(id)arg1;	// IMP=0x000000010018eed8
- (void)_activityMonitorMultipleUsersLoggedInChanged:(id)arg1;	// IMP=0x000000010018ed9c
- (double)_activityMonitorLastUserEventDelta;	// IMP=0x000000010018ed74
- (void)_activityMonitorCarPlayStatusChanged:(id)arg1;	// IMP=0x000000010018ec38
- (unsigned char)_activityMonitorCurrentLevelAndNeedsPoll:(_Bool *)arg1 recentUserActivity:(_Bool *)arg2;	// IMP=0x000000010018e9a0
- (void)_activityMonitorUpdate;	// IMP=0x000000010018e810
- (void)_activityMonitorEnsureStopped;	// IMP=0x000000010018e6e4
- (void)_activityMonitorEnsureStarted;	// IMP=0x000000010018e5d8
- (void)_update;	// IMP=0x000000010018e2f0
- (void)update;	// IMP=0x000000010018e2b8
- (void)prefsChanged;	// IMP=0x000000010018d044
- (void)_handleAppleIDChanged:(id)arg1;	// IMP=0x000000010018cf3c
- (void)_invalidate;	// IMP=0x000000010018c9d4
- (void)invalidate;	// IMP=0x000000010018c964
- (void)_activate;	// IMP=0x000000010018c278
- (void)activate;	// IMP=0x000000010018c208
@property(readonly, copy) NSString *description;
- (id)init;	// IMP=0x000000010018a7f4
- (id)sharedNearbyPipe;	// IMP=0x000000010018a770

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

