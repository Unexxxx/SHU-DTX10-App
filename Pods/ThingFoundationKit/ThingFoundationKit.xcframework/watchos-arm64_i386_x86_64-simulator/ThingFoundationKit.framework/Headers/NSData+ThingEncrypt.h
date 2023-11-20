//
//  NSData+ThingEncrypt.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/4/16.
//

#import <Foundation/Foundation.h>
#import "ThingRSAImpl.h"
#import "ThingAESImpl.h"
#import "ThingDigestImpl.h"

NS_ASSUME_NONNULL_BEGIN

@interface NSData (ThingDigestAlgorithm)

- (NSString *)thing_md5String;

- (NSString *)thing_sha1String;
@end



// AES 加密，只支持返回 Hex String
@interface NSData (ThingAESEncrypt)
- (NSData *)thing_AES128EncryptWithKey:(NSString *)key;
- (NSData *)thing_AES128DecryptWithKey:(NSString *)key;

- (NSData *)thing_AES256EncryptWithKey:(NSString *)key;
- (NSData *)thing_AES256DecryptWithKey:(NSString *)key;
@end



@interface NSData (ThingRSAEncrypt)
/**
 RSA公钥加密，返回加密后的数据
 
 @param publicKey 公钥，支持带header和不带header的格式，可以用config.keyWithHeader定义。
 @*param config 加密配置，默认: + [ThingRSAConfig defaultConfig]
 @return 加密后的数据
 */
- (NSData *)thing_RSAEncryptWithPublicKey:(NSString *)publicKey;
- (NSData *)thing_RSAEncryptWithPublicKey:(NSString *)publicKey config:(ThingRSAConfig *)config;

/**
 RSA私钥解密数据，返回解密的数据
 
 @param privateKey 私钥，支持带header和不带header的格式，可以用config.keyWithHeader定义。
 @return 解密内容
 */
- (NSData *)thing_RSADecryptWithPrivateKey:(NSString *)privateKey;
- (NSData *)thing_RSADecryptWithPrivateKey:(NSString *)privateKey config:(ThingRSAConfig *)config;
@end
NS_ASSUME_NONNULL_END
