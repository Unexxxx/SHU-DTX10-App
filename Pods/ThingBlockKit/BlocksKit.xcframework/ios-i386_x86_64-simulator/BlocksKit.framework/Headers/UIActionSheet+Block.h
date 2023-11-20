//
//  UIActionSheet+Block.h
//  ThingBlockKit_Example
//
//  Created by ThingInc on 2018/12/3.
//  Copyright © 2018 ThingInc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIActionSheet (Block)

+ (id)bk_actionSheetWithTitle:(NSString *)title;

- (id)bk_initWithTitle:(NSString *)title NS_REPLACES_RECEIVER;

- (NSInteger)bk_addButtonWithTitle:(NSString *)title handler:(void (^)(void))block;

- (NSInteger)bk_setCancelButtonWithTitle:(NSString *)title handler:(void (^)(void))block;

- (void)bk_setHandler:(void (^)(void))block forButtonAtIndex:(NSInteger)index;

- (void (^)(void))bk_handlerForButtonAtIndex:(NSInteger)index;

- (void (^)(void))bk_cancelBlock;

@end

NS_ASSUME_NONNULL_END
