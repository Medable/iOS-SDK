//
//  MDBundleManager.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MDBundle;

typedef void (^BundleLoaderCallback) (MDBundle* _Nullable bundle, MDFault* _Nullable fault);

/**
 * Load and manage the local bundle.
 */
@interface MDBundleManager : NSObject

/**
 * Local MDBundle instance, this value is nil the bundle is downloaded for the first time.
 *
 * @see -bundleWithCallback:
 */
@property (nullable, nonatomic, readonly) MDBundle* localBundle;

/// Singleton Instance
+ (nonnull MDBundleManager*)sharedManager;


// unavailable
+ (nonnull instancetype)new NS_UNAVAILABLE;

// unavailable init
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Fetch the latest version of the local bundle.
 *
 * @param callback Asynchronous callback block that gets called after processing.
 */
- (void)bundleWithCallback:(nonnull BundleLoaderCallback)callback;

@end
