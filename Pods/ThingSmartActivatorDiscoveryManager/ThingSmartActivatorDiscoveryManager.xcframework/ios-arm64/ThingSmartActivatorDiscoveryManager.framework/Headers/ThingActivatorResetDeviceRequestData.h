//
//  ThingActivatorResetDeviceRequestData.h
//  ThingActivatorModule
//
//  Created by qisong on 2022/3/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingActivatorResetDeviceRequestData : NSObject
@property (nonatomic, copy) NSArray *tokens;
@property (nonatomic, copy) NSArray *devIds;
@end

NS_ASSUME_NONNULL_END
