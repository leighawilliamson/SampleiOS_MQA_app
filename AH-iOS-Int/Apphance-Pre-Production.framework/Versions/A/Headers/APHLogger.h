//  Copyright 2013 uTest. All rights reserved.
//
//	This is the main logger file. Include it in your project
//  along with the Apphance Framework. 

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "APHDefines.h"
#import "APHSettings.h"


/**
* Enum presenting possible logging level
*/
typedef enum {
    APHLogLevelFatal = 16,
    APHLogLevelError = 8,
    APHLogLevelWarning = 4,
    APHLogLevelInfo = 2,
    APHLogLevelVerbose = 0
} APHLogLevel;

/**
* Convinience method to log applications exceptions
*/
APH_EXTERN

void APHUncaughtExceptionHandler(NSException *exception);

/** Logging macros **/

/*
 * Replace all occurences of NSLog with APHLog. 
 * Except for working like normal log it will also send message to Apphance server.
 */
#define APHLog(nsstring_format, ...)    \
    do {                        \
        [APHLogger logWithLevel:APHLogLevelInfo \
        tag:nil \
        line:__LINE__ fileName:[NSString stringWithUTF8String:__FILE__] \
        method:[NSString stringWithUTF8String:__PRETTY_FUNCTION__] \
        stacktrace:[NSThread callStackReturnAddresses]\
        format:nsstring_format, \
        ##__VA_ARGS__];\
} while(0)

/*
 * Works as the one above, except it provides additional configuration options
 */
#define APHExtendedLog(APHLogLevel, nsstring_tag, nsstring_format, ...)    \
    do {                        \
        [APHLogger logWithLevel:(APHLogLevel) \
        tag:(nsstring_tag) \
        line:__LINE__ fileName:[NSString stringWithUTF8String:__FILE__] \
        method:[NSString stringWithUTF8String:__PRETTY_FUNCTION__] \
        stacktrace:[NSThread callStackReturnAddresses] \
        format:nsstring_format, \
        ##__VA_ARGS__];\
} while(0)


/**
* Main apphance API class
* @see https://help.apphance.com/library-installation/ios/tutorial
 */
@interface APHLogger : NSObject {

}

/**
* Default settings:
* - applicationVersionName is equal to CFBundleShortVersionString
* - applicationVersionCode is equal to CFBundleVersion
* - apphanceMode is equal to APHSettingsModeQA
* - reportOnShakeEnabled is equal to YES
* - reportOnDoubleSlideEnabled is equal to NO
* - withUTest is equal to NO
* @return Apphance APHSettings object with default values. You can easily change apphance behaviour by simply changing it's properties.
*/
+ (APHSettings *)defaultSettings;

/**
* Starting APH session. Should be called once per application run - doing otherwise will result in an undefined behavior.
* If you want to change default settings change properties for object [APHLogger defaultSettings].
* @param applicationID Application ID that you can get from Apphance
 */
+ (void)startNewSessionWithApplicationKey:(NSString *)applicationId;

/**
* Logs exception. Screenshot will be included in the data sent to the server.
* You can use APHUncaughtExceptionHandler as a convenience accessor to this method.
* @param error Exception that will be passed to Apphance
 */
+ (void)logApplicationException:(NSException *)error;

/**
* This method will register object for logging, meaning each and every method sent to it will be logged, including timestamp.
* See documentation for more information.
* @param object Object that will be registered for logging
 */
+ (id)registerObjectForLogging:(id)object;

/**
* Forces the contents of the session log buffer to be send.
 */
+ (void)flush;

/**
* This function manually shows report screen that is normally accessible by shaking device.
*/
+ (void)showReportScreen;

@end


/**
* Deprecated methods.
* If you want to start session please use startNewSessionWithSettings.
*/
@interface APHLogger (DeprecatedMethods)

/**
* Starting APH session. Should be called once per application run - doing otherwise will result in an undefined behavior.
* @param applicationID Application ID that you can get from Apphance
* @param apphanceMode Apphance mode:kAPHApphanceModeQA, kAPHApphanceModeSilent
* @param withUtest uTest enabled
 */
+ (void)startNewSessionWithApplicationKey:(NSString *)applicationID apphanceMode:(NSString *)apphanceMode withUtest:(BOOL)withUtest __attribute__ ((deprecated));

/**
* uTest is disabled by default.
* @see APHLogger#startNewSessionWithApplicationKey:apphanceMode:withUtest:
 */
+ (void)startNewSessionWithApplicationKey:(NSString *)applicationID apphanceMode:(NSString *)apphanceMode __attribute__ ((deprecated));

/**
* This will enable/disable shake gesture to report a problem.
* Default it YES.
* Be sure to call this before starting Apphance session otherwise it will have no effect.
* @param shakeEnabled
 */
+ (void)setReportOnShakeEnabled:(BOOL)shakeEnabled __attribute__ ((deprecated));

/**
* This will enable/disable double slide gesture to report a problem.
* Default it NO.
* Be sure to call this before starting Apphance session otherwise it will have no effect.
* @param doubleSlideEnabled
 */
+ (void)setReportOnDoubleSlideEnabled:(BOOL)doubleSlideEnabled __attribute__ ((deprecated));

/**
* This will override current application version name.
* Default one is obtained by CFBundleShortVersionString.
* Be sure to call this before starting Apphance session otherwise it will have no effect.
* @param versionName Application version name
 */
+ (void)setVersionName:(NSString *)versionName __attribute__ ((deprecated));

/**
* This will override current application version code.
* Default one is obtained by CFBundleVersion.
* Be sure to call this before starting Apphance session otherwise it will have no effect.
* @param versionNumber Application version number
 */
+ (void)setVersionNumber:(NSString *)versionNumber __attribute__ ((deprecated));

/**
* This will set default user. With this set on there will be no login screen.
* Be sure to call this before starting Apphance session otherwise it will have no effect.
* @param defaultUser Default user mail
 */
+ (void)setDefaultUser:(NSString *)defaultUser __attribute__ ((deprecated));

@end


/**
* Despite being called private, you can generally call these method, if you wish.
* However, this is strongly discouraged, since given macros and functions are more convenient way of using APH.
 */
@interface APHLogger (PrivateAccessors)

+ (void)logWithLevel:(APHLogLevel)level tag:(NSString *)tag line:(NSInteger)line fileName:(NSString *)fileName method:(NSString *)method stacktrace:(NSArray *)stacktrace format:(NSString *)format, ...;

@end


/**
* Methods that are only available on Production library.
* @see https://help.apphance.com/library-installation/ios/tutorial
*/
@interface APHLogger (ProductionLibraryMethods)

+ (void)feedback:(NSString *)title placeholder:(NSString *)placeholder;

+ (void)feedback:(NSString *)title;

+ (void)feedback;

+ (void)sendFeedback:(NSString *)feedback;

@end