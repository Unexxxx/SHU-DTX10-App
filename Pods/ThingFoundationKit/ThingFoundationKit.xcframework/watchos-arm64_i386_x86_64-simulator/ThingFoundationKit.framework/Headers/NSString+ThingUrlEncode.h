//
//  NSString+ThingUrlEncode.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/3/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (ThingUrlEncode)

- (NSString *)thing_urlEncode;
- (NSString *)thing_urlDecode;

@end

NS_ASSUME_NONNULL_END
