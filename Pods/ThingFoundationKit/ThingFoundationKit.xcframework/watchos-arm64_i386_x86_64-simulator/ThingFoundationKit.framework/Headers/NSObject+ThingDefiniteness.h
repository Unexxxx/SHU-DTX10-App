//
//  NSObject+ThingDefiniteness.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/3/27.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (ThingDefiniteness)

/**
 convert id or NSObject to int
 retrun 0 if fail
 */
- (NSInteger)thing_int;
/**
 convert id or NSObject to unsigned int
 retrun 0 if fail
 */
- (NSUInteger)thing_uInt;
/**
 convert id or NSObject to float
 retrun 0.0 if fail
 */
- (CGFloat)thing_float;
/**
 convert id or NSObject to double
 retrun 0.0 if fail
 */
- (double)thing_double;
/**
 convert id or NSObject to bool
 retrun NO if fail
 */
- (BOOL)thing_bool;
/**
 convert id or NSObject to string
 retrun nil if fail
 */
- (NSString *)thing_string;
/**
 convert id or NSObject to array
 retrun nil if fail
 */
- (NSArray *)thing_array;
/**
 convert id or NSObject to dictionary
 retrun nil if fail
 */
- (NSDictionary *)thing_dictionary;


- (BOOL)thing_isDictionaryAndNotEmpty;
- (BOOL)thing_isStringAndNotEmpty;
- (BOOL)thing_isArrayAndNotEmpty;

@end

NS_ASSUME_NONNULL_END
