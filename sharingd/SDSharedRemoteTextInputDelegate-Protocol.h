//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

@class NSDictionary;

@protocol SDSharedRemoteTextInputDelegate

@optional
- (void)handleInputDidEndWithFlags:(unsigned long long)arg1 sessionInfo:(NSDictionary *)arg2;
- (void)handleInputDidBeginWithFlags:(unsigned long long)arg1 sessionInfo:(NSDictionary *)arg2;
- (void)handleEventWithData:(struct NSDictionary *)arg1;
@end
