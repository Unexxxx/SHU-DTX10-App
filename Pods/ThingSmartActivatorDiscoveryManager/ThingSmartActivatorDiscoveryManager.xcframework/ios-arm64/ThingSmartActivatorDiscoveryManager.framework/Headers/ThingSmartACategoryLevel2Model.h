//
//  ThingSmartACategoryLevel2Model.h
//  ThingActivatorSktAPI
//
//  Created by qisong on 2022/3/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ThingSmartACategoryLevel3Model;
@interface ThingSmartACategoryLevel2Model : NSObject
@property (nonatomic, copy) NSString *name; ///< 父类名称
@property (nonatomic, copy) NSString *tagCode; ///< 父类code
@property (nonatomic, strong) NSArray<ThingSmartACategoryLevel3Model *> *level3Items; ///< 类目3数组
@end

NS_ASSUME_NONNULL_END
