//
//  NSObject+ThingRateLimiting.h
//  ThingFoundationKit
//
//  Created by 津渡 on 2021/2/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (ThingRateLimiting)

/// 节流
- (void)thing_throttle:(nonnull SEL)action withObject:(nullable id)object duration:(NSTimeInterval)duration;

- (void)thing_debounce:(nonnull SEL)action withObject:(nullable id)object duration:(NSTimeInterval)duration;

@end

NS_ASSUME_NONNULL_END
