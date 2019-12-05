//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <ProtocolBuffer/PBCodable.h>

#import "NSCopying-Protocol.h"

@class NSData;

@interface SDUnlockSessionAuthToken : PBCodable <NSCopying>
{
    NSData *_authToken;	// 8 = 0x8
    unsigned int _errorCode;	// 16 = 0x10
    unsigned int _sessionID;	// 20 = 0x14
    unsigned int _version;	// 24 = 0x18
    CDStruct_e173124d _has;	// 28 = 0x1c
}

@property(nonatomic) unsigned int errorCode; // @synthesize errorCode=_errorCode;
@property(retain, nonatomic) NSData *authToken; // @synthesize authToken=_authToken;
@property(nonatomic) unsigned int sessionID; // @synthesize sessionID=_sessionID;
@property(nonatomic) unsigned int version; // @synthesize version=_version;
- (void).cxx_destruct;	// IMP=0x00000001000f6194
- (void)mergeFrom:(id)arg1;	// IMP=0x00000001000f6078
- (unsigned long long)hash;	// IMP=0x00000001000f5fac
- (_Bool)isEqual:(id)arg1;	// IMP=0x00000001000f5e70
- (id)copyWithZone:(struct _NSZone *)arg1;	// IMP=0x00000001000f5d70
- (void)copyTo:(id)arg1;	// IMP=0x00000001000f5ca8
- (void)writeTo:(id)arg1;	// IMP=0x00000001000f5bf0
- (_Bool)readFrom:(id)arg1;	// IMP=0x00000001000f5be8
- (id)dictionaryRepresentation;	// IMP=0x00000001000f5684
- (id)description;	// IMP=0x00000001000f55d0
@property(nonatomic) _Bool hasErrorCode;
@property(readonly, nonatomic) _Bool hasAuthToken;
@property(nonatomic) _Bool hasSessionID;
@property(nonatomic) _Bool hasVersion;

@end
