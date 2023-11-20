//
//  ThingProtocolAnnotation.h
//  ThingAnnotationFoundation
//
//  Created by Storm on 2021/11/29.
//

#import "ThingRegisterAPIProtocol.h"
#pragma mark ThingAnnotation
//实现协议，即提供协议
//举例：ThingRegisterApiAnnotation(ThingLoginProtocol, ThingLoginProtocolImpl)
//ThingLoginProtocol是登录协议 ThingLoginProtocolImpl是登录实现
#define ThingRegisterAPIAnnotation(Protocol, IMPL) __ThingInterfaceAnnotation(Protocol,IMPL)

//需要，可选协议。目前看可以只是用做脚本扫描，不需要记录数据到macho里面
//举例：ThingRequireAPIAnnotation(ThingLoginProtocol)
#define ThingRequireAPIAnnotation(Protocol)
#define ThingOptionalAPIAnnotation(Protocol)



#pragma mark ThingAnnotationIMPL

extern NSMutableArray *getProtocolSectionData(void);

typedef struct __attribute__((packed)) {
    const char * protocol;
    const char * impl;
} _ThingMachRegisterProtocolStruct;


#define __ThingInterfaceAnnotation(Protocol,IMPL) \
static _ThingMachRegisterProtocolStruct  __##Protocol __attribute__((used, section("__RouterSection, Protocol"))) = {\
#Protocol,\
#IMPL,\
};




