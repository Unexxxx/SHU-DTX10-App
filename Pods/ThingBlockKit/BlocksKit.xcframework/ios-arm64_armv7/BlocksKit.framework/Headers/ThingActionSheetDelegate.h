//
//  ThingActionSheetDelegate.h
//  ThingBlockKit_Example
//
//  Created by ThingInc on 2018/12/3.
//  Copyright © 2018 ThingInc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingActionSheetDelegate : NSObject <UIActionSheetDelegate>

@property (nonatomic, strong, readonly) NSMutableDictionary *handlers;
@property (nonatomic, weak) id realDelegate;

@end

NS_ASSUME_NONNULL_END
