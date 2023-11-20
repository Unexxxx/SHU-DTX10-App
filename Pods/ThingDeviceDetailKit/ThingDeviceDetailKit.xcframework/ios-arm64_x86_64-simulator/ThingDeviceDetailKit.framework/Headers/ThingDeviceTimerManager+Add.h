//
//  ThingDeviceTimerManager+Add.h
//  ThingDeviceDetailKit
//
//  Created by 后主 on 2023/8/24.
//

#import "ThingDeviceTimerManager.h"
#import "ThingDeviceTimerOperator.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceTimerManager (Add)

- (void)generalAddTimer:(ThingDeviceTimerAddParams *)params success:(void(^)(NSString *timerId))success failure:(void(^)(NSError *error))failure;

- (void)specialAddTimer:(ThingDeviceTimerAddParams *)params success:(void(^)(NSString *timerId))success failure:(void(^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
