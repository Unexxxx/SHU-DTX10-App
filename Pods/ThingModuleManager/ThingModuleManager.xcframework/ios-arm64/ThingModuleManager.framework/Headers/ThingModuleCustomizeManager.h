//
//  ThingModuleCustomizeManager.h
//  ThingModuleManager
//
//  Created by yeqiu on 2020/2/26.
//

#import <Foundation/Foundation.h>
#import "ThingModuleApplicationBlueprint.h"
#import "ThingModuleTabRegisterProtocol.h"

typedef NS_ENUM(NSUInteger, ThingModuleLevel) {
    ThingModuleLevelVeryLow,
    ThingModuleLevelLow,
    ThingModuleLevelNormal,
    ThingModuleLevelHigh,
    ThingModuleLevelVeryHigh
};

NS_ASSUME_NONNULL_BEGIN

/// 在需要配置的类的实现文件中添加这个宏，className为类名，如：ThingModuleCustomizeRegister(ThingModuleCustomizeManager)
#define ThingModuleCustomizeRegister(className) \
char * thingmodule_##className##_data ThingModuleCustomizeDATASection = ""#className"";

#define ThingModuleSectionName "TModuleSection"
#define ThingModuleCustomizeDATASection __attribute((used, section("__DATA, TModuleSection")))



@protocol ThingModuleConfigDataSource <NSObject>

/// 注册应用初始类（这块已经有对应独立的service了）
/// 对应config_module.json的application、login、tabStyle
//- (NSString *)provideApplicationModuleClass;
//- (NSString *)provideLoginConfigClass;
//- (NSString *)provideTabbarStyleConfigClass;

/// 埋点文件路径
+ (NSString *)pathForMarkInfoDataFile;

/// 注册tabbar
/// 对应config_module.json的tabs
+ (NSArray<NSString *> *)provideTabBarModules;
+ (NSString *)provideTabBarDefaultSelectModule;

/// 模块注册
/// 对应config_module.json的modules，返回对应类的string数组
+ (NSArray<NSString *> *)provideModules;

/// 注册mix的类
/// 对应config_module.json的mixMap
+ (NSDictionary<NSString *, NSString *> *)provideMixMaps;

@end

@interface ThingModuleCustomizeManager : NSObject

@property (nonatomic, strong, readonly)NSDictionary<NSString *, NSString*> *mixMap;
@property (nonatomic, strong, readonly)NSString             *applicationModule;
@property (nonatomic, strong, readonly)NSString             *loginConfigClassName;
@property (nonatomic, strong, readonly)NSString             *tabStyleConfigClassName;
@property (nonatomic, strong, readonly)NSArray              *moduleOnTabBar;
@property (nonatomic, strong, readonly)NSString             *tabSelectedModule;
@property (nonatomic, strong, readonly)NSArray              *modules;
@property (nonatomic, strong, readonly)NSMutableSet         *dataProviderSet;

+ (instancetype)shareManager;

- (void)generalCustomerConfig;

@end

NS_ASSUME_NONNULL_END

