//
//  NSURL+ThingPrefs.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/5/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSURL (ThingPrefs)

/// Open the Settings page for the specified app in iOS Settings App
+ (NSURL *_Nullable)thing_appPrefsApplicationSetting NS_AVAILABLE_IOS(8.0);

/// App’s notification settings in the Settings app
+ (NSURL *_Nullable)thing_notificationSettings;

#pragma mark - deprecated

+ (NSURL *_Nullable)thing_appPrefsWifi __deprecated_msg("This method is deprecated, Use -thing_appPrefsApplicationSetting instead");
+ (NSURL *_Nullable)thing_appPrefsBLE __deprecated_msg("This method is deprecated, Use -thing_appPrefsApplicationSetting instead");;
+ (NSURL *_Nullable)thing_appPrefsLocation __deprecated_msg("This method is deprecated, Use -thing_appPrefsApplicationSetting instead");;
+ (NSURL *_Nullable)thing_iOSDefaultSettings __deprecated_msg("This method is deprecated, Use -thing_appPrefsApplicationSetting instead");;
+ (NSURL *_Nullable)thing_prefsUrlWithQuery:(NSDictionary *)query  __deprecated_msg("This method is deprecated, Use -thing_appPrefsApplicationSetting instead");;

@end

NS_ASSUME_NONNULL_END
