//
//  NSURL+ThingPrefs.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/5/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSURL (ThingPrefs)

+ (NSURL *)thing_appPrefsWifi;
+ (NSURL *)thing_appPrefsBLE;
+ (NSURL *)thing_appPrefsLocation;

+ (NSURL *)thing_iOSDefaultSettings;

+ (NSURL *)thing_appPrefsApplicationSetting NS_AVAILABLE_IOS(8.0);

+ (NSURL *)thing_prefsUrlWithQuery:(NSDictionary *)query;

@end

NS_ASSUME_NONNULL_END
