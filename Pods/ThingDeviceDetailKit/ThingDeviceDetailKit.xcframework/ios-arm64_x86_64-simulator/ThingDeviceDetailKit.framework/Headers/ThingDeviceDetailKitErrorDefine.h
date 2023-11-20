//
//  ThingDeviceDetailKitErrorDefine.h
//  ThingDeviceDetailKit
//
//  Created by 后主 on 2023/8/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 通用错误
extern NSErrorDomain const ThingDeviceDetailKitErrorDomain;

typedef NS_ENUM(NSInteger, ThingDeviceDetailKitError) {
    ThingDeviceDetailKitDeviceNullError = -10001, //device is nil
    ThingDeviceDetailKitDeviceOfflineError = -10002, //device is offline
    ThingDeviceDetailKitTimerExtraError = -10003, //get data extra of timer fail
    ThingDeviceDetailKitTimerBleTransmissionTimeoutError = -10004, //ble transmission time out
    ThingDeviceDetailKitTimerBleDataParseError = -10005, //ble data parse error
    ThingDeviceDetailKitTimerDeviceCannotSyncError = -10006, //device can not sync
};



/// 蓝牙协议层错误
extern NSErrorDomain const ThingDeviceTimerBleSyncErrorDomain;

/// 操作失败原因
typedef NS_ENUM(NSInteger, ThingDeviceTimerBleSyncErrorCode) {
    /// 取不到错误码（数据为空，数据字节过短）
    ThingTimerBleTimerProtocolErrorCode_DataError = -1,
    /// 协议层只定义了一种错误码 0x01
    ThingTimerBleTimerProtocolErrorCode_Unknow  = 0x01
};

NS_ASSUME_NONNULL_END
