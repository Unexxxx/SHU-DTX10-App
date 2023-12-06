//
//  ThingBaseAnnotation.h
//  ThingAnnotationFoundation
//
//  Created by Storm on 2022/1/20.
//

#import <Foundation/Foundation.h>

typedef enum {
    EAnnotationPriorityMin = -1024,
    EAnnotationPriorityLow = -16,
    EAnnotationPriorityBase = 0,
    EAnnotationPriorityHigher = 16,
    EAnnotationPriorityMax = 1024,
}EAnnotationPriority;

BOOL thingIsInsideAppImage(uint32_t imageIndex);


@interface ThingAnnotationObject:NSObject

@property (strong)  NSString *name;
@property (strong)  Class impl;

@end
