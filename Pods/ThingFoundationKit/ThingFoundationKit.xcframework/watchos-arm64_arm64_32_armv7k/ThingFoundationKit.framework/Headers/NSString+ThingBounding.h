//
//  NSString+ThingBounding.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/3/26.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (ThingBounding)

- (CGSize)thing_boundingSizeWithFont:(UIFont *)font constrainedToSize:(CGSize)maxSize lineBreakMode:(NSLineBreakMode)breakMode;
- (CGSize)thing_boundingSizeWithFont:(UIFont *)font constrainedToSize:(CGSize)maxSize paragraphStyle:(nullable NSParagraphStyle *)paragraphStyle;

- (CGFloat)thing_boundingWidthWithFont:(UIFont *)font;
- (CGFloat)thing_boundingHeightWithFont:(UIFont *)font constrainedToWidth:(CGFloat)maxWidth;

@end

NS_ASSUME_NONNULL_END
