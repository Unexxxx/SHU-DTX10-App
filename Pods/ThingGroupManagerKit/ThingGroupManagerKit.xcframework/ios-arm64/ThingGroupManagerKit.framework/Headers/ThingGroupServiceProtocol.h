//
//  ThingGroupServiceProtocol.h
//  Pods
//
//  Created by yuheng on 2023/6/19.
//

#import <Foundation/Foundation.h>
#import "ThingGroupDef.h"

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartDeviceModel;

@protocol ThingGroupServiceProtocol <NSObject>

@optional
#pragma mark 初始化
/// 根据devId初始化群组实例--创建群组
/// @param devId devId
- (instancetype)initWithDevId:(NSString *)devId;

/// 根据groupId初始化群组实例--编辑群组
/// @param groupId groupId
- (instancetype)initWithGroupId:(NSString *)groupId;

/// 设置当前家庭的设备列表   适用于私有Mesh群组、普通SIGMesh群组、Beacon群组
- (void)setCurrentSpaceDeviceList:(NSArray<ThingSmartDeviceModel*> *)deviceList;


/// 初始化Zigbee遥控器实例
/// @param devId 遥控器devId
/// @param localId localId
/// @param categoryCode categoryCode非三级品类编码，云端用于判断处理遥控器群组  zigbee遥控器有单分组和8分组的区别，单分组为8001，8分组为3001-3008
/// @param codes 二级品类code
- (instancetype)initWithDevId:(NSString *)devId
                      localId:(NSString *)localId
                 categoryCode:(NSString *)categoryCode
                        codes:(NSArray *)codes;

/// 初始化遥控器实例-- 旧版本 SIGMesh遥控器
/// @param devId 遥控器devId
/// @param localId localId
/// @param pccs  pcc过滤条件
- (instancetype)initWithDevId:(NSString *)devId
                      localId:(NSString *)localId
                         pccs:(NSArray *)pccs;

/// 初始化遥控器实例--- 新版本 SIGMesh遥控器
/// @param devId 遥控器devId
/// @param localId localId
/// @param categoryCode  并非三级品类，与localId匹配范围为7001-7008；localId 为云端分配，步长为8，因此一个遥控器内部最多支持关联8个群组，localid为初始值依次+1，与之匹配的categoryCode从7001依次+1.
/// @param filterType 类型 ，0:pccs 、1:codes，旧面板无此字段，作为新旧面板区分标志，旧面板走之前本地逻辑，新面板走云端
/// @param pccs mesh category
/// @param codes 二级品类code
- (instancetype)initWithDevId:(NSString *)devId
                      localId:(NSString *)localId
                 categoryCode:(nullable NSString *)categoryCode
                   filterType:(nullable NSString *)filterType
                         pccs:(NSArray *)pccs
                        codes:(nullable NSArray *)codes;

#pragma mark - 群组的创建和编辑
/// 获取群组下符合条件的设备列表
/// @param result 设备列表
/// @param failure failure
- (void)fetchDeviceListWithSuccess:(ThingGroupDevListResult)result
                           failure:(void(^)(NSError *error))failure;


/// 创建群组--将设备加入群组   遥控器群组不需要此步骤
/// @param name 群组名字
/// @param deviceList 待添加设备列表
/// @param process 进度信息 {"total":5,"current":1}
/// @param result 成功回调 {"groupId":"xxx"}
/// @param failure 失败回调  {"groupId":"xxxx","failureList":[{"devId":"xxx","errorCode":1},{"devId":"xxx","errorCode":1}],"error":{"errorCode":1,"errorMsg":"xxx"}}  优先解析error信息，error不存在时解析failureList，failureList为失败设备列表
- (void)createGroupWithName:(NSString *)name
                 deviceList:(NSArray <NSString *> *)deviceList
                    process:(ThingGroupProcess)process
                    success:(ThingGroupSuccess)result
                    failure:(ThingGroupResultFailure)failure;

/// 更新群组
/// @param deviceList 选中的设备列表
/// @param process 进度信息 {"total":5,"current":1}
/// @param result 成功回调 {"groupId":"xxx"}
/// @param failure 失败回调 {"groupId":"xxxx","failureList":[{"devId":"xxx","errorCode":1},{"devId":"xxx","errorCode":1}],"error":{"errorCode":1,"errorMsg":"xxx"}}  优先解析error信息，error不存在时解析failureList，failureList为失败设备列表
- (void)updateGroupWithDeviceList:(NSArray <NSString *> *)deviceList
                             process:(ThingGroupProcess)process
                             success:(ThingGroupSuccess)result
                          failure:(ThingGroupResultFailure)failure;

#pragma mark - 删除群组
/// 删除群组（支持正常群组和分享的群组移除）  --- 遥控器群组不支持
/// @param groupId 群组id
/// @param success 成功回调
/// @param failure 失败回调
- (void)removeGroupWithGroupId:(NSString *)groupId
                       success:(void (^)(void))success
                       failure:(void (^)(NSError *error))failure;

@end


NS_ASSUME_NONNULL_END

