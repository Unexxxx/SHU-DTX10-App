//
//  NSNotificationCenter+ThingDefaultCenter.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/5/15.
//

#import <Foundation/Foundation.h>


/**
 post directly if current thread is main, async to main thread otherwise
 */
FOUNDATION_EXTERN void Thing_PostNotification(NSString * _Nonnull name, NSDictionary * _Nullable userInfo);

NS_ASSUME_NONNULL_BEGIN

@interface NSNotificationCenter (ThingDefaultCenter)

+ (void)thing_addObserver:(id)obj withName:(NSString *)name selector:(SEL)sel;

/**
 @param dictionary NSDictionary<NotificationName, NSStringFromSelector>
 */
+ (void)thing_addObserver:(id)obj withDictionary:(NSDictionary<NSString *, NSString *> *)dictionary;


/**
 post directly if current thread is main, async to main thread otherwise
 */
+ (void)thing_postNotificationAsyncOnMain:(NSString *)name;
+ (void)thing_postNotificationAsyncOnMain:(NSString *)name withUserInfo:(nullable NSDictionary *)userInfo;


@end

NS_ASSUME_NONNULL_END
