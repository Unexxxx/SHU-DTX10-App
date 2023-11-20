//
//  ThingProtocolAnnotation.h
//  ThingAnnotationFoundation
//
//  Created by Storm on 2021/11/29.
//

#pragma mark ThingAnnotation

#import <UIKit/UIKit.h>
#import "ThingRegisterLaunchProtocol.h"

#define ThingLaunchBeforeType              "PreMain"
#define ThingLaunchSyncType                "TaskSync"
#define ThingLaunchSyncOtherThreadType     "TaskOther"

////+load之后，main之前
#define ThingLaunchBeforeAnnotation(IMPL)  ThingLaunchAnnotation(PreMain, IMPL)
////模块化启动后同步
#define ThingLaunchSyncAnnotation(IMPL)  ThingLaunchAnnotation(TaskSync, IMPL)
////模块化启动后非主线程同步执行
#define ThingLaunchSyncOtherThreadAnnotation(IMPL)  ThingLaunchAnnotation(TaskOther, IMPL)


#pragma mark ThingAnnotationIMPL



typedef void(^_ThingAnnotationLaunchBlock)(void);

typedef struct __attribute__((packed)) {
    const char * impl;
} _ThingMachRegisterLaunchStruct;

#define ThingLaunchAnnotation(NAME, IMPL) __ThingLaunchAnnotation(NAME, IMPL)

#define __ThingLaunchAnnotation(NAME, IMPL) \
static _ThingMachRegisterLaunchStruct  __Launch__##Name __attribute__((used, section("__Launch, "#NAME))) = {\
#IMPL\
};

typedef void(^ThingAnnotationRegisterLaunchBlock)(int privacy, id block);

extern NSArray *getLaunchSectionData(const char *type);


@interface ThingLaunchTaskAnnotationObject:NSObject

@property (strong)  NSString *impl;

@end

