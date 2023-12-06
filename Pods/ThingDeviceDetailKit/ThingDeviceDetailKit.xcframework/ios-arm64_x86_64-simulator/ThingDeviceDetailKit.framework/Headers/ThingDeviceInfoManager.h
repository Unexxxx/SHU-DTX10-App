//
//  ThingDeviceInfoManager.h
//  ThingDeviceDetailKit
//
//  Created by 后主 on 2023/8/17.
//

#import <Foundation/Foundation.h>
#import "ThingDeviceDetailInfo.h"
@class ThingDeviceInfoManager;


NS_ASSUME_NONNULL_BEGIN

@protocol ThingDeviceInfoManagerListener <NSObject>
@optional
- (void)deviceInfoManager:(ThingDeviceInfoManager *)manager wifiSignalDidUpdate:(int)wifiSignal;

@end



@interface ThingDeviceInfoManager : NSObject
- (instancetype)initWithDeviceId:(NSString *)deviceId;

- (nullable ThingDeviceDetailInfo *)deviceInfo;

- (void)addListener:(id<ThingDeviceInfoManagerListener>)listener;
- (void)removeListener:(id<ThingDeviceInfoManagerListener>)listener;
- (void)fetchDataSuccess:(void(^)(ThingDeviceDetailInfo *info, NSDictionary *hardwareInfo))success failure:(void(^)(NSError *error))failure;
@end

NS_ASSUME_NONNULL_END
