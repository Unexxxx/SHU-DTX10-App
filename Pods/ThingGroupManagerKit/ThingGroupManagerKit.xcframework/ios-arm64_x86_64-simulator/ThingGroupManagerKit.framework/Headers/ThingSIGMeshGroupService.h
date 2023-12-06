//
//  ThingSIGMeshGroupService.h
//  ThingGroupManagerKit
//
//  Created by yuheng on 2021/6/25.
//

#import "ThingGroupServiceProtocol.h"
#import "ThingGroupBaseService.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSIGMeshGroupService :  ThingGroupBaseService <ThingGroupServiceProtocol>

@property (nonatomic, readonly) NSString *groupId;
@property (nonatomic, readonly) NSString *entryDevId;

@end

NS_ASSUME_NONNULL_END
