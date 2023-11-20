//
//  ThingGroupBaseError.h
//  ThingGroupManagerKit
//
//  Created by yuheng on 2023/6/16.
//

#import "ThingGroupDef.h"

NS_ASSUME_NONNULL_BEGIN

extern NSErrorDomain const ThingGroupBaseErrorDomain;

@interface ThingGroupBaseError : NSObject

/*
 失败回调示例
 {
     "groupId": "xxxx",
     "failureList": [{
         "devId": "xxx",
         "errorCode": 1
     }, {
         "devId": "xxx",
         "errorCode": 1
     }],
     "error": {
         "errorCode": 1,
         "errorMsg": "xxx"
     }
 }
 */

/// 根据error生成失败信息
/// @param error error
+ (NSDictionary *)makeFailureInfoWithError:(NSError *)error;

///  根据groupId和failureList生成失败信息
/// @param groupId groupId
/// @param failureList failureList
+ (NSDictionary *)makeFailureInfoWithGroupId:(NSString *)groupId
                                 failureList:(NSArray <NSDictionary *> *)failureList;

/// mesh类设备添加错误码转化为标砖错误码
/// @param code mesh错误码
+ (ThingGroupErrorType)standardErrorCodeWithMeshCode:(NSInteger)code;

@end

NS_ASSUME_NONNULL_END
