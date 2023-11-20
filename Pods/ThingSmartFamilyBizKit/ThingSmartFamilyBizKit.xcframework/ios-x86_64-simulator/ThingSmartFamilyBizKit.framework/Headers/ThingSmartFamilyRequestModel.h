//
//  ThingSmartFamilyRequestModel.h
//  ThingSmartFamilyBizKit
//
//  Created by 柒松 on 2023/8/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartFamilyRequestModel : NSObject
/// Family name
@property (nonatomic, copy) NSString *name;

/// Name of the area where the family is located
@property (nonatomic, copy) NSString *geoName;

/// Latitude of home area
@property (nonatomic, assign) double latitude;

/// Longitude of home area
@property (nonatomic, assign) double longitude;

/// Array of rooms in a family
@property (nonatomic, copy) NSArray<NSString *> *rooms;
@end

NS_ASSUME_NONNULL_END
