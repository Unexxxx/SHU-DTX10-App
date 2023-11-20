//
//  ThingRegisterRouterProtocol.h
//  ThingAnnotationFoundation
//
//  Created by Storm on 2022/2/6.
//

#import "ThingBaseAnnotation.h"

@protocol ThingRegisterAPIProtocol <NSObject>

//协议优先级，默认是EAnnotationPriorityBase（0）
+ (NSNumber *)APIPriority:(NSString *)api;//EAnnotationPriority

@end
