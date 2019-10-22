/*
* This header is generated by classdump-dyld 1.0
* on Saturday, August 24, 2019 at 9:49:31 PM Mountain Standard Time
* Operating System: Version 12.4 (Build 16M568)
* Image Source: /System/Library/Frameworks/CoreServices.framework/CoreServices
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/


@protocol OS_dispatch_queue, OS_dispatch_source;
@class NSObject, NSMutableDictionary, NSMutableSet;

@interface _LSQueryCache : NSObject {

	NSObject*<OS_dispatch_queue> _queue;
	NSMutableDictionary* _cache;
	NSMutableSet* _uniqueObjects;
	int _databaseChangeToken;
	NSObject*<OS_dispatch_source> _memPressureSource;

}
+(id)sharedCache;
-(id)cachedQueryResultsForQueries:(id)arg1 ;
-(id)cacheAndUniquifyQueryResults:(id)arg1 ;
-(id)uniquifiedObjectNotDispatched:(id)arg1 localObjects:(id)arg2 ;
-(void)cacheLocalObjects:(id)arg1 ;
-(id)init;
-(void)dealloc;
-(void)clearCache;
@end

