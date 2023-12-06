//
//  NSString+ThingCharacterSequence.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/5/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (ThingCharacterSequence)

/**
 character at index will be discarded if it is sequences(such as Emoji) when ignore is YES
 ignore default: NO
 */
- (NSString *)thing_substringFromIndex:(NSUInteger)index ignoreCharacterSequence:(BOOL)ignore;
- (NSString *)thing_substringToIndex:(NSInteger)index ignoreCharacterSequence:(BOOL)ignore;
- (NSString *)thing_substringWithRange:(NSRange)range ignoreCharacterSequence:(BOOL)ignore;

@end

NS_ASSUME_NONNULL_END
