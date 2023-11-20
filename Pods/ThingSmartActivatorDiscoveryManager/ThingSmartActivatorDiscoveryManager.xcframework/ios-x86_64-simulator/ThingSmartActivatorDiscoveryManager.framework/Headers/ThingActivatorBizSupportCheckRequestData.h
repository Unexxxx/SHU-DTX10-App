//
//  ThingActivatorBizSupportCheckRequestData.h
//  ThingActivatorSktAPI
//
//  Created by heye on 2023/7/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingActivatorBizSupportCheckRequestData : NSObject
@property (nonatomic, copy) NSString *bizId;
@property (nonatomic, assign) NSInteger bizType;
@property (nonatomic, assign) NSInteger actualBizType;
@property (nonatomic, copy) NSString *bizCodes; // gateway_batch_add_room
@end

NS_ASSUME_NONNULL_END
