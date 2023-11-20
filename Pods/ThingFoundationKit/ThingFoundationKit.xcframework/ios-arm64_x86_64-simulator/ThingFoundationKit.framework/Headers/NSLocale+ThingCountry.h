//
//  NSLocale+ThingCountry.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/5/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#if TARGET_OS_IOS
FOUNDATION_EXPORT NSString * Thing_ISOCountryCode(void);
#endif

@interface NSLocale (ThingCountry)

#if TARGET_OS_IOS
+ (NSString *)thing_ISOCountryCode;
#endif

@end

NS_ASSUME_NONNULL_END
