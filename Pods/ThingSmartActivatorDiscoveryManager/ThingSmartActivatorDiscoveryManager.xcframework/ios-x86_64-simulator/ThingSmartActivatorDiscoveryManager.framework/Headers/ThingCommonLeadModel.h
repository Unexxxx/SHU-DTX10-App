//
//  ThingCommonLeadModel.h
//  ThingActivatorModule
//
//  Created by 龙卷 on 2019/12/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingActivatorLeadModel;
@interface ThingCommonLeadModel : NSObject

@property (nonatomic, strong) NSArray<ThingActivatorLeadModel *> *activatorLeadList;

@end

@interface ThingActivatorLeadModel : NSObject

@property (nonatomic, copy) NSString *desText;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *iconUrl;

@end

NS_ASSUME_NONNULL_END
