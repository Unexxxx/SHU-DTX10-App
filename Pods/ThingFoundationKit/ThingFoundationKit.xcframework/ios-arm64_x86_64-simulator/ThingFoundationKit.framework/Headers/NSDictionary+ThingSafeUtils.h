//
//  NSDictionary+ThingSafeUtils.h
//  ThingSmartSceneModule
//
//  Created by mile on 2020/8/17.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDictionary (ThingSafeUtils)

- (id)thing_safeObjectForKey:(id)key;
- (id)thing_safeObjectForKey:(id)key class:(Class)aClass;

- (bool)thing_boolForKey:(id)key;
- (float)thing_floatForKey:(id)key;
- (double)thing_doubleForKey:(id)key;
- (NSInteger)thing_integerForKey:(id)key;
- (int)thing_intForKey:(id)key;
- (long)thing_longForKey:(id)key;
- (NSNumber *)thing_numberForKey:(id)key;
- (NSString *)thing_stringForKey:(id)key;
- (NSDictionary *)thing_dictionaryForKey:(id)key;
- (NSArray *)thing_arrayForKey:(id)key;
- (NSMutableDictionary *)thing_mutableDictionaryForKey:(id)key;
- (NSMutableArray *)thing_mutableArrayForKey:(id)key;

@end

NS_ASSUME_NONNULL_END
