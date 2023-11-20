//
//  NSDate+ThingOffset.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDate (ThingOffset)

/// offset years from the current date
/// @param numYears years
- (NSDate *)thing_offsetYears:(int)numYears;

/// offset years from the specific date, if specific date is nil, return nil
/// @param numYears years
/// @param fromDate specific date
+ (NSDate *)thing_offsetYears:(int)numYears fromDate:(NSDate *)fromDate;

/// offset months from the current date
/// @param numMonths months
- (NSDate *)thing_offsetMonths:(int)numMonths;

/// offset months from the specific date, if specific date is nil, return nil
/// @param numMonths months
/// @param fromDate specific date
+ (NSDate *)thing_offsetMonths:(int)numMonths fromDate:(NSDate *)fromDate;

/// offset days from the current date
/// @param numDays days
- (NSDate *)thing_offsetDays:(int)numDays;

/// offset days from the specific date, if specific date is nil, return nil
/// @param numDays days
/// @param fromDate specific date
+ (NSDate *)thing_offsetDays:(int)numDays fromDate:(NSDate *)fromDate;

/// offset hours from the current date
/// @param numHours hours
- (NSDate *)thing_offsetHours:(int)numHours;

/// offset hours from the specific date, if specific date is nil, return nil
/// @param numHours hours
/// @param fromDate specific date
+ (NSDate *)thing_offsetHours:(int)numHours fromDate:(NSDate *)fromDate;

/// offset minutes from the current date
/// @param numMinutes minutes
- (NSDate *)thing_offsetMinutes:(int)numMinutes;

/// offset minutes from the specific date, if specific date is nil, return nil
/// @param numMinutes minutes
/// @param fromDate specific date
+ (NSDate *)thing_offsetMinutes:(int)numMinutes fromDate:(NSDate *)fromDate;

/// offset seconds from the current date
/// @param numSeconds seconds
- (NSDate *)thing_offsetSeconds:(int)numSeconds;

/// offset seconds from the specific date, if specific date is nil, return nil
/// @param numSeconds seconds
/// @param fromDate specific date
+ (NSDate *)thing_offsetSeconds:(int)numSeconds fromDate:(NSDate *)fromDate;

#pragma mark - time interval

/// The start of the current minute, i.e. 0 seconds
- (NSDate *_Nullable)thing_startOfCurrentMinute;

/// The end of the current minute, i.e. 59 seconds
- (NSDate *_Nullable)thing_endOfCurrentMinute;

/// Range of the current minute, including start and end
- (NSArray<NSDate*> *_Nullable)thing_secondsDurationsAtCurrentMinute;

/// The start of the current hour, i.e. 0 minutes and 0 seconds
- (NSDate *_Nullable)thing_startOfCurrentHour;

/// The end of the current hour, i.e. 59 minutes and 59 seconds
- (NSDate *_Nullable)thing_endOfCurrentHour;

/// Range of the current hour, including start and end
- (NSArray<NSDate*> *_Nullable)thing_minuteDurationsAtCurrentHour;

/// The start of the current day, i.e. 00:00:00
- (NSDate *_Nullable)thing_startOfCurrentDay;

/// The end of the  current day, i.e. 23:59:59
- (NSDate *_Nullable)thing_endOfCurrentDay;

/// Range for the current day, including start and end
- (NSArray<NSDate*> *_Nullable)thing_hourDurationsAtCurrentDay;

/// The start of the current month, e.g. January 1st 00:00:00
- (NSDate *_Nullable)thing_startOfCurrentMonth;

/// The end of the current month, e.g. January 31st 23:59:59
- (NSDate *_Nullable)thing_endOfCurrentMonth;

/// Range for the current month, including start and end
- (NSArray<NSDate*> *_Nullable)thing_dayDurationsAtCurrentMonth;

/// The start of the current year, i.e. January 1st 00:00:00
- (NSDate *_Nullable)thing_startOfCurrentYear;

/// The end of the current year, i.e. December 31st 23:59:59
- (NSDate *_Nullable)thing_endOfCurrentYear;

/// Range for the current year, including start and end
- (NSArray<NSDate*> *_Nullable)thing_monthDurationsAtCurrentYear;

/// Determines whether the current date is included in the specified time interval
/// @param startDate specified start date
/// @param endDate specified end date
- (BOOL)thing_containtsFromStartDate:(NSDate *_Nonnull)startDate endDate:(NSDate *_Nonnull)endDate;

@end

NS_ASSUME_NONNULL_END
