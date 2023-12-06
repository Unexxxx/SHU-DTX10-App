//
//  ThingModule.h
//  ThingModuleManager
//
//  Created by ThingInc on 2018/8/28.
//

#import <Foundation/Foundation.h>

#import "ThingModuleServiceBlueprint.h"
#import "ThingModuleConfigBlueprint.h"
#import "ThingModuleRouteBlueprint.h"
#import "ThingModuleApplicationBlueprint.h"
#import "ThingModuleTabBarBlueprint.h"
#import "ThingModuleNotifyBlueprint.h"
#import "ThingModuleLaunchTaskBlueprint.h"

#import "ThingModuleRegisterProtocol.h"

// 一个用来提供Thing的Native方法的调用的类
#import "ThingModuleMixBridge.h"

#define Thing_ServiceImpl(prot) ((id<prot>)[ThingModule serviceOfProtocol:@protocol(prot)])

#define Thing_RouteService [ThingModule routeService]
#define Thing_ApplicationService [ThingModule applicationService]
#define Thing_TabService [ThingModule tabService]
#define Thing_NotifyService [ThingModule notifyService]
#define Thing_ConfigService [ThingModule configService]


extern ThingModuleServiceInfo  *_Nullable ThingModuleServiceInfoMake(Protocol* _Nonnull, Class _Nonnull);
/**
 *【V2】创建 ThingModuleServiceInfo 实例
 *
 * @param prot 协议名称
 * @param cls 类名
 *
 * @return ThingModuleServiceInfo*
 */
#ifndef ThingMMakeService
#define ThingMMakeService(prot,cls) ThingModuleServiceInfoMake(@protocol(prot),[cls class])
#endif


/**
 ThingModule类主要用于提供一些快捷的方法，便于书写
 没有其它实质意义
 */
@interface ThingModule : NSObject

#pragma mark - Service

+ (nullable id)serviceOfProtocol:(nonnull Protocol *)protocol OBJC_DEPRECATED("组件2.0 之后弃用。请使用 `serviceOfOptionalProtocol:` 或者 `serviceOfRequiedProtocol`");

+ (nullable id)serviceOfOptionalProtocol:(nonnull Protocol *)protocol;
+ (nullable id)serviceOfRequiredProtocol:(nonnull Protocol *)protocol;


+ (void)registService:(nonnull Class)implCls withProtocol:(nonnull Protocol *)protocol;

#pragma mark - Module
+ (nullable id)moduleImplOfClass:(nonnull Class)cls;

#pragma mark - CoreService
+ (nullable id<ThingModuleServiceBlueprint>)moduleService;
+ (nullable id<ThingModuleConfigBlueprint>)configService;
+ (nullable id<ThingModuleRouteBlueprint>)routeService;
+ (nullable id<ThingModuleApplicationBlueprint>)applicationService;
+ (nullable id<ThingModuleTabBarBlueprint>)tabService;
+ (nullable id<ThingModuleNotifyBlueprint>)notifyService;
+ (nullable id<ThingModuleLaunchTaskBlueprint>)taskService;

@end
