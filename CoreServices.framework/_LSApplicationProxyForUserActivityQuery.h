/*
* This header is generated by classdump-dyld 1.0
* on Saturday, August 24, 2019 at 9:49:32 PM Mountain Standard Time
* Operating System: Version 12.4 (Build 16M568)
* Image Source: /System/Library/Frameworks/CoreServices.framework/CoreServices
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <CoreServices/_LSBundleQuery.h>

@class NSString;

@interface _LSApplicationProxyForUserActivityQuery : _LSBundleQuery {

	NSString* _domainName;
	NSString* _activityType;

}

@property (nonatomic,copy,readonly) NSString * domainName;                //@synthesize domainName=_domainName - In the implementation block
@property (nonatomic,copy,readonly) NSString * activityType;              //@synthesize activityType=_activityType - In the implementation block
+(id)queryWithActivityType:(id)arg1 ;
+(id)queryWithDomainName:(id)arg1 ;
+(BOOL)supportsSecureCoding;
-(NSString *)domainName;
-(void)_enumerateWithXPCConnection:(id)arg1 block:(/*^block*/id)arg2 ;
-(BOOL)_requiresDatabaseMappingEntitlement;
-(void)dealloc;
-(BOOL)isEqual:(id)arg1 ;
-(void)encodeWithCoder:(id)arg1 ;
-(id)initWithCoder:(id)arg1 ;
-(unsigned long long)hash;
-(NSString *)activityType;
@end

