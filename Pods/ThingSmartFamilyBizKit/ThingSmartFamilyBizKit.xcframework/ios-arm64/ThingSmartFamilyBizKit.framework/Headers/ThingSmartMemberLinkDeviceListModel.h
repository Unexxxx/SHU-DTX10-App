//
//  ThingSmartMemberLinkDeviceListModel.h
//  ThingSmartDeviceKit
//
//  Created by 吴戈 on 2018/10/12.
//

#import <Foundation/Foundation.h>
#import "ThingSmartMemberLinkDeviceModel.h"

@interface ThingSmartMemberLinkDeviceListModel : NSObject

/// Product category
@property (nonatomic, strong) NSString *productType;

/// Device List
@property (nonatomic, strong) NSArray<ThingSmartMemberLinkDeviceModel *> * deviceList;

@end
