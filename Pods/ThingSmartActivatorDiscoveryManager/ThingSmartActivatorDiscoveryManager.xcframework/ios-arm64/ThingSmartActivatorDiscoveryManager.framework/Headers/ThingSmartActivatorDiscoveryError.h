//
//  ThingSmartActivatorDiscoveryError.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by Jesse Zhou on 2022/1/14.
//

#import <Foundation/Foundation.h>


FOUNDATION_EXPORT NSErrorDomain const ThingSmartActivatorDiscoveryErrorDomain;


typedef enum : NSUInteger {
    ThingSmartActivatorDiscoveryErrorDefault = 0,
    
    ThingSmartActivatorDiscoveryErrorConfigInfoError = 1,
    
    ThingSmartActivatorDiscoveryErrorRouterNotFound = 2,
    
    ThingSmartActivatorDiscoveryErrorWrongPassword = 3,
    
    ThingSmartActivatorDiscoveryErrorRouterConnectFailed = 4,
    
    ThingSmartActivatorDiscoveryErrorDHCPError = 5,
    
    
    ThingSmartActivatorDiscoveryErrorSubDeviceOverLimit = 201,
    
    ThingSmartActivatorDiscoveryErrorZigbeeSubDeviceReportError = 402,
    
    ThingSmartActivatorDiscoveryErrorZigbeeGatewayReportError = 403,
    
    
    ThingSmartActivatorDiscoveryErrorTimeout = 1512,
    
    
    ThingSmartActivatorDiscoveryErrorBleScanExpired = 3700,
    
    ThingSmartActivatorDiscoveryErrorResumeConfigInfoError = 3701,
    
    ThingSmartActivatorDiscoveryErrorResumeRouterNotFound = 3702,
    
    ThingSmartActivatorDiscoveryErrorResumeWrongPassword = 3703,
    
    ThingSmartActivatorDiscoveryErrorResumeRouterConnectFailed = 3704,
    
    ThingSmartActivatorDiscoveryErrorResumeDHCPError = 3705,
    
    ThingSmartActivatorDiscoveryErrorWanNotConnected = 3706,
    
    ThingSmartActivatorDiscoveryErrorPPPOEInfoError = 3707,
    
    ThingSmartActivatorDiscoveryErrorNoNetwork= 3708,
    
    ThingSmartActivatorDiscoveryErrorDeviceNotConnectMQTT = 3709,
    
    ThingSmartActivatorDiscoveryErrorDeviceActiveRepeated = 3710,
    
    ThingSmartActivatorDiscoveryErrorDeviceAlreadyBound = 3711,
    
    ThingSmartActivatorDiscoveryErrorGuestNotSupportStrongBind = 3712,
    
    ThingSmartActivatorDiscoveryErrorAPPUnsupportProduct = 3713,
    
    ThingSmartActivatorDiscoveryErrorAPPUnsupportUUID = 3714,
    
    ThingSmartActivatorDiscoveryErrorDeviceForLocationOverLimit = 3715,
    
    ThingSmartActivatorDiscoveryErrorDeviceHasResetFactory = 3716,
    
    ThingSmartActivatorDiscoveryErrorProducNotExists = 3717,
    
    ThingSmartActivatorDiscoveryErrorTokenExpired = 3718,
    
    ThingSmartActivatorDiscoveryErrorPermissionDenied = 3719,
    
    ThingSmartActivatorDiscoveryErrorUserSessionLoss = 3720,
    
    ThingSmartActivatorDiscoveryErrorRemoteApiParamLoss = 3721,
    
    ThingSmartActivatorDiscoveryErrorRemoteApiParamBlank = 3722,
    
    ThingSmartActivatorDiscoveryErrorRemoteApiParamIllegal = 3723,
    
    ThingSmartActivatorDiscoveryErrorResumeInvalidParamters = 3724,
    
    ThingSmartActivatorDiscoveryErrorResumeNotInPairing = 3725,
    
    ThingSmartActivatorDiscoveryErrorResumeOnlyAPPairingSupported = 3726,
    
    ThingSmartActivatorDiscoveryErrorResumeAPDirectNotSupported = 3728,
    
    ThingSmartActivatorDiscoveryErrorResumeInvalidDeviceUUID = 3729,
    
    ThingSmartActivatorDiscoveryErrorResumeDeviceNotSupported = 3730,
    
    ThingSmartActivatorDiscoveryErrorResumeDeviceIPNotFound = 3731,
    
    ThingSmartActivatorDiscoveryErrorResumeFailedToConnectWiFi = 3732,
    
    ThingSmartActivatorDiscoveryErrorResumeDeviceNotExist = 3733,
    
    ThingSmartActivatorDiscoveryErrorFailedActiveBeaconDevice = 3734,

    // 通用的错误信息，表示后端遇到需要在 App UI 中显示设备错误信息
    ThingSmartActivatorDiscoveryErrorCommonDeviceActive = 4000
    
} ThingSmartActivatorDiscoveryError;

