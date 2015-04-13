//
//  MDConnection.h
//  iOSMedableSDK
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

/// True is targeting the current user, False otherwise.
- (BOOL)isTargetingCurrentUser;

/// Id of the targeted account.
- (MDObjectId*)targetedId;

@end

/**
 * Represents a connection the current user has to another user with relationship to a context (an object instance).
 */
@interface MDConnection : NSObject

/// The Id of this connection object.
@property (nonatomic, readonly) MDObjectId* Id;

/**
 * The name of the object class this connection belongs to.
 */
@property (nonatomic, readonly) NSString* object;

/**
 * The date the connection was initiated
 */
@property (nonatomic, readonly) NSDate* created;

/**
 * The account id of the connection creator.
 */
@property (nonatomic, readonly) MDReference* creator;

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

/**
 * The access level granted by the connection. In the case of an ownership transfer, the access level is the object’s default owner access.
 */
@property (nonatomic, readonly) MDACLLevel access;

/**
 * A thumbnail image representing the connection.
 *
 * @param callback The asynchronous callback block where the thumbnail is returned. Check the MDFault object for errors.
 */ 
- (void)thumbnailWithCallback:(MDImageOrFaultCallback)callback;

@end
