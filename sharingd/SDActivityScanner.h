//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "SDActivityController.h"

#import "IDSContinuityDelegate-Protocol.h"
#import "SFContinuityScannerProtocol-Protocol.h"

@class IDSContinuity, NSMutableDictionary, NSObject, NSString, SDStatusMonitor;
@protocol OS_dispatch_source;

__attribute__((visibility("hidden")))
@interface SDActivityScanner : SDActivityController <IDSContinuityDelegate, SFContinuityScannerProtocol>
{
    unsigned long long _stateHandle;	// 8 = 0x8
    unsigned char _versionByte;	// 16 = 0x10
    SDStatusMonitor *_monitor;	// 24 = 0x18
    IDSContinuity *_continuity;	// 32 = 0x20
    unsigned long long _scanTypes;	// 40 = 0x28
    _Bool _scannerEnabled;	// 48 = 0x30
    _Bool _isScanning;	// 49 = 0x31
    NSObject<OS_dispatch_source> *_stopScanLostDeviceTimer;	// 56 = 0x38
    NSMutableDictionary *_deviceIdentifierToDeviceRecord;	// 64 = 0x40
    NSMutableDictionary *_deviceIdentifierToLostDeviceTimers;	// 72 = 0x48
}

+ (id)sharedScanner;	// IMP=0x0000000100158ae4
- (void).cxx_destruct;	// IMP=0x000000010015c1c0
- (void)activityPayloadFromDeviceUniqueID:(id)arg1 forAdvertisementPayload:(id)arg2 command:(id)arg3 timeout:(long long)arg4 withCompletionHandler:(CDUnknownBlockType)arg5;	// IMP=0x000000010015bf5c
- (void)scanForTypes:(unsigned long long)arg1;	// IMP=0x000000010015be2c
- (void)didLosePeerTimer:(id)arg1;	// IMP=0x000000010015bd78
- (void)lostAllDevices;	// IMP=0x000000010015bbc8
- (void)didLosePeer:(id)arg1;	// IMP=0x000000010015b8d8
- (void)continuity:(id)arg1 didDiscoverType:(long long)arg2 withData:(id)arg3 fromPeer:(id)arg4;	// IMP=0x000000010015b794
- (void)continuity:(id)arg1 didFailToStartScanningForType:(long long)arg2 withError:(id)arg3;	// IMP=0x000000010015b66c
- (void)continuity:(id)arg1 didStopScanningForType:(long long)arg2;	// IMP=0x000000010015b594
- (void)continuity:(id)arg1 didStartScanningForType:(long long)arg2;	// IMP=0x000000010015b4b8
- (void)continuityDidUpdateState:(id)arg1;	// IMP=0x000000010015b218
- (void)consoleUserChanged:(id)arg1;	// IMP=0x000000010015b0ec
- (void)systemHasPoweredOn:(id)arg1;	// IMP=0x000000010015b018
- (void)systemWillSleep:(id)arg1;	// IMP=0x000000010015af60
- (void)resetStateRequested:(id)arg1;	// IMP=0x000000010015af54
- (void)removeObservers;	// IMP=0x000000010015af04
- (void)addObservers;	// IMP=0x000000010015ae18
- (id)state;	// IMP=0x000000010015abe4
- (struct os_state_data_s *)dumpState;	// IMP=0x000000010015a894
- (void)initializeStateCaptureBlock;	// IMP=0x000000010015a814
- (void)connectionInvalidated:(id)arg1;	// IMP=0x000000010015a754
- (void)connectionEstablished:(id)arg1;	// IMP=0x000000010015a508
- (_Bool)shouldAcceptNewConnection:(id)arg1;	// IMP=0x000000010015a500
- (id)remoteObjectInterface;	// IMP=0x000000010015a340
- (id)exportedInterface;	// IMP=0x000000010015a324
- (id)machServiceName;	// IMP=0x000000010015a2f8
- (void)_enumerateRemoteObjectProxiesUsingBlock:(CDUnknownBlockType)arg1;	// IMP=0x000000010015a2ec
- (void)_remoteObjectProxyForConnection:(id)arg1 usingBlock:(CDUnknownBlockType)arg2;	// IMP=0x000000010015a29c
- (void)handleNewAdvertisementDevice:(id)arg1 data:(id)arg2 receivedViaScanning:(_Bool)arg3 withSuccessHandler:(CDUnknownBlockType)arg4;	// IMP=0x0000000100159b20
- (void)nearbyServiceDevicesChanged:(id)arg1;	// IMP=0x00000001001598ac
- (void)activityServiceDevicesChanged:(id)arg1;	// IMP=0x0000000100159418
- (_Bool)restart;	// IMP=0x0000000100158d98
- (void)stop;	// IMP=0x0000000100158d80
- (void)start;	// IMP=0x0000000100158d64
- (_Bool)shouldScanForCopyPaste;	// IMP=0x0000000100158d50
- (_Bool)shouldScanForHandoff;	// IMP=0x0000000100158d3c
- (id)init;	// IMP=0x0000000100158bb4

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
