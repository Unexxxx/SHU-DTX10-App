//
//  ThingDeviceTimerBleSyncTaskManager.h
//  ThingDeviceDetailKit
//
//  Created by 后主 on 2023/8/23.
//

#import <Foundation/Foundation.h>
#import "ThingDeviceTimerBleSyncTask.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceTimerBleSyncTaskManager : NSObject

/// 每个 task 的超时时间，默认是 0，不设置超时
@property (nonatomic, assign) NSTimeInterval timeout;

- (instancetype)initWithDevId:(NSString *)devId;

- (void)addWithTask:(ThingDeviceTimerBleSyncTask *)task;

@property (nonatomic, copy) void(^completionHandle)(void);

@end

NS_ASSUME_NONNULL_END
