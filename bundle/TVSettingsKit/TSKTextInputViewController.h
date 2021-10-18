/*
* This header is generated by classdump-dyld 1.0
* on Sunday, July 22, 2018 at 11:13:55 PM Mountain Standard Time
* Operating System: Version 11.3 (Build 15L211)
* Image Source: /System/Library/PrivateFrameworks/TVSettingKit.framework/TVSettingKit
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <UIKit/UIViewController.h>
#import "TVSUITextEntryControllerDelegate.h"
#import "TSKSettingItemEditingController.h"

@protocol TSKSettingItemEditingControllerDelegate;
@class TVSUITextEntryHeaderView, SFPasswordSharingService, TVSUITextEntryController, TSKSettingItem, NSString;

@interface TSKTextInputViewController : UIViewController <TVSUITextEntryControllerDelegate, TSKSettingItemEditingController> {

	TVSUITextEntryHeaderView* _headerView;
	SFPasswordSharingService* _passwordSharingService;
	TVSUITextEntryController* _textEntryController;
	BOOL _secureTextEntry;
	BOOL _allowsEmptyInput;
	BOOL _supportsPasswordSharing;
	TSKSettingItem* _editingItem;
	id<TSKSettingItemEditingControllerDelegate> _editingDelegate;
	NSString* _headerText;
	NSString* _messageText;
	NSString* _initialText;
	NSString* _recentsCategory;
	long long _capitalizationType;
	long long _keyboardType;
	NSString* _networkName;

}

@property (assign,nonatomic) BOOL supportsPasswordSharing;                                                    //@synthesize supportsPasswordSharing=_supportsPasswordSharing - In the implementation block
@property (nonatomic,retain) NSString * networkName;                                                          //@synthesize networkName=_networkName - In the implementation block
@property (assign,nonatomic) BOOL secureTextEntry;                                                            //@synthesize secureTextEntry=_secureTextEntry - In the implementation block
@property (nonatomic,copy) NSString * headerText;                                                             //@synthesize headerText=_headerText - In the implementation block
@property (nonatomic,copy) NSString * messageText;                                                            //@synthesize messageText=_messageText - In the implementation block
@property (nonatomic,copy) NSString * initialText;                                                            //@synthesize initialText=_initialText - In the implementation block
@property (nonatomic,copy) NSString * recentsCategory;                                                        //@synthesize recentsCategory=_recentsCategory - In the implementation block
@property (assign,nonatomic) long long capitalizationType;                                                    //@synthesize capitalizationType=_capitalizationType - In the implementation block
@property (assign,nonatomic) long long keyboardType;                                                          //@synthesize keyboardType=_keyboardType - In the implementation block
@property (assign,nonatomic) BOOL allowsEmptyInput;                                                           //@synthesize allowsEmptyInput=_allowsEmptyInput - In the implementation block
 
@property (readonly) Class superclass; 
@property (copy,readonly) NSString * description; 
@property (copy,readonly) NSString * debugDescription; 
@property (nonatomic,retain) TSKSettingItem * editingItem;                                                    //@synthesize editingItem=_editingItem - In the implementation block
@property (weak,nonatomic) id<TSKSettingItemEditingControllerDelegate> editingDelegate;              //@synthesize editingDelegate=_editingDelegate - In the implementation block
-(void)dealloc;
-(void)traitCollectionDidChange:(id)arg1 ;
-(NSString *)messageText;
-(void)setMessageText:(NSString *)arg1 ;
-(id)initWithNibName:(id)arg1 bundle:(id)arg2 ;
-(id)preferredFocusEnvironments;
-(long long)keyboardType;
-(void)setKeyboardType:(long long)arg1 ;
-(void)setSecureTextEntry:(BOOL)arg1 ;
-(void)viewDidLoad;
-(void)viewWillDisappear:(BOOL)arg1 ;
-(void)setEditingDelegate:(id<TSKSettingItemEditingControllerDelegate>)arg1 ;
-(id<TSKSettingItemEditingControllerDelegate>)editingDelegate;
-(BOOL)secureTextEntry;
-(NSString *)headerText;
-(void)setHeaderText:(NSString *)arg1 ;
-(NSString *)networkName;
-(void)setNetworkName:(NSString *)arg1 ;
-(void)_applicationDidEnterBackgroundNotification:(id)arg1 ;
-(void)_applicationWillEnterForegroundNotification:(id)arg1 ;
-(void)_textFieldTextDidChange:(id)arg1 ;
-(void)service:(id)arg1 receivedNetworkInfo:(id)arg2 ;
-(void)_configureTextField;
-(void)textEntryControllerDidFinish:(id)arg1 ;
-(id)_titleStringAttributes;
-(id)_messageStringAttributes;
-(TSKSettingItem *)editingItem;
-(void)setEditingItem:(TSKSettingItem *)arg1 ;
-(NSString *)recentsCategory;
-(void)setRecentsCategory:(NSString *)arg1 ;
-(void)_configureTitleView;
-(void)_donePressed:(id)arg1 ;
-(void)_menuPressed;
-(BOOL)supportsPasswordSharing;
-(void)_passwordSharingEnsureStarted;
-(void)_passwordSharingEnsureStopped;
-(void)_configureSubmitButton;
-(NSString *)initialText;
-(BOOL)service:(id)arg1 shouldPromptForNetwork:(id)arg2 ;
-(void)setInitialText:(NSString *)arg1 ;
-(void)setCapitalizationType:(long long)arg1 ;
-(long long)capitalizationType;
-(BOOL)allowsEmptyInput;
-(void)setAllowsEmptyInput:(BOOL)arg1 ;
-(void)setSupportsPasswordSharing:(BOOL)arg1 ;
@end

