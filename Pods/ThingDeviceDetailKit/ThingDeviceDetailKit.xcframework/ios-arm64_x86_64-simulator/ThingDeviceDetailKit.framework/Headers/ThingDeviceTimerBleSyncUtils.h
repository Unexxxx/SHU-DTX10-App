//
//  ThingDeviceTimerBleSyncUtils.h
//  ThingDeviceDetailKit
//
//  Created by 后主 on 2023/8/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// ===========
/// 蓝牙协议实现
/// ===========
///
/// 蓝牙通道业务标识【蓝牙定时业务】
/// 蓝牙定时 subcmd, 2 字节
#define ThingDeviceTimerBleSyncSubCmdLength 2
#define ThingDeviceTimerBleSyncSubCmd 0x0000

/// 最多定时任务 30
#define ThingDeviceTimerBleSyncMaxTaskSize 30

/// 定时类型
typedef NS_ENUM(uint8_t, ThingDeviceTimerBleSyncTimerType) {
    /// 普通定时
    ThingDeviceTimerBleSyncTimerType_Normal = 0x01,
};

/// 操作码
typedef NS_ENUM(uint8_t, ThingDeviceTimerBleSyncOpCode) {
    /// 设置定时
    ThingDeviceTimerBleSyncOPCode_Set = 0x01,
    /// 删除定时
    ThingDeviceTimerBleSyncOPCode_Remove = 0x02,
    /// 读取定时
    ThingDeviceTimerBleSyncOPCode_Read = 0x03,
};

/// 操作结果
typedef NS_ENUM(uint8_t, ThingDeviceTimerBleSyncResultCode) {
    /// 操作成功
    ThingDeviceTimerBleSyncResultCodeSuccess = 0x00,
    /// 操作失败
    ThingDeviceTimerBleSyncResultCodeFail_Unknow = 0x01
};


/// ============
/// 读取的定时任务
/// ============

/**
 读取的定时任务 Header size  (3 bytes)
 ret_code | count | length
 */
#define ThingDeviceTimerBleSyncReadingDataHeaderSize 3
/**
 读取的单个定时任务数据大小 (8 bytes)
 timer_id | crc32
 */
#define ThingDeviceTimerBleSyncReadingDataBodyLength 8

/// 读取的定时任务 Header
typedef struct ThingDeviceTimerBleSyncReadingHeader {
    ThingDeviceTimerBleSyncResultCode ret_code;           // 操作结果
    uint8_t count;                                        // 返回个数
    uint8_t length;                                       // 数据长度（length+id1+crc+id2+crc+…）包含自己
} ThingDeviceTimerBleSyncReadingHeader;



/// 读取的定时任务 body
@interface ThingDeviceTimerBleSyncReadingBody: NSObject
@property (nonatomic, assign) uint32_t timer_id; // 定时 id
@property (nonatomic, assign) uint32_t crc32;
@end


/// 读取的定时任务
@interface ThingDeviceTimerBleSyncReadingTask : NSObject
@property (nonatomic, assign) ThingDeviceTimerBleSyncReadingHeader header;
@property (nullable, nonatomic, copy) NSArray<ThingDeviceTimerBleSyncReadingBody *> *taskList;

/// 使用蓝牙返回的 data 初始化
/// @param data 蓝牙返回的 data
/// @return 返回 nil 如果格式有问题
- (nullable instancetype)initWithBleData:(NSData *)data;
@end


/// ============
/// 设置的定时任务
/// ============

/**
 设置定时的 data header size (bytes)
 ThingDeviceTimerBleSyncOpCode - ThingDeviceTimerBleSyncTimerType - 数据长度（2bytes）
 */
#define ThingDeviceTimerBleSyncSettingDataHeaderLength 4

/// DP Thingpe
typedef NS_ENUM(uint8_t, ThingDeviceTimerBleDPType) {
    ThingDeviceTimerBleDPType_RAW = 0,
    ThingDeviceTimerBleDPType_BOOL = 1,
    ThingDeviceTimerBleDPType_VALUE = 2,
    ThingDeviceTimerBleDPType_STRING = 3,
    ThingDeviceTimerBleDPType_ENUM = 4,
    ThingDeviceTimerBleDPType_BITMAP = 5,
};

/// 设置的定时任务 header （10 个字节）
typedef struct ThingDeviceTimerBleSyncSettingHeader {
    uint8_t year;       //（低两位）
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t loops;
    uint32_t timer_id;
} ThingDeviceTimerBleSyncSettingHeader;






@interface ThingDeviceTimerBleSyncSettingTask : NSObject

@property (nonatomic, assign) ThingDeviceTimerBleSyncSettingHeader header;

/// 如果 YES 计算 crc32 的范围为 header{hour, minute, loops, timer_id}, dpData
/// 否则 header{year, month, day, hour, minute, loops, timer_id}, dpData
///
/// 默认 NO
@property (nonatomic) BOOL crc32IgnoreDate;

/// 大端序
///
/// `makeData` 后生成
@property (nonatomic, assign) uint32_t crc32;

/// 初始化设置定时任务
/// @param header 头部
/// @param dps 定时 DP
/// @param schemaDict dp schema
- (instancetype)initWithHeader:(ThingDeviceTimerBleSyncSettingHeader)header dps:(NSDictionary *)dps schemaDict:(NSDictionary *)schemaDict;

// convenience method
- (instancetype)initWithTimerId:(uint32_t)timerId loops:(NSString *)loops dps:(NSDictionary *)dps dateComponents:(NSDateComponents *)dateComponents schemaDict:(NSDictionary *)schemaDict;

/// 返回传给蓝牙设备的 Data
///
/// @note 只有调用这个方法才会计算  `crc32`
- (NSData *)makeData;

@end


@interface ThingDeviceTimerBleSyncUtils : NSObject

/// 2 进制字符串转到 uint32_t
+ (uint32_t)convertBinaryStringToUint32:(NSString *)binaryString;

@end

NS_ASSUME_NONNULL_END
