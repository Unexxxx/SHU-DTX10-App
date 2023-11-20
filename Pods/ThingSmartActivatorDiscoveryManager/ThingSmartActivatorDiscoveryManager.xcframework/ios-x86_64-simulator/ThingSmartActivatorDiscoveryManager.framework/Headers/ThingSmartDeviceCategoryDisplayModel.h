//
//  ThingSmartDeviceCategoryDisplayModel.h
//  ThingActivatorRequestSktImpl
//
//  Created by qisong on 2022/3/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartDeviceCategoryDisplayModel : NSObject
// WIFI密码页配置
@property (nonatomic, copy) NSString *wifiTitle;
@property (nonatomic, copy) NSString *wifiContent;
@property (nonatomic, copy) NSString *wifiIconUrl;
// EZ
@property (nonatomic, copy) NSString *ezTipIconUrl;
@property (nonatomic, copy) NSString *ezTip; // 接通电源，确认指示灯快闪
@property (nonatomic, copy) NSString *ezAddBtText; // 确认指示灯在快闪
@property (nonatomic, copy) NSString *ezHelpBtText; // 如何将指示灯设置为快闪
@property (nonatomic, copy) NSString *ezHelpUrl; ///< 帮助链接
@property (nonatomic, copy) NSString *ezVideoUrl; ///< 视频
@property (nonatomic, copy) NSString *ezTipConfirm; /// < 确认指示灯在快闪 (目前为兼容 IPC 处理来做)
@property (nonatomic, copy) NSString *ezStatusTitle;///快闪 quickly
@property (nonatomic, copy) NSString *ezStatusIconUrl;///快闪GIF图

// AP
@property (nonatomic, copy) NSString *apTipIconUrl;
@property (nonatomic, copy) NSString *apTip;
@property (nonatomic, copy) NSString *apAddBtText;
@property (nonatomic, copy) NSString *apHelpBtText;
@property (nonatomic, copy) NSString *apHelpUrl;
@property (nonatomic, copy) NSString *apVideoUrl; ///< 视频
@property (nonatomic, copy) NSString *apTipConfirm; /// < 确认指示灯在快闪 (目前为兼容 IPC 处理来做)
@property (nonatomic, copy) NSString *apStatusTitle;///慢闪 slowly
@property (nonatomic, copy) NSString *apStatusIconUrl;///慢闪GIF图

@property (nonatomic, copy) NSString *hotspotName; /// < xxx|xxx|xxx
// captureDevice
@property (nonatomic, copy) NSString *qrTipIconUrl;
@property (nonatomic, copy) NSString *qrTip;
@property (nonatomic, copy) NSString *qrAddBtText;
@property (nonatomic, copy) NSString *qrHelpBtText;
@property (nonatomic, copy) NSString *qrHelpUrl;
@property (nonatomic, copy) NSString *qrVideoUrl; ///< 视频
// 二维码
@property (nonatomic, copy) NSString *qcTipIconUrl;
@property (nonatomic, copy) NSString *qcTip;
@property (nonatomic, copy) NSString *qcAddBtText;
@property (nonatomic, copy) NSString *qcHelpBtText;
@property (nonatomic, copy) NSString *qcHelpUrl;
@property (nonatomic, copy) NSString *qcVideoUrl; ///< 视频
@property (nonatomic, copy) NSString *qcScanTitle; ///< qcScanTitle
@property (nonatomic, copy) NSString *qcScanDesc; ///< qcScanDesc
@property (nonatomic, copy) NSString *qcScanImg; ///< qcScanImg
@property (nonatomic, copy) NSString *qcScanBtn; ///< qcScanBtn
@property (nonatomic, copy) NSString *qcVoiceTips; ///< qcVoiceTips
@property (nonatomic, copy) NSString *qcVoiceBtn; ///< qcVoiceBtn
@property (nonatomic, copy) NSString *qcTipConfirm; /// < 确认指示灯在快闪 (目前为兼容 IPC 处理来做)
@property (nonatomic, copy) NSString *qcScanTips; /// <引导文案
@property (nonatomic, copy) NSString *qcScanGifUrl; /// <引导动图
// 二维码 (窝封)
@property (nonatomic, copy) NSString *qccellularTipIconUrl;
@property (nonatomic, copy) NSString *qccellularTip;
@property (nonatomic, copy) NSString *qccellularAddBtText;
@property (nonatomic, copy) NSString *qccellularHelpBtText;
@property (nonatomic, copy) NSString *qccellularHelpUrl;
@property (nonatomic, copy) NSString *qccellularVideoUrl; ///< 视频
@property (nonatomic, copy) NSString *qccellularScanTitle; ///< qcScanTitle
@property (nonatomic, copy) NSString *qccellularScanDesc; ///< qcScanDesc
@property (nonatomic, copy) NSString *qccellularScanImg; ///< qcScanImg
@property (nonatomic, copy) NSString *qccellularScanBtn; ///< qcScanBtn
@property (nonatomic, copy) NSString *qccellularVoiceTips; ///< qcVoiceTips
@property (nonatomic, copy) NSString *qccellularVoiceBtn; ///< qcVoiceBtn
@property (nonatomic, copy) NSString *qccellularTipConfirm; /// < 确认指示灯在快闪 (目前为兼容 IPC 处理来做)
@property (nonatomic, copy) NSString *qccellularScanTips; /// <引导文案
@property (nonatomic, copy) NSString *qccellularScanGifUrl; /// <引导动图
// 有线
@property (nonatomic, copy) NSString *wcTipIconUrl;
@property (nonatomic, copy) NSString *wcTip;
@property (nonatomic, copy) NSString *wcAddBtText;
@property (nonatomic, copy) NSString *wcHelpBtText;
@property (nonatomic, copy) NSString *wcHelpUrl;
@property (nonatomic, copy) NSString *wcVideoUrl; ///< 视频
@property (nonatomic, copy) NSString *wcTipConfirm; /// < 确认指示灯在快闪 (目前为兼容 IPC 处理来做)
// nb
@property (nonatomic, copy) NSString *nbTipIconUrl;
@property (nonatomic, copy) NSString *nbTip;
@property (nonatomic, copy) NSString *nbAddBtText;
@property (nonatomic, copy) NSString *nbHelpBtText;
@property (nonatomic, copy) NSString *nbHelpUrl;
@property (nonatomic, copy) NSString *nbVideoUrl; ///< 视频
// GPRS
@property (nonatomic, copy) NSString *gprsTipIconUrl;
@property (nonatomic, copy) NSString *gprsTip;
@property (nonatomic, copy) NSString *gprsAddBtText;
@property (nonatomic, copy) NSString *gprsHelpBtText;
@property (nonatomic, copy) NSString *gprsHelpUrl;
@property (nonatomic, copy) NSString *gprsVideoUrl; ///< 视频
// 蓝牙
@property (nonatomic, copy) NSString *btTipIconUrl;
@property (nonatomic, copy) NSString *btTip;
@property (nonatomic, copy) NSString *btAddBtText;
@property (nonatomic, copy) NSString *btHelpBtText;
@property (nonatomic, copy) NSString *btHelpUrl;
@property (nonatomic, copy) NSString *btVideoUrl; ///< 视频
// zigbee sub
@property (nonatomic, copy) NSString *zigsubTipIconUrl;
@property (nonatomic, copy) NSString *zigsubTip;
@property (nonatomic, copy) NSString *zigsubAddBtText;
@property (nonatomic, copy) NSString *zigsubHelpBtText;
@property (nonatomic, copy) NSString *zigsubHelpUrl;
@property (nonatomic, copy) NSString *zigsubVideoUrl; ///< 视频
// 433 sub
@property (nonatomic, copy) NSString *sub433TipIconUrl;
@property (nonatomic, copy) NSString *sub433Tip;
@property (nonatomic, copy) NSString *sub433AddBtText;
@property (nonatomic, copy) NSString *sub433HelpBtText;
@property (nonatomic, copy) NSString *sub433HelpUrl;
@property (nonatomic, copy) NSString *sub433VideoUrl; ///< 视频
// wifi assist
@property (nonatomic, copy) NSString *waTipIconUrl;
@property (nonatomic, copy) NSString *waTip;
@property (nonatomic, copy) NSString *waAddBtText;
@property (nonatomic, copy) NSString *waHelpBtText;
@property (nonatomic, copy) NSString *waHelpUrl;
@property (nonatomic, copy) NSString *waVideoUrl; ///< 视频
//router
@property (nonatomic, copy) NSString *routerTipIconUrl;
@property (nonatomic, copy) NSString *routerTip;
@property (nonatomic, copy) NSString *routerAddBtText;
@property (nonatomic, copy) NSString *routerHelpUrl;

//蓝牙扫码配网
@property (nonatomic, copy) NSString *bt_qrTipIconUrl;
@property (nonatomic, copy) NSString *bt_qrTip;
@property (nonatomic, copy) NSString *bt_qrAddBtText;
@property (nonatomic, copy) NSString *bt_qrHelpUrl;
@property (nonatomic, copy) NSString *bt_qrVideoUrl;

@end

NS_ASSUME_NONNULL_END
