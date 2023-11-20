//
//  NSString+ThingNumber.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/3/29.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (ThingNumber)

+ (instancetype)thing_stringFromInteger:(NSInteger)num;

+ (instancetype)thing_stringFromFloat:(CGFloat)num;

+ (instancetype)thing_stringFromFloat:(CGFloat)num withFractionDigits:(NSUInteger)digit roundingMode:(NSNumberFormatterRoundingMode)mode;

/**
 return boolean ? @"1" : @"0";
 */
+ (instancetype)thing_stringFromBool:(BOOL)boolean;

+ (BOOL)thing_isPureInt:(NSString*)string;

@end

NS_ASSUME_NONNULL_END
