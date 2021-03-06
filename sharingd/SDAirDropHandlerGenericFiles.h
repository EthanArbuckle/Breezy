//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "SDAirDropHandler.h"

@class LSBundleProxy, NSArray, NSOperationQueue, SDAirDropHandleriCloudDrive;

__attribute__((visibility("hidden")))
@interface SDAirDropHandlerGenericFiles : SDAirDropHandler
{
    NSOperationQueue *_workOperationsQueue;	// 8 = 0x8
    SDAirDropHandleriCloudDrive *_icloudDriveHandler;	// 16 = 0x10
    SDAirDropHandler *_selectedHandler;	// 24 = 0x18
    LSBundleProxy *_selectedProxy;	// 32 = 0x20
    NSArray *_availableApplications;	// 40 = 0x28
    LSBundleProxy *_selectedApplication;	// 48 = 0x30
}

@property(retain, nonatomic) LSBundleProxy *selectedApplication; // @synthesize selectedApplication=_selectedApplication;
@property(copy, nonatomic) NSArray *availableApplications; // @synthesize availableApplications=_availableApplications;
- (void).cxx_destruct;	// IMP=0x0000000100090da4
- (id)cancelActionTitleToAccompanyActions:(id)arg1;	// IMP=0x0000000100090cd4
- (void)updatePossibleActions;	// IMP=0x0000000100090a40
- (id)suitableContentsDescription;	// IMP=0x0000000100090894
- (long long)transferTypes;	// IMP=0x000000010009085c
- (_Bool)canHandleTransfer;	// IMP=0x0000000100090784
- (id)initWithTransfer:(id)arg1 bundleIdentifier:(id)arg2;	// IMP=0x0000000100090688
- (id)initWithTransfer:(id)arg1;	// IMP=0x0000000100090678

@end

