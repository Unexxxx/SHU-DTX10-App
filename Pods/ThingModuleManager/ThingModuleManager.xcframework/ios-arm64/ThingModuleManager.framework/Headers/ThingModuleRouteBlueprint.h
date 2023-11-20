//
//  ThingModuleRouteBlueprint.h
//  ThingModuleManager
//
//  Created by ThingInc on 2018/8/21.
//

#import <Foundation/Foundation.h>

#import "ThingModuleBaseBlueprint.h"
#import <ThingAnnotationFoundation/ThingAnnotationFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingModuleRouteInfo;

@protocol ThingModuleRouteBlueprint <ThingModuleBaseBlueprint>

/**
 scheme、path、query will be ignore
 */
- (void)registRoute:(NSString *)route forModule:(id)module;
- (void)unregistRoute:(NSString *)route;

- (void)registRoute:(NSString *)route inViewController:(Class)vc;
//- (void)registRoute:(NSString *)route inViewController:(UIViewController *)vc inMethod:(NSString *)method startBlock:(_ThingRouterBlock)block endBlock:(_ThingRouterResultBlock)endBlock;

- (nullable id)moduleOfRoute:(NSString *)route;


- (BOOL)canOpenRoute:(NSString *)route;

/**
 scheme、path、query will passthrough to the handle impl
 */
- (BOOL)openRoute:(NSString *)route withParams:(nullable NSDictionary *)params;
/**
scheme、path、query 、callBack will passthrough to the handle impl
attention：because of connecting to Flutter，result in callBack must be serializable（可序列化）
*/
- (BOOL)openRoute:(NSString *)route withParams:(nullable NSDictionary *)params callBack:(void(^)(NSDictionary *result))callBack;

- (void)registerUnhandledRoute:(BOOL(^)(NSString *scheme, NSString *host, NSString *path, NSDictionary *params))callback;

@end

NS_ASSUME_NONNULL_END
