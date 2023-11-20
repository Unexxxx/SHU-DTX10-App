//
//  ThingModuleTabBarStyleProtocol.h
//  ThingModuleManager
//
//  Created by ThingInc on 2018/9/4.
//

#import <Foundation/Foundation.h>

@class ThingTabItemAttribute;

@protocol ThingModuleTabBarStyleProtocol <NSObject>

@optional
- (void)tabBarDidLoad;

- (Class)tabBarModuleForDefaultSelected;

- (NSDictionary<NSAttributedStringKey, id> *)tabBarItemTitleAttributesForState:(UIControlState)state withNativeResult:(NSDictionary<NSAttributedStringKey, id> *)nativeResult;

- (void)customTabBarStyleWithItemAttributes:(NSMutableArray<ThingTabItemAttribute *> *)attrArr;

- (void)tabBarWillLoadModule:(Class)moduleCls withAttributes:(NSMutableArray<ThingTabItemAttribute *> *)attrArr;
/**
 @return 事件是否继续向原生代码实现传递
 */
- (BOOL)tabBarWillAdd:(nullable UIViewController *)controller withItemAttribute:(nonnull ThingTabItemAttribute *)attribute;

/**
 item是否允许被选中
 该方法仅在defaultSelect无效时回调
 如果实现此方法
 请 不要 在此回调中处理业务逻辑
 请 务必仅返回 YES/NO
 style中此方法优先级高于native
 */
- (BOOL)tabBarCanSelect:(nullable UIViewController *)controller withItemAttribute:(ThingTabItemAttribute *)attribute nativeResult:(BOOL)nativeResult;

/**
 用户点击tab后，是否允许展示对应vc
 */
- (BOOL)tabBarShouldShow:(nullable UIViewController *)controller withItemAttribute:(ThingTabItemAttribute *)attribute nativeResult:(BOOL)nativeResult;

/**
 @return 事件是否继续向原生代码实现传递
 */
- (BOOL)tabBarDidSelect:(nullable UIViewController *)controller withItemAttribute:(ThingTabItemAttribute *)attribute;

/**
 @return 事件是否继续向原生代码实现传递
 */
- (BOOL)tabBarDidUnselect:(nullable UIViewController *)controller withItemAttribute:(ThingTabItemAttribute *)attribute;

/**
 是否允许设置badge
 */
- (BOOL)tabBarShouldSetBadge:(nullable NSString *)badge withItemAttribute:(ThingTabItemAttribute *)attribute nativeResult:(BOOL)nativeResult;

@end
