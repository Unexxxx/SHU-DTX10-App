//
//  ThingModuleLinkedItem.h
//  ThingModuleManager
//
//  Created by zjutwhw on 2020/7/31.
//

#import <Foundation/Foundation.h>
#import <ThingAnnotationFoundation/ThingAnnotationFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingModuleLinkedItem : NSObject

@property (nonatomic, strong) NSNumber *priority;
@property (nonatomic, strong) ThingModuleLinkedItem *next;
@property (nonatomic, weak) id module;

@property (nonatomic, weak) Class vc;
//@property (nonatomic, weak) NSString *method;
//@property (nonatomic, copy) _ThingRouterBlock startBlock;
//@property (nonatomic, copy) _ThingRouterResultBlock endBlock;
/*
 说明：插入item到链表，按优先级大小排序
 */
+ (ThingModuleLinkedItem *)insertItem:(ThingModuleLinkedItem *)item toLinked:(ThingModuleLinkedItem *)head;

/*
 说明：删除链表上可能已经释放的Module节点
 */
+ (ThingModuleLinkedItem *)cleanNilInLinked:(ThingModuleLinkedItem *)head;

@end

NS_ASSUME_NONNULL_END
