//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

#import "SDMISManagerDelegate-Protocol.h"

@class NSMutableArray, NSString, NSTimer, SDMISManager;
@protocol OS_dispatch_queue, SDHotspotManagerDelegate;

__attribute__((visibility("hidden")))
@interface SDHotspotManager : NSObject <SDMISManagerDelegate>
{
    struct __WiFiManagerClient *_wifiClient;	// 8 = 0x8
    struct __WiFiDeviceClient *_wifiDevice;	// 16 = 0x10
    SDMISManager *_misManager;	// 24 = 0x18
    _Bool _isWifiPowerOn;	// 32 = 0x20
    _Bool _checkedAuthentication;	// 33 = 0x21
    _Bool _tetheringSupported;	// 34 = 0x22
    _Bool _startedHostAP;	// 35 = 0x23
    _Bool _capturingTailspin;	// 36 = 0x24
    _Bool _flippedHotspotSwitch;	// 37 = 0x25
    id <SDHotspotManagerDelegate> _delegate;	// 40 = 0x28
    id _hostAPNetwork;	// 48 = 0x30
    NSObject<OS_dispatch_queue> *_workQueue;	// 56 = 0x38
    NSTimer *_networkTimer;	// 64 = 0x40
    NSMutableArray *_handlers;	// 72 = 0x48
}

@property(retain) NSMutableArray *handlers; // @synthesize handlers=_handlers;
@property(retain) NSTimer *networkTimer; // @synthesize networkTimer=_networkTimer;
@property(retain) NSObject<OS_dispatch_queue> *workQueue; // @synthesize workQueue=_workQueue;
@property(retain) id hostAPNetwork; // @synthesize hostAPNetwork=_hostAPNetwork;
@property _Bool flippedHotspotSwitch; // @synthesize flippedHotspotSwitch=_flippedHotspotSwitch;
@property _Bool capturingTailspin; // @synthesize capturingTailspin=_capturingTailspin;
@property _Bool startedHostAP; // @synthesize startedHostAP=_startedHostAP;
@property __weak id <SDHotspotManagerDelegate> delegate; // @synthesize delegate=_delegate;
@property(getter=isTetheringSupported) _Bool tetheringSupported; // @synthesize tetheringSupported=_tetheringSupported;
- (void).cxx_destruct;	// IMP=0x0000000100135da0
- (void)onqueue_handleHostAPChanged:(id)arg1;	// IMP=0x0000000100135a50
- (void)handleHostAPChanged:(id)arg1;	// IMP=0x0000000100135904
- (_Bool)isNetworkHostAP:(struct __WiFiNetwork *)arg1;	// IMP=0x000000010013589c
- (void)misStateChanged:(id)arg1;	// IMP=0x0000000100135804
- (void)notifyHostAPError:(id)arg1;	// IMP=0x00000001001356b0
- (void)notifyHostAPActivated;	// IMP=0x00000001001354ec
- (id)hotspotChannel;	// IMP=0x000000010013543c
@property(readonly) NSString *hotspotPassword;
- (id)_createDefaultPassword;	// IMP=0x00000001001350e0
- (_Bool)setHotspotPassword:(id)arg1;	// IMP=0x0000000100135024
@property(readonly) NSString *hotspotName;
- (void)onqueue_captureTailspin;	// IMP=0x0000000100134af8
- (void)invalidateNetworkTimer;	// IMP=0x0000000100134a54
- (void)networkTimerFired:(id)arg1;	// IMP=0x0000000100134950
- (void)restartNetworkTimer;	// IMP=0x0000000100134820
- (void)onqueue_cleanUpFailedNetworkBringUp;	// IMP=0x00000001001346f8
- (void)disableMISImmediately;	// IMP=0x0000000100134654
- (void)turnOffDiscovery;	// IMP=0x0000000100134540
- (void)stopTethering;	// IMP=0x00000001001344f0
- (void)onqueue_startTetheringWithCompletionHandler:(CDUnknownBlockType)arg1;	// IMP=0x0000000100134028
- (void)startTetheringWithCompletionHandler:(CDUnknownBlockType)arg1;	// IMP=0x0000000100133f88
@property(readonly, getter=isTetheringInUse) _Bool tetheringInUse;
- (_Bool)isTethering;	// IMP=0x0000000100133d14
- (_Bool)shouldTurnOffTethering;	// IMP=0x0000000100133ac0
- (void)onqueue_handleSwitchCondtionsChanged;	// IMP=0x000000010013398c
- (void)onqueue_updateHostAPNetwork;	// IMP=0x0000000100133710
- (void)onqueue_updateTetheringSupported;	// IMP=0x00000001001333b4
- (_Bool)netRBTetheringSupported;	// IMP=0x000000010013335c
- (void)personalHotspotAllowedChanged:(id)arg1;	// IMP=0x000000010013327c
- (void)simStateChanged:(id)arg1;	// IMP=0x000000010013320c
- (void)firstUnlockStateChanged:(id)arg1;	// IMP=0x000000010013319c
- (void)debugInfoRequest:(id)arg1;	// IMP=0x0000000100132e4c
- (void)removeObservers;	// IMP=0x0000000100132dfc
- (void)addObservers;	// IMP=0x0000000100132d10
- (void)dealloc;	// IMP=0x0000000100132c5c
- (id)initWithDelegate:(id)arg1;	// IMP=0x00000001001328fc

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

