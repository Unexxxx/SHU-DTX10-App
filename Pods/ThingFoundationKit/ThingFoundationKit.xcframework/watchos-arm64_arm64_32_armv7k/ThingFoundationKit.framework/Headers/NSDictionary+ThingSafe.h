//
//  NSDictionary+ThingSafe.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/3/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSMutableDictionary (ThingSafe)

- (void)thing_safeSetObject:(id)anObject forKey:(id<NSCopying>)aKey;

@end

NS_ASSUME_NONNULL_END
