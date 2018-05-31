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

// Deprecated methods
+ (MDEnvironment*)environmentWithBaseUrl:(NSString*)baseUrl organization:(NSString*)organization clientKey:(NSString*)clientKey DEPRECATED_MSG_ATTRIBUTE("Use -[MDEnvironment resetEnvironmentWithBaseUrl:organization:clientKey:] instead.");
+ (MDEnvironment*)environment DEPRECATED_MSG_ATTRIBUTE("Will be removed in future releases. Use +[MDEnvironment sharedEnvironment] instead.");

@end
