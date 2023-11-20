//
//  ThingDeviceTimerManager+Sync.h
//  ThingTimerModule
//
//  Created by 后主 on 2023/8/24.
//

#import "ThingDeviceTimerManager.h"
#import "ThingDeviceTimerOperator.h"
#import "ThingDeviceTimerObjectExtra.h"
#import "ThingDeviceTimerBleSyncUtils.h"

NS_ASSUME_NONNULL_BEGIN

//主要负责通过与设备的数据同步
@interface ThingDeviceTimerManager (Sync)

/// 定时清洗为零时区数据
- (void)getUTCTimerListWithDevId:(NSString *)devId timerIds:(nullable NSArray<NSString *> *)timerIds success:(void(^)(NSArray<ThingDeviceTimerObjectExtra *> *result))success failure:(void(^)(NSError *error))failure;

- (void)syncTimerToDevice:(ThingDeviceTimerData *)params timerId:(NSString *)timerId success:(void(^)(void))success failure:(void(^)(NSError *))failure;

- (void)bleSyncTimerWithDeviceId:(NSString *)deviceId timerId:(NSString *)timerId year:(uint8_t)year month:(uint8_t)month day:(uint8_t)day hour:(uint8_t)hour minute:(uint8_t)minute loops:(NSString *)loops dps:(NSDictionary *)dps success:(void (^)(void))success failure:(void (^)(NSError *error))failure;

- (void)removeTimerForDevice:(NSString *)deviceId timerId:(NSString *)timerId success:(void (^)(void))success failure:(void (^)(NSError *error))failure;

- (void)getDeviceLocalTimerList:(NSString *)deviceId success:(void(^)(ThingDeviceTimerBleSyncReadingTask *task))success failure:(void(^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
