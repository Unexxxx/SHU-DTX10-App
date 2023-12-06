//
//  ThingDeviceRepeatActiveRequestData.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by huangjj on 2023/8/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceRepeatActiveRequestData : NSObject
@property (nonatomic, strong) NSString *uuid;
@property (nonatomic, assign) long long spaceId;
@end

NS_ASSUME_NONNULL_END
