//
//  ThingDeviceTimerObjectExtra.h
//  ThingDeviceDetailKit
//
//  Created by 后主 on 2023/8/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingDeviceTimerObjectLoopType) {
    /// 周循环
    ThingDeviceTimerObjectLoopTypeWeek = 0,
    /// 日间隔
    ThingDeviceTimerObjectLoopTypeDay = 1,
    /// 小时间隔
    ThingDeviceTimerObjectLoopTypeHour = 2,
    /// 3:奇偶循环 4:cron循环
};

///【云端】设备定时模型的额外信息
@interface ThingDeviceTimerObjectExtra : NSObject

/// 定时id
@property (nonatomic, copy) NSString *timerId;
/// 执行日期或首次执行日期
@property (nonatomic, copy) NSString *date;
/// 执行时间点或首次执行时间
@property (nonatomic, copy) NSString *time;

@property ThingDeviceTimerObjectLoopType loopType;

@end


@interface ThingDeviceTimerObjectExtra (Date)

/// input: date+time
- (NSDateComponents *)dateComponents;

@end

NS_ASSUME_NONNULL_END
