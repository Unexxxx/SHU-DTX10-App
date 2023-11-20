//
//  NSString+ThingEmpty.h
//  AFNetworking
//
//  Created by 津渡 on 2020/6/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (ThingEmpty)

- (BOOL)isValid;
- (NSString *)thing_safeString;

@end

NS_ASSUME_NONNULL_END
