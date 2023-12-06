//
//  ThingSmartActivatorMatterProtocol.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by huangjj on 2022/10/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartActivatorMatterProtocol <NSObject>

/// Check the matter code is legal or not. Returns nil if it is invalid.
/// @param qrString The matter QRCode string or Manual Code string.
- (ThingSmartActivatorDeviceModel *)parseSetupCode:(NSString *)qrString;

/// Continue the pairing or NOT.
///
/// **Notice:** Can only be used after the `-matterDeviceAttestation:error:` delegate callback.
///
/// @param device It MUST BE the device object through the `-matterDeviceAttestation:error:` delegate callback.
/// @param ignoreAttestationFailure Ignore the attestation fail or NOT.  `YES` - continue pairing,  `NO` - interrupt pairing.
/// @param error the error info.
- (void)continueCommissioningDevice:(void *)device
           ignoreAttestationFailure:(BOOL)ignoreAttestationFailure
                              error:(NSError * __autoreleasing *)error;


/// Continue pair WIFI or Thread matter device when session establishment completed.
///
/// **Notice:** There are some rules before use this api to continue pair the matter device.
/// 1. Can only be used after the `- matterCommissioningSessionEstablishmentComplete:`
/// 2. The `routingType` must be equal to `ThingMatterRoutingTypeThing`.  (`routingType` can be known by `-matterRoutingComplete:`)
/// 3. If you are pairing thread device and want to set gateway device, you can set gwid in ThingSmartActivatorTypeMatterModel and use this api after the `- matterCommissioningSessionEstablishmentComplete:`
///
/// @param deviceModel the matter devicemodel.
/// @param typeModel Network configuration type.
- (void)continueCommissionDevice:(ThingSmartActivatorDeviceModel *)deviceModel typeModel:(ThingSmartActivatorTypeMatterModel *)typeModel;


/// Set your `App Groups identify` to share data with `Matter Extension`
///
/// **Notice**
/// 1. Please check the `configKey` must be same as the `App Groups identify` which is both chose it to `Matter Extension Target` and your  `App Main Target`.
/// 2. Please call this API before start pairing, Usually this api is called after the App is started and before the matter device activator starts.
///
/// - Parameter configKey: The App Groups identify.
+ (void)setMatterConfigKey:(NSString *)configKey;

@end

NS_ASSUME_NONNULL_END
