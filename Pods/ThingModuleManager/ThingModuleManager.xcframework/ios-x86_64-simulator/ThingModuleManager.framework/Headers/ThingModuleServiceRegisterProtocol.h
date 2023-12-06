//
//  ThingModuleServiceRegisterProtocol.h
//  ThingModuleManager
//
//  Created by ThingInc on 2018/8/30.
//

#import <Foundation/Foundation.h>

#import "ThingModuleServiceInfo.h"

@protocol ThingModuleServiceRegisterProtocol <NSObject>

@optional
- (NSArray<ThingModuleServiceInfo *> *)registModuleServices;

@end
