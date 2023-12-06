//
//  ThingModuleLifeCycleCallbackProtocol.h
//  ThingModuleManager
//
//  Created by ThingInc on 2019/3/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 if you need any callback in this protocol
 use - (NSArray<NSString *> *)registRespondsNotifies or [ThingModule notifyService] to regist
 */
@protocol ThingModuleLifeCycleCallbackProtocol <NSObject>

- (void)applicationModulesDidFinishLoadingNotify;

@end

NS_ASSUME_NONNULL_END
