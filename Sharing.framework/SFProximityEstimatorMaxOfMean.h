/*
* This header is generated by classdump-dyld 1.0
* on Saturday, August 24, 2019 at 9:47:04 PM Mountain Standard Time
* Operating System: Version 12.4 (Build 16M568)
* Image Source: /System/Library/PrivateFrameworks/Sharing.framework/Sharing
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <Sharing/SFProximityEstimator.h>

@interface SFProximityEstimatorMaxOfMean : SFProximityEstimator {

	char* _channelNumberArray;
	char* _rssiArray;
	unsigned _rssiCount;
	unsigned _rssiIndex;
	unsigned _rssiMinCount;

}
-(id)initWithProximityInfo:(id)arg1 ;
-(int)_estimateRSSIForSFBLEDevice:(id)arg1 ;
-(void)dealloc;
@end
