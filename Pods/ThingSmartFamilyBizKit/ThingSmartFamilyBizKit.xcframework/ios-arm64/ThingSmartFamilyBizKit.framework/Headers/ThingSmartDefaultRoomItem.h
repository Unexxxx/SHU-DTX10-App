//
//  ThingSmartDefaultRoomItem.h
//  ThingSmartFamilyBizKit
//
//  Created by 柒松 on 2023/8/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartDefaultRoomItem : NSObject
/// The name of default room
@property (nonatomic, copy) NSString *roomName;

/// Whether the room is selected when added to the family.
@property (nonatomic, assign) BOOL isSelected;
@end

NS_ASSUME_NONNULL_END
