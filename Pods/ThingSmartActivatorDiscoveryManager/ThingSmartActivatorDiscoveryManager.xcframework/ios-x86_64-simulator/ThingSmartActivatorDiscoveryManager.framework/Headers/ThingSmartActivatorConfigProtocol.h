//
//  ThingSmartActivatorConfigProtocol.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by huangjj on 2022/10/18.
//

#import <Foundation/Foundation.h>
#import "ThingSmartActivatorDiscoverySerializer.h"
#import "ThingSmartActivatorTypeModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartActivatorConfigProtocol <NSObject>

@required

/// Start the basic configuration, this method needs to be called after the APP starts.
- (void)loadConfig;

/// Initialize network configuration types
/// @param typeList Network configuration types
- (void)registerWithActivatorList:(NSArray<ThingSmartActivatorTypeModel *>*)typeList;

/// Configure delegate object
/// @param delegate Delegate
- (void)setupDelegate:(nullable id)delegate;

/// Remove delegate object
/// @param delegate Delegate
- (void)removeDelegate:(nullable id)delegate;

@optional

// Retrieve specific network configuration type information
/// @param type Network configuration type
/// @return Network configuration type information
- (ThingSmartActivatorTypeModel *)activatorTypeModelWith:(ThingSmartActivatorType)type;

/// Retrieve all network configuration type models
/// @return Network configuration type list
- (NSArray<ThingSmartActivatorTypeModel *>*)getActivatorList;

/// Configure input and output serializers
/// @param serializer Serializer object
- (void)setupSerializer:(id<ThingSmartActivatorDiscoverySerializer>)serializer;

/// Retrieve the configured input and output serializer object
/// @return Serializer object
- (id<ThingSmartActivatorDiscoverySerializer>)getSerializer;

@end

NS_ASSUME_NONNULL_END
