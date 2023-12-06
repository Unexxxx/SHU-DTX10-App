//
//  ThingSmartActivatorTypeModel.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by huangjj on 2022/10/18.
//

#import <Foundation/Foundation.h>
#import "ThingASActivatorServiceAction.h"
#import "ThingSmartActivatorType.h"
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

typedef NS_ENUM(NSInteger,ThingActivatorBleScanType){
    ThingActivatorBleScanTypeNoraml = 1 << 0, //  0001  1
    ThingActivatorBleScanTypeQRCode = 1 << 1, //  0010  2
};

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartActivatorTypeModel : NSObject
/// Network configuration type
@property (nonatomic, assign) ThingSmartActivatorType type;
/// Network configuration type name
@property (nonatomic, copy) NSString *typeName;
/// Extended behavior during network configuration process
@property (nonatomic, strong) ThingASActivatorServiceAction *action;
/// Timeout
@property (nonatomic, assign) NSTimeInterval timeout;
@property (nonatomic, copy, nullable) NSDictionary *extensions; // 配网扩展信息
@end


/// EZ
@interface ThingSmartActivatorTypeEZModel : ThingSmartActivatorTypeModel
/// Wi-Fi name
@property (nonatomic, copy) NSString * _Nullable ssid;
/// Wi-Fi password
@property (nonatomic, copy) NSString * _Nullable password;
/// Pairing token
@property (nonatomic, copy) NSString *token;
/// Home ID
@property (nonatomic, assign) long long spaceId;
@end

/// Ap
@interface ThingSmartActivatorTypeAPModel : ThingSmartActivatorTypeModel
/// Wi-Fi name
@property (nonatomic, copy) NSString * _Nullable ssid;
/// Wi-Fi password
@property (nonatomic, copy) NSString * _Nullable password;
/// Pairing token
@property (nonatomic, copy) NSString *token;
/// Security certificate configuration for PSK AP network configuration
@property (nonatomic, copy, nullable) NSDictionary *securityConfig;
/// Home ID
@property (nonatomic, assign) long long spaceId;

@end

/// QRCode
@interface ThingSmartActivatorTypeQRCodeModel : ThingSmartActivatorTypeModel
/// Wi-Fi name
@property (nonatomic, copy) NSString * _Nullable ssid;
/// Wi-Fi password
@property (nonatomic, copy) NSString * _Nullable password;
/// Pairing token
@property (nonatomic, copy) NSString *token;
/// Home ID
@property (nonatomic, assign) long long spaceId;
@end


/// Router
@interface ThingSmartActivatorTypeRouterModel : ThingSmartActivatorTypeModel
@property (nonatomic, strong) NSArray <ThingSmartDeviceModel *> *routerActiveDeviceList;
/// Pairing token
@property (nonatomic, strong) NSString *token;
@end

/// Auto
@interface ThingSmartActivatorTypeAutoModel : ThingSmartActivatorTypeModel
@property (nonatomic, strong) NSArray <ThingSmartDeviceModel *> *autoActiveSupportedDeviceList;
/// Pairing token
@property (nonatomic, strong) NSString *token;
@end

/// SigMesh
@interface ThingSmartActivatorTypeSigMeshModel : ThingSmartActivatorTypeModel
/// Home ID
@property (nonatomic, assign) long long spaceId;
@end


/// BleMesh
@interface ThingSmartActivatorTypeBleMeshModel : ThingSmartActivatorTypeModel
/// Home ID
@property (nonatomic, assign) long long spaceId;
/// Wi-Fi name
@property (nonatomic, strong) NSString *ssid;
/// Wi-Fi password
@property (nonatomic, strong) NSString *password;
/// Pairing token
@property (nonatomic, strong) NSString *token;

@end


/// Ble
@interface ThingSmartActivatorTypeBleModel : ThingSmartActivatorTypeModel
/// Ble Scan Type
@property (nonatomic, assign) ThingActivatorBleScanType scanType;
/// Home ID
@property (nonatomic, assign) long long spaceId;
/// Pairing token (only used for Bluetooth fallback pairing)
@property (nonatomic, strong) NSString *token;
/// Wi-Fi name
@property (nonatomic, strong) NSString *ssid;
/// Wi-Fi password
@property (nonatomic, strong) NSString *password;
/// Gateway ID
@property (nonatomic, copy) NSString *gwDevId;
@end

/// Homekit
@interface ThingSmartActivatorTypeHomeKitModel : ThingSmartActivatorTypeModel
/// Home ID
@property (nonatomic, assign) long long spaceId;
@end

/// Matter
@interface ThingSmartActivatorTypeMatterModel : ThingSmartActivatorTypeModel
/// Home ID
@property (nonatomic, assign) long long spaceId;
/// Pairing token
@property (nonatomic, strong) NSString *token;
/// Gateway ID
@property (nonatomic, copy) NSString *gwDevId;
/// Wi-Fi name
@property (nonatomic, strong) NSString *ssid;
/// Wi-Fi password
@property (nonatomic, strong) NSString *password;
@end

/// Pegasus
@interface ThingSmartActivatorTypePegasusModel : ThingSmartActivatorTypeModel
/// Devices that support pegasus pairing act as a server to send pairing packets.
@property (nonatomic, copy) NSArray<NSString *> *pegasusServerDevIDs;
/// Home ID
@property (nonatomic, assign) long long spaceId;
/// Pairing token
@property (nonatomic, strong) NSString *token;
/// Gateway ID
@property (nonatomic, copy) NSString *gwDevId;
@end

/// Wired
@interface ThingSmartActivatorTypeWiredModel : ThingSmartActivatorTypeModel
/// Pairing token
@property (nonatomic, strong) NSString *token;
/// Home ID
@property (nonatomic, assign) long long spaceId;
@end

/// subDevice
@interface ThingSmartActivatorTypeSubDeviceModel : ThingSmartActivatorTypeModel
/// Gateway ID
@property (nonatomic, copy) NSString *gwDevId;
@end

/// NB
@interface ThingSmartActivatorTypeNBModel : ThingSmartActivatorTypeModel
/// NB device ID
@property (nonatomic, copy) NSString *nbId;
/// Pairing token
@property (nonatomic, assign) long long spaceId;
@end

/// TuyaLink
@interface ThingSmartActivatorTypeThingLinkModel : ThingSmartActivatorTypeModel
/// Device UUID identifier
@property (nonatomic, copy) NSString *uuid;
/// Home ID
@property (nonatomic, assign) long long spaceId;
@end

/// Virtual
@interface ThingSmartActivatorTypeVirtualModel : ThingSmartActivatorTypeModel
/// Product ID
@property (nonatomic, copy) NSString *productId;
/// Pairing token
@property (nonatomic, copy) NSString *token;
/// Home ID
@property (nonatomic, assign) long long spaceId;
@end

/// ApDirectly
@interface ThingSmartActivatorTypeApDirectlyModel : ThingSmartActivatorTypeModel
/// Device UUID identifier
@property (nonatomic, copy) NSString *uuid;
@end

/// MQTT Directly
@interface ThingSmartActivatorTypeMQTTDirectlyModel : ThingSmartActivatorTypeModel
/// Device UUID identifier
@property (nonatomic, copy) NSString *uuid;
@property (nonatomic, assign) long long spaceId;
@end

@interface ThingSmartActivatorTypeBroadbandModel : ThingSmartActivatorTypeModel
@property (nonatomic, strong) NSDictionary *parameter;
/// Pairing token
@property (nonatomic, copy) NSString *token;
/// Home ID
@property (nonatomic, assign) long long spaceId;
@end

@interface ThingSmartActivatorTypeInstallCodeModel : ThingSmartActivatorTypeModel
/// Gateway ID
@property (nonatomic, copy) NSString *gwDevId;
/// Install codes list
@property (nonatomic, strong) NSArray<NSDictionary *> *installCodes;
@end

@interface ThingSmartActivatorTypeBeaconModel: ThingSmartActivatorTypeModel
@end


NS_ASSUME_NONNULL_END
