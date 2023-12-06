//
//  ThingSmartActivatorWifiProtocol.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by huangjj on 2023/5/10.
//

#import <Foundation/Foundation.h>
#import "ThingSmartActivatorParam.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartActivatorWifiProtocol <NSObject>

/// Scan nearby Wi-Fi networks for devices.
/// @param param Scan parameters
/// @param activatorType Network configuration type (supports AP and dual-mode)
/// @param success Success block
/// @param failure Failure block
- (void)scanWifiList:(ThingSmartActivatorScanWifiParam *)param
       activatorType:(ThingSmartActivatorType)activatorType
             success:(void(^)(NSArray<ThingSmartActivatorScanWifiModel *> *list))success
             failure:(void(^)(NSError * _Nullable error))failure;

/// Restore Wi-Fi network configuration
/// @param param Restore network configuration parameters
/// @param activatorType Network configuration type
/// @param success Success block
/// @param failure Failure block
- (void)resumeConfigWifi:(ThingSmartActivatorResumeConfigWiFiParam *)param
           activatorType:(ThingSmartActivatorType)activatorType
                 success:(void(^)(void))success
                 failure:(void(^)(ThingSmartActivatorErrorModel * _Nullable error))failure;
@end

NS_ASSUME_NONNULL_END
