//
//  ThingSmartActivatorDiscovery.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by Jesse Zhou on 2021/8/27.
//

#import <Foundation/Foundation.h>
#import "ThingSmartActivatorType.h"
#import "ThingSmartActivatorDiscoverySerializer.h"
#import "ThingSmartActivatorParam.h"
#import "ThingSmartActivatorConfigProtocol.h"
#import "ThingSmartActivatorSearchProtocol.h"
#import "ThingSmartActivatorActiveProtocol.h"
#import "ThingSmartActivatorDeviceExpandDelegate.h"


NS_ASSUME_NONNULL_BEGIN
@class ThingSmartActivatorDeviceModel, ThingSmartActivatorErrorModel, ThingActivatorFactoryConfig, ThingSmartActivatorDeviceConnectModel;
@protocol ThingSmartActivatorSearchDelegate,ThingSmartActivatorActiveDelegate,ThingSmartActivatorDeviceExpandDelegate;

/// Pairing device implementation class, this class implements methods from three protocols: ThingSmartActivatorConfigProtocol, ThingSmartActivatorSearchProtocol, and ThingSmartActivatorActiveProtocol.
/// The initialization method can be found in the ThingSmartActivatorConfigProtocol protocol
/// The device search method can be found in the ThingSmartActivatorSearchProtocol protocol
/// The pairing method can be found in the ThingSmartActivatorActiveProtocol
@interface ThingSmartActivatorDiscovery : NSObject<ThingSmartActivatorActiveProtocol,ThingSmartActivatorSearchProtocol,ThingSmartActivatorConfigProtocol>

@end

NS_ASSUME_NONNULL_END
