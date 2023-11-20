//
//  ThingRegisterRouterProtocol.h
//  ThingAnnotationFoundation
//
//  Created by Storm on 2022/2/6.
//

#import "ThingBaseAnnotation.h"

@protocol ThingRegisterRouterProtocol <NSObject>

@optional
//路由处理函数，返回YES的话即认为已经处理，否则走默认逻辑。
//例如处理路由的逻辑非常复杂，即可在此方法中实现处理并返回YES，就不走默认的push实现
+ (BOOL)routerDistribute:(NSString *)router;

//路由优先级，默认是EAnnotationPriorityBase（0）
+ (NSNumber *)routerPriority:(NSString *)router;

//路由前置判断，当满足条件的时候返回YES，说明处理，否则不处理
+ (BOOL)routerPrepose:(NSString *)router withParams:(NSDictionary *)params;
//{
//    return [query thing_safeObjectForKey:@"groupId"] > 0 ? YES : NO;
//}

//默认是用init创建对象VC，可自定义initWithRouterParams初始化并赋值
- (instancetype)initWithRouterParams:(NSDictionary *)params;

//路由后置判断，可以设置一些属性
+ (void)routerStposition:(id)vc withParams:(NSDictionary *)params;
//{
//    Vc.groupId = [query thing_safeObjectForKey:@"groupId"];
//    VC.dealBlock = params["XX"];
//}

//默认push，YES的话用present
+ (BOOL)isPresentVC:(NSString *)router;
//默认YES
+ (BOOL)isAnimated:(NSString *)router;

@end
