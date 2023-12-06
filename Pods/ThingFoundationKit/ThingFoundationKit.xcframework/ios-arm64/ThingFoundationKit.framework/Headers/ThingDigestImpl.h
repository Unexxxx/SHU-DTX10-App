//
//  ThingDigestImpl.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/5/8.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ThingDigestType) {
    ThingDigestMD2Type,        // MD2算法
    ThingDigestMD4Type,        // MD4算法
    ThingDigestMD5Type,        // MD5算法
    ThingDigestSHA1Type,       // SHA1算法
    ThingDigestSHA224Type,     // SHA224算法
    ThingDigestSHA256Type,     // SHA256算法
    ThingDigestSHA384Type,     // SHA384算法
    ThingDigestSHA512Type,     // SHA512算法
};

typedef NS_ENUM(NSInteger, ThingHmacType) {
    ThingHmacMD5Type,          // MD5算法
    ThingHmacSHA1Type,         // SHA1算法
    ThingHmacSHA224Type,       // SHA224算法
    ThingHmacSHA256Type,       // SHA256算法
    ThingHmacSHA384Type,       // SHA384算法
    ThingHmacSHA512Type,       // SHA512算法
};

/*
 摘要算法实现
 */
@interface ThingDigestImpl : NSObject

// MD算法和SHA算法
+ (NSData *)digestWithData:(NSData *)data type:(ThingDigestType)digestType;

// HMAC算法
+ (NSData *)hmacWithData:(NSData *)data keyData:(NSData *)keyData type:(ThingHmacType)hmacType;

@end
