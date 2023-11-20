//
//  ThingGroupBaseService.h
//  ThingGroupManagerKit
//
//  Created by yuheng on 2021/6/25.
//

#import <Foundation/Foundation.h>
#import "ThingGroupServiceProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/// 只实现移除群组方法
@interface ThingGroupBaseService : NSObject <ThingGroupServiceProtocol>

@end

NS_ASSUME_NONNULL_END
