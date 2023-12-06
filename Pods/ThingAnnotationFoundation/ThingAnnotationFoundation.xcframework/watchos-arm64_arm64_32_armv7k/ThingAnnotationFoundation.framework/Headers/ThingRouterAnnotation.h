//
//  ThingRouterAnnotation.h
//  ThingAnnotationFoundation
//
//  Created by Storm on 2021/11/29.
//

#import "ThingBaseAnnotation.h"
#import "ThingRegisterRouterProtocol.h"
#pragma mark ThingAnnotation

/*
 路由注册注解，两个参数：1 路由名 2.处理VC
 如果VC不实现TYRegisterRouterProtocol，则说明当前路由默认就是生成一个IMPLVC来处理，否则会去调用IMPLVC下的TYRegisterRouterProtocol来选择处理。
 什么情况下需要实现TYRegisterRouterProtocol呢？
 1.处理的路由有一些前置判断，例如当满足某条件的时候才会去处理，否则不处理路由，此时可以实现routerPreposing协议方法
 2.路由不是由VC直接处理，而是由某个方法来处理，那就实现routerDistribute协议方法，并返回YES
 
 举例：ThingRegisterRouterAnnotation(tp_login, ThingDebuggerNativeLoginViewController)
 */
#define ThingRegisterRouterAnnotation(Router, IMPLVC)    __ThingRouterAnnotation(Router,IMPLVC)

//比较复杂的路由，类似Router=thing://login
#define ThingRegisterRouterNameAnnotation(Name, Router, IMPLVC)    __ThingRouterNameAnnotation(Name, Router,IMPLVC)

//举例：ThingRequireAPIAnnotation(tp_login)
#define ThingRequiredRouteAnnotation(Router)



#pragma mark ThingAnnotationIMPL
#define ThingRouterSectionName "__RouterSection"

typedef void(^registerRouter)(NSDictionary *params);
typedef void(^ThingAnnotationRegisterRouterBlock)(NSString *router, id vc);

extern NSMutableArray *getRouterSectionData(void);


typedef struct __attribute__((packed)) {
    const char * router;
    const char * viewcontroller;
} _ThingMachRegisterRouterStruct;

#define __ThingRouterAnnotation(Name,VC) \
static _ThingMachRegisterRouterStruct  __##Name __attribute__((used, section("__RouterSection, Router"))) = {\
#Name,\
#VC,\
};


#define __ThingRouterNameAnnotation(RouterName, Name, VC) \
static _ThingMachRegisterRouterStruct  __##RouterName __attribute__((used, section("__RouterSection, Router"))) = {\
Name,\
#VC,\
};








