//
//  utestDetailViewController.h
//  helloWorldApphanceIntegration
//
//  Created by Wojciech Kedzierski on 31.08.2012.
//  Copyright (c) 2012 Wojciech Kedzierski. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface utestDetailViewController : UIViewController <UISplitViewControllerDelegate>

@property (strong, nonatomic) id detailItem;

@property (weak, nonatomic) IBOutlet UILabel *detailDescriptionLabel;
@end
