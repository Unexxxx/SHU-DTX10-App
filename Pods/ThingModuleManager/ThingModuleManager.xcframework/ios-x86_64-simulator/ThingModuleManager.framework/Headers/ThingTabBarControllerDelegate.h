//
//  ThingTabBarControllerDelegate.h
//  ThingModuleTabbar
//
//  Created by ThingInc on 2018/8/23.
//

#import <Foundation/Foundation.h>

@protocol ThingTabBarControllerDelegate <NSObject>

@optional

- (NSUInteger)thing_defaultTabIndex;

/**
 设置tabItem上title的样式
 */
- (NSDictionary<NSAttributedStringKey,id> *)thing_tabItemTitleTextAttributesForState:(UIControlState)state;

/**
 将要添加到tabbar
 */
- (void)thing_tabBar:(UITabBarController<ThingTabBarControllerProtocol> *)tabController willAdd:(UIViewController *)childController withItemAttribute:(ThingTabItemAttribute *)attr;

/**
 item是否允许被选中
 该方法仅在defaultSelect无效时回调
 如果实现此方法
 请 不要 在此回调中处理业务逻辑
 请 务必仅返回 YES/NO
 默认根据ThingTabItemAttribute.viewController判断
 */
- (BOOL)thing_tabBar:(UITabBarController<ThingTabBarControllerProtocol> *)tabController childControllerCanBeSelected:(__kindof UIViewController *)childController withItemAttribute:(ThingTabItemAttribute *)attr;

/**
 用户点击tab后，是否允许展示对应vc
 */
- (BOOL)thing_tabBar:(UITabBarController<ThingTabBarControllerProtocol> *)controller shouldShow:(UIViewController *)childController withItemAttribute:(ThingTabItemAttribute *)attr;

/**
 选中
 */
- (void)thing_tabBar:(UITabBarController<ThingTabBarControllerProtocol> *)tabController didSelect:(UIViewController *)childController withItemAttribute:(ThingTabItemAttribute *)attr;
/**
 取消选中
 */
- (void)thing_tabBar:(UITabBarController<ThingTabBarControllerProtocol> *)tabController didUnselect:(UIViewController *)childController withItemAttribute:(ThingTabItemAttribute *)attr;

/**
 设置badge
 */
- (BOOL)thing_tabBar:(UITabBarController<ThingTabBarControllerProtocol> *)tabController shouldSetBadge:(NSString *)value withViewController:(UIViewController *)childController itemAttribute:(ThingTabItemAttribute *)attr;


@end
