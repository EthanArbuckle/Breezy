//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "SDXPCDaemonProtocol-Protocol.h"

@class NSDictionary, NSString;

@protocol SDAirDropClassroomTransferManagerProtocol <SDXPCDaemonProtocol>
- (void)updateTransferWithIdentifier:(NSString *)arg1 withState:(long long)arg2 information:(NSDictionary *)arg3 completionHandler:(void (^)(_Bool, NSURL *, NSError *))arg4;
@end
