//
//  ThingGroupManagerKit.h
//  ThingGroupManagerKit
//
//  Created by yuheng on 2023/6/20.
//

#ifndef ThingGroupManagerKit_h
#define ThingGroupManagerKit_h

#import "ThingGroupServiceProtocol.h"
#import "ThingGroupServiceMaker.h"
#import "ThingGroupMakerHelper.h"
#import "ThingGroupBaseError.h"
#import "ThingGroupDef.h"

#import "ThingGroupBaseService.h"
#import "ThingWiFiGroupService.h"// 普通WiFi群组
#import "ThingStandardWiFiGroupService.h" // 标准WiFi群组
#import "ThingZigbeeGroupService.h" // 普通zigbee群组
#import "ThingStandardZigbeeGroupService.h" //标准zigbee群组
#import "ThingBLEMeshGroupService.h" // 普通私有mesh群组
#import "ThingSIGMeshGroupService.h" // 普通SIGMesh群组
#import "ThingStandardSIGMeshGroupService.h" // 标准SIGMesh群组
#import "ThingGroupBeaconService.h" // 普通Beacon群组
#import "ThingThreadGroupService.h" // 普通Thread群组

#import "ThingZigbeeRemoteControlGroupService.h" // zigbee遥控器群组
#import "ThingSIGMeshRemoteControlService.h" // SIGMesh遥控器群组
#import "ThingSIGMeshRemoteControlNewService.h" // SIGMesh遥控器群组-- 支持网关链路添加设备及低功耗设备添加时进行链接

#endif /* ThingGroupManagerKit_h */
