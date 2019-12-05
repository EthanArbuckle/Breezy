/*
* This header is generated by classdump-dyld 1.0
* on Saturday, August 24, 2019 at 9:47:02 PM Mountain Standard Time
* Operating System: Version 12.4 (Build 16M568)
* Image Source: /System/Library/PrivateFrameworks/Sharing.framework/Sharing
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <libobjc.A.dylib/NSSecureCoding.h>

@class NSString;

@interface SFAirDropTransferItem : NSObject <NSSecureCoding> {

	BOOL _isFile;
	NSString* _type;
	long long _count;

}

@property (nonatomic,copy,readonly) NSString * type;              //@synthesize type=_type - In the implementation block
@property (nonatomic,readonly) long long count;                   //@synthesize count=_count - In the implementation block
@property (nonatomic,readonly) BOOL isFile;                       //@synthesize isFile=_isFile - In the implementation block
+(BOOL)supportsSecureCoding;
-(void)incrementCount;
-(BOOL)isFile;
-(id)initWithType:(id)arg1 isFile:(BOOL)arg2 ;
-(id)init;
-(BOOL)isEqual:(id)arg1 ;
-(long long)count;
-(void)encodeWithCoder:(id)arg1 ;
-(id)initWithCoder:(id)arg1 ;
-(unsigned long long)hash;
-(id)description;
-(NSString *)type;
@end
