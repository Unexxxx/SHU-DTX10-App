//
//  ThingACTEZUnvailabilityResponseData.h
//  ThingActivatorSktAPI
//
//  Created by qisong on 2022/9/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingACTEZUnavailabilityScrop : NSObject
@property (nonatomic, copy) NSString *min;
@property (nonatomic, copy) NSString *max;
@end

@interface ThingACTEZUnvailabilityResponseData : NSObject
@property (nonatomic, copy) NSArray <ThingACTEZUnavailabilityScrop *>*scrops;
@property (nonatomic, copy) NSArray <ThingACTEZUnavailabilityScrop *>*matterScrops;
@end

NS_ASSUME_NONNULL_END
