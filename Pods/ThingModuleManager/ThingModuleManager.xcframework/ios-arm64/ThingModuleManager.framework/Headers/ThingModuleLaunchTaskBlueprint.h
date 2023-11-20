//
//  ThingModuleLaunchTaskBlueprint.h
//  ThingModuleManager
//
//  Created by ThingInc on 2018/9/18.
//

#import <Foundation/Foundation.h>

#import "ThingModuleBaseBlueprint.h"
#import "ThingLaunchTaskProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingModuleLaunchTaskBlueprint <ThingModuleBaseBlueprint>

@property (nonatomic) BOOL enableCircleCheck;   /**< 是否开启依赖的成环检测 默认仅在DEBUG下开启 */

- (void)registLaunchTask:(Class<ThingLaunchTaskProtocol>)taskCls;
- (void)registLaunchTaskFromArray:(NSArray<Class<ThingLaunchTaskProtocol>> *)taskArr;

/*
 * 优先执行串行任务，然后 并发 asyncOnMain和asyncOnGlobal，同时此方法结束
 */
- (void)executeLaunchTasks;

@end

NS_ASSUME_NONNULL_END
