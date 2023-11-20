//
//  ThingModuleMixBridge.h
//  ThingModuleManager
//
//  Created by ThingInc on 2018/10/10.
//

#import <Foundation/Foundation.h>

#define ThingNative ((id)[ThingModuleMixBridge bridgeTargetOfObj:self])
#define ThingNativeTarget(obj) ((id)[ThingModuleMixBridge bridgeTargetOfObj:obj])

@interface ThingModuleMixBridge : NSObject

/**
 如果obj是class，则返回class
 如果obj是instance，则返回instance
 */
+ (id)bridgeTargetOfObj:(id)obj;
+ (instancetype)shareInstance;

- (void)hookService:(Protocol *)prot ofSelector:(SEL)sel withModuleCls:(Class)moduleCls;

@end
