//
//  NSObject+ThingDeepCopy.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/3/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (ThingDeepCopy)

/**
 use NSKeyedArchiver and NSKeyedUnarchiver to do deep copy
 you can override this method to do deep copy by yourself
 */
- (id)thing_deepCopy;

- (id)thing_deepCopyWithArchiver:(Class)archiver unarchiver:(Class)unarchiver;

@end

NS_ASSUME_NONNULL_END
