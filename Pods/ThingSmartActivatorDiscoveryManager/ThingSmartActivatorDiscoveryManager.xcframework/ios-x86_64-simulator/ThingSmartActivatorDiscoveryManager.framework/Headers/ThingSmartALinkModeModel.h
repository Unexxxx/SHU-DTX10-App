//
//  ThingSmartALinkModeModel.h
//  ThingActivatorRequestSktImpl
//
//  Created by qisong on 2022/3/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ThingSmartALeadModel;
@interface ThingSmartALinkModeModel : NSObject

@property (nonatomic, copy) NSString *title; ///< linkMode 名
@property (nonatomic, copy) NSString *desText; ///< 描述
/// EZ=1 AP=2 ZIGSUB=3 QRCode=4 NB=5 GPRS=6 BT=7 WC=8 433SUB=9 CaptureDevice2=10 QRCode2=11 CaptureDevice=1000
@property (nonatomic, assign) NSInteger linkMode; ///< 当前配网类型
@property (nonatomic, strong) NSArray<ThingSmartALeadModel *> *leadList; ///< 详细引导
@property (nonatomic, assign) BOOL updatedTag; ///< 是否在 IoT 平台上被修改过，未修改时仍然使用默认默认交互

@end

NS_ASSUME_NONNULL_END
