//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "SDXPCDaemon.h"

#import "SDAirDropAlertManager-Protocol.h"
#import "SDAirDropTransferManagerProtocol-Protocol.h"

@class NSArray, NSMutableDictionary, NSObject, NSString;
@protocol SDAirDropAlertManagerDelegate;

__attribute__((visibility("hidden")))
@interface SDAirDropTransferManager : SDXPCDaemon <SDAirDropTransferManagerProtocol, SDAirDropAlertManager>
{
    NSObject<SDAirDropAlertManagerDelegate> *delegate;	// 8 = 0x8
    NSObject<SDAirDropAlertManagerDelegate> *_classroomDelegate;	// 16 = 0x10
    NSMutableDictionary *_transferIdentifierToTransfer;	// 24 = 0x18
    NSMutableDictionary *_transferIdentifierToHandler;	// 32 = 0x20
    NSArray *_kvoObservingKeys;	// 40 = 0x28
}

@property(retain) NSArray *kvoObservingKeys; // @synthesize kvoObservingKeys=_kvoObservingKeys;
@property(retain) NSMutableDictionary *transferIdentifierToHandler; // @synthesize transferIdentifierToHandler=_transferIdentifierToHandler;
@property(retain) NSMutableDictionary *transferIdentifierToTransfer; // @synthesize transferIdentifierToTransfer=_transferIdentifierToTransfer;
@property(nonatomic) __weak NSObject<SDAirDropAlertManagerDelegate> *classroomDelegate; // @synthesize classroomDelegate=_classroomDelegate;
@property(nonatomic) __weak NSObject<SDAirDropAlertManagerDelegate> *delegate; // @synthesize delegate;
- (void).cxx_destruct;	// IMP=0x0000000100161134
- (id)itemTypesForTransfer:(id)arg1;	// IMP=0x0000000100160b10
- (void)loadAllPersistedTransfers;	// IMP=0x0000000100160784
- (void)cleanUpURL:(id)arg1;	// IMP=0x0000000100160588
- (id)transferURLForTransfer:(id)arg1;	// IMP=0x00000001001604a0
- (id)persistedTransfersBaseURL;	// IMP=0x000000010016044c
- (void)setTransferState:(unsigned long long)arg1 forTransfer:(id)arg2 shouldNotify:(_Bool)arg3 shouldCleanup:(_Bool)arg4;	// IMP=0x0000000100160280
- (void)setTransferState:(unsigned long long)arg1 forTransfer:(id)arg2 shouldNotify:(_Bool)arg3;	// IMP=0x0000000100160270
- (void)failTransfer:(id)arg1 withState:(unsigned long long)arg2 failureReason:(unsigned long long)arg3;	// IMP=0x000000010015fff0
- (void)handlerFailedForTransfer:(id)arg1;	// IMP=0x000000010015fd6c
- (void)setHandler:(id)arg1 forTransfer:(id)arg2;	// IMP=0x000000010015faa4
- (id)determineHandlerForTransfer:(id)arg1;	// IMP=0x000000010015f5e0
- (void)connectionInvalidated:(id)arg1;	// IMP=0x000000010015f4fc
- (void)connectionEstablished:(id)arg1;	// IMP=0x000000010015f260
- (_Bool)shouldAcceptNewConnection:(id)arg1;	// IMP=0x000000010015f258
- (id)remoteObjectInterface;	// IMP=0x000000010015f23c
- (id)exportedInterface;	// IMP=0x000000010015f220
- (id)machServiceName;	// IMP=0x000000010015f1f4
- (void)transfer:(id)arg1 actionTriggeredForAction:(id)arg2;	// IMP=0x000000010015f080
- (void)transferUserResponseUpdated:(id)arg1;	// IMP=0x000000010015ebd0
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;	// IMP=0x000000010015ea74
- (void)finishedEventForRecordID:(id)arg1 withResults:(id)arg2;	// IMP=0x000000010015e8e4
- (void)errorEventForRecordID:(id)arg1 withResults:(id)arg2;	// IMP=0x000000010015e6b0
- (void)cancelEventForRecordID:(id)arg1 withResults:(id)arg2;	// IMP=0x000000010015e520
- (void)progressEventForRecordID:(id)arg1 withResults:(id)arg2;	// IMP=0x000000010015e378
- (void)askEventForRecordID:(id)arg1 withResults:(id)arg2;	// IMP=0x000000010015dedc
- (void)cleanUpTransfer:(id)arg1;	// IMP=0x000000010015dddc
- (void)removeTransfer:(id)arg1 shouldCleanup:(_Bool)arg2;	// IMP=0x000000010015dbc8
- (void)notifyObserversOfRemovedTransfer:(id)arg1;	// IMP=0x000000010015db14
- (void)notifyObserversOfUpdatedTransfer:(id)arg1;	// IMP=0x000000010015da6c
- (void)_enumerateRemoteObjectProxiesUsingBlock:(CDUnknownBlockType)arg1;	// IMP=0x000000010015da60
- (void)_remoteObjectProxyForConnection:(id)arg1 usingBlock:(CDUnknownBlockType)arg2;	// IMP=0x000000010015da10
- (void)invalidate;	// IMP=0x000000010015d9dc
- (void)activate;	// IMP=0x000000010015d9a8
- (id)init;	// IMP=0x000000010015d844

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

