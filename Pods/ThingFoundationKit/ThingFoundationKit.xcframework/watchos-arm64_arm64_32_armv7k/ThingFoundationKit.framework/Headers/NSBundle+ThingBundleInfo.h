//
//  NSBundle+ThingBundleInfo.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/4/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN NSDictionary * Thing_MainBundleInfoDictionary(void);

FOUNDATION_EXTERN id Thing_MainBundleInfoWithKey(NSString * key);

FOUNDATION_EXTERN NSString * Thing_MainBundleId(void);         /**< [NSBundle mainBundle].thing_bundleId */
FOUNDATION_EXTERN NSString * Thing_MainBundleName(void);       /**< [NSBundle mainBundle].thing_bundleName */
FOUNDATION_EXTERN NSString * Thing_MainBundleVersion(void);    /**< [NSBundle mainBundle].thing_bundleVersion */

FOUNDATION_EXTERN NSString * Thing_AppName(void);              /**< [NSBundle mainBundle].thing_bundleName */
FOUNDATION_EXTERN NSString * Thing_AppVersion(void);           /**< [NSBundle mainBundle].thing_bundleVersion */

/**
 @return return YES if info.plist contains value for key "NSExtension"
 */
FOUNDATION_EXTERN BOOL Thing_IsExtensionBundle(void);


@interface NSBundle (ThingBundleInfo)

- (NSString *)thing_bundleId;

/**
 bundle short verion string
 */
- (NSString *)thing_bundleVersion;

/**
 if bundle localized display name is not nil, return it
 else if bundle display name is not nil, return it
 else return bundle name
 */
- (NSString *)thing_bundleName;

@end

NS_ASSUME_NONNULL_END
