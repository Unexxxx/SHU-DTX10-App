//
//  ThingGroupMakerHelper.h
//  ThingGroupManagerKit
//
//  Created by yuheng on 2021/8/11.
//

#import <Foundation/Foundation.h>
#import "ThingGroupDef.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingGroupMakerHelper : NSObject

/// 根据设备id返回业务类型
+ (ThingGroupBizType)groupBizTypeFromDeviceId:(NSString *)devId;
/// 根据群组id返回页面类型
+ (ThingGroupBizType)groupBizTypeFromGroupId:(NSString *)groupId;

@end

NS_ASSUME_NONNULL_END
