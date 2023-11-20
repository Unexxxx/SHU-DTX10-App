//
//  ThingModuleNotifyRegisterProtocol.h
//  ThingModuleManager
//
//  Created by ThingInc on 2018/9/3.
//

#import <Foundation/Foundation.h>

#define ThingNotifyName(sel) NSStringFromSelector(@selector(sel))

@protocol ThingModuleNotifyRegisterProtocol <NSObject>

@optional
/**
 返回本模块能响应的通知方法名
 
 @return @[NSStringFromSelector(@selector(xxx))] / @[ThingNotifyName(xxx)]
 */
- (NSArray<NSString *> *)registRespondsNotifies;

@end
