//
//  NSString+ThingHex.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/4/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (ThingHex)

- (NSString *)thing_hexString;
- (NSString *)thing_hexToUTF8String;

- (NSData *)thing_hexToData;
- (uint32_t)thing_hexToIntValue;

@end

NS_ASSUME_NONNULL_END
