//  Copyright 2013 uTest. All rights reserved.


#import <Foundation/Foundation.h>
#import "APHDefines.h"

/**
* Anonymous login name - you can set it as defaultUser parameter.
*/
APH_EXTERN NSString *const APHAnonymousUser;


typedef NS_ENUM(NSInteger, APHSettingsMode)
{
    APHSettingsModeQA,
    APHSettingsModeSilent
};


@interface APHSettings : NSObject <NSCoding>

/**
* This value you get from Apphance application webpage.
*/
@property(nonatomic, strong) NSString *applicationId;

/**
* Version name that is used by Apphance.
*/
@property(nonatomic, strong) NSString *applicationVersionName;

/**
* Version code that is used by Apphance.
*/
@property(nonatomic, strong) NSString *applicationVersionCode;

/**
* Apphance Pre Production mode: APHSettingsModeQA and APHSettingsModeSilent.
* More at http://help.apphance.com/library-installation/ios
*/
@property(nonatomic) APHSettingsMode apphanceMode;

/**
* This will set default user. With this set on there will be no login screen.
*/
@property(nonatomic, strong) NSString *defaultUser;

/**
* This will enable/disable shake gesture to report a problem.
*/
@property(nonatomic, getter=isReportOnShakeEnabled) BOOL reportOnShakeEnabled;

/**
* This will enable/disable double slide gesture to report a problem.
*/
@property(nonatomic, getter=isReportOnDoubleSlideEnabled) BOOL reportOnDoubleSlideEnabled;

/**
* Enable it when you use uTest with your apphance application.
*/
@property(nonatomic) BOOL withUTest;

/**
* Enable this flag to alter Apphance screen capturing method. When set to True Apphance will use system screenshots (stored in the device's gallery)
* In order to report bugs in such a mode, system screenshot needs to be created first.
*/
@property(nonatomic) BOOL screenShotsFromGallery;

@end

#define APH_OS_BASE_SDK_ABOVE_7 0

#ifdef __IPHONE_7_0
    #if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_7_0
        #undef APH_OS_BASE_SDK_ABOVE_7
        #define APH_OS_BASE_SDK_ABOVE_7 1
    #endif
#endif

typedef NS_ENUM(NSInteger, APHSettingsOSBaseSDK)
{
    APHSettingsOSBaseSDKAbove7 = APH_OS_BASE_SDK_ABOVE_7
};