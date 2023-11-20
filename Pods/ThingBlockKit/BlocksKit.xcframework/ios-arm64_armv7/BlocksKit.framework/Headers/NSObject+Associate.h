
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (Associate)

/**
OBJC_ASSOCIATION_RETAIN_NONATOMIC

 @param value any object
 @param key A unique key pointer.
 */
- (void)bk_associateValue:(id)value withKey:(const void *)key;

/**
 OBJC_ASSOCIATION_COPY_NONATOMIC
 
 @param value any object
 @param key A unique key pointer.
 */
- (void)bk_associateCopyOfValue:(id)value withKey:(const void *)key;

/**
 OBJC_ASSOCIATION_RETAIN_NONATOMIC

 @param value any object
 @param key A unique key pointer.
 */
+ (void)bk_associateValue:(id)value withKey:(const void *)key;

/**
 OBJC_ASSOCIATION_COPY_NONATOMIC
 
 @param value any object
 @param key A unique key pointer.
 */
+ (void)bk_associateCopyOfValue:(id)value withKey:(const void *)key;

/** Returns the associated value for a key on the reciever.
 
 @param key A unique key pointer.
 @return The object associated with the key, or `nil` if not found.
 */
- (id)bk_associatedValueForKey:(const void *)key;

/** Returns the associated value for a key on the receiving class.
 
 @see associatedValueForKey:
 @param key A unique key pointer.
 @return The object associated with the key, or `nil` if not found.
 */
+ (id)bk_associatedValueForKey:(const void *)key;

@end

NS_ASSUME_NONNULL_END
