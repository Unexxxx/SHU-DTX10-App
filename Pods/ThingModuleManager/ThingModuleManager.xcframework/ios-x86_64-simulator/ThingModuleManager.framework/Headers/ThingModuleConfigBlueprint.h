//
//  ThingModuleConfigProtocol.h
//  ThingModuleManager
//
//  Created by ThingInc on 2018/8/21.
//

#import <Foundation/Foundation.h>

#import "ThingModuleApplicationBlueprint.h"
#import "ThingModuleServiceRegisterProtocol.h"
#import "ThingModuleTabRegisterProtocol.h"

#import "ThingTabBarControllerProtocol.h"

@protocol ThingModuleConfigBlueprint <ThingModuleBaseBlueprint>

@property (nonatomic, strong, readonly, nonnull) NSDictionary *originalData;

@property (nonatomic, strong, readonly, nullable) Class<ThingModuleApplicationBlueprint> applicationModule;

/**
 all modules that need to be loaded
 
 所有需要被加载的模块
 */
@property (nonatomic, strong, readonly, nullable) NSArray<Class<ThingModuleServiceRegisterProtocol>> *buildModules;

/**
 modules that need to display on the tab bar
 
 想要展示在tab上的模块
 */
@property (nonatomic, strong, readonly, nullable) NSArray<Class<ThingModuleTabRegisterProtocol>> *moduleOnTabBar;

/**
 default select module on tab bar
 
 tabBar上默认选中的模块
 */
@property (nonatomic, strong, readonly, nullable) Class<ThingModuleTabRegisterProtocol> tabSelectedModule;


/**
 map of Mix Mode
 */
@property (nonatomic, strong, readonly, nullable) NSDictionary<NSString *, Class> *mixMapping;


/**
 value for specified key path in the original data
 key path like that is supported :
 a_path    a_path.sub_path     a_path.[2].sub_path
 
 根据所给keyPath，在originalData中查找并返回数据
 支持点语法 xxx.xxx  支持数组 xxx.[2].xxx
 */
- (id)configValueForKeyPath:(NSString *)keyPath;

/**
 the class that find out by the module name
 eg. input: @"TestModule"  return: TestModuleImpl or TestModule class
 
 根据根据所给模块名返回正确的类
 */
- (nullable Class)validClassOfConfigClass:(nonnull NSString *)moduleName;

/**
 class for specified key path in the original data
 key path like that is supported :
 a_path    a_path.sub_path     a_path.[2].sub_path
 
 根据所给keyPath，在originalData中查找并返回正确的class
 支持点语法 xxx.xxx  支持数组 xxx.[2].xxx
 */
- (nullable Class)validClassOfConfigKeyPath:(nonnull NSString *)keyPath;

@end
