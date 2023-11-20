//
//  NSObject+ThingPerformSelector.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/5/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (ThingPerformSelector)

- (id)thing_performSelector:(SEL)sel;

/**
 Instead of performselector method with NSInvocation
 params_key: index of argument, begin from 0
 params_value: value of argument
 */
- (id)thing_performSelector:(SEL)sel withObjects:(nullable NSDictionary<NSString *, id> *)params;

@end

NS_ASSUME_NONNULL_END
