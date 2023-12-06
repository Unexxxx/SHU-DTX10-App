//
//  ThingSearchActivatorEnum.h
//  ThingSearchActivatorModule
//
//  Created by huangjj on 2019/6/21.
//

#ifndef ThingSearchActivatorEnum_h
#define ThingSearchActivatorEnum_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Device Type
typedef enum : NSUInteger {
    ThingSearchDeviceModelTypeUnknow = 0,
    ThingSearchDeviceModelTypeWifi,    /// WiFi Devices
    ThingSearchDeviceModelTypeWired,  /// Wired devices (Zigbee wired gateway, wired camera, low-power base station, router)
    ThingSearchDeviceModelTypeBleMeshSubDevice, /// Mesh devices
    ThingSearchDeviceModelTypeBleMeshGateway,   /// Mesh Gateway
    ThingSearchDeviceModelTypeBle,    /// BLE Devices
    ThingSearchDeviceModelTypeBleWifi,    /// Bluetooth dual-mode devices
    ThingSearchDeviceModelTypeBleZigbee,   /// Bluetooth-ZigBee dual-mode devices
    ThingSearchDeviceModelTypeHomeKit, /// HomeKit devices
    ThingSearchDeviceModelTypeSigMeshSubDevice, /// SIG Mesh devices
    ThingSearchDeviceModelTypeSubDevice,  /// Sub device (zigbee, 433)
    ThingSearchDeviceModelTypePegasus, /// Pegasus (WiFi, Bluetooth dual-mode devices)
    ThingSearchDeviceModelTypeBleLTE,    /// Bluetooth LTE devices (Cat.1)
    ThingSearchDeviceModelTypeBeacon,    /// Bluetooth Beacon
    ThingSearchDeviceModelTypeMatterWired,  /// Gateway(Matter)
    ThingSearchDeviceModelTypeMatterWifi, /// WiFi(Matter)
    ThingSearchDeviceModelTypeMatterThread, /// Thread
    ThingSearchDeviceModelTypeMQTTDirectly, /// MQTT direct-connected devices  (cat.1,GPRS)
    ThingSearchDeviceModelTypeNB, /// NB Devices
    ThingSearchDeviceModelTypeEnd,
} ThingSearchDeviceModelType;

/// Device capabilities during the network configuration process. A real device may have multiple capabilities, such as a dual-mode device that has capabilities like Lightning, Plug&Play, etc.
typedef NS_OPTIONS(NSUInteger, ThingActivatorDeviceAbility) {
    ThingActivatorDeviceAbilityUnknown = 0,
    ThingActivatorDeviceAbilityPegasus = (1 << 0),  /// Pegasus ⚡️ capability
    ThingActivatorDeviceAbilityHomeKit = (1 << 1),    /// HomeKit capability
    ThingActivatorDeviceAbilityPlugPlay = (1 << 2),  /// Plug&Play capability
    ThingActivatorDeviceAbilityBlePrior = (1 << 3), /// Bluetooth priority
    ThingActivatorDeviceAbilityBleQRCode = (1 << 4), /// Bluetooth device, configured through scanning QR code
    ThingActivatorDeviceAbilityMatterBle = (1 << 5), /// Matter BLE capability
    ThingActivatorDeviceAbilityMatterOnNetwork = (1 << 6), /// Matter wired capability
    ThingActivatorDeviceAbilityMatterFabric = (1 << 7), /// Matter Fabric capability
};

/// Device Status
typedef enum : NSUInteger {
    ThingSearchDeviceStatusDefault = 0,
    ThingSearchDeviceStatusNoNetwork,    /// Not connected to the network
    ThingSearchDeviceStatusNetwork,      /// Network connectivity status
    ThingSearchDeviceStatusRetry,        /// Retryable status
    ThingSearchDeviceStatusFailure,      /// Failure status
} ThingSearchDeviceStatus;

NS_ASSUME_NONNULL_END

#endif /* ThingSearchActivatorEnum_h */
