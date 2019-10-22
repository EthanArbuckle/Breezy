/*
* This header is generated by classdump-dyld 1.0
* on Saturday, August 24, 2019 at 9:49:32 PM Mountain Standard Time
* Operating System: Version 12.4 (Build 16M568)
* Image Source: /System/Library/Frameworks/CoreServices.framework/CoreServices
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <CoreServices/CoreServices-Structs.h>
#import <libobjc.A.dylib/NSCopying.h>

@class NSString, NSDictionary, NSXPCConnection;

@interface _LSSpringBoardCall : NSObject <NSCopying> {

	NSString* _schemeIfNotFileURL;
	BOOL _callCompletionHandlerWhenFullyComplete;
	NSDictionary* _launchOptions;
	NSString* _applicationIdentifier;
	NSXPCConnection* _clientXPCConnection;

}

@property (copy) NSString * applicationIdentifier;                           //@synthesize applicationIdentifier=_applicationIdentifier - In the implementation block
@property (copy) NSDictionary * launchOptions;                               //@synthesize launchOptions=_launchOptions - In the implementation block
@property (retain) NSXPCConnection * clientXPCConnection;                    //@synthesize clientXPCConnection=_clientXPCConnection - In the implementation block
@property (assign) BOOL callCompletionHandlerWhenFullyComplete;              //@synthesize callCompletionHandlerWhenFullyComplete=_callCompletionHandlerWhenFullyComplete - In the implementation block
+(id)springBoardQueue;
-(NSDictionary *)launchOptions;
-(void)setClientXPCConnection:(NSXPCConnection *)arg1 ;
-(void)setCallCompletionHandlerWhenFullyComplete:(BOOL)arg1 ;
-(void)callWithCompletionHandler:(/*^block*/id)arg1 ;
-(NSXPCConnection *)clientXPCConnection;
-(void)callSpringBoardWithCompletionHandler:(/*^block*/id)arg1 ;
-(void)promptAndCallSpringBoardWithCompletionHandler:(/*^block*/id)arg1 ;
-(BOOL)callCompletionHandlerWhenFullyComplete;
-(void)lieWithCompletionHandler:(/*^block*/id)arg1 ;
-(void)dealloc;
-(id)debugDescription;
-(id)copyWithZone:(NSZone*)arg1 ;
-(void)setApplicationIdentifier:(NSString *)arg1 ;
-(NSString *)applicationIdentifier;
-(void)setLaunchOptions:(NSDictionary *)arg1 ;
@end

