//
//  ThingDeviceTimerManager+Get.h
//  ThingDeviceDetailKit
//
//  Created by 后主 on 2023/8/24.
//

#import "ThingDeviceTimerManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceTimerManager (Get)

- (void)generalGetTimers:(ThingDeviceTimerGetParams *)params success:(void(^)(NSArray<ThingTimerModel *> *timers))success failure:(void(^)(NSError *error))failure;

- (void)specialGetTimers:(ThingDeviceTimerGetParams *)params success:(void(^)(NSArray<ThingTimerModel *> *timers))success failure:(void(^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
