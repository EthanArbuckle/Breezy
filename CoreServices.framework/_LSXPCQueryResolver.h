/*
* This header is generated by classdump-dyld 1.0
* on Saturday, August 24, 2019 at 9:49:31 PM Mountain Standard Time
* Operating System: Version 12.4 (Build 16M568)
* Image Source: /System/Library/Frameworks/CoreServices.framework/CoreServices
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <libobjc.A.dylib/_LSQueryResolving.h>

@class _LSQueryCache, _LSLocalQueryResolver, NSString;

@interface _LSXPCQueryResolver : NSObject <_LSQueryResolving> {

	_LSQueryCache* _queryCache;
	_LSLocalQueryResolver* _localResolver;

}

@property (readonly) unsigned long long hash; 
@property (readonly) Class superclass; 
@property (copy,readonly) NSString * description; 
@property (copy,readonly) NSString * debugDescription; 
-(id)_queryCache;
-(void)_enumerateResolvedResultsOfQuery:(id)arg1 XPCConnection:(id)arg2 withBlock:(/*^block*/id)arg3 ;
-(id)_resolveQueries:(id)arg1 XPCConnection:(id)arg2 error:(id*)arg3 ;
-(id)resolveWhatWeCanLocallyWithQueries:(id)arg1 XPCConnection:(id)arg2 error:(id*)arg3 ;
-(id)init;
-(void)dealloc;
@end

