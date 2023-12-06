//
//  ThingSmartActivatorBeaconProtocol.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by huangjj on 2022/11/18.
//

#import <Foundation/Foundation.h>
#import "ThingSmartActivatorTypeModel.h"
#import "ThingSmartActivatorDeviceModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartActivatorBeaconProtocol <NSObject>

/// Stop network configuration for specific devices (currently only implemented for beacon)
/// @param type Network configuration type
/// @param deviceList List of devices for which network configuration needs to be stopped
- (void)stopActive:(ThingSmartActivatorTypeModel *)type devicelist:(NSArray<ThingSmartActivatorDeviceModel *>*)deviceList clearCache:(BOOL)clearCache;


@end

NS_ASSUME_NONNULL_END
