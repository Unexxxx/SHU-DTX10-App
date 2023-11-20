//
//  ThingSmartActivatorErrorModel.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by Jesse Zhou on 2021/9/24.
//

#import <Foundation/Foundation.h>
#import "ThingSmartActivatorDeviceModel.h"
#import "ThingSmartActivatorDiscoveryError.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartActivatorErrorModel : NSObject

@property (nonatomic, strong, nullable) ThingSmartActivatorDeviceModel *deviceModel;

@property (nonatomic) NSError *error;

+ (instancetype)generateError:(NSError *)error deviceModel:(ThingSmartActivatorDeviceModel *)deviceModel;

+ (instancetype)generateError:(NSError *)error activatorType:(ThingSmartActivatorType)activatorType;

/// 将云端返回的成功数据解析成错误模型
+ (instancetype _Nullable)generateWithRepsonseResult:(NSDictionary *)result;

@end

NS_ASSUME_NONNULL_END
