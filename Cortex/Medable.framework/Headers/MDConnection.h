//
//  MDConnection.h
//  Medable
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Specifies the target in a connection between two users.
 */
@interface MDConnectionTarget : NSObject

/// The target's first name.
@property (nonatomic, readonly) NSString* firstName;

/// The target's last name.
@property (nonatomic, readonly) NSString* lastName;

/// The target's email.
@property (nonatomic, readonly) NSString* email;

/// A reference to the target's account.
@property (nonatomic, readonly) MDReference* account;


// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

/// True is targeting the current user, False otherwise.
- (BOOL)isTargetingCurrentUser;

/// Id of the targeted account.
- (MDObjectId*)targetedId;

@end

/**
 * Represents a connection the current user has to another user with relationship to a context (an object instance).
 */
@interface MDConnection : MDObjectInstance

/**
 * The connection target recipient. The email property will only be present if the connection was created using an email address. Conversely, the account property will only be present if the connection was created using an account id. The name property will only be present if the connection creator added one.
 */
@property (nonatomic, readonly) MDConnectionTarget* target;

/**
 * True if the context has been archived.
 */
@property (nonatomic, readonly) NSNumber* isArchived;

/**
 * The connection state.
 */
@property (nonatomic, readonly) MDConnectionState state;

/**
 * A reference to the object instance this connection was made out for.
 */
@property (nonatomic, readonly) MDReference* context;

/**
 * The connection token.
 */
@property (nonatomic, readonly) NSString* token;

/**
 * For pending connections. the time at which the connection request will expire.
 */
@property (nonatomic, readonly) NSDate* expiresAt;


// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

/**
 * A thumbnail image representing the connection.
 *
 * @param callback The asynchronous callback block where the thumbnail is returned. Check the MDFault object for errors.
 */ 
- (void)thumbnailWithCallback:(MDImageOrFaultCallback)callback;

/**
 * Update the receiver with the latest data from the backend.
 *
 * @param parameters Extra parameters in the API call. Connections and posts may be included here.
 * @param callback The asynchronous callback, called upon receiving a response from the backend.
 */
- (void)synchronizeObjectWithParameters:(MDAPIParameters *)parameters
                               callback:(MDObjectFaultCallback)callback;

@end
