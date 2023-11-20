//
//  ThingRegisterRouterProtocol.h
//  ThingAnnotationFoundation
//
//  Created by Storm on 2022/2/6.
//

#import "ThingBaseAnnotation.h"

@protocol ThingRegisterLaunchProtocol <NSObject>

@optional

//路由优先级，默认是EAnnotationPriorityBase（0）
+ (NSNumber *)launchPriority;
+ (void)launchAnnotationTask;

@end
