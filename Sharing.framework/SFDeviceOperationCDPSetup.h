/*
* This header is generated by classdump-dyld 1.0
* on Saturday, August 24, 2019 at 9:47:03 PM Mountain Standard Time
* Operating System: Version 12.4 (Build 16M568)
* Image Source: /System/Library/PrivateFrameworks/Sharing.framework/Sharing
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/


@protocol OS_dispatch_source, OS_dispatch_queue;
@class CDPContext, CDPStateController, NSObject, SFSession;

@interface SFDeviceOperationCDPSetup : NSObject {

	int _cdpApprovalServerState;
	CDPContext* _cdpContext;
	CDPStateController* _cdpController;
	int _cdpSetupRequestState;
	BOOL _invalidateCalled;
	unsigned long long _startTicks;
	NSObject*<OS_dispatch_source> _timeoutTimer;
	/*^block*/id _completionHandler;
	NSObject*<OS_dispatch_queue> _dispatchQueue;
	double _metricSeconds;
	id _presentingViewController;
	SFSession* _sfSession;

}

@property (nonatomic,copy) id completionHandler;                                      //@synthesize completionHandler=_completionHandler - In the implementation block
@property (nonatomic,retain) NSObject*<OS_dispatch_queue> dispatchQueue;              //@synthesize dispatchQueue=_dispatchQueue - In the implementation block
@property (nonatomic,readonly) double metricSeconds;                                  //@synthesize metricSeconds=_metricSeconds - In the implementation block
@property (nonatomic,retain) id presentingViewController;                             //@synthesize presentingViewController=_presentingViewController - In the implementation block
@property (nonatomic,retain) SFSession * sfSession;                                   //@synthesize sfSession=_sfSession - In the implementation block
-(void)setPresentingViewController:(id)arg1 ;
-(void)_activate;
-(void)_complete:(id)arg1 ;
-(int)_runCDPApprovalServerStart;
-(int)_runCDPSetupRequest;
-(double)metricSeconds;
-(SFSession *)sfSession;
-(void)setSfSession:(SFSession *)arg1 ;
-(void)setDispatchQueue:(NSObject*<OS_dispatch_queue>)arg1 ;
-(NSObject*<OS_dispatch_queue>)dispatchQueue;
-(id)init;
-(id)presentingViewController;
-(void)invalidate;
-(id)completionHandler;
-(void)activate;
-(void)setCompletionHandler:(id)arg1 ;
-(void)_run;
@end

