/*
* This header is generated by classdump-dyld 1.0
* on Saturday, August 24, 2019 at 9:47:03 PM Mountain Standard Time
* Operating System: Version 12.4 (Build 16M568)
* Image Source: /System/Library/PrivateFrameworks/Sharing.framework/Sharing
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <Sharing/Sharing-Structs.h>
#import <libobjc.A.dylib/NSSecureCoding.h>

@class NSData, NSDictionary, NSUUID, NSString, SFProximityEstimator;

@interface SFBLEDevice : NSObject <NSSecureCoding> {

	char _rssiHistory[8];
	unsigned char _rssiCount;
	unsigned char _rssiIndex;
	BOOL _insideBubble;
	BOOL _paired;
	BOOL _triggered;
	int _rssiEstimate;
	unsigned _connectedServices;
	unsigned _productID2;
	NSData* _advertisementData;
	NSDictionary* _advertisementFields;
	NSData* _bluetoothAddress;
	NSUUID* _counterpartIdentifier;
	long long _distance;
	unsigned long long _foundTicks;
	NSUUID* _identifier;
	NSString* _name;
	long long _rssi;
	long long _rssiCeiling;
	long long _rssiFloor;
	long long _smoothedRSSI;
	SFProximityEstimator* _infoProximityEstimator;
	double _lastSeen;
	double _pairCheckTime;
	SFProximityEstimator* _proxPairProximityEstimator;
	SFProximityEstimator* _setupProximityEstimator;

}

@property (nonatomic,copy) NSData * advertisementData;                                       //@synthesize advertisementData=_advertisementData - In the implementation block
@property (nonatomic,copy) NSDictionary * advertisementFields;                               //@synthesize advertisementFields=_advertisementFields - In the implementation block
@property (nonatomic,copy) NSData * bluetoothAddress;                                        //@synthesize bluetoothAddress=_bluetoothAddress - In the implementation block
@property (assign,nonatomic) unsigned connectedServices;                                     //@synthesize connectedServices=_connectedServices - In the implementation block
@property (nonatomic,copy) NSUUID * counterpartIdentifier;                                   //@synthesize counterpartIdentifier=_counterpartIdentifier - In the implementation block
@property (assign,nonatomic) long long distance;                                             //@synthesize distance=_distance - In the implementation block
@property (assign,nonatomic) unsigned long long foundTicks;                                  //@synthesize foundTicks=_foundTicks - In the implementation block
@property (nonatomic,copy) NSUUID * identifier;                                              //@synthesize identifier=_identifier - In the implementation block
@property (nonatomic,retain) SFProximityEstimator * infoProximityEstimator;                  //@synthesize infoProximityEstimator=_infoProximityEstimator - In the implementation block
@property (assign,nonatomic) BOOL insideBubble;                                              //@synthesize insideBubble=_insideBubble - In the implementation block
@property (nonatomic,copy) NSString * name;                                                  //@synthesize name=_name - In the implementation block
@property (assign,nonatomic) double lastSeen;                                                //@synthesize lastSeen=_lastSeen - In the implementation block
@property (assign,nonatomic) double pairCheckTime;                                           //@synthesize pairCheckTime=_pairCheckTime - In the implementation block
@property (assign,nonatomic) BOOL paired;                                                    //@synthesize paired=_paired - In the implementation block
@property (assign,nonatomic) unsigned productID2;                                            //@synthesize productID2=_productID2 - In the implementation block
@property (nonatomic,retain) SFProximityEstimator * proxPairProximityEstimator;              //@synthesize proxPairProximityEstimator=_proxPairProximityEstimator - In the implementation block
@property (nonatomic,retain) SFProximityEstimator * setupProximityEstimator;                 //@synthesize setupProximityEstimator=_setupProximityEstimator - In the implementation block
@property (assign,nonatomic) long long rssi;                                                 //@synthesize rssi=_rssi - In the implementation block
@property (assign,nonatomic) long long rssiCeiling;                                          //@synthesize rssiCeiling=_rssiCeiling - In the implementation block
@property (assign,nonatomic) int rssiEstimate;                                               //@synthesize rssiEstimate=_rssiEstimate - In the implementation block
@property (assign,nonatomic) long long rssiFloor;                                            //@synthesize rssiFloor=_rssiFloor - In the implementation block
@property (assign,nonatomic) long long smoothedRSSI;                                         //@synthesize smoothedRSSI=_smoothedRSSI - In the implementation block
@property (assign,nonatomic) BOOL triggered;                                                 //@synthesize triggered=_triggered - In the implementation block
+(void)setRSSIEstimatorInfo:(id)arg1 ;
+(BOOL)supportsSecureCoding;
-(void)setRssi:(long long)arg1 ;
-(long long)rssi;
-(void)setDistance:(long long)arg1 ;
-(long long)distance;
-(void)setTriggered:(BOOL)arg1 ;
-(BOOL)triggered;
-(void)setPaired:(BOOL)arg1 ;
-(NSData *)bluetoothAddress;
-(void)setBluetoothAddress:(NSData *)arg1 ;
-(double)lastSeen;
-(void)setLastSeen:(double)arg1 ;
-(unsigned)connectedServices;
-(NSData *)advertisementData;
-(BOOL)updateRSSI:(long long)arg1 ;
-(void)setAdvertisementData:(NSData *)arg1 ;
-(NSDictionary *)advertisementFields;
-(void)setAdvertisementFields:(NSDictionary *)arg1 ;
-(NSUUID *)counterpartIdentifier;
-(void)setCounterpartIdentifier:(NSUUID *)arg1 ;
-(unsigned long long)foundTicks;
-(void)setFoundTicks:(unsigned long long)arg1 ;
-(BOOL)insideBubble;
-(void)setInsideBubble:(BOOL)arg1 ;
-(int)rssiEstimate;
-(void)setRssiEstimate:(int)arg1 ;
-(long long)rssiCeiling;
-(void)setRssiCeiling:(long long)arg1 ;
-(long long)rssiFloor;
-(void)setRssiFloor:(long long)arg1 ;
-(long long)smoothedRSSI;
-(void)setSmoothedRSSI:(long long)arg1 ;
-(void)setConnectedServices:(unsigned)arg1 ;
-(SFProximityEstimator *)infoProximityEstimator;
-(void)setInfoProximityEstimator:(SFProximityEstimator *)arg1 ;
-(double)pairCheckTime;
-(void)setPairCheckTime:(double)arg1 ;
-(unsigned)productID2;
-(void)setProductID2:(unsigned)arg1 ;
-(SFProximityEstimator *)proxPairProximityEstimator;
-(void)setProxPairProximityEstimator:(SFProximityEstimator *)arg1 ;
-(SFProximityEstimator *)setupProximityEstimator;
-(void)setSetupProximityEstimator:(SFProximityEstimator *)arg1 ;
-(BOOL)paired;
-(NSUUID *)identifier;
-(void)encodeWithCoder:(id)arg1 ;
-(id)initWithCoder:(id)arg1 ;
-(NSString *)name;
-(void)setName:(NSString *)arg1 ;
-(id)description;
-(id)copyWithZone:(NSZone*)arg1 ;
-(void)setIdentifier:(NSUUID *)arg1 ;
@end

