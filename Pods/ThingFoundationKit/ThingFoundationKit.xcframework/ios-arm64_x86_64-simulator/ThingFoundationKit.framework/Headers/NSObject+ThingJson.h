//
//  NSObject+ThingJson.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/3/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (ThingJson)

+ (id)thing_objectFromJson:(NSString *)json;

- (NSString *)thing_jsonString;

@end

NS_ASSUME_NONNULL_END
