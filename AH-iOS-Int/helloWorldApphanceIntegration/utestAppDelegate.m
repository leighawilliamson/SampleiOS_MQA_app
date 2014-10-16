//
//  utestAppDelegate.m
//  helloWorldApphanceIntegration
//
//  Created by Wojciech Kedzierski on 31.08.2012.
//  Copyright (c) 2012 Wojciech Kedzierski. All rights reserved.
//

#import "utestAppDelegate.h"

#import "utestLogObject.h"

@implementation utestAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Override point for customization after application launch.
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad) {
        UISplitViewController *splitViewController = (UISplitViewController *)self.window.rootViewController;
        UINavigationController *navigationController = [splitViewController.viewControllers lastObject];
        splitViewController.delegate = (id)navigationController.topViewController;
    }
   
    /**********************************/
    /* Configuration for for Apphance */
    /**********************************/
    
    // Preferable bug report trigger can be set before starting Apphance session

    // You must insert your Apphance application key in the next line of code:
 //   [APHLogger startNewSessionWithApplicationKey:@"517f47631f8bfe070165a83097e96baff334dbf0"];
    
    // If you do not have an Apphance application key, you must first create a free account.
    // Visit http://www.apphance.com for more information about how to create your account.
    //
    // If you already have an Apphance account, login to the Apphance control panel at: https://panel.apphance.com
    // Create a new application (if you have not done so already).
    // Your application key can be retrieved at any time from the "Settings" tab on the left menu.
    
    // The following line handles all uncaught exceptions and will send them to Apphance the next
    // time the application starts. Add this line to enable crash reporting.
    
 //   NSSetUncaughtExceptionHandler(&APHUncaughtExceptionHandler);
    
    // For more Apphance help, visit http://help.apphance.com
    // For more help with Apphance on iOS, visit http://help.apphance.com/library-installation/ios/
    
    /***********************/
    /* End Apphance Config */
    /***********************/
    
    /********************************/
    /* Examples of Apphance Logging */
    /********************************/

    // The following lines are just examples - they are NOT necessary for configuration.
    //
    // Apphance allows you to log activities from within your application. The following lines of code are examples
    // of several different ways to log from within your application.
    //
    // You can use logging tools like these from anywhere within your app. In this example application, these methods
    // will write their log events when your app is started.
    
    /* APHLog */
    // This is the standard AppHance logging method. It works very similarly to NSLog. (You can even use this method
    // in place of NSLog - data sent to APHLog will still be logged to the console.)
//    APHLog(@"Example of APHLog", nil);
    
    // An example of the standard Apphance logging method with parameters.
 //   APHLog(@"APHLog with a parameter: %@", @"demo parameter");
    
    /* APHExtendedLog */
    // Apphance also features an extended logging method that supports log levels and tags. (You can even use this method
    // in place of NSLog - data sent to APHExtendedLog will still be logged to the console.)
    // Here's an example of the extended logging method with a warning log level and no tags.
//    APHExtendedLog(APHLogLevelWarning, nil, @"APHExtendedLog with a warning log level", nil);
    
    // Here's an example of the extended logging method with a verbose log level and a custom tag.
    NSString *const tag = @"example_tag";
 //   APHExtendedLog(APHLogLevelVerbose, tag, @"APHExtendedLog with a verbose log level and with tag: %@", tag);

    /* Object Logging */
    // Apphance can log messages received by objects. The following lines of code create a new
    // object with object logging enabled and then call an example method.
    //
    // Please see Supporting Files/utestLogObject.m for more details about how to enable object logging.
    utestLogObject *testObject = [[utestLogObject alloc] init];
    [testObject testMethod];
    
    // For more help with logging, visit http://help.apphance.com/library-installation/ios/logging
    
    /*********************************/
    /* End Apphance Logging Examples */
    /*********************************/

    return YES;
}
							
- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
