//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "NSObject-Protocol.h"

@class IDSContinuity, NSData, NSError, NSUUID;

@protocol IDSContinuityDelegate <NSObject>
- (void)continuityDidUpdateState:(IDSContinuity *)arg1;

@optional
- (void)continuity:(IDSContinuity *)arg1 didStopTrackingPeer:(NSUUID *)arg2 type:(long long)arg3;
- (void)continuity:(IDSContinuity *)arg1 didStartTrackingPeer:(NSUUID *)arg2 type:(long long)arg3 error:(NSError *)arg4;
- (void)continuity:(IDSContinuity *)arg1 didLosePeer:(NSUUID *)arg2 type:(long long)arg3;
- (void)continuity:(IDSContinuity *)arg1 didDiscoverType:(long long)arg2 withData:(NSData *)arg3 fromPeer:(NSUUID *)arg4;
- (void)continuity:(IDSContinuity *)arg1 didFailToStartScanningForType:(long long)arg2 withError:(NSError *)arg3;
- (void)continuity:(IDSContinuity *)arg1 didStopScanningForType:(long long)arg2;
- (void)continuity:(IDSContinuity *)arg1 didStartScanningForType:(long long)arg2;
- (void)continuity:(IDSContinuity *)arg1 didFailToStartAdvertisingOfType:(long long)arg2 withError:(NSError *)arg3;
- (void)continuity:(IDSContinuity *)arg1 didStopAdvertisingOfType:(long long)arg2;
- (void)continuity:(IDSContinuity *)arg1 didStartAdvertisingOfType:(long long)arg2;
@end

