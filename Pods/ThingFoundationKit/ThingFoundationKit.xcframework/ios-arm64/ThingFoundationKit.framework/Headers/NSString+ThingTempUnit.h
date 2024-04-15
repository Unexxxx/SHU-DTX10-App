//
//  NSString+ThingTempUnit.h
//  ThingSmartSceneCoreKit
//
//  Created by liwan.chen on 2021/12/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN NSString * const thing_celsius;
FOUNDATION_EXTERN NSString * const thing_fahrenheit;

@interface NSString (ThingTempUnit)

- (BOOL)thing_celsiusUnit;

- (BOOL)thing_fahrenheitUnit;

@end

NS_ASSUME_NONNULL_END
