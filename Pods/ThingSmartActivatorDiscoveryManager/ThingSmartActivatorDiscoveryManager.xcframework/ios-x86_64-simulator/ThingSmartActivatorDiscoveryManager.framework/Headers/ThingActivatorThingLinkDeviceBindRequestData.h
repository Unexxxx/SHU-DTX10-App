//
//  ThingActivatorThingLinkDeviceBindRequestData.h
//  ThingActivatorSktAPI
//
//  Created by qisong on 2022/3/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingActivatorThingLinkDeviceBindRequestData : NSObject
@property (nonatomic, copy) NSString *groupType;
@property (nonatomic, copy) NSString *uuid;
@property (nonatomic, assign) long long gid;//空间ID
@end

NS_ASSUME_NONNULL_END
