//
//  ThingUITestAnnotation.h
//  ThingAnnotationFoundation
//
//  Created by Storm on 2021/11/29.
//
#import "ThingUITestContext.h"
#pragma mark ThingAnnotation
#define ThingUITestAnnotation(title,startBlock,testBlock) __ThingUITestAnnotation(UITest,title,startBlock,testBlock)
#define ThingUITestIDAnnotation(id,title,startBlock,testBlock) __ThingUITestAnnotation(id,title,startBlock,testBlock)


#pragma mark ThingAnnotationIMPL

typedef void(^ThingAnnotationUITestLaunchTaskBlock)(ThingUITestContext *);
typedef BOOL(^ThingAnnotationUITestBlock)(NSInteger, ThingUITestContext *);
typedef void(^ThingAnnotationRegisterUITestBlock)(NSString *title, ThingAnnotationUITestLaunchTaskBlock startBlock, ThingAnnotationUITestBlock testBlock);

extern void setRegisterUITestBlock(ThingAnnotationRegisterUITestBlock block);
extern NSArray *getUITestSectionData(void);

typedef struct __attribute__((packed)) {
    const char * title;
    ThingAnnotationUITestLaunchTaskBlock startBlock;
    ThingAnnotationUITestBlock testBlock;
} _ThingMachRegisterUITestStruct;



#define __ThingUITestAnnotation(id,title,startBlock,testBlock) \
static _ThingMachRegisterUITestStruct  __##id __attribute__((used, section("__RouterSection, UITest"))) = {\
title,\
startBlock,\
testBlock\
};

@interface ThingUITestAnnotationObject : NSObject
@property (strong)  NSString *title;
@property (copy)  ThingAnnotationUITestLaunchTaskBlock startBlock;
@property (copy)  ThingAnnotationUITestBlock testBlock;
@end


