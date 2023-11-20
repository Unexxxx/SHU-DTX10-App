//
//  ThingDeviceConfigInfo.h
//  ThingActivatorModule
//
//  Created by huangjj on 2019/8/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceConfigInfo : NSObject

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *icon;


// zigbee gateway need 
@property (nonatomic, strong) NSString *gwid;
@property (nonatomic, strong) NSString *id;
@end

NS_ASSUME_NONNULL_END
