//
//  NSArray+Ex.h
//  ThingBlockKit_Example
//
//  Created by ThingInc on 2018/12/13.
//  Copyright © 2018 ThingInc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSArray (Ex)

- (void)bk_each:(void (^)(id obj))block;

- (NSArray *)bk_select:(BOOL (^)(id obj))block;

- (NSArray *)bk_map:(id (^)(id obj))block;

@end

NS_ASSUME_NONNULL_END
