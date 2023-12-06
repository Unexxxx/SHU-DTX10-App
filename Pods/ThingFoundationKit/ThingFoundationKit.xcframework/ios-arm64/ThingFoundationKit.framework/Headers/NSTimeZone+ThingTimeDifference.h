//
//  NSTimeZone+ThingTimeDifference.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/3/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @return [NSTimeZone localTimeZone].name
 */
FOUNDATION_EXTERN NSString * Thing_LocalTimeZoneName(void);
/**
 if timeZoneName is nil, use localTimeZone insted
 @return string like +08:00
 */
FOUNDATION_EXTERN NSString * Thing_TimeDifferenceWithGMT(NSString * _Nullable timeZoneName);


@interface NSTimeZone (ThingTimeDifference)

/**
 @return string like +08:00
 */
- (NSString *)thing_timeDifferenceWithGMT;

@end

NS_ASSUME_NONNULL_END
