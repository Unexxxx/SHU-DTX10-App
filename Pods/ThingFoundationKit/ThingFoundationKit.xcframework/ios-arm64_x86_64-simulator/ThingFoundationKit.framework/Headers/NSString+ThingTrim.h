//
//  NSString+ThingTrim.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/3/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (ThingTrim)

- (NSString *)thing_trimWithWhitespaceAndNewline;
- (NSString *)thing_trimWithCharacterSet:(NSCharacterSet *)set;

@end

NS_ASSUME_NONNULL_END
