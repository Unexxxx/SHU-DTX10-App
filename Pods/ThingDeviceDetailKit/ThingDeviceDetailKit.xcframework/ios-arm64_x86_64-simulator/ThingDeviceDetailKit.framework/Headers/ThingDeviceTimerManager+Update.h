//
//  ThingDeviceTimerManager+Update.h
//  ThingTimerModule
//
//  Created by 后主 on 2023/8/24.
//

#import "ThingDeviceTimerManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceTimerManager (Update)

- (void)generalUpdateTimer:(ThingDeviceTimerUpdateParams *)params success:(void(^)(void))success failure:(void(^)(NSError *error))failure;

- (void)specialUpdateTimer:(ThingDeviceTimerUpdateParams *)params success:(void(^)(void))success failure:(void(^)(NSError *error))failure;

- (void)generalUpdateTimerStatus:(ThingDeviceTimerStatusUpdateParams *)params success:(void(^)(void))success failure:(void(^)(NSError *error))failure;

- (void)specialUpdateTimerStatus:(ThingDeviceTimerStatusUpdateParams *)params success:(void(^)(void))success failure:(void(^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
