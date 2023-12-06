//
//  NSObject+ThingClassInfo.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/3/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (ThingClassInfo)

+ (NSString *)thing_className;
- (NSString *)thing_className;

+ (BOOL)thing_isMetaClass;
+ (Class)thing_superClass;

@end

NS_ASSUME_NONNULL_END
