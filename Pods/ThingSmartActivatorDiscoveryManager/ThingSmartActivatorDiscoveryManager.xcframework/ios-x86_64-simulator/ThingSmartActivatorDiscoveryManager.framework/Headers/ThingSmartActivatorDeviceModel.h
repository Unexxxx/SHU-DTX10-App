//
//  ThingSmartActivatorDeviceModel.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by huangjj on 2019/3/14.
//

#import <Foundation/Foundation.h>
#import <ThingSmartPairingCoreKit/ThingSmartPairingCoreKit.h>
#import "ThingSearchActivatorEnum.h"
#import "ThingSmartActivatorType.h"

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartDeviceModel;

// Default name for the gateway, used when the actual name of the gateway cannot be retrieved, default name = @"Smart Gateway"
FOUNDATION_EXPORT NSString *const ThingSmartActivatorDiscoveryWiredServiceDefaultName;

/// Device Model
@interface ThingSmartActivatorDeviceModel : NSObject

/// Device unique identifier
@property (nonatomic, readonly, copy) NSString *uniqueID;

/// Device virtual ID, devId is the virtual ID assigned by the cloud after the device completes the network configuration. It is empty before the network configuration.
@property (nonatomic, copy) NSString *devId;

/// Device Type
@property (nonatomic, assign) ThingSearchDeviceModelType deviceModelType;
/// Device network configuration type
@property (nonatomic, assign) ThingSmartActivatorType activatorType;
/// Device capabilities
@property (nonatomic, assign) ThingActivatorDeviceAbility deviceAbility;
/// Device status
@property (nonatomic, assign) ThingSearchDeviceStatus  deviceStatus;
/// Pairing step
@property (nonatomic, assign) ThingActivatorStep step;
/// Device name
@property (nonatomic, copy) NSString *name;
/// Device icon URL
@property (nonatomic, copy, nullable) NSString *iconUrl;
/// Product Id
@property (nonatomic, copy, nullable) NSString *productId;

/// Error
//@property (nonatomic, strong, nullable) NSError *error;
//@property (nonatomic, strong) ThingSmartActivatorErrorModel *errorModel;

/// Whether the device supports 5GHz network, default NO
@property (nonatomic, assign) BOOL isSupport5G;

/// Reserved extension information
@property (nonatomic, strong, nullable) NSMutableArray<ThingSmartActivatorDeviceModel *> *deviceLists;

/// Reserved extension information
@property (nonatomic, copy, nullable) NSDictionary *userInfo;

@property (nonatomic, strong, nullable) NSError *error;


/// Initializes the device object with a unique identifier.
/// @param uniqueId The unique identifier of the device.
/// @return An instance of the device object.
- (instancetype)initWithUniqueID:(NSString *)uniqueId;

/// Initializes the device object with a device model.
/// @param deviceModel The device model containing information about the device.
/// @return An instance of the device object.
- (instancetype)initWithDeviceModel:(ThingSmartDeviceModel*)deviceModel;

/// Determines whether the device pairing process is dependent on WiFi authentication information.
/// @return YES if the device pairing process requires WiFi authentication, NO otherwise.
- (BOOL)needWiFiAuthentication;

/// Checks if the device supports the Plug&Play capability.
/// @return YES if the device supports Plug&Play capability, NO otherwise.
- (BOOL)supportAbilityPlugPlay;

/// Checks if the device supports the Pegasus capability.
/// @return YES if the device supports Pegasus capability, NO otherwise.
- (BOOL)supportAbilityPegasus;

/// Checks if the device supports the HomeKit capability.
/// @return YES if the device supports HomeKit capability, NO otherwise.
- (BOOL)supportAbilityHomeKit;

/// Checks if the device supports Bluetooth-ZigBee capability.
/// @return YES if the device supports Bluetooth-ZigBee capability, NO otherwise.
- (BOOL)supportAbilityBleZigbee;

/// Checks if the device supports Bluetooth priority.
/// @return YES if the device supports Bluetooth priority, NO otherwise.
- (BOOL)supportAbilityBlePrior;

/// Checks if the device supports Bluetooth QR code pairing.
/// @return YES if the device supports Bluetooth QR code pairing, NO otherwise.
- (BOOL)supportAbilityBleQRCode;

/// Checks if the device supports Matter.
/// @return YES if the device supports Matter, NO otherwise.
- (BOOL)supportAbilityMatter;

/// Checks if the device supports Matter Fabric.
/// @return YES if the device supports Matter Fabric, NO otherwise.
- (BOOL)supportAbilityMatterFabric;


/// Checks if the device has not scanned any Thread network.
/// @return YES if the device has not scanned any Thread network, NO otherwise.
- (BOOL)deviceScanNoneThread;

/// Returns the scanned gateway.
/// @return gatewayId Return the gateway id if scanned.
- (NSString *)deviceScanThreadGateway;

/// Checks if two devices are of the same model.
/// @return YES if the two devices are of the same model, NO otherwise.
- (BOOL)isEqualToDevice:(ThingSmartActivatorDeviceModel *)aDevice;

/// Checks if the device is Thing matter Device.
/// @return YES if the Device is Thing Matter Device, NO otherwise.
- (BOOL)isThingDevice;
@end

NS_ASSUME_NONNULL_END

