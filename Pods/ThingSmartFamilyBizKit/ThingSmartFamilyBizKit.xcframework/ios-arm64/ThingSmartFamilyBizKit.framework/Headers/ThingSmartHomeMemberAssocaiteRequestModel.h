//
//  ThingSmartHomeMemberAssocaiteRequestModel.h
//  ThingSmartFamilyBizKit
//
//  Created by 柒松 on 2023/9/4.
//

#import <Foundation/Foundation.h>
#import <ThingSmartDeviceKit/ThingSmartHomeModelUtils.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartHomeMemberAssocaiteRequestModel : NSObject
/// Member Unique Identifier
@property (nonatomic, assign) long long memberId;

/// Country code of member's account
@property (nonatomic, copy) NSString *countryCode;

/// Member's account
@property (nonatomic, copy) NSString *account;

/// Member's role
@property (nonatomic, assign) ThingHomeRoleType role;
@end

NS_ASSUME_NONNULL_END
