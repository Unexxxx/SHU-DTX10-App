//
//  ThingModuleLaunchTaskRegisterProtocol.h
//  ThingModuleManager
//
//  Created by ThingInc on 2018/9/18.
//

#import <Foundation/Foundation.h>

#import "ThingLaunchTaskProtocol.h"

@protocol ThingModuleLaunchTaskRegisterProtocol <NSObject>

@optional
- (NSArray<Class<ThingLaunchTaskProtocol>> *)registLaunchTasks;

@end
