//
//  ThingAESImpl.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/4/17.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ThingAESKeySize) {
    ThingAESKey128Bits,    // 128位
    ThingAESKey256Bits     // 256位
};

typedef NS_ENUM(NSInteger, ThingAESMode) {
    ThingAESModeP7ECB,     // ECB模式 kCCOptionPKCS7Padding | kCCOptionECBMode
    ThingAESModeP7CBC      // CBC模式 kCCOptionPKCS7Padding
};


@interface ThingAESConfig : NSObject

/**
 秘钥大小, 默认ThingAESKey128Bits
 */
@property (nonatomic, assign) ThingAESKeySize keySize;

/**
 加密模式，默认ThingAESModeP7ECB
 */
@property (nonatomic, assign) ThingAESMode mode;

/**
 ThingAESModeP7CBC加密时使用的向量, 默认为空
 */
@property (nonatomic, strong) NSData *CBCIV;

+ (instancetype)default128Config;

+ (instancetype)default256Config;

@end


@interface ThingAESImpl : NSObject

/**
 AES加密数据
 
 @param data 需要加密的内容
 @param keyData 秘钥
 @param config 加密配置, 默认可以使用+ [ThingAESConfig defaultConfig]
 @return 加密后的内容
 */
+ (NSData *)encryptData:(NSData *)data keyData:(NSData *)keyData config:(ThingAESConfig *)config;

/**
 AES解密数据
 
 @param data 需要加密的内容
 @param keyData 秘钥
 @param config 解密配置, 默认可以使用+ [ThingAESConfig defaultConfig]
 @return 解密后的内容
 */
+ (NSData *)decryptData:(NSData *)data keyData:(NSData *)keyData config:(ThingAESConfig *)config;


# pragma mark - deprecated
// 128:ECB  256:CBC
+ (NSData *)encryptData:(NSData *)data keyData:(NSData *)keyData keySize:(ThingAESKeySize)keySize DEPRECATED_MSG_ATTRIBUTE("use encryptData:keyData:config: instead.");

// 128:ECB  256:CBC
+ (NSData *)decryptData:(NSData *)data keyData:(NSData *)keyData keySize:(ThingAESKeySize)keySize DEPRECATED_MSG_ATTRIBUTE("use decryptData:keyData:config: instead.");

@end
