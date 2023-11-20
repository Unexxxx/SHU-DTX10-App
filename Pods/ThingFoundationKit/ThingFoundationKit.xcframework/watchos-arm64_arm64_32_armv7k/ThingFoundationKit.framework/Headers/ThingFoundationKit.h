//
//  ThingFoundationKit.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2018/12/24.
//

#ifdef __OBJC__
    #import <Foundation/Foundation.h>
#else
    #ifndef FOUNDATION_EXTERN
        #if defined(__cplusplus)
            #define FOUNDATION_EXTERN extern "C"
        #else
            #define FOUNDATION_EXTERN extern
        #endif
    #endif
#endif

#ifndef ThingFoundationKit_h
#define ThingFoundationKit_h

#import "NSObject+ThingFoundation.h"
#import "ThingFoundationKitMacro.h"
#import "ThingAssert.h"

#import "CLLocationCoordinate+ThingCategory.h"
#import "NSNotificationCenter+ThingCategory.h"
#import "NSFileManager+ThingCategory.h"
#import "NSDictionary+ThingCategory.h"
#import "NSTimeZone+ThingCategory.h"
#import "NSBundle+ThingCategory.h"
#import "NSLocale+ThingCategory.h"
#import "NSString+ThingCategory.h"
#import "NSLocale+ThingCountry.h"
#import "NSArray+ThingCategory.h"
#import "NSArray+ThingSafe.h"
#import "NSData+ThingCategory.h"
#import "NSDate+ThingCategory.h"
#import "NSURL+ThingCategory.h"
#import "NSObject+ThingRateLimiting.h"
#import "ThingDispatchQueue.h"
#import "ThingVersionString.h"
#import "ThingWeakProxy.h"
#import "ThingKVOController.h"
#import "NSObject+ThingSwizzle.h"

#pragma mark - Encrypt
#import "ThingDigestImpl.h"
#import "ThingAESImpl.h"
#import "ThingRSAImpl.h"
#import "ThingStringXORImpl.h"

#pragma mark - Localized
#import "ThingLanguageLoader.h"
#import "NSString+ThingLocalized.h"

#import "ThingTemperatureConversion.h"

#if TARGET_OS_IOS

#import "Reachability+ThingNetwork.h"


#endif

#endif /* ThingFoundationKit_h */
