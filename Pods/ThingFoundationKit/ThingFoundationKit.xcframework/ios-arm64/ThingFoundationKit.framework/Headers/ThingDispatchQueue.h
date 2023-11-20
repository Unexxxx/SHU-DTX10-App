//
//  ThingDispatchQueue.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/5/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 sync to main thread if current thread isn't main
 execute directly if current thread is main
 */
void thing_sync_on_main(dispatch_block_t block);
/**
 async to main thread if current thread isn't main
 execute directly if current thread is main
 */
void thing_async_on_main(dispatch_block_t block);
/**
 async to global thread
 */
void thing_async_on_global(dispatch_block_t block);


void thing_delay_on_main(NSTimeInterval delayInSeconds, dispatch_block_t block);

void thing_delay_on_global(NSTimeInterval delayInSeconds, dispatch_block_t block);


NS_ASSUME_NONNULL_END
