//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <ProtocolBuffer/PBCodable.h>

#import "NSCopying-Protocol.h"

@class NSString;

@interface AWDSharingProximityPairingTriggered : PBCodable <NSCopying>
{
    unsigned long long _timestamp;	// 8 = 0x8
    int _deviceRole;	// 16 = 0x10
    int _deviceSide;	// 20 = 0x14
    NSString *_model;	// 24 = 0x18
    int _primaryLocation;	// 32 = 0x20
    int _rssi;	// 36 = 0x24
    int _secondaryLocation;	// 40 = 0x28
    NSString *_sessionUUID;	// 48 = 0x30
    int _smoothedRSSI;	// 56 = 0x38
    _Bool _outOfBoxMode;	// 60 = 0x3c
    struct {
        unsigned int timestamp:1;
        unsigned int deviceRole:1;
        unsigned int deviceSide:1;
        unsigned int primaryLocation:1;
        unsigned int rssi:1;
        unsigned int secondaryLocation:1;
        unsigned int smoothedRSSI:1;
        unsigned int outOfBoxMode:1;
    } _has;	// 64 = 0x40
}

@property(nonatomic) _Bool outOfBoxMode; // @synthesize outOfBoxMode=_outOfBoxMode;
@property(nonatomic) int deviceRole; // @synthesize deviceRole=_deviceRole;
@property(nonatomic) int deviceSide; // @synthesize deviceSide=_deviceSide;
@property(nonatomic) int secondaryLocation; // @synthesize secondaryLocation=_secondaryLocation;
@property(nonatomic) int primaryLocation; // @synthesize primaryLocation=_primaryLocation;
@property(retain, nonatomic) NSString *model; // @synthesize model=_model;
@property(nonatomic) int smoothedRSSI; // @synthesize smoothedRSSI=_smoothedRSSI;
@property(nonatomic) int rssi; // @synthesize rssi=_rssi;
@property(retain, nonatomic) NSString *sessionUUID; // @synthesize sessionUUID=_sessionUUID;
@property(nonatomic) unsigned long long timestamp; // @synthesize timestamp=_timestamp;
- (void).cxx_destruct;	// IMP=0x0000000100085338
- (void)mergeFrom:(id)arg1;	// IMP=0x00000001000850c0
- (unsigned long long)hash;	// IMP=0x0000000100084f04
- (_Bool)isEqual:(id)arg1;	// IMP=0x0000000100084cb4
- (id)copyWithZone:(struct _NSZone *)arg1;	// IMP=0x0000000100084ac0
- (void)copyTo:(id)arg1;	// IMP=0x0000000100084910
- (void)writeTo:(id)arg1;	// IMP=0x0000000100084788
- (_Bool)readFrom:(id)arg1;	// IMP=0x0000000100084780
- (id)dictionaryRepresentation;	// IMP=0x0000000100083c84
- (id)description;	// IMP=0x0000000100083bd0
@property(nonatomic) _Bool hasOutOfBoxMode;
@property(nonatomic) _Bool hasDeviceRole;
@property(nonatomic) _Bool hasDeviceSide;
@property(nonatomic) _Bool hasSecondaryLocation;
@property(nonatomic) _Bool hasPrimaryLocation;
@property(readonly, nonatomic) _Bool hasModel;
@property(nonatomic) _Bool hasSmoothedRSSI;
@property(nonatomic) _Bool hasRssi;
@property(readonly, nonatomic) _Bool hasSessionUUID;
@property(nonatomic) _Bool hasTimestamp;

@end
