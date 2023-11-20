//
//  ThingGroupBeaconService.h
//  ThingGroupManagerKit
//
//  Created by jesse on 2021/5/28.
//

#import "ThingGroupBaseService.h"
#import "ThingGroupServiceProtocol.h"
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>


NS_ASSUME_NONNULL_BEGIN

/// 本地 Beacon 操作 error domain
extern NSErrorDomain const ThingBluetoothBeaconErrorDomain;

@interface ThingGroupBeaconService : ThingGroupBaseService <ThingGroupServiceProtocol>

/// 群组 ID，只有通过“修改群组的始化”才有
@property (nonatomic, copy, readonly, nullable) NSString *groupId;
/// 1.从设备进入的群组页面，入参
@property (nonatomic, copy, readonly, nullable) NSString *devId;

/// Beacon 群组可以添加的设备
/// @param deviceModel 设备模型   
- (BOOL)isBeaconGroupSupportDevice:(ThingSmartDeviceModel *)deviceModel;

#pragma mark - Timer -
/// 取消定时   
- (void)timerInvalidate;
@end

NS_ASSUME_NONNULL_END
