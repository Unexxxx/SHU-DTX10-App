//
//  ThingAlertViewDelegate.h
//  ThingBlockKit_Example
//
//  Created by ThingInc on 2018/12/13.
//  Copyright © 2018 ThingInc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingAlertViewDelegate : NSObject <UIAlertViewDelegate>

@property (nonatomic, strong, readonly) NSMutableDictionary *handlers;
@property (nonatomic, weak) id realDelegate;
@property (nonatomic, copy) void (^thing_didDismissBlock)(UIAlertView *alertView, NSInteger buttonIndex);

@end

NS_ASSUME_NONNULL_END
