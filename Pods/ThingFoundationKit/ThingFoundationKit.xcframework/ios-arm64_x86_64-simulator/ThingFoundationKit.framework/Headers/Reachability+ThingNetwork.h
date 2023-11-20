//
//  Reachability+ThingNetwork.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/5/15.
//

#if TARGET_OS_IOS

#import <ThingSmartUtil/ThingSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    ThingNetworkStatusUnknown = 0,
    ThingNetworkStatusUnreachable,
    ThingNetworkStatusWWAN2G,
    ThingNetworkStatusWWAN3G,
    ThingNetworkStatusWWAN4G,
    ThingNetworkStatusWWAN5G,
    ThingNetworkStatusWiFi = 100,
} ThingNetworkStatus;

typedef void(^ThingNetworkStatusChangedHandler)(ThingNetworkStatus status);


FOUNDATION_EXTERN ThingNetworkStatus Thing_NetworkStatus(void);
FOUNDATION_EXTERN BOOL Thing_NetworkReachable(void);
FOUNDATION_EXTERN BOOL Thing_NetworkWiFiReachable(void);
/**
 return NO if connect with WiFi
 */
FOUNDATION_EXTERN BOOL Thing_NetworkWWANReachable(void);
/**
 handler will be associated to obj
 */
FOUNDATION_EXTERN void Thing_NetworkStatusChanged(NSObject *obj, ThingNetworkStatusChangedHandler handler);


@interface ThingSmartReachability (ThingNetwork)

- (ThingNetworkStatus)thing_networkStatus;

- (void)thing_addNetworkStatusObserver:(NSObject *)obj withHandler:(ThingNetworkStatusChangedHandler)handler;

@end

NS_ASSUME_NONNULL_END

#endif
