//
//  NSString+ThingLanguage.h
//  ThingFoundationKit
//
//  Created by Hemin Won on 2023/3/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (ThingLanguage)

/// 纯中文
- (BOOL)isChinese;

/// 包含中文
- (BOOL)includeChinese;

@end

NS_ASSUME_NONNULL_END
