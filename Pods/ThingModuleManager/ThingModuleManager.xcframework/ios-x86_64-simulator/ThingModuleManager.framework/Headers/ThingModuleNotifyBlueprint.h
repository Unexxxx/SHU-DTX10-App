//
//  ThingModuleNotifyBlueprint.h
//  ThingModuleManager
//
//  Created by ThingInc on 2018/9/3.
//

#import <Foundation/Foundation.h>

#import "ThingModuleBaseBlueprint.h"

@protocol ThingModuleNotifyBlueprint <ThingModuleBaseBlueprint>

- (void)registResponder:(id)obj forNotify:(SEL)sel;
- (void)unregistResponder:(id)obj forNotify:(SEL)sel;

- (void)triggerNotify:(SEL)sel withUserInfo:(id)userInfo;
- (void)triggerNotify:(SEL)sel withUserInfo:(id)userInfo postNotification:(NSString *)name;

@end
