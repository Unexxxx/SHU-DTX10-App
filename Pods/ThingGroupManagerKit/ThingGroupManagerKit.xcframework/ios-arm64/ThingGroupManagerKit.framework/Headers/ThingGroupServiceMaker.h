//
//  ThingGroupServiceMaker.h
//  ThingGroupManagerKit
//
//  Created by yuheng on 2021/8/5.
//

#import <Foundation/Foundation.h>
#import "ThingGroupServiceProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingGroupServiceMaker : NSObject
/// 生成非遥控器群组服务实例
+ (id<ThingGroupServiceProtocol>)groupServiceMakerWithBuildQuery:(NSDictionary *)params;
/// 生成遥控器群组服务实例
+ (id<ThingGroupServiceProtocol>)remoteControlGroupServiceMakerWithBuildQuery:(NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
