//
//  UIView+Tap.h
//  ThingBlockKit_Example
//
//  Created by ThingInc on 2018/12/3.
//  Copyright © 2018 ThingInc. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (Tap)

- (void)bk_whenTapped:(void (^)(void))block;

@end



NS_ASSUME_NONNULL_END



