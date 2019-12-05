//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@class NSData, NSMutableDictionary, NSString, SDActivityEncryptionKey;

__attribute__((visibility("hidden")))
@interface SDActivityEncryptionManager : NSObject
{
    NSMutableDictionary *_deviceIdentifierToDecryptionKey;	// 8 = 0x8
    SDActivityEncryptionKey *_encryptionKey;	// 16 = 0x10
    NSData *_wrappingKey;	// 24 = 0x18
    _Bool _shouldRefreshWrappingKey;	// 32 = 0x20
}

+ (id)sharedEncryptionManager;	// IMP=0x0000000100152350
- (void).cxx_destruct;	// IMP=0x000000010015516c
- (id)baseDictDecryptionKeyForDeviceIdentifier:(id)arg1;	// IMP=0x0000000100154fd4
- (id)baseDictEncryptionKey;	// IMP=0x0000000100154ea4
- (id)baseDictWrappingKey;	// IMP=0x0000000100154d74
- (id)baseDict;	// IMP=0x0000000100154cf8
- (_Bool)saveDecryptionKeyDataRepresentation:(id)arg1 forDeviceIdentifier:(id)arg2;	// IMP=0x0000000100154c74
- (id)loadDecryptionKeyDataRepresentationForDeviceIdentifier:(id)arg1;	// IMP=0x0000000100154c14
- (_Bool)saveEncryptionKeyDataRepresentation:(id)arg1;	// IMP=0x0000000100154b94
- (id)loadEncryptionKeyDataRepresentation;	// IMP=0x0000000100154b34
- (_Bool)saveKeyDataRepresentation:(id)arg1 withBaseDict:(id)arg2;	// IMP=0x0000000100154834
- (id)loadKeyDataRepresentationWithBaseDict:(id)arg1;	// IMP=0x00000001001546fc
- (void)testWrappingKeychainItem;	// IMP=0x00000001001546f8
- (id)loadWrappingKeyData;	// IMP=0x0000000100154578
- (id)allKeys;	// IMP=0x00000001001540a0
- (_Bool)deleteAllEncryptionAndDecryptionKeys;	// IMP=0x0000000100153e94
- (id)newDecryptionKeyFromDataRepresentation:(id)arg1;	// IMP=0x0000000100153a1c
- (id)unwrappedDataRepresentationForKey:(id)arg1;	// IMP=0x0000000100153890
@property(readonly, nonatomic) NSData *dataRepresentationForCurrentEncryptionKey;
- (id)cachedDecryptionKeyForDeviceIdentifier:(id)arg1;	// IMP=0x0000000100153428
- (id)decryptionKeyForDeviceIdentifier:(id)arg1;	// IMP=0x00000001001532c4
- (void)setDecryptionKey:(id)arg1 forDeviceIdentifier:(id)arg2;	// IMP=0x0000000100153020
- (void)getTagAndCounterWhileEncryptingBytesInPlace:(unsigned char [10])arg1 forAdvertisementWithVersion:(unsigned char)arg2 handler:(CDUnknownBlockType)arg3;	// IMP=0x0000000100152c98
@property(readonly, nonatomic) SDActivityEncryptionKey *encryptionKey;
- (void)generateNewEncryptionKey;	// IMP=0x0000000100152824
- (void)resetStateRequested:(id)arg1;	// IMP=0x0000000100152818
- (void)removeObservers;	// IMP=0x00000001001527c8
- (void)addObservers;	// IMP=0x0000000100152760
@property(readonly) NSString *state;
- (void)dealloc;	// IMP=0x00000001001524a8
- (id)init;	// IMP=0x0000000100152414

@end
