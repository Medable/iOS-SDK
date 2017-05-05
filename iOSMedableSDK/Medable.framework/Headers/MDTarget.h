//
//  MDTarget.h
//  iOSMedableSDK
//
//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 * Target base class
 */
@interface MDTarget : NSObject
@end

/*
 *  Targets used for when creating connections
 */
@interface MDConnectTarget : MDTarget


/**
 * Creates a connect target.
 * @param context target context
 * @param objectId context object Id
 * @param access access level
 * @param additionalInfo additional info
 * @param autoAccept auto accept connection
 **/
+ (MDConnectTarget*)targetWithContext:(NSString*)context
                            contextId:(MDObjectId*)objectId
                               access:(MDACLLevel)access
                       additionalInfo:(NSDictionary*)additionalInfo
                           autoAccept:(NSNumber*)autoAccept NOTNULL(1);

/**
 * Creates a connect target.
 * @param email Target email
 * @param firstName Target first name
 * @param lastName Target last name
 * @param access Target access
 **/
+ (MDConnectTarget*)targetWithEmail:(NSString*)email
                          firstName:(NSString*)firstName
                           lastName:(NSString*)lastName
                             access:(MDACLLevel)access NOTNULL(1);

@end

/*
 *  Targets used for when creating posts
 */
@interface MDPostTarget : MDTarget

/**
 * Creates a connect target.
 * @param accountId Target account Id
 */
+ (MDPostTarget*)targetWithAccountId:(MDObjectId*)accountId NOTNULL(1);

/**
 * Creates a connect target.
 * @param role Target role
 */
+ (MDPostTarget*)targetWithRole:(MDAccountRole*)role NOTNULL(1);

@end

/*
 *  Targets container. This is used as parameter of API methods that accept targets (both types, connection and post targets).
 *  Also it provides API compatible format to create the required parameters for related services method calls.
 */
@interface MDTargets : NSObject

/**
 * Creates a container with the targets array provided as varargs. The list must be nil terminated.
 * @param firstObject Nil terminated array of MDTarget objects.
 */
+ (MDTargets*)instanceWithTargets:(MDTarget*)firstObject, ... NS_REQUIRES_NIL_TERMINATION;

/**
 * Adds a new target to the container.
 * @param target the target to add. Can't be nil.
 */
- (void)addTarget:(MDTarget*)target NOTNULL(1);

/**
 * Returns the amount of targets this container has.
 */
- (NSUInteger)count;

/**
 * Provides API compatible target parameters.
 */
- (NSDictionary*)apiFormat;

@end
