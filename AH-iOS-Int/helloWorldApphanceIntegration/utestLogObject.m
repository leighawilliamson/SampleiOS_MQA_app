//
//  utestLogObject.m
//  helloWorldApphanceIntegration
//
//  Created by Stanton Champion on 9/11/12.
//  Copyright (c) 2012 Wojciech Kedzierski. All rights reserved.
//

#import "utestLogObject.h"

@implementation utestLogObject

- (id) init {
    self = [super init];
    if(self) {
        
    }
    
    // This method registers this object for logging with Apphance. Messages sent to this object will
    // also be sent to Apphance for debugging purposes.
    //
    // To see this in action, see the utestAppDelegate.m file.
//    return [APHLogger registerObjectForLogging:self];
}

- (void) testMethod {
    NSLog(@"testMethod");
}



@end
