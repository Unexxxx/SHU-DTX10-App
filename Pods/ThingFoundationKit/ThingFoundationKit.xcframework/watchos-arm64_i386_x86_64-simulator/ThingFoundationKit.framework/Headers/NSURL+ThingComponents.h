//
//  NSURL+ThingComponents.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/3/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSURL (ThingComponents)

@property (nonatomic, strong, readonly) NSString *thing_scheme;
@property (nonatomic, strong, readonly) NSString *thing_host;
@property (nonatomic, strong, readonly) NSString *thing_path;
@property (nonatomic, strong, readonly) NSString *thing_query;

@property (nonatomic, strong, readonly) NSArray *thing_pathArray;
@property (nonatomic, strong, readonly) NSDictionary *thing_queryDictionary;

/**
 if value isn't NSString, it will be ignore
 */
- (NSURL *)thing_URLByAppendingQuery:(NSDictionary<NSString *, NSString *> *)query;
- (id)thing_valueForQueryKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
