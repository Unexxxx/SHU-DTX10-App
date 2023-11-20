//
//  ThingSmartActivatorBleProtocol.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by huangjj on 2022/10/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartActivatorBleProtocol <NSObject>

/// Configure Wi-Fi channel for Bluetooth dual-mode devices (Bluetooth channel is already activated), the result is provided through network configuration callback
/// @param activatorType Network configuration type, please use ActivatorTypeBleModel
/// @param deviceModel Device model
- (void)configMultimodeDeviceDualWifiChannel:(ThingSmartActivatorTypeModel *)activatorType
                                       model:(ThingSmartActivatorDeviceModel *)deviceModel;

/// Activate Bluetooth channel for Bluetooth dual-mode devices (only activate Bluetooth), the result is provided through network configuration callback
/// @param activatorType Network configuration type, please use ThingSmartActivatorTypeBleModel
/// @param deviceModel Device model
- (void)configMultimodeDeviceDualBleChannel:(ThingSmartActivatorTypeModel *)activatorType
                                      model:(ThingSmartActivatorDeviceModel *)deviceModel;

/// Switching ble-zigbee devices to a sub-device pairing network
/// @param activatorType Network configuration type, please use ThingSmartActivatorTypeBleModel
/// @param devices ble-zigbee devices
/// @param success Successful callback
/// @param failure Failure callback
- (void)switchZigbeeSubDeviceToZigbeeActivator:(ThingSmartActivatorTypeModel *)activatorType
                                       devices:(NSArray<ThingSmartActivatorDeviceModel *> *)devices
                                       success:(ThingSuccessHandler)success
                                       failure:(ThingFailureError)failure;

/// Set current home ID
/// @param spaceId home ID
- (void)currentSpaceId:(long long)spaceId; 
@end

NS_ASSUME_NONNULL_END
