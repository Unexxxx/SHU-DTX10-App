//
//  ThingActivatorNBDeviceBindRequestData.h
//  ThingActivatorModule
//
//  Created by qisong on 2022/3/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingActivatorNBDeviceBindRequestData : NSObject
@property (nonatomic, copy) NSString *hid;//即token
@property (nonatomic, copy) NSString *timeZone;
@property (nonatomic, assign) long long gid;//空间ID,getData
@end

NS_ASSUME_NONNULL_END
