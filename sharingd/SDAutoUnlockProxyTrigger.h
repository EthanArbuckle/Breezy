//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <ProtocolBuffer/PBCodable.h>

#import "NSCopying-Protocol.h"

@interface SDAutoUnlockProxyTrigger : PBCodable <NSCopying>
{
    unsigned int _version;	// 8 = 0x8
    CDStruct_f20694ce _has;	// 12 = 0xc
}

@property(nonatomic) unsigned int version; // @synthesize version=_version;
- (void)mergeFrom:(id)arg1;	// IMP=0x00000001000db89c
- (unsigned long long)hash;	// IMP=0x00000001000db860
- (_Bool)isEqual:(id)arg1;	// IMP=0x00000001000db7ac
- (id)copyWithZone:(struct _NSZone *)arg1;	// IMP=0x00000001000db738
- (void)copyTo:(id)arg1;	// IMP=0x00000001000db708
- (void)writeTo:(id)arg1;	// IMP=0x00000001000db6d8
- (_Bool)readFrom:(id)arg1;	// IMP=0x00000001000db6d0
- (id)dictionaryRepresentation;	// IMP=0x00000001000db3fc
- (id)description;	// IMP=0x00000001000db348
@property(nonatomic) _Bool hasVersion;

@end

