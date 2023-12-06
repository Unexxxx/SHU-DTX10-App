//
//  ThingDeviceTimerManager+Utils.h
//  ThingDeviceDetailKit
//
//  Created by 后主 on 2023/8/24.
//

#import "ThingDeviceTimerManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceTimerManager (Utils)

- (BOOL)isDeviceSupportBleTimer:(NSString *)deviceId;

- (BOOL)isDeviceWifiOnline:(NSString *)deviceId;

- (BOOL)isDeviceBleOnline:(NSString *)deviceId;

- (NSDictionary *)schemaDictOfDeviceId:(NSString *)deviceId;


@end

NS_ASSUME_NONNULL_END
