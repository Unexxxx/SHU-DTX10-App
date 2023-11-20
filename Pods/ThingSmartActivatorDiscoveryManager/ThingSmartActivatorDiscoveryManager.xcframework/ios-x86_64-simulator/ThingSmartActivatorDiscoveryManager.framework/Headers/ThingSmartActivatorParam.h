//
//  ThingSmartActivatorScanWifiParam.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by Jesse Zhou on 2022/8/16.
//

#import <Foundation/Foundation.h>
#import <ThingSmartActivatorCoreKit/ThingSmartActivatorCoreKit.h>
#import "ThingSmartActivatorType.h"
#import "ThingSmartActivatorDiscoveryError.h"

/// Resume activate event type
typedef NS_ENUM (NSInteger, ThingActivatorBleWifiConfigModelResumeActionType){
    ThingActivatorBleWifiConfigModelResumeActionTypeSetWifi = 0,//Setup wifi and pwd
    ThingActivatorBleWifiConfigModelResumeActionTypePlugPlay,//Continue Bluetooth activation
};

typedef NS_ENUM(NSUInteger, ThingActivatorMatterDeviceType) {
    ThingActivatorMatterDeviceTypeUnknown = 0,
    ThingActivatorMatterDeviceTypeThread,
    ThingActivatorMatterDeviceTypeWifi,
    ThingActivatorMatterDeviceTypeOnNetwork,
    ThingActivatorMatterDeviceTypeAP,
};

typedef NS_ENUM(NSUInteger, ThingActivatorMatterRoutingType){
    ThingActivatorMatterRoutingTypeThing             = 0,
    ThingActivatorMatterRoutingTypeSupport           = 1,
    ThingActivatorMatterRoutingTypeShare             = 2,
};

NS_ASSUME_NONNULL_BEGIN

/// Wi-Fi scanning parameters
@interface ThingSmartActivatorScanWifiParam : NSObject
/// Maximum number of requested Wi-Fi networks
@property (nonatomic, assign) NSInteger limit;
/// Timeout duration
@property (nonatomic, assign) NSTimeInterval timeInterval;
/// Device UUID identifier
@property (nullable, nonatomic, copy) NSString *uuid;

/// limit: 10, timeInterval: 5
+ (instancetype)defaultParam;

@end

/// Scanned Wi-Fi results
@interface ThingSmartActivatorScanWifiModel : NSObject
/// Wi-Fi name
@property (nonatomic, copy) NSString *ssid;
/// Signal strength
@property (nonatomic, strong) NSNumber *rssi;
///  Encryption method, where 0 indicates no encryption
@property (nonatomic, strong) NSNumber *sec;

@end

@interface ThingSmartActivatorResumeConfigWiFiParam : NSObject
/// Wi-Fi name
@property (nonatomic, copy) NSString *ssid;
/// Wi-Fi Password
@property (nullable, nonatomic, copy) NSString *password;
/// Activator mode
@property (nonatomic, assign) ThingActivatorMode mode;
/// Device UUID identifier
@property (nullable, nonatomic, copy) NSString *uuid;
/// Restore network configuration type
@property (nonatomic) ThingActivatorBleWifiConfigModelResumeActionType bleWifiActionType;

@end

@interface ThingMatterDeviceDiscoveriedType : NSObject
/// Device is Thing Device or Third Device.
@property (nonatomic, assign) BOOL isThingDevice;
/// Device Type. if is third device,devicetype will be unKnown.
@property (nonatomic, assign) ThingActivatorMatterDeviceType deviceType;
/// Routing type.
@property (nonatomic, assign) ThingActivatorMatterRoutingType routingType;
@end


NS_ASSUME_NONNULL_END
