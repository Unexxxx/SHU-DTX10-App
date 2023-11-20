//
//  ThingSmartFamilyCityModel.h
//  ThingSmartFamilyBizKit
//
//  Created by huangjj on 2022/12/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartFamilyCityModel : NSObject

/// Area of the home
@property (nonatomic, strong) NSString *area;

@property (nonatomic, strong) NSString *pinyin;

/// Province of home
@property (nonatomic, strong) NSString *province;

/// City of home
@property (nonatomic, strong) NSString *city;
@property (nonatomic, strong) NSString *cityIdTxt;
@property (nonatomic, strong) NSString *cityId;

@end

NS_ASSUME_NONNULL_END
