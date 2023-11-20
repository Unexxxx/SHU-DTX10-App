//
//  UIAlertView+Block.h
//  ThingBlockKit_Example
//
//  Created by ThingInc on 2018/12/13.
//  Copyright © 2018 ThingInc. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIAlertView (Block)

+ (UIAlertView *)bk_showAlertViewWithTitle:(NSString *)title
                        message:(NSString *)message
              cancelButtonTitle:(NSString *)cancelButtonTitle
              otherButtonTitles:(NSArray *)otherButtonTitles
                        handler:(void (^)(UIAlertView *alertView, NSInteger buttonIndex))block;

+ (id)bk_alertViewWithTitle:(NSString *)title;

/** Creates and returns a new alert view with only a title, message, and cancel button.
 
 @param title The title of the alert view.
 @param message The message content of the alert.
 @return A newly created alert view.
 */
+ (id)bk_alertViewWithTitle:(NSString *)title
                    message:(NSString *)message;

/** Returns a configured alert view with only a title, message, and cancel button.
 
 @param title The title of the alert view.
 @param message The message content of the alert.
 @return An instantiated alert view.
 */
- (id)bk_initWithTitle:(NSString *)title
               message:(NSString *)message NS_REPLACES_RECEIVER;

///-----------------------------------
/// @name Adding buttons
///-----------------------------------

/** Add a new button with an associated code block.
 
 @param title The text of the button.
 @param block A block of code.
 */
- (NSInteger)bk_addButtonWithTitle:(NSString *)title
                           handler:(void (^)(void))block;

/** Set the title and trigger of the cancel button.
 
 @param title The text of the button.
 @param block A block of code.
 */
- (NSInteger)bk_setCancelButtonWithTitle:(NSString *)title
                                 handler:(void (^)(void))block;

///-----------------------------------
/// @name Altering actions
///-----------------------------------

/** Sets the block that is to be fired when a button is pressed.
 
 @param block A code block, or nil to set no response.
 @param index The index of a button already added to the action sheet.
 */
- (void)bk_setHandler:(void (^)(void))block
     forButtonAtIndex:(NSInteger)index;

/** The block that is to be fired when a button is pressed.
 
 @param index The index of the button already added to the alert view.
 @return A code block, or nil if no block yet assigned.
 */
- (void (^)(void))bk_handlerForButtonAtIndex:(NSInteger)index;


@property (nonatomic, copy, setter = bk_setCancelBlock:) void (^bk_cancelBlock)(void);

@end

NS_ASSUME_NONNULL_END
