//
//  ThingSmartActivatorDiscoverySerializer.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by Jesse Zhou on 2021/8/27.
//

#import <Foundation/Foundation.h>
#import "ThingSearchActivatorEnum.h"

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartActivatorDeviceModel;

/// Search Result Processing
@protocol ThingSmartActivatorDiscoverySerializer <NSObject>

@optional

/// Determine if a search result is valid for a device.
/// @param model Search result
- (BOOL)isDeviceModelValid:(ThingSmartActivatorDeviceModel *)model;


/// Custom processing for search results.
/// @param model Newly found device in the search
/// @param list List of current devices found in the search
/// @return Return the processed device
- (nullable ThingSmartActivatorDeviceModel *)handleDeviceModel:(ThingSmartActivatorDeviceModel *)model
                                                forDeviceList:(NSArray<ThingSmartActivatorDeviceModel *> *)list;
@end

/// Default processing, can inherit this class and process search results as needed.
@interface ThingSmartActivatorDiscoveryRawSerializer : NSObject <ThingSmartActivatorDiscoverySerializer>

+ (instancetype)serializer;

@end
NS_ASSUME_NONNULL_END
