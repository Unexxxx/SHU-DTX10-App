//
//  ThingSmartACategoryModel.h
//  ThingActivatorSktAPI
//
//  Created by qisong on 2022/3/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ThingSmartACategoryLevel1Model, ThingSmartACategoryLevel2Model, ThingSmartDeviceCategoryModel;

@interface ThingSmartACategoryModel : NSObject
@property (nonatomic, copy) NSString *superName; ///< 名称
@property (nonatomic, strong) NSArray<ThingSmartACategoryLevel1Model *> *level1List; ///< 类目一数组
@property (nonatomic, strong) NSArray<ThingSmartACategoryLevel2Model *> *defaultLevel2List; ///< 类目一对应的类目二数组
@property (nonatomic, strong) NSArray<ThingSmartDeviceCategoryModel *> *defaultWglist; ///< 网关模型数组
@end

NS_ASSUME_NONNULL_END
