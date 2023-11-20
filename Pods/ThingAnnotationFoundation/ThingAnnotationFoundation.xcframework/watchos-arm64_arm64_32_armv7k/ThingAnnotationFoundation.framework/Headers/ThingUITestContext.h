//
//  ThingUITestContext.h
//  ThingAnnotationFoundation
//
//  Created by Storm on 2021/12/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingUITestContext : NSObject

+ (instancetype)sharedInstance;

//设置环境变量，例如在startBlock中的请求对象，防止请求block直接结束
- (void)setContextParams:(id)object forKey:(NSString *)key;
- (id)getContextParams:(NSString *)key;

//设置保存变量，例如在startBlock中请求后，需要存储的值。
- (void)setUserdefault:(id)object forKey:(NSString *)key;
- (id)getUserdefault:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
