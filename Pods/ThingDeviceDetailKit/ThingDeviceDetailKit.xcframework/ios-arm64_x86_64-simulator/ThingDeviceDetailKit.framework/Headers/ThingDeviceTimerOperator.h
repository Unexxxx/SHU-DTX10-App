//
//  ThingDeviceTimerOperator.h
//  AAAThingLoadTask
//
//  Created by 后主 on 2023/8/21.
//

#import <Foundation/Foundation.h>
#import <ThingSmartTimerKit/ThingSmartTimerKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingDeviceTimerBizType) {
    ThingDeviceTimerBizTypeDevice = 0, //device
    ThingDeviceTimerBizTypeGroup = 1, //group
};

/// 基础的定时数据
@interface ThingDeviceTimerData : NSObject
/// ThingDeviceTimerBizTypeDevice for device, ThingDeviceTimerBizTypeGroup for group
@property (nonatomic, assign) ThingDeviceTimerBizType bizType;

/// deviceId if bizType is ThingDeviceTimerBizTypeDevice, groupId  if bizType is ThingDeviceTimerBizTypeGroup
@property (nonatomic, copy) NSString *bizId;

/// The loop of the timer
@property (nonatomic, copy) NSString *loops;

/// The status of the timer.
@property (nonatomic, assign) BOOL status;

//The time when the timer runs.
@property (nonatomic, copy) NSString *time;

/// The action DPs of the timer.
@property (nonatomic, strong) NSDictionary *dps;

/// Specifies whether the timer push notification is enabled. If the value is set to `yes`, when the timer runs, the app receives a push notification.
@property (nonatomic, assign) BOOL isAppPush;

/// The alias name of the timer.
@property (nonatomic, copy) NSString *aliasName;
@end



@interface ThingDeviceTimerAddParams : ThingDeviceTimerData

/// The category of timer
@property (nonatomic, copy) NSString *category;

- (instancetype)initWithBizType:(ThingDeviceTimerBizType)bizType bizId:(NSString *)bizId category:(NSString *)category loops:(NSString *)loops time:(NSString *)time dps:(NSDictionary *)dps aliasName:(NSString *)aliasName isAppPush:(BOOL)isAppPush status:(BOOL)status;

@end



@interface ThingDeviceTimerUpdateParams : ThingDeviceTimerData
/// id of the timer
@property (nonatomic, copy) NSString *timerId;

- (instancetype)initWithTimerId:(NSString *)timerId bizType:(ThingDeviceTimerBizType)bizType bizId:(NSString *)bizId loops:(NSString *)loops time:(NSString *)time dps:(NSDictionary *)dps aliasName:(NSString *)aliasName isAppPush:(BOOL)isAppPush status:(BOOL)status;

@end



@interface ThingDeviceTimerRemoveParams : NSObject
/// id of the timer
@property (nonatomic, copy) NSString *timerId;

/// ThingDeviceTimerBizTypeDevice for device, ThingDeviceTimerBizTypeGroup for group
@property (nonatomic, assign) ThingDeviceTimerBizType bizType;

/// deviceId if bizType is ThingDeviceTimerBizTypeDevice, groupId  if bizType is ThingDeviceTimerBizTypeGroup
@property (nonatomic, copy) NSString *bizId;

- (instancetype)initWithTimerId:(NSString *)timerId bizType:(ThingDeviceTimerBizType)bizType bizId:(NSString *)bizId;

@end


@interface ThingDeviceTimerStatusUpdateParams : ThingDeviceTimerData
/// id of the timer
@property (nonatomic, copy) NSString *timerId;

- (instancetype)initWithTimerId:(NSString *)timerId bizType:(ThingDeviceTimerBizType)bizType bizId:(NSString *)bizId loops:(NSString *)loops time:(NSString *)time dps:(NSDictionary *)dps aliasName:(NSString *)aliasName isAppPush:(BOOL)isAppPush status:(BOOL)status;

@end


@interface ThingDeviceTimerGetParams : NSObject
/// ThingDeviceTimerBizTypeDevice for device, ThingDeviceTimerBizTypeGroup for group
@property (nonatomic, assign) ThingDeviceTimerBizType bizType;

/// deviceId if bizType is ThingDeviceTimerBizTypeDevice, groupId  if bizType is ThingDeviceTimerBizTypeGroup
@property (nonatomic, copy) NSString *bizId;

/// The category of timer
@property (nonatomic, copy) NSString *category;

- (instancetype)initWithBizType:(ThingDeviceTimerBizType)bizType bizId:(NSString *)bizId category:(NSString *)category;

@end




@protocol ThingDeviceTimerOperator <NSObject>

- (void)addTimer:(ThingDeviceTimerAddParams *)params success:(void(^)(NSString *timerId))success failure:(void(^)(NSError *error))failure;

- (void)updateTimer:(ThingDeviceTimerUpdateParams *)params success:(void(^)(void))success failure:(void(^)(NSError *error))failure;

- (void)getTimers:(ThingDeviceTimerGetParams *)params success:(void(^)(NSArray<ThingTimerModel *> *timers))success failure:(void(^)(NSError *error))failure;

- (void)removeTimer:(ThingDeviceTimerRemoveParams *)params success:(void(^)(void))success failure:(void(^)(NSError *error))failure;

- (void)updateTimerStatus:(ThingDeviceTimerStatusUpdateParams *)params success:(void(^)(void))success failure:(void(^)(NSError *error))failure;

- (void)syncTimers:(NSArray<ThingTimerModel *> *)timers toDevice:(NSString *)deviceId success:(void(^)(void))success failure:(void(^)(NSError *error))failure;

- (BOOL)isDeviceCanSync:(NSString *)deviceId;

@end

NS_ASSUME_NONNULL_END
