//
//  NSString+ThingPinyin.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/4/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (ThingPinyin)

/**
 the Chinese Pinyin of current string
 Support Japanese and Korean
 */
- (NSString *)thing_pinyin;

- (NSString *)thing_pinyinWithDiacritics;

/**
 the first letter of Pinyin
 */
- (NSString *)thing_initialsOfPinyin;

@end

NS_ASSUME_NONNULL_END
