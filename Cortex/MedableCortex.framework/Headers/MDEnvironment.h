//
//  MDEnvironment.h
//  Medable
//
//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * A Medable Environment holds basic information about your SDK's configuration to operate with the backend API.
 */
@interface MDEnvironment : NSObject

/// Singleton Instance - For Swift users, this method is lost in translation, use sharedEnvironment instead.
+ (MDEnvironment*)environment DEPRECATED_MSG_ATTRIBUTE("Will be removed in future releases.");

/// Singleton Instance
+ (MDEnvironment*)sharedEnvironment;

// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

/// The API URL includes the organization and API version as part of it's path.
- (NSString*)APIURL;

/// Private API key or Medable Client Key.
- (NSString*)appAPIKey;

/**
 * Name of the Organization.
 *
 * @see MDOrg
 */
- (NSString*)orgName;

@end
