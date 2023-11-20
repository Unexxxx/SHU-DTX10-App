//
//  NSArray+ThingSafe.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2018/12/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSArray<ObjectType> (ThingSafe)

- (ObjectType)thing_safeObjectAtIndex:(NSUInteger)index;

@end

@interface NSMutableArray (ThingSafe)

- (void)thing_safeAddObject:(id)anObject;
- (void)thing_safeInsertObject:(id)anObject atIndex:(NSUInteger)index;

@end

NS_ASSUME_NONNULL_END
