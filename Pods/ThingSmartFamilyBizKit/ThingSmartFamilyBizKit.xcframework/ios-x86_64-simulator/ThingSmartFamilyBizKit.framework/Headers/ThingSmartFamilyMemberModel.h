//
//  ThingSmartFamilyMemberModel.h
//  ThingSmartFamilyBizKit
//
//  Created by 柒松 on 2023/9/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartFamilyMemberModel : NSObject
/// Member Unique Identifier
@property (nonatomic, assign) long long memberId;

/// Members' avatars
@property (nonatomic, copy) NSString *headPic;
@end

NS_ASSUME_NONNULL_END
