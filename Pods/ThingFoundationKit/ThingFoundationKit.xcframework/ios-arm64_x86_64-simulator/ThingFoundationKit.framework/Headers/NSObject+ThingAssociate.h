//
//  NSObject+ThingAssociate.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/3/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (ThingAssociate)

- (void)thing_setAssociate:(_Nullable id)value withKey:(const void *)key;
- (void)thing_setAssociate:(_Nullable id)value withStringKey:(NSString *)keyStr;

- (void)thing_setWeakAssociate:(_Nullable id)value withKey:(const void *)key;
- (void)thing_setWeakAssociate:(_Nullable id)value withStringKey:(NSString *)keyStr;

- (_Nullable id)thing_getAssociateWithKey:(const void *)key;
- (_Nullable id)thing_getAssociateWithStringKey:(NSString *)keyStr;

- (void)thing_removeAllAssociate;

@end

NS_ASSUME_NONNULL_END
