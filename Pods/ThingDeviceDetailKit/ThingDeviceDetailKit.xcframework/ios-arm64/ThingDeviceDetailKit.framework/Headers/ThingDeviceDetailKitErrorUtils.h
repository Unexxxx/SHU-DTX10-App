//
//  ThingDeviceDetailKitErrorUtils.h
//  ThingDeviceDetailKit
//
//  Created by 后主 on 2023/8/17.
//

#import <Foundation/Foundation.h>
#import "ThingDeviceDetailKitErrorDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceDetailKitErrorUtils : NSObject

+ (NSError *)deviceNullError;

+ (NSError *)deviceOfflineError;

+ (NSError *)timerExtraError;

+ (NSError *)bleTransmissionTimeoutError;

+ (NSError *)bleDataParseError;

+ (NSError *)deviceCannotSyncError;


@end

NS_ASSUME_NONNULL_END
