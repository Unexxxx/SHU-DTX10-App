//
//  NSObject+ThingSwizzle.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/3/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN BOOL Thing_OverrideImplementation(Class cls, SEL sel, id(^implBlock)(Class originCls, SEL originSel, IMP originImp));

@interface NSObject (ThingSwizzle)

+ (BOOL)thing_swizzleInstanceMethod:(SEL)originalSel with:(SEL)swizzleSel;
+ (BOOL)thing_swizzleClassMethod:(SEL)originalSel with:(SEL)swizzleSel;

+ (BOOL)thing_swizzleAddMethod:(SEL)addSel fromClass:(Class)implCls method:(SEL)implSel;

@end

NS_ASSUME_NONNULL_END
