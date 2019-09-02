//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "SDXPCDaemon.h"

#import "SDAirDropAlertManagerDelegate-Protocol.h"
#import "SDAirDropClassroomTransferManagerProtocol-Protocol.h"

@class NSMutableDictionary, NSString, SDAirDropTransferManager;

__attribute__((visibility("hidden")))
@interface SDAirDropClassroomTransferManager : SDXPCDaemon <SDAirDropClassroomTransferManagerProtocol, SDAirDropAlertManagerDelegate>
{
    NSMutableDictionary *_transferIDToProgress;	// 8 = 0x8
    SDAirDropTransferManager *_transferManager;	// 16 = 0x10
}

@property(retain, nonatomic) SDAirDropTransferManager *transferManager; // @synthesize transferManager=_transferManager;
- (void).cxx_destruct;	// IMP=0x0000000100137500
- (void)connectionInvalidated:(id)arg1;	// IMP=0x0000000100137388
- (void)connectionEstablished:(id)arg1;	// IMP=0x000000010013726c
- (_Bool)shouldAcceptNewConnection:(id)arg1;	// IMP=0x0000000100137264
- (id)remoteObjectInterface;	// IMP=0x0000000100137248
- (id)exportedInterface;	// IMP=0x00000001001370c8
- (id)machServiceName;	// IMP=0x000000010013709c
- (void)alertManager:(id)arg1 cancelingTransferWithRecordID:(id)arg2 withFailureReason:(unsigned long long)arg3;	// IMP=0x0000000100136eb0
- (void)alertManager:(id)arg1 acceptingTransferWithRecordID:(id)arg2 withDestinationURL:(id)arg3 shouldExtractImagesFromLivePhotosForRecordID:(_Bool)arg4;	// IMP=0x0000000100136cd4
- (void)updateTransferWithIdentifier:(id)arg1 withState:(long long)arg2 information:(id)arg3 completionHandler:(CDUnknownBlockType)arg4;	// IMP=0x0000000100136290
- (void)replaceIconValue:(id)arg1 forKey:(id)arg2;	// IMP=0x0000000100136124
- (id)makeDestinationDirectoryWithIdentifier:(id)arg1 error:(id *)arg2;	// IMP=0x0000000100135f20
- (void)_enumerateRemoteObjectProxiesUsingBlock:(CDUnknownBlockType)arg1;	// IMP=0x0000000100135f14
- (void)invalidate;	// IMP=0x0000000100135ee0
- (void)activate;	// IMP=0x0000000100135eac
- (id)init;	// IMP=0x0000000100135e38

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

