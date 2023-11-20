//
//  ThingASActivatorActionContext.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by qisong on 2022/4/22.
//

#import <Foundation/Foundation.h>
#import "ThingSmartActivatorActionContextProtocol.h"
NS_ASSUME_NONNULL_BEGIN

@interface ThingASActivatorActionContext : NSObject<ThingSmartActivatorActionContextProtocol>
@property (nonatomic, copy) NSString *gwDevId;
@end

NS_ASSUME_NONNULL_END
