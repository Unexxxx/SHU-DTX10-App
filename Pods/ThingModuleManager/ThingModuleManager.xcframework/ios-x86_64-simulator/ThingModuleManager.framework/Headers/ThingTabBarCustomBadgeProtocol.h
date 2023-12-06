//
//  ThingTabBarCustomBadgeProtocol.h
//  ThingModuleManager
//
//  Created by ThingInc on 2018/12/7.
//

#import <Foundation/Foundation.h>

@class ThingTabItemAttribute;

@protocol ThingTabBarCustomBadgeProtocol <NSObject>

@required
- (void)thing_setBadgeValue:(NSString *)value withItemAttribute:(ThingTabItemAttribute *)attr;

@optional
@property (nonatomic) CGPoint originLocation;   /**< badge左上在barButton上的 比例位置 */
@property (nonatomic) CGSize offset;    /**< 在originLocation基础上偏移 */


@end

