//
//  NSLocale+ThingLanguage.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/3/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN NSString * Thing_SystemLanguage(void);
FOUNDATION_EXTERN NSString * Thing_SystemLanguageCode(void) __deprecated_msg("Use Thing_SystemLanguage() instead");
FOUNDATION_EXTERN BOOL Thing_IsChineseLanguage(void);

@interface NSLocale (ThingLanguage)

/**
 This method will get current app language and not system language,
 if user switch language in the app, this method can get the changed
 language. Try not to use [[NSBundle mainBundle] preferredLocalizations]
 or [NSLocale preferredLanguages].
 */
+ (NSString *)thing_systemLanguage;

/**
 Deprecated method, this method is same as thing_systemLanguage.
 */
+ (NSString *)thing_systemLanguageCode __deprecated_msg("Use thing_systemLanguage instead");

+ (BOOL)thing_isChineseLanguate;

@end

NS_ASSUME_NONNULL_END
