//
//  ThingSmartActivatorRequestProtocol.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by huangjj on 2023/8/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef void(^ThingActivatorCallbackError)(NSError *error);

@class ThingActivatorPrimaryCategoryRequestData, ThingActivatorSecondaryCategoryRequestData, ThingActivatorCategoryDetailRequestData, ThingActivatorProductInfoRequestData, ThingActivatorGatewayLeadListRequestData, ThingActivatorCategoryListRequestData, ThingActivatorUserGuideRequestData, ThingActivatorProductGuideRequestData, ThingActivatorFeedbackInfoRequestData,ThingACTEZUnvailabilityRequestData,ThingActivatorBizSupportCheckRequestData,ThingActivatorParseQRCodeRequestData,ThingActivatorResetDeviceRequestData,ThingActivatorDeviceBindRequestData,ThingActivatorNBDeviceBindRequestData,ThingActivatorVirtualDeviceBindRequestData,ThingActivatorThingLinkDeviceBindRequestData,ThingActivatorSubDeviceGWRequestData,ThingDeviceRepeatActiveRequestData;

@class ThingSmartACategoryModel,
ThingSmartACategoryLevel2Model,
ThingSmartDeviceCategoryModel,
ThingDeviceConfigInfo,
ThingCommonLeadModel,
ThingSmartAProductGuideData,
ThingActivatorFeedbackInfoData,
ThingACTEZUnvailabilityResponseData,
ThingDeviceRepeatActiveResponseData,
ThingACTLinkmodeUrlResponseData,
ThingActivatorBizSupportCheckResponseData,
ThingSmartAScanCodeModel,
ThingActivatorResetDeviceResponseData,
ThingActivatorDeviceBindResponseData,
ThingActivatorNBDeviceBindResponseData,
ThingActivatorVirtualDeviceBindResponseData,
ThingActivatorThingLinkDeviceBindResponseData,
ThingActivatorSubDeviceGWResponseData;

@protocol ThingSmartActivatorRequestProtocol <NSObject>

/// Request a list of categories at the first level
/// @param param Request Parameters
/// @param success Network success callback, return the corresponding first-level category information
/// @param failure Network Failure Callbacks
- (void)requestPrimaryCategoryWithParam:(ThingActivatorPrimaryCategoryRequestData *)param success:(void(^)(ThingSmartACategoryModel *result))success failure:(ThingActivatorCallbackError)failure;

/// Request a list of secondary categories corresponding to primary categories
/// @param param Request Parameters
/// @param success Network success callback, return the corresponding secondary category list
/// @param failure Network Failure Callbacks
- (void)requestSecondaryCategoryWithParam:(ThingActivatorSecondaryCategoryRequestData *)param success:(void(^)( NSArray <ThingSmartACategoryLevel2Model *>*result))success failure:(ThingActivatorCallbackError)failure;

/// Request a list of secondary categories corresponding to primary categories
/// @param param Request Parameters
/// @param success Network success callback to return bootstrap details
/// @param failure Network Failure Callbacks
- (void)requestCategoryDetailWithParam:(ThingActivatorCategoryDetailRequestData *)param success:(void(^)(ThingSmartDeviceCategoryModel *result))success failure:(ThingActivatorCallbackError)failure;

/// Request Product Information
/// @param param Request Parameters
/// @param success Network success callback to return product information
/// @param failure Network Failure Callbacks
- (void)requestProductInfoWithParam:(ThingActivatorProductInfoRequestData *)param success:(void(^)(ThingDeviceConfigInfo *result))success failure:(ThingActivatorCallbackError)failure;


/// Request a list of configured gateways
/// @param param Request Parameters
/// @param success Network success callback
/// @param failure Network Failure Callbacks
- (void)requestGatewayLeadListWithParam:(ThingActivatorGatewayLeadListRequestData *)param success:(void(^)(NSArray<ThingSmartDeviceCategoryModel *> *result))success failure:(ThingActivatorCallbackError)failure;

/// Get a list of categories by pid or gateway pid
/// @param param Request Parameters
/// @param success Network success callback
/// @param failure Network Failure Callbacks
- (void)requestCategoryListWithParam:(ThingActivatorCategoryListRequestData *)param success:(void(^)(NSArray<ThingSmartDeviceCategoryModel *> *result))success failure:(ThingActivatorCallbackError)failure;

/// Requesting guidance for newcomers to the distribution network
/// @param param Request Parameters
/// @param success Network success callback
/// @param failure Network Failure Callbacks
- (void)requestUserGuideWithParam:(ThingActivatorUserGuideRequestData *)param success:(void(^)(ThingCommonLeadModel *result))success failure:(ThingActivatorCallbackError)failure;

/// Request product guidance information
/// @param param Request Parameters
/// @param success Network success callback
/// @param failure Network Failure Callbacks
- (void)requestProductGuideWithParam:(ThingActivatorProductGuideRequestData *)param success:(void(^)(ThingSmartAProductGuideData *result))success failure:(ThingActivatorCallbackError)failure;

/// Get smart customer service feedback link
/// @param param Request Parameters
/// @param success Network success callback
/// @param failure Network Failure Callbacks
- (void)requestFeedbackInfoWithParam:(ThingActivatorFeedbackInfoRequestData *)param success:(void(^)(ThingActivatorFeedbackInfoData *result))success failure:(ThingActivatorCallbackError)failure;

/// Request EZ unavailable version information
/// @param param Request Parameters
/// @param success Network success callback
/// @param failure Network Failure Callbacks
- (void)requestEZUnvailabilityInfoWithParam:(ThingACTEZUnvailabilityRequestData *)param success:(void(^)(ThingACTEZUnvailabilityResponseData *result))success failure:(ThingActivatorCallbackError)failure;

/// Get the corresponding applet distribution network connection based on product information (product advanced capability, product support required)
/// @param param Request Parameters
/// @param success Network success callback
/// @param failure Network Failure Callbacks
- (void)requestAppletsUrlWithParam:(ThingActivatorCategoryDetailRequestData *)param success:(void(^)(NSArray<ThingACTLinkmodeUrlResponseData *>*))success
                           failure:(ThingActivatorCallbackError _Nullable)failure;

/// Detect whether the device can be activated when Bluetooth scanning
/// @param param Request Parameters
/// @param success Network success callback,If data is empty when canActive is true, it means the device is ready to be paired.If data is not empty when canActive is true, it means the device may have been activated repeatedly.
/// @param failure Network Failure Callbacks
- (void)requestDeviceRepeatActiveCheckWithParam:(ThingDeviceRepeatActiveRequestData *)param success:(void(^)(BOOL canActive, ThingDeviceRepeatActiveResponseData *_Nullable data))success failure:(ThingActivatorCallbackError _Nullable)failure;


/// Determine if certain device capabilities are supported based on product information
/// @param param Request Parameters
/// @param success Network success callback
/// @param failure Network Failure Callbacks
- (void)requestBizSupportCheckWithParam:(ThingActivatorBizSupportCheckRequestData *)param success:(void (^)(NSArray<ThingActivatorBizSupportCheckResponseData *> * _Nonnull list))success
                                failure:(ThingActivatorCallbackError _Nullable)failure;

/// Provide QR code parsing capability
/// @param param Request Parameters
/// @param success Network success callback
/// @param failure Network Failure Callbacks
- (void)requestParseQRCodeWithParam:(ThingActivatorParseQRCodeRequestData *)param success:(void(^)(ThingSmartAScanCodeModel *result))success failure:(ThingActivatorCallbackError)failure;

/// Reset device
/// @param param Request Parameters
/// @param success Network success callback
/// @param failure Network Failure Callbacks
- (void)requestResetDeviceWithParam:(ThingActivatorResetDeviceRequestData *)param success:(void(^)(ThingActivatorResetDeviceResponseData *result))success failure:(ThingActivatorCallbackError)failure;

/// Infrared, gprs device binding
/// @param param Request Parameters
/// @param success Network success callback
/// @param failure Network Failure Callbacks
- (void)requestDeviceBindWithParam:(ThingActivatorDeviceBindRequestData *)param success:(void(^)(ThingActivatorDeviceBindResponseData *result))success failure:(ThingActivatorCallbackError)failure;

/// NB device binding
/// @param param Request Parameters
/// @param success Network success callback
/// @param failure Network Failure Callbacks
- (void)requestNBDeviceBindWithParam:(ThingActivatorNBDeviceBindRequestData *)param success:(void(^)(ThingActivatorNBDeviceBindResponseData *result))success failure:(ThingActivatorCallbackError)failure;

/// Adding a virtual device
/// @param param Request Parameters
/// @param success Network success callback
/// @param failure Network Failure Callbacks
- (void)requestVirtualDeviceBindWithParam:(ThingActivatorVirtualDeviceBindRequestData *)param success:(void(^)(ThingActivatorVirtualDeviceBindResponseData *result))success failure:(ThingActivatorCallbackError)failure;

/// ThingLink Device Binding
/// @param param Request Parameters
/// @param success Network success callback
/// @param failure Network Failure Callbacks
- (void)requestThingLinkDeviceBindWithParam:(ThingActivatorThingLinkDeviceBindRequestData *)param success:(void(^)(ThingActivatorThingLinkDeviceBindResponseData *result))success failure:(ThingActivatorCallbackError)failure;

/// Get the gateway to which the sub-device is connected
/// @param param Request Parameters
/// @param success Network success callback
/// @param failure Network Failure Callbacks
- (void)requestSubDeviceGatewayWithParam:(ThingActivatorSubDeviceGWRequestData *)param
                                 success:(void(^)(ThingActivatorSubDeviceGWResponseData *result))success
                                 failure:(ThingActivatorCallbackError)failure;
@end

NS_ASSUME_NONNULL_END
