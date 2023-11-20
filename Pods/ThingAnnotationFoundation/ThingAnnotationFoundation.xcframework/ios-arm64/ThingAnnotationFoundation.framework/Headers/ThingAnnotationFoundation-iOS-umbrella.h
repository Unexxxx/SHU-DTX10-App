#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "ThingAnnotationFoundation.h"
#import "ThingAPIAnnotation.h"
#import "ThingBaseAnnotation.h"
#import "ThingLaunchAnnotation.h"
#import "ThingRegisterAPIProtocol.h"
#import "ThingRegisterLaunchProtocol.h"
#import "ThingRegisterRouterProtocol.h"
#import "ThingRouterAnnotation.h"
#import "ThingUITestAnnotation.h"
#import "ThingUITestContext.h"

FOUNDATION_EXPORT double ThingAnnotationFoundationVersionNumber;
FOUNDATION_EXPORT const unsigned char ThingAnnotationFoundationVersionString[];

