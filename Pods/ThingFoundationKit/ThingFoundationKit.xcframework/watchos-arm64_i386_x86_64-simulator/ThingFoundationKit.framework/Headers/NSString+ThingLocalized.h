//
//  NSString+ThingLocalized.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/12/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (ThingLocalized)
@property (nonatomic, readonly) NSString *thing_localized;

/// Use localizedString from MainBundle if found, otherwise search from the Placehold Bundle
+ (NSString *)thing_localized:(NSString *)key placeholdBundle:(NSBundle *)bundle;

@end

NS_ASSUME_NONNULL_END
