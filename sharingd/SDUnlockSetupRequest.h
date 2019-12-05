//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <ProtocolBuffer/PBRequest.h>

#import "NSCopying-Protocol.h"

@class NSData;

@interface SDUnlockSetupRequest : PBRequest <NSCopying>
{
    NSData *_longTermKey;	// 8 = 0x8
    NSData *_ltkHash;	// 16 = 0x10
    unsigned int _sessionID;	// 24 = 0x18
    unsigned int _version;	// 28 = 0x1c
    _Bool _remoteNeedsLTK;	// 32 = 0x20
    struct {
        unsigned int sessionID:1;
        unsigned int version:1;
        unsigned int remoteNeedsLTK:1;
    } _has;	// 36 = 0x24
}

@property(nonatomic) _Bool remoteNeedsLTK; // @synthesize remoteNeedsLTK=_remoteNeedsLTK;
@property(retain, nonatomic) NSData *ltkHash; // @synthesize ltkHash=_ltkHash;
@property(retain, nonatomic) NSData *longTermKey; // @synthesize longTermKey=_longTermKey;
@property(nonatomic) unsigned int sessionID; // @synthesize sessionID=_sessionID;
@property(nonatomic) unsigned int version; // @synthesize version=_version;
- (void).cxx_destruct;	// IMP=0x0000000100095f5c
- (void)mergeFrom:(id)arg1;	// IMP=0x0000000100095dfc
- (unsigned long long)hash;	// IMP=0x0000000100095d0c
- (_Bool)isEqual:(id)arg1;	// IMP=0x0000000100095b98
- (id)copyWithZone:(struct _NSZone *)arg1;	// IMP=0x0000000100095a6c
- (void)copyTo:(id)arg1;	// IMP=0x0000000100095984
- (void)writeTo:(id)arg1;	// IMP=0x00000001000958b0
- (_Bool)readFrom:(id)arg1;	// IMP=0x00000001000958a8
- (id)dictionaryRepresentation;	// IMP=0x00000001000952f0
- (id)description;	// IMP=0x000000010009523c
@property(nonatomic) _Bool hasRemoteNeedsLTK;
@property(readonly, nonatomic) _Bool hasLtkHash;
@property(readonly, nonatomic) _Bool hasLongTermKey;
@property(nonatomic) _Bool hasSessionID;
@property(nonatomic) _Bool hasVersion;

@end
