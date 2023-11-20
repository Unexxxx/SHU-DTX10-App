//
//  NSObject+ThingKVOController.h
//  AFNetworking
//
//  Created by 尼奥 on 2020/7/24.
//

#import <Foundation/Foundation.h>

#import "ThingKVOController.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Category that adds built-in `KVOController` and `KVOControllerNonRetaining` on any instance of `NSObject`.

 This makes it convenient to simply create and forget a `ThingKVOController`, 
 and when this object gets dealloc'd, so will the associated controller and the observation info.
 */
@interface NSObject (ThingKVOController)

/**
 @abstract Lazy-loaded ThingKVOController for use with any object
 @return ThingKVOController associated with this object, creating one if necessary
 @discussion This makes it convenient to simply create and forget a ThingKVOController, and when this object gets dealloc'd, so will the associated controller and the observation info.
 */
@property (nonatomic, strong) ThingKVOController *thing_KVOController;

/**
 @abstract Lazy-loaded ThingKVOController for use with any object
 @return ThingKVOController associated with this object, creating one if necessary
 @discussion This makes it convenient to simply create and forget a ThingKVOController.
 Use this version when a strong reference between controller and observed object would create a retain cycle.
 When not retaining observed objects, special care must be taken to remove observation info prior to deallocation of the observed object.
 */
@property (nonatomic, strong) ThingKVOController *thing_KVOControllerNonRetaining;

@end

NS_ASSUME_NONNULL_END
