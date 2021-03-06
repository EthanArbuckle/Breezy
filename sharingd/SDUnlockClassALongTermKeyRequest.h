//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <ProtocolBuffer/PBRequest.h>

#import "NSCopying-Protocol.h"

@class NSData;

@interface SDUnlockClassALongTermKeyRequest : PBRequest <NSCopying>
{
    NSData *_longTermKey;	// 8 = 0x8
    unsigned int _sessionID;	// 16 = 0x10
    unsigned int _version;	// 20 = 0x14
    CDStruct_6358cc24 _has;	// 24 = 0x18
}

@property(retain, nonatomic) NSData *longTermKey; // @synthesize longTermKey=_longTermKey;
@property(nonatomic) unsigned int sessionID; // @synthesize sessionID=_sessionID;
@property(nonatomic) unsigned int version; // @synthesize version=_version;
- (void).cxx_destruct;	// IMP=0x000000010016bef0
- (void)mergeFrom:(id)arg1;	// IMP=0x000000010016be10
- (unsigned long long)hash;	// IMP=0x000000010016bd7c
- (_Bool)isEqual:(id)arg1;	// IMP=0x000000010016bc74
- (id)copyWithZone:(struct _NSZone *)arg1;	// IMP=0x000000010016bba0
- (void)copyTo:(id)arg1;	// IMP=0x000000010016bb04
- (void)writeTo:(id)arg1;	// IMP=0x000000010016ba6c
- (_Bool)readFrom:(id)arg1;	// IMP=0x000000010016ba64
- (id)dictionaryRepresentation;	// IMP=0x000000010016b620
- (id)description;	// IMP=0x000000010016b56c
@property(readonly, nonatomic) _Bool hasLongTermKey;
@property(nonatomic) _Bool hasSessionID;
@property(nonatomic) _Bool hasVersion;

@end

