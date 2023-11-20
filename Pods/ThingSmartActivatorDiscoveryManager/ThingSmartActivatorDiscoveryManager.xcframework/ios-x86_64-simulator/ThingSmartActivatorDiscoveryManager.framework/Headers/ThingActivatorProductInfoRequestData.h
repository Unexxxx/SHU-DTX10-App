//
//  ThingActivatorProductInfoRequestData.h
//  ThingActivatorModule
//
//  Created by qisong on 2022/3/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingActivatorProductInfoRequestData : NSObject
@property (nonatomic, copy) NSString *productId;
@property (nonatomic, copy) NSString *uuid;
@property (nonatomic, copy) NSString *mac;
@end

NS_ASSUME_NONNULL_END
