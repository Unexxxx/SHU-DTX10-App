//
//  NSData+ThingStringEncoding.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/5/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (ThingStringEncoding)

- (NSString *)thing_UTF8String;
- (NSString *)thing_hexString;
- (NSString *)thing_base64String;

- (NSString *)thing_stringWithEncode:(NSStringEncoding)encode;

@end

NS_ASSUME_NONNULL_END
