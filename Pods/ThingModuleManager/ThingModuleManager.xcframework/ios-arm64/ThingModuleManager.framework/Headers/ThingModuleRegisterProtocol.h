//
//  ThingModuleRegisterProtocol.h
//  ThingModuleManager
//
//  Created by ThingInc on 2019/5/11.
//

#import "ThingModuleServiceRegisterProtocol.h"
#import "ThingModuleRouteRegisterProtocol.h"
#import "ThingModuleTabRegisterProtocol.h"
#import "ThingModuleNotifyRegisterProtocol.h"
#import "ThingModuleLaunchTaskRegisterProtocol.h"
#import "ThingModuleHookRegisterProtocol.h"
// Callback
#import "ThingModuleLifeCycleCallbackProtocol.h"

@protocol ThingModuleRegisterProtocol <ThingModuleServiceRegisterProtocol, ThingModuleRouteRegisterProtocol, ThingModuleTabRegisterProtocol, ThingModuleNotifyRegisterProtocol, ThingModuleLaunchTaskRegisterProtocol>
@end
