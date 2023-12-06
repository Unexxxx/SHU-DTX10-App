//
//  ThingSmartFamilyDeviceGroupOrderRequestModel.h
//  ThingSmartFamilyBizKit
//
//  Created by 柒松 on 2023/9/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingSmartFamilyParentBizType) {
    ThingSmartFamilyParentBizTypeGroup = 5,
    ThingSmartFamilyParentBizTypeDevice = 6,
};

@interface ThingSmartFamilyDeviceGroupOrderRequestModel : NSObject
/// bizType is ThingSmartFamilyParentBizTypeGroup, bizId is groupId;
/// bizType is ThingSmartFamilyParentBizTypeDevice, bizId is deviceId
@property (nonatomic, copy) NSString *bizId;

/// Type of Sorted Objects
@property (nonatomic, assign) ThingSmartFamilyParentBizType bizType;
@end

NS_ASSUME_NONNULL_END
