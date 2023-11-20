//
//  ThingDeviceDetailInfo.h
//  ThingDeviceDetailKit
//
//  Created by 后主 on 2023/8/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingDeviceInfoConnectAbility) {
    ThingDeviceInfoConnectAbilityUnknown = 0,
    ThingDeviceInfoConnectAbilityPhone = 1,
    ThingDeviceInfoConnectAbilityGateway = 2,
    ThingDeviceInfoConnectAbilityPhoneAndGateway = 3,
};

@interface ThingDeviceDetailInfo : NSObject <NSCopying>

/// the id of the device
@property (nonatomic, copy) NSString *devId;

/// iccid
@property (nonatomic, copy, nullable) NSString *iccid;

/// netStrength
@property (nonatomic, copy, nullable) NSString *netStrength;

/// lan ip address
@property (nonatomic, copy, nullable) NSString *lanIp;

/// ip address
@property (nonatomic, copy, nullable) NSString *ip;

/// mac address
@property (nonatomic, copy, nullable) NSString *mac;

/// timezone
@property (nonatomic, copy, nullable) NSString *timezone;

/// channel
@property (nonatomic, copy, nullable) NSString *channel;

/// rsrp
@property (nonatomic, strong, nullable) NSNumber *rsrp;

/// signal
@property (nonatomic, strong, nullable) NSNumber *wifiSignal;

/// homekit code
@property (nonatomic, copy, nullable) NSString *homekitCode;

/// connect ability
@property (nonatomic, assign) ThingDeviceInfoConnectAbility connectAbility;

/// the name of vendor
@property (nonatomic, copy, nullable) NSString *vendorName;

@end

NS_ASSUME_NONNULL_END
