//
//  ThingTabBarControllerDataSource.h
//  ThingModuleTabbar
//
//  Created by ThingInc on 2018/8/23.
//

#import <Foundation/Foundation.h>

#import "ThingTabItemAttribute.h"

@protocol ThingTabBarControllerDataSource <NSObject>

@required
- (NSArray<ThingTabItemAttribute *> *)thing_tabItemAttributes;

@end
