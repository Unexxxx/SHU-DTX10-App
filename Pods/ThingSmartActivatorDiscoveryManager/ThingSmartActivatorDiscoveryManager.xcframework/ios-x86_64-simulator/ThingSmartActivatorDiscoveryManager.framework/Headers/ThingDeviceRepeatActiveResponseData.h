//
//  ThingDeviceRepeatActiveResponseData.h
//  ThingActivatorSktAPI
//
//  Created by 尼奥 on 2023/7/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceRepeatActiveResponseData : NSObject

@property (nonatomic, strong) NSString *devId;
@property (nonatomic) BOOL changeSpace;
@property (nonatomic, strong) NSString *groupName;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *icon;
@property (nonatomic, strong) NSString *errorCode;
@property (nonatomic, strong) NSString *iconUrl;
@property (nonatomic, strong) NSString *uuid;
@property (nonatomic, strong) NSString *errorMsg;

@property (nonatomic, strong) NSDictionary *raw;

@end

NS_ASSUME_NONNULL_END
