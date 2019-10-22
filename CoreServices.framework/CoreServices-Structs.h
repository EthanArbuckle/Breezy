/*
* This header is generated by classdump-dyld 1.0
* on Saturday, August 24, 2019 at 9:49:32 PM Mountain Standard Time
* Operating System: Version 12.4 (Build 16M568)
* Image Source: /System/Library/Frameworks/CoreServices.framework/CoreServices
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

typedef struct os_unfair_lock_s {
	unsigned _os_unfair_lock_opaque;
} os_unfair_lock_s;

typedef struct LSContext {
	LSDatabase db;
} LSContext;

typedef struct LSBundleData {
	unsigned _clas;
	unsigned long long _bundleFlags;
	unsigned _plistContentFlags;
	unsigned _itemFlags;
	unsigned char _iconFlags;
	unsigned char _highResFlags;
	unsigned char _appNapFlags;
	unsigned char eGPUFlags;
	unsigned short _archFlags;
	unsigned _hfsType;
	unsigned _hfsCreator;
	unsigned long long _inoBundle;
	unsigned long long _inoExec;
	int _mtime;
	int _rtime;
	unsigned long long _version;
	unsigned long long _minSystemVersion;
	unsigned long long _maxSystemVersion;
	unsigned long long _execSDKVersion;
	unsigned appStoreToolsBuildVersion;
	unsigned machOUUIDs[4];
	unsigned long long sequenceNumber;
	unsigned long long compatibilityState;
	unsigned long long installFailureReason;
	unsigned long long itemID;
	unsigned deviceFamilies;
	unsigned installType;
	unsigned teamID;
	unsigned identifier;
	unsigned exactIdentifier;
	unsigned name;
	unsigned displayName;
	unsigned companionAppID;
	unsigned counterpartIdentifiers;
	unsigned filename;
	unsigned bundleVersion;
	unsigned shortVersionString;
	unsigned signerIdentity;
	unsigned codeInfoIdentifier;
	unsigned signerOrganization;
	unsigned appType;
	unsigned long long staticDiskUsage;
	unsigned long long purchaserDSID;
	unsigned long long downloaderDSID;
	unsigned long long familyID;
	unsigned vendorName;
	unsigned itemName;
	unsigned long long storefront;
	unsigned long long versionIdentifier;
	unsigned long long ratingRank;
	unsigned ratingLabel;
	unsigned long long genreID;
	unsigned genre;
	unsigned sourceAppIdentifier;
	unsigned appVariant;
	unsigned primaryIconName;
	unsigned iconsDict;
	unsigned iconFileNames;
	unsigned execPath;
	unsigned libraryPath;
	unsigned libraryItems;
	unsigned claims;
	unsigned types;
	unsigned services;
	unsigned plugins;
	unsigned extensionPoints;
	unsigned activityTypes;
	unsigned schemesWhitelist;
	unsigned alias;
	unsigned appContainerAlias;
	unsigned dataContainerAlias;
	unsigned container;
	unsigned char revision;
	unsigned char retries;
	unsigned char _reserved3;
	unsigned char _reserved4;
	unsigned plistRarities;
	unsigned commonPlistEntries;
	unsigned entitlements;
	unsigned groupContainers;
	unsigned sandboxEnvironmentVariables;
	unsigned _reserved5;
} LSBundleData;

typedef struct _NSZone* NSZoneRef;

typedef struct _compressed_pair<CSStore2::Store *, std::__1::default_delete<CSStore2::Store> > {
	Store __value_;
} compressed_pair<CSStore2::Store *, std::__1::default_delete<CSStore2::Store> >;

typedef struct unique_ptr<CSStore2::Store, std::__1::default_delete<CSStore2::Store> > {
	compressed_pair<CSStore2::Store *, std::__1::default_delete<CSStore2::Store> > __ptr_;
} unique_ptr<CSStore2::Store, std::__1::default_delete<CSStore2::Store> >;

typedef struct {
	unsigned val[8];
} SCD_Struct_LS6;

typedef struct {
	int field1;
	CGSize field2;
} SCD_Struct_LS7;

typedef struct __CFData* CFDataRef;

typedef struct __CFBundle* CFBundleRef;

typedef struct __CFArray* CFArrayRef;

typedef struct {
	unsigned field1;
	unsigned field2;
	unsigned field3;
	unsigned field4;
	int field5;
	unsigned field6;
	unsigned field7;
	unsigned field8[8];
	unsigned field9;
	unsigned field10;
	unsigned field11;
	unsigned field12;
	unsigned field13;
} SCD_Struct_UT11;

