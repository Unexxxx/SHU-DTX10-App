//
//  ThingSmartActivatorSearchEnum.h
//  Pods
//
//  Created by Jesse Zhou on 2021/8/27.
//

#ifndef ThingSmartActivatorType_h
#define ThingSmartActivatorType_h

/// Network configuration type.
typedef NS_OPTIONS(NSInteger, ThingSmartActivatorType) {
    ThingSmartActivatorTypeDefault =     0,       // Default
    ThingSmartActivatorTypeWired =       1 << 0,  // Wired
    ThingSmartActivatorTypeBle =         1 << 1,  // BLE
    ThingSmartActivatorTypeBleMesh =     1 << 2,  // BleMesh
    ThingSmartActivatorTypeSigMesh =     1 << 3,  // SigMesh
    ThingSmartActivatorTypeSubDevice =   1 << 4,  // Sub-device
    ThingSmartActivatorTypeEZSearch =    1 << 5,  // EZ 
    ThingSmartActivatorTypeAuto =        1 << 6,  // Auto
    ThingSmartActivatorTypeHomeKit =     1 << 7,  // HomeKit
    ThingSmartActivatorTypeRouter =      1 << 8,  // Router
    ThingSmartActivatorTypePegasus =     1 << 9,  // Pegasus
    ThingSmartActivatorTypeAP =          1 << 10, // AP
    ThingSmartActivatorTypeQRCode =      1 << 11, // Camera scans QR code
    ThingSmartActivatorTypeBroadband =   1 << 12, // Broadband
    ThingSmartActivatorTypeMatter =      1 << 13, // Matter
    ThingSmartActivatorTypeNB =          1 << 14, // NB
    ThingSmartActivatorTypeApDirectly =  1 << 15, // AP Direct
    ThingSmartActivatorTypeThingLink =   1 << 16, // TuyaLink
    ThingSmartActivatorTypeVirtual =     1 << 17, // Virtual
    ThingSmartActivatorTypeMQTTDirectly = 1 << 18, // GPRS/cat1/
    ThingSmartActivatorTypeInstallCode = 1 << 19, // ZigBee install code
    ThingSmartActivatorTypeBeacon =      1 << 20, // Beacon
    ThingSmartActivatorTypeEnd =         1 << 21,
};

// e.g. ThingSmartActivatorTypeDefault -> @"ThingSmartActivatorTypeDefault"
FOUNDATION_EXTERN NSString *NSStringFromThingSmartActivatorType(ThingSmartActivatorType value);
// e.g. @"ThingSmartActivatorTypeDefault" -> ThingSmartActivatorTypeDefault
FOUNDATION_EXTERN ThingSmartActivatorType ThingSmartActivatorTypeFromNSString(NSString *string);

#endif /* ThingSmartActivatorType_h */
