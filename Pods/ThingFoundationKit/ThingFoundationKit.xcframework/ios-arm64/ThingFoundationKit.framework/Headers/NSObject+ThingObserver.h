//
//  NSObject+ThingObserver.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/3/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 swizzle addObserver:forKeyPath:options:context: method
 and automatic remove observer when observer dealloc
 */
@interface NSObject (ThingObserverAutoRemove)

@end


@interface NSObject (ThingObserver)

/**
 add observer with block
 */
// - (void)thing_addObserverBlockForKeyPath:(NSString *)keyPath block:(void (^)(__weak id obj, id oldVal, id newVal))block;

@end

NS_ASSUME_NONNULL_END
