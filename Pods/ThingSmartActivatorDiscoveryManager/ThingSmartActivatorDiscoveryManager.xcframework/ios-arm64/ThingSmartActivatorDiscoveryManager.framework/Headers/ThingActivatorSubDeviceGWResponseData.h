//
//  ThingActivatorSubDeviceGWResponseData.h
//  ThingActivatorSktAPI
//
//  Created by Jesse Zhou on 2022/7/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingActivatorSubDeviceGWResponseData : NSObject

/// 子设备配网的网关
@property (nonatomic) NSString *devId;
/// 网关名称
@property (nonatomic) NSString *name;

@end

NS_ASSUME_NONNULL_END
