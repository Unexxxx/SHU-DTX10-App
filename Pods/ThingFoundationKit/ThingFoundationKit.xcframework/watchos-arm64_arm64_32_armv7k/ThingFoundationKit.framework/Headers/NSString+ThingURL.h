//
//  NSString+ThingURL.h
//  ThingFoundationKit
//
//  Created by 尼奥 on 2023/6/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (ThingURL)

/// 拼接 URL
/// - Parameter appendUrl: 拼接在 self 之后，如果 self 和 appendUrl 之间没有 `/` 会补充；并且会处理 self 和 appendUrl 之间存在两个 `/` 的情况
- (NSString *)thing_URLAppend:(NSString *)appendUrl;


/// 拼接 URL 参数
/// - Parameter params: 会将 value 进行 url encode
- (NSString *)thing_URLAppendParams:(NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
