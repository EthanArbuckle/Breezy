//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@class NSNetService, NSString;
@protocol SDAirDropIconCacherDelegate;

__attribute__((visibility("hidden")))
@interface SDAirDropIconCacher : NSObject
{
    long long _bytesWritten;	// 8 = 0x8
    struct __CFReadStream *_readStream;	// 16 = 0x10
    struct __CFWriteStream *_writeStream;	// 24 = 0x18
    id _iconData;	// 32 = 0x20
    NSString *_iconHash;	// 40 = 0x28
    NSNetService *_netService;	// 48 = 0x30
    id <SDAirDropIconCacherDelegate> _delegate;	// 56 = 0x38
}

@property __weak id <SDAirDropIconCacherDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain) NSNetService *netService; // @synthesize netService=_netService;
@property(copy) NSString *iconHash; // @synthesize iconHash=_iconHash;
@property(copy) id iconData; // @synthesize iconData=_iconData;
- (void).cxx_destruct;	// IMP=0x00000001000689dc
- (void)cancel;	// IMP=0x0000000100068920
- (void)cancelWriteStream;	// IMP=0x00000001000688c4
- (void)cancelReadStream;	// IMP=0x0000000100068868
- (void)store;	// IMP=0x00000001000686cc
- (void)fetch;	// IMP=0x0000000100068530
- (void)notifyFetchWithError:(id)arg1;	// IMP=0x0000000100068464
- (void)notifyStoreWithError:(id)arg1;	// IMP=0x0000000100068398
- (id)airDropCacheFileURL;	// IMP=0x0000000100068278
- (void)handleWriteStreamEvent:(struct __CFWriteStream *)arg1 type:(unsigned long long)arg2;	// IMP=0x0000000100068040
- (void)handleReadStreamEvent:(struct __CFReadStream *)arg1 type:(unsigned long long)arg2;	// IMP=0x0000000100067e24
- (void)dealloc;	// IMP=0x0000000100067dd8
- (id)init;	// IMP=0x0000000100067d40

@end
