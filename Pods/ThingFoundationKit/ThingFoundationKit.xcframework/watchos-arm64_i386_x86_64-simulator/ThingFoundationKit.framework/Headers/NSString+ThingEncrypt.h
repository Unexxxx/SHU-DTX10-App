//
//  NSString+ThingEncrypt.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/4/16.
//

#import <Foundation/Foundation.h>
#import "ThingDigestImpl.h"
#import "ThingRSAImpl.h"
#import "ThingAESImpl.h"

@interface NSString (ThingDigestAlgorithm)

- (NSString *)thing_md5String;

- (NSString *)thing_sha1String;

- (NSData *)thing_hmacWithKey:(NSString *)key type:(ThingHmacType)type;
@end



// AES 加密，只支持返回 Hex String
@interface NSString (ThingAESEncrypt)

// AES128加解密，key的长度必须小于等于16，否则会加密失败
- (NSString *)thing_AES128EncryptWithKey:(NSString *)key;
- (NSString *)thing_AES128DecryptWithKey:(NSString *)key;

// AES256加解密，key的长度必须小于等于32，否则会加密失败
- (NSString *)thing_AES256EncryptWithKey:(NSString *)key;
- (NSString *)thing_AES256DecryptWithKey:(NSString *)key;
@end



@interface NSString (ThingRSAEncrypt)

#pragma mark - 加密

/**
 RSA公钥加密，返回base64编码的加密密文
 
 @param publicKey 公钥，支持带header和不带header的格式，可以用config.keyWithHeader定义。
 @*param config 加密配置，默认: + [ThingRSAConfig defaultConfig]
 @return Base64编码的加密密文
 */
- (NSString *)thing_base64RSAEncryptWithPublicKey:(NSString *)publicKey;
- (NSString *)thing_base64RSAEncryptWithPublicKey:(NSString *)publicKey config:(ThingRSAConfig *)config;

/**
 RSA公钥加密，返回16进制的加密密文
 
 @param publicKey publicKey 公钥，支持带header和不带header的格式，可以用config.keyWithHeader定义。
 @*param config config 加密配置，默认: + [ThingRSAConfig defaultConfig]
 @return 16进制的加密密文
 */
- (NSString *)thing_hexRSAEncryptWithPublicKey:(NSString *)publicKey;
- (NSString *)thing_hexRSAEncryptWithPublicKey:(NSString *)publicKey config:(ThingRSAConfig *)config;


#pragma mark - 解密

/**
 RSA私钥解密16进制密文，返回解密内容
 
 @param privateKey 私钥，支持带header和不带header的格式，可以用config.keyWithHeader定义。
 @return 解密内容
 */
- (NSString *)thing_RSADecryptHexWithPrivateKey:(NSString *)privateKey;
- (NSString *)thing_RSADecryptHexWithPrivateKey:(NSString *)privateKey config:(ThingRSAConfig *)config;

/**
 RSA私钥解密base64密文，返回解密内容
 
 @param privateKey 私钥，支持带header和不带header的格式，可以用config.keyWithHeader定义。
 @return 解密内容
 */
- (NSString *)thing_RSADecryptBase64WithPrivateKey:(NSString *)privateKey;
- (NSString *)thing_RSADecryptBase64WithPrivateKey:(NSString *)privateKey config:(ThingRSAConfig *)config;

@end
