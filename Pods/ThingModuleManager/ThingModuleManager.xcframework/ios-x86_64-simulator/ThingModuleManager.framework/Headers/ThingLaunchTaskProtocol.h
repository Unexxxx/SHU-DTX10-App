//
//  ThingLaunchTaskProtocol.h
//  ThingModuleManager
//
//  Created by ThingInc on 2018/10/23.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    ThingLaunchTaskRunMode_AsyncOnGlobal   = 0,      /**< 异步到全局队列执行 */
    ThingLaunchTaskRunMode_AsyncOnMain     = 1,      /**< 异步到主队列执行 */
    // 在主线程串行由于对启动时间影响较大，为内部保留类型，有需要请打call
} ThingLaunchTaskRunMode;

typedef enum : NSUInteger {
    ThingLaunchTaskPriority_Low = 250,
    ThingLaunchTaskPriority_Default = 750,
    ThingLaunchTaskPriority_Hight = 1000,
} ThingLaunchTaskPriority;


@protocol ThingLaunchTaskProtocol <NSObject>

@required
/*
 开始执行, 请把需要执行的任务写在此回调下
 */
- (void)start;

@optional
/*
 执行方式  [Default: ThingLaunchTaskRunMode_AsyncOnGlobal]
 */
+ (ThingLaunchTaskRunMode)runMode;

/**
 优先级，默认为 ThingLaunchTaskPriority_Default
 */
+ (ThingLaunchTaskPriority)priority;

@end
