//
//  NSString+ThingBase64.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/4/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define ThingStr(a) a.thingStr

@interface NSString (ThingBase64)

@property (nonatomic, readonly) NSString *thingStr;

- (NSData *)thing_base64Data;

@end



NS_ASSUME_NONNULL_END
