#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "ThingModuleApplicationBlueprint.h"
#import "ThingModuleBaseBlueprint.h"
#import "ThingModuleConfigBlueprint.h"
#import "ThingModuleLaunchTaskBlueprint.h"
#import "ThingModuleNotifyBlueprint.h"
#import "ThingModuleRouteBlueprint.h"
#import "ThingModuleServiceBlueprint.h"
#import "ThingModuleTabBarBlueprint.h"
#import "ThingModuleConfig.h"
#import "ThingModuleMixBridge.h"
#import "ThingModule.h"
#import "ThingModuleCustomizeManager.h"
#import "ThingModuleLifeCycleCallbackProtocol.h"
#import "ThingModuleLinkedItem.h"
#import "ThingModuleManager.h"
#import "ThingModuleRegisterProtocol.h"
#import "UIViewController+Route.h"
#import "ThingModuleHookInfo.h"
#import "ThingModuleHookRegisterProtocol.h"
#import "ThingModuleNotifyRegisterProtocol.h"
#import "ThingModuleRouteRegisterProtocol.h"
#import "ThingModuleServiceInfo.h"
#import "ThingModuleServiceRegisterProtocol.h"
#import "ThingTabBarControllerDataSource.h"
#import "ThingTabBarControllerDelegate.h"
#import "ThingTabBarControllerProtocol.h"
#import "ThingTabBarCustomButton.h"
#import "ThingModuleTabBarStyleProtocol.h"
#import "ThingModuleTabRegisterProtocol.h"
#import "ThingTabBarCustomBadgeProtocol.h"
#import "ThingTabItemAttribute+Private.h"
#import "ThingTabItemAttribute.h"
#import "ThingLaunchTaskProtocol.h"
#import "ThingModuleLaunchTaskRegisterProtocol.h"

FOUNDATION_EXPORT double ThingModuleManagerVersionNumber;
FOUNDATION_EXPORT const unsigned char ThingModuleManagerVersionString[];

