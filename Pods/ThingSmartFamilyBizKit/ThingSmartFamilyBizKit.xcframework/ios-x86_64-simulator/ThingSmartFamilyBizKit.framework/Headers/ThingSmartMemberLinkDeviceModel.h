//
//  ThingSmartMemberLinkDeviceModel.h
//  ThingSmartFamilyBizKit
//
//  Created by 吴戈 on 2019/4/8.
//

#import <Foundation/Foundation.h>

@interface ThingSmartMemberLinkDeviceModel : NSObject

/// Device ID
@property (nonatomic, strong) NSString *devId;

/// Device Name
@property (nonatomic, strong) NSString *deviceName;

/// Name of the room where the device is located
@property (nonatomic, strong) NSString *room;

/// Whether the device is associated with a room
@property (nonatomic, assign) BOOL relation;

/// Device Icon
@property (nonatomic, strong) NSString *icon;

@end
