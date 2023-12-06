//
//  ThingDeviceTimerBleSyncTask.h
//  ThingDeviceDetailKit
//
//  Created by 后主 on 2023/8/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceTimerBleSyncTask : NSObject

@property (nonatomic, copy, readonly) NSString *deviceId;

/// 任务唯一标识，只是用来 debug
@property (nonatomic, copy, readonly) NSString *identifier;

/// 指令的 Data
@property (nonatomic, readonly) NSData *data;

/// 任务描述信息
@property (nullable, nonatomic, copy) NSString *desc;

@property (nullable, nonatomic, copy, readonly) void(^completion)(NSData * _Nullable data, NSError *_Nullable error);


+ (instancetype)taskWithDeviceId:(NSString *)deviceId identifier:(NSString *)identifier data:(NSData *)data completion:(void(^)(NSData * _Nullable data, NSError *_Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
