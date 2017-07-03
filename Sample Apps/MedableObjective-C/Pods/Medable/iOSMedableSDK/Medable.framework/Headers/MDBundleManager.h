//
//  MDBundleManager.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MDBundle;

typedef void (^BundleLoaderCallback) (MDBundle* bundle, MDFault* fault);

/**
 * Load and manage the local bundle.
 */
@interface MDBundleManager : NSObject

/**
 * Local MDBundle instance, this value is nil the bundle is downloaded for the first time.
 *
 * @see -bundleWithCallback:
 */
@property (nonatomic, readonly) MDBundle* localBundle;

/// Singleton Instance
+ (MDBundleManager*)sharedManager;

/**
 * Fetch the latest version of the local bundle.
 *
 * @param callback Asynchronous callback block that gets called after processing.
 */
- (void)bundleWithCallback:(BundleLoaderCallback)callback NOTNULL(1);

@end
