//
//  ThingSmartActivatorActiveProtocol.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by huangjj on 2022/10/20.
//

#import <Foundation/Foundation.h>
#import "ThingSmartActivatorTypeModel.h"
#import "ThingSmartActivatorDeviceModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartActivatorActiveProtocol <NSObject>

/// Activate devices with a single network configuration type
/// @param type Network configuration type
/// @param deviceList Devices to be activated
- (void)startActive:(ThingSmartActivatorTypeModel *)type deviceList:(NSArray<ThingSmartActivatorDeviceModel *>*)deviceList;

/// Stop activating devices
/// @param typeList Array of network configuration types
/// @param clearCache Whether to clear the cache
- (void)stopActive:(NSArray <ThingSmartActivatorTypeModel *>*)typeList clearCache:(BOOL)clearCache;

/// Reset unbound devices
/// @param deviceList Devices to be reset
- (void)resetUnbindDeviceList:(NSArray<ThingSmartActivatorDeviceModel *> *)deviceList;

@end


@protocol ThingSmartActivatorActiveDelegate <NSObject>


/// Device network configuration result callback
/// @param service Device network configuration implementation object
/// @param type Network configuration type
/// @param devices devices Devices being configured
/// @param errorModel Error encountered during network configuration
- (void)activatorService:(id<ThingSmartActivatorActiveProtocol>)service
           activatorType:(ThingSmartActivatorTypeModel *)type
       didReceiveDevices:(nullable NSArray<ThingSmartActivatorDeviceModel *> *)devices
                   error:(nullable ThingSmartActivatorErrorModel *)errorModel;


@end

NS_ASSUME_NONNULL_END
