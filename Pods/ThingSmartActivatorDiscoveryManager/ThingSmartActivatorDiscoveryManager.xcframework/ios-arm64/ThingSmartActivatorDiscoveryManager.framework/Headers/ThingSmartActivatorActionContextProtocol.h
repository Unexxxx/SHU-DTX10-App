//
//  ThingSmartActivatorActionContextProtocol.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by qisong on 2022/4/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartActivatorActionContextProtocol <NSObject>
/// Gateway ID for sub-device pairing, used to search for Zigbee sub-devices under the current gateway
/// This field is empty for other network configuration methods
@property (nonatomic, readonly, copy, nullable) NSString *gwDevId;
@end

NS_ASSUME_NONNULL_END
