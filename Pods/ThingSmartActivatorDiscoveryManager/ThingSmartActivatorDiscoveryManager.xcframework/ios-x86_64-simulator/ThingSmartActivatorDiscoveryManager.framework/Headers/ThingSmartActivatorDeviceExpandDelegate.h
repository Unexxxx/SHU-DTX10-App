//
//  ThingSmartActivatorDeviceExpandDelegate.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by huangjj on 2022/10/24.
//

#import <Foundation/Foundation.h>
#import "ThingSmartActivatorTypeModel.h"
#import "ThingSmartActivatorDeviceModel.h"
#import "ThingSmartActivatorErrorModel.h"
#import "ThingSmartActivatorParam.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartActivatorDeviceExpandDelegate <NSObject>

@optional

#pragma mark - hardware
/// Response information from the device (required for AP/BLE/Broadband service).
/// @param service Network configuration instance.
/// @param type Network configuration type.
/// @param response Response information from the device.
/// For Wi-Fi network configuration errors:
///   - response: ActivatorConfigResponse
///     - response.response: ActivatorConfigResponseConfigWifi
/// @param errorModel Error returned by the device.
- (void)activatorService:(id<ThingSmartActivatorActiveProtocol>)service
           activatorType:(ThingSmartActivatorTypeModel *)type
      didReceiveResponse:(id __nullable)response
                   error:(nullable ThingSmartActivatorErrorModel *)errorModel;

#pragma mark - beacon

/// Batch network configuration completed, only supports beacon devices.
- (void)beaconServiceDidFinishConfigAllDevices;

#pragma mark - matter

/// Matter commission establish complet, model's type will be known.
/// @param deviceModel Device model.
- (void)matterCommissioningSessionEstablishmentComplete:(ThingSmartActivatorDeviceModel *)deviceModel;

/// Matter device attestation fail, use `-continueCommissioningDevice:ignoreAttestationFailure:error:` to continue OR interrupt.
///
/// **Notice**
/// Usually app will display a alert view to user, allowing the user to judge whether to ignore the attestation fail.
///
/// @param device the failure device.
/// @param error the failure error info.
- (void)matterDeviceAttestation:(void *)device error:(NSError * _Nonnull)error;

/// System matter support operation complete.
/// @param gatewayName gateway device name.
- (void)matterSupportComplete:(NSString *)gatewayName;

/// Discoveryed Matter Device.
/// @param typeModel device type model
- (void)matterDeviceDiscoveryed:(ThingMatterDeviceDiscoveriedType *)typeModel;


@end

NS_ASSUME_NONNULL_END
