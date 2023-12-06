//
//  ThingActivatorNBDeviceBindResponseData.h
//  ThingActivatorModule
//
//  Created by qisong on 2022/3/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingActivatorNBDeviceBindResponseData : NSObject

@property (nonatomic, strong) NSString *errorCode;
@property (nonatomic, assign) BOOL relyCloud;
@property (nonatomic, strong) NSString *iconUrl;
@property (nonatomic, strong) NSString *errorMsg;
@property (nonatomic, strong) NSString *devId;
@property (nonatomic, assign) BOOL changeSpace;
@property (nonatomic, strong) NSString *uuid;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *icon;

@property (nonatomic, strong, nullable) NSDictionary *raw;

@end

NS_ASSUME_NONNULL_END
