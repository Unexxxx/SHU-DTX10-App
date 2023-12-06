//
//  NSDate+ThingFormat.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN BOOL Thing_Is24HourClock(void);

@interface NSDate (ThingFormat)

@property (nonatomic, readonly) NSDateComponents *thing_dateComponments __deprecated_msg("Use thing_dateComponents instead");
@property (nonatomic, readonly) NSDateComponents *thing_dateComponents;
@property (nonatomic, readonly) NSInteger thing_year;
@property (nonatomic, readonly) NSInteger thing_month;
@property (nonatomic, readonly) NSInteger thing_day;
@property (nonatomic, readonly) NSInteger thing_weekday;
@property (nonatomic, readonly) NSInteger thing_hour;
@property (nonatomic, readonly) NSInteger thing_minute;
@property (nonatomic, readonly) NSInteger thing_second;

/**
 format current date
 if dateFormat == nil, use "yyyy-MM-dd HH:mm:ss" instead
 */
- (NSString *)thing_stringWithFormat:(NSString * _Nullable)dateFormat;
- (NSString *)thing_stringWithFormat:(NSString * _Nullable)dateFormat timeZone:(NSTimeZone * _Nullable)timeZone;
/**
 format current date
 if formatter == nil, use "yyyy-MM-dd HH:mm:ss" instead
 */
- (NSString *)thing_stringWithFormatter:(NSDateFormatter * _Nullable)formatter;


/**
 create date with format string
 if dateFormat == nil, use "yyyy-MM-dd HH:mm:ss" instead
 */
+ (instancetype)thing_dateFromString:(NSString *)dateStr withFormat:(NSString * _Nullable)dateFormat;
+ (instancetype)thing_dateFromString:(NSString *)dateStr withFormat:(NSString * _Nullable)dateFormat timeZone:(NSTimeZone * _Nullable)timeZone;
/**
 create date with format string
 if dateFormat == nil, use "yyyy-MM-dd HH:mm:ss" instead
 */
+ (instancetype)thing_dateFromString:(NSString *)dateStr withFormatter:(NSDateFormatter * _Nullable)formatter;


/**
 return YES if self.thing_year self.thing_month self.thing_day equal to [NSDate date]
 */
- (BOOL)thing_isToday;

/**
 if unit == 0, return self.timeIntervalSince1970 == date.timeIntervalSince1970
 */
- (BOOL)thing_isEqualToDate:(NSDate *)date withOptions:(NSCalendarUnit)unit;



+ (BOOL)thing_is24HourClock;

@end

NS_ASSUME_NONNULL_END
