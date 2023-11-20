//
//  ThingSmartDeviceCategoryModel.h
//  ThingActivatorRequestSktImpl
//
//  Created by qisong on 2022/3/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartALinkModeModel, ThingSmartDeviceCategoryDisplayModel, ThingSmartALeadModel;

@interface ThingSmartDeviceCategoryModel : NSObject

@property (nonatomic, copy) NSString *icon; ///< 设备图标
@property (nonatomic, copy) NSString *name; ///< 设备名称
@property (nonatomic, copy) NSString *activatorDes; ///< 配网方式：wifi、zigbee、蓝牙等
@property (nonatomic, copy) NSString *pid; ///< 设备 pid
@property (nonatomic, copy) NSString *sale; ///< "即将推出",  有就返回，没有则为空
@property (nonatomic, assign) BOOL enableLead; ///< 是否支持详细引导
@property (nonatomic, strong) ThingSmartDeviceCategoryDisplayModel *display;
@property (nonatomic, strong) NSArray<ThingSmartALinkModeModel *> *linkModes;

@property (nonatomic, assign) BOOL nProcess; ///< 是否为EZ/AP流程, 否则为混合流程
@property (nonatomic, assign) BOOL fromFeedback; ///< 反馈之后的流程

#pragma mark 待删除
@property (nonatomic, assign) long long capability; ///< 子设备有在使用，待删除(需有新的方案替换)
@property (nonatomic, copy) NSString *category; ///< 目前仅打点里使用


/// 根据类型返回 Link Mode 数据
/// - Parameter linkMode: `ThingLinkMode`
- (ThingSmartALinkModeModel * _Nullable)linkModeWithType:(NSInteger)linkMode;

/// 是否是多步配网引导
/// - Parameter linkMode: `ThingLinkMode`
- (BOOL)hasDetailPrepareWithType:(NSInteger)linkMode;

@end

NS_ASSUME_NONNULL_END
