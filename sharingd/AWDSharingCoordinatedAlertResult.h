//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <ProtocolBuffer/PBCodable.h>

#import "NSCopying-Protocol.h"

@interface AWDSharingCoordinatedAlertResult : PBCodable <NSCopying>
{
    unsigned long long _timestamp;	// 8 = 0x8
    unsigned int _activityLevel;	// 16 = 0x10
    unsigned int _eventType;	// 20 = 0x14
    int _otherDevices;	// 24 = 0x18
    _Bool _bestIsMe;	// 28 = 0x1c
    _Bool _skipScanPhoneCall;	// 29 = 0x1d
    _Bool _skipScanVeryActive;	// 30 = 0x1e
    struct {
        unsigned int timestamp:1;
        unsigned int activityLevel:1;
        unsigned int eventType:1;
        unsigned int otherDevices:1;
        unsigned int bestIsMe:1;
        unsigned int skipScanPhoneCall:1;
        unsigned int skipScanVeryActive:1;
    } _has;	// 32 = 0x20
}

@property(nonatomic) _Bool skipScanVeryActive; // @synthesize skipScanVeryActive=_skipScanVeryActive;
@property(nonatomic) _Bool skipScanPhoneCall; // @synthesize skipScanPhoneCall=_skipScanPhoneCall;
@property(nonatomic) _Bool bestIsMe; // @synthesize bestIsMe=_bestIsMe;
@property(nonatomic) int otherDevices; // @synthesize otherDevices=_otherDevices;
@property(nonatomic) unsigned int activityLevel; // @synthesize activityLevel=_activityLevel;
@property(nonatomic) unsigned int eventType; // @synthesize eventType=_eventType;
@property(nonatomic) unsigned long long timestamp; // @synthesize timestamp=_timestamp;
- (void)mergeFrom:(id)arg1;	// IMP=0x00000001000dd20c
- (unsigned long long)hash;	// IMP=0x00000001000dd0e0
- (_Bool)isEqual:(id)arg1;	// IMP=0x00000001000dcf24
- (id)copyWithZone:(struct _NSZone *)arg1;	// IMP=0x00000001000dcdbc
- (void)copyTo:(id)arg1;	// IMP=0x00000001000dcc78
- (void)writeTo:(id)arg1;	// IMP=0x00000001000dcb40
- (_Bool)readFrom:(id)arg1;	// IMP=0x00000001000dcb38
- (id)dictionaryRepresentation;	// IMP=0x00000001000dc1c8
- (id)description;	// IMP=0x00000001000dc114
@property(nonatomic) _Bool hasSkipScanVeryActive;
@property(nonatomic) _Bool hasSkipScanPhoneCall;
@property(nonatomic) _Bool hasBestIsMe;
@property(nonatomic) _Bool hasOtherDevices;
@property(nonatomic) _Bool hasActivityLevel;
@property(nonatomic) _Bool hasEventType;
@property(nonatomic) _Bool hasTimestamp;

@end
