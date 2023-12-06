//
//  ThingModuleHookInfo.h
//  ThingModuleManager
//
//  Created by ThingInc on 2019/5/14.
//

#import <Foundation/Foundation.h>

@class ThingModuleHookInfo;

#define ThingModuleHookInfoMake(prot, sel) [ThingModuleHookInfo hookInfoWith:@protocol(prot) selector:@selector(sel)]

NS_ASSUME_NONNULL_BEGIN

@interface ThingModuleHookInfo : NSObject

@property (nonatomic, strong) Protocol *hookProtocol;
@property (nonatomic, strong) NSArray<NSString *> *hookSelectorArr;

+ (ThingModuleHookInfo *)hookInfoWith:(Protocol *)prot selector:(SEL)sel;

@end

NS_ASSUME_NONNULL_END
