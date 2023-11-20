//
//  ThingSmartAProductGuideData.h
//  ThingActivatorSktAPI
//
//  Created by qisong on 2022/3/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartAProductGuideInfo : NSObject
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *content;
@property (nonatomic, strong) NSString *url;
@end

@interface ThingSmartAProductGuideData : NSObject
@property (nonatomic, strong) NSArray <ThingSmartAProductGuideInfo *>*guideInfo;
@end

NS_ASSUME_NONNULL_END
