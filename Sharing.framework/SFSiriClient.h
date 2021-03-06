/*
* This header is generated by classdump-dyld 1.0
* on Saturday, August 24, 2019 at 9:47:04 PM Mountain Standard Time
* Operating System: Version 12.4 (Build 16M568)
* Image Source: /System/Library/PrivateFrameworks/Sharing.framework/Sharing
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <Sharing/Sharing-Structs.h>
#import <libobjc.A.dylib/VSSpeechSynthesizerDelegate.h>

@protocol OS_dispatch_source, OS_dispatch_queue;
@class SFSiriRequest, NSObject, NSString, VSSpeechSynthesizer;

@interface SFSiriClient : NSObject <VSSpeechSynthesizerDelegate> {

	BOOL _invalidateCalled;
	unsigned _invalidateFlags;
	SFSiriRequest* _currentRequest;
	NSObject*<OS_dispatch_source> _currentTimer;
	NSString* _languageCode;
	NSMutableArray* _requests;
	VSSpeechSynthesizer* _speechSynthesizer;
	NSObject*<OS_dispatch_queue> _dispatchQueue;
	/*^block*/id _invalidationHandler;
	/*^block*/id _siriDialogHandler;

}

@property (nonatomic,retain) NSObject*<OS_dispatch_queue> dispatchQueue;              //@synthesize dispatchQueue=_dispatchQueue - In the implementation block
@property (nonatomic,copy) id invalidationHandler;                                    //@synthesize invalidationHandler=_invalidationHandler - In the implementation block
@property (nonatomic,copy) id siriDialogHandler;                                      //@synthesize siriDialogHandler=_siriDialogHandler - In the implementation block
@property (readonly) unsigned long long hash; 
@property (readonly) Class superclass; 
@property (copy,readonly) NSString * description; 
@property (copy,readonly) NSString * debugDescription; 
-(void)_activate;
-(void)invalidateWithFlags:(unsigned)arg1 ;
-(void)setSiriDialogHandler:(id)arg1 ;
-(void)deviceSetupEnd;
-(void)stopSpeaking;
-(void)speakPasscode:(id)arg1 instructions:(id)arg2 languageCode:(id)arg3 flags:(unsigned)arg4 completion:(/*^block*/id)arg5 ;
-(void)deviceSetupPlayGreetingID:(int)arg1 completion:(/*^block*/id)arg2 ;
-(void)deviceSetupBegin:(unsigned long long)arg1 ;
-(void)deviceSetupPrepareGreeting:(/*^block*/id)arg1 ;
-(void)speakText:(id)arg1 flags:(unsigned)arg2 rate:(double)arg3 delay:(double)arg4 startHandler:(/*^block*/id)arg5 completion:(/*^block*/id)arg6 ;
-(void)_completeRequest:(id)arg1 error:(id)arg2 ;
-(void)_completeAllRequestsWithError:(id)arg1 ;
-(void)_speakPasscode:(id)arg1 instructions:(id)arg2 languageCode:(id)arg3 flags:(unsigned)arg4 completion:(/*^block*/id)arg5 ;
-(void)_processQueuedRequests;
-(void)speakText:(id)arg1 rate:(double)arg2 completion:(/*^block*/id)arg3 ;
-(void)_speakText:(id)arg1 languageCode:(id)arg2 flags:(unsigned)arg3 rate:(double)arg4 delay:(double)arg5 startHandler:(/*^block*/id)arg6 completion:(/*^block*/id)arg7 ;
-(void)speechSynthesizer:(id)arg1 withRequest:(id)arg2 didReceiveTimingInfo2:(id)arg3 ;
-(void)speechSynthesizer:(id)arg1 didFinishSpeakingRequest:(id)arg2 successfully:(BOOL)arg3 withError2:(id)arg4 ;
-(void)speechSynthesizer:(id)arg1 didFinishSynthesisRequest:(id)arg2 withInstrumentMetrics:(id)arg3 error2:(id)arg4 ;
-(void)startDelayedRequest:(id)arg1 ;
-(void)speechSynthesizer:(id)arg1 didStartSpeakingRequest:(id)arg2 ;
-(void)speechSynthesizer:(id)arg1 withRequest:(id)arg2 didReceiveTimingInfo:(id)arg3 ;
-(void)speechSynthesizer:(id)arg1 didFinishSpeakingRequest:(id)arg2 successfully:(BOOL)arg3 phonemesSpoken:(id)arg4 withError:(id)arg5 ;
-(void)speechSynthesizer:(id)arg1 didFinishSynthesisRequest:(id)arg2 withInstrumentMetrics:(id)arg3 error:(id)arg4 ;
-(void)preWarmDeviceSetupWelcomePhaseWithCompletion:(/*^block*/id)arg1 ;
-(void)speakDeviceSetupWelcomePhaseWithCompletion:(/*^block*/id)arg1 ;
-(void)speakText:(id)arg1 completion:(/*^block*/id)arg2 ;
-(void)speakText:(id)arg1 languageCode:(id)arg2 completion:(/*^block*/id)arg3 ;
-(void)_deviceSetupEnd;
-(id)siriDialogHandler;
-(void)setDispatchQueue:(NSObject*<OS_dispatch_queue>)arg1 ;
-(NSObject*<OS_dispatch_queue>)dispatchQueue;
-(id)init;
-(void)invalidate;
-(void)_invalidate;
-(void)activate;
-(id)invalidationHandler;
-(void)setInvalidationHandler:(id)arg1 ;
@end

