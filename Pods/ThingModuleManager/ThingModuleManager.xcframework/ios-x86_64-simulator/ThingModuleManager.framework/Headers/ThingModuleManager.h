//
//  ThingModuleManager.h
//  ThingModuleManager
//
//  Created by ThingInc on 2018/3/20.
//

#import <Foundation/Foundation.h>

// 一个用来提供快速方法的类
#import "ThingModule.h"

@interface ThingModuleManager : NSObject

+ (_Nonnull instancetype)sharedInstance;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

- (void)loadConfig;

/*
 if you need to use ThingModuleManager in extension or widget
 call this method once before you use it
 */
- (void)extensionDidFinishInitial;

@end

