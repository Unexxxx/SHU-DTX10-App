//
//  ThingSmartActivatorSearchProtocol.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by huangjj on 2022/10/20.
//

#import <Foundation/Foundation.h>
#import "ThingSmartActivatorTypeModel.h"
#import "ThingSmartActivatorDeviceModel.h"
#import "ThingSmartActivatorErrorModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartActivatorSearchProtocol <NSObject>

/// Start searching
/// @param typeList Network configuration types
- (void)startSearch:(NSArray <ThingSmartActivatorTypeModel *>*)typeList;

/// Stop searching
/// @param typeList Network configuration types
/// @param clearCache Whether to clear the cache
- (void)stopSearch:(NSArray <ThingSmartActivatorTypeModel *>*)typeList clearCache:(BOOL)clearCache;

@end

@protocol ThingSmartActivatorSearchDelegate <NSObject>

/// Device search callback
/// @param service Search instance
/// @param type Network configuration type
/// @param device Discovered device
/// @param errorModel Error callback
- (void)activatorService:(id<ThingSmartActivatorSearchProtocol>)service
            activatorType:(ThingSmartActivatorTypeModel *)type
             didFindDevice:(nullable ThingSmartActivatorDeviceModel *)device
                     error:(nullable ThingSmartActivatorErrorModel *)errorModel;

@optional
/// Device information update or device rediscovered on a different channel
/// @param service Search instance
/// @param type Network configuration type
/// @param device Device model
- (void)activatorService:(id<ThingSmartActivatorSearchProtocol>)service
            activatorType:(ThingSmartActivatorTypeModel *)type
           didUpdateDevice:(ThingSmartActivatorDeviceModel *)device;
@end



NS_ASSUME_NONNULL_END
