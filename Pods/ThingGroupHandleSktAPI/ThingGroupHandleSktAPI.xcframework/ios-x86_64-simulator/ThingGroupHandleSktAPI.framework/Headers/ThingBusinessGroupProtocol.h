//
//  ThingBusinessGroupProtocol.h
//  Pods
//
//  Created by yuheng on 2022/5/25.
//

#import <Foundation/Foundation.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^ThingFailureError)(NSError *error);
typedef void (^ThingSuccessHandler)(void);

@protocol ThingBusinessGroupProtocol <NSObject>

@required

#pragma mark - home 相关信息

- (long long)getCurrentSpaceId;

- (NSArray<ThingSmartDeviceModel*> *)deviceListForCurrentSpace;

- (NSArray<ThingSmartGroupModel *> *)groupListForCurrentSpace;

- (NSString *)getsubSpaceNameWithDevice:(ThingSmartDevice *)device;

#pragma mark - deviceKit 实现

// 普通WiFi群组：创建群组时，拉取列表
- (void)getDevListWithProductId:(NSString *)productId
                        spaceId:(long long)spaceId
                        success:(nullable void(^)(NSArray <ThingSmartGroupDevListModel *> *list))success
                        failure:(nullable ThingFailureError)failure;

// 普通WiFi群组、普通 Zigbee 群组：编辑时查询设备列表
- (void)getDevListWithGroup:(ThingSmartGroup *)group
                  productId:(NSString *_Nullable)productId
                    success:(nullable void(^)(NSArray <ThingSmartGroupDevListModel *> *list))success
                    failure:(nullable ThingFailureError)failure;

// 普通WiFi群组：创建群组
- (void)createGroupWithName:(NSString *)name
                  productId:(NSString *)productId
                    spaceId:(long long)spaceId
                  devIdList:(NSArray<NSString *> *)devIdList
                    success:(nullable void (^)(ThingSmartGroup *group))success
                    failure:(nullable ThingFailureError)failure;

// 普通Wifi 群组：更新群组
- (void)updateGroupRelationsWithGroup:(ThingSmartGroup *)group
                              devList:(NSArray <NSString *>*)devList
                              success:(nullable ThingSuccessHandler)success
                              failure:(nullable ThingFailureError)failure;

// 标准WiFi群组：新建群组时查询设备列表
- (void)getDpCodeDevListWithSpaceId:(long long)spaceId
                          productId:(NSString *)productId
                            success:(nullable void(^)(NSArray <ThingSmartGroupDevListModel *> *list))success
                            failure:(nullable ThingFailureError)failure;

// 标准WiFi群组：编辑群组时查询设备列表
- (void)getDpCodeDevListWithGroup:(ThingSmartGroup *)group
                          success:(nullable void(^)(NSArray <ThingSmartGroupDevListModel *> *list))success
                          failure:(nullable ThingFailureError)failure;

// 标准WiFi群组：创建群组
- (void)createDpCodeGroupWithName:(NSString *)name
                          spaceId:(long long)spaceId
                        productId:(NSString *)productId
                        devIdList:(NSArray<NSString *> *)devIdList
                          success:(nullable void (^)(ThingSmartGroup *group))success
                          failure:(nullable ThingFailureError)failure;

// 标准WiFi群组：编辑群组
- (void)updateDpCodeGroupRelationsWithGroup:(ThingSmartGroup *)group
                                    devList:(NSArray <NSString *>*)devList
                                    success:(nullable ThingSuccessHandler)success
                                    failure:(nullable ThingFailureError)failure;

// 普通zigbee群组：新建群组时查询设备列表
- (void)getDevListWithProductId:(NSString *)productId
                           gwId:(NSString *)gwId
                        spaceId:(long long)spaceId
                        success:(nullable void (^)(NSArray<ThingSmartGroupDevListModel *> *))success
                        failure:(nullable ThingFailureError)failure;

// 普通zigbee群组：创建群组
- (void)createGroupWithName:(NSString *)name
                    spaceId:(long long)spaceId
                       gwId:(NSString *)gwId
                  productId:(NSString *)productId
                    success:(nullable void (^)(ThingSmartGroup *))success
                    failure:(nullable ThingFailureError)failure;

// 普通zigbee群组、标准 Zigbee 群组：从群组移除设备
- (void)removeZigbeeDeviceWithGroup:(ThingSmartGroup *)group
                           nodeList:(NSArray <NSString *>*)nodeList
                            success:(nullable ThingSuccessHandler)success
                            failure:(nullable ThingFailureError)failure;

// 普通zigbee群组、标准 Zigbee 群组：向群组添加设备
- (void)addZigbeeDeviceWithGroup:(ThingSmartGroup *)group
                        nodeList:(NSArray <NSString *>*)nodeList
                         success:(nullable ThingSuccessHandler)success
                         failure:(nullable ThingFailureError)failure;

// 标准 Zigbee 群组：创建群组
- (void)createDpCodeGroupWithName:(NSString *)name
                          spaceId:(long long)spaceId
                        productId:(NSString *)productId
                           devIds:(NSArray<NSString *> *)devIds
                           meshId:(NSString *)meshId
                          success:(nullable void (^)(ThingSmartGroup *group))success
                          failure:(nullable ThingFailureError)failure;

// 普通thread群组：创建时获取设备列表
- (void)getThreadDevListWithProductId:(NSString *)productId
                           gwId:(NSString *)gwId
                        spaceId:(long long)spaceId
                        success:(nullable void (^)(NSArray<ThingSmartGroupDevListModel *> *))success
                              failure:(nullable ThingFailureError)failure;

// 普通thread群组：创建群组
- (void)createThreadGroupWithName:(NSString *)name
                          spaceId:(long long)spaceId
                             gwId:(NSString *)gwId
                        productId:(NSString *)productId
                        devIdList:(NSArray<NSString *> *)devIdList
                          success:(nullable void (^)(ThingSmartGroup *))success
                          failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
