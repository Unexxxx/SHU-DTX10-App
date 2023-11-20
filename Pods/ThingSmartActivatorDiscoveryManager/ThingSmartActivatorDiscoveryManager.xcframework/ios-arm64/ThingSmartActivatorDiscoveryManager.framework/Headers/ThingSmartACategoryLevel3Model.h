//
//  ThingSmartACategoryLevel3Model.h
//  ThingActivatorSktAPI
//
//  Created by qisong on 2022/3/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartACategoryLevel3Model : NSObject
@property (nonatomic, copy) NSString *icon; ///< 设备图标
@property (nonatomic, copy) NSString *name; ///< 设备名称
@property (nonatomic, copy) NSString *pid;  ///< 设备 pid
@property (nonatomic, copy) NSString *sale; ///< "即将推出",  有就返回，没有则为空
@property (nonatomic, assign) long long capability;
@property (nonatomic, copy) NSString *attribute;
@property (nonatomic, copy) NSString *category;
@property (nonatomic, copy) NSString *activatorDes; ///< 配网方式：wifi、zigbee、蓝牙等
@end

NS_ASSUME_NONNULL_END
