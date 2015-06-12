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


/*
 * Creates a connect target.
 * @param context
 * @param objectId
 * @param access
 * @param additionalInfo
 * @param autoAccept
 */
+ (MDConnectTarget*)targetWithContext:(NSString*)context
                            contextId:(MDObjectId*)objectId
                               access:(MDACLLevel)access
                       additionalInfo:(NSDictionary*)additionalInfo
                           autoAccept:(NSNumber*)autoAccept NOTNULL(1);

/*
 * Creates a connect target.
 * @param email
 * @param firstName
 * @param lastName
 * @param access
 */
+ (MDConnectTarget*)targetWithEmail:(NSString*)email
                          firstName:(NSString*)firstName
                           lastName:(NSString*)lastName
                             access:(MDACLLevel)access NOTNULL(1);

@end

/*
 *  Targets used for when creating posts
 */
@interface MDPostTarget : MDTarget

/*
 * Creates a connect target.
 * @param accountId
 */
+ (MDPostTarget*)targetWithAccountId:(MDObjectId*)accountId NOTNULL(1);

/*
 * Creates a connect target.
 * @param role
 */
+ (MDPostTarget*)targetWithRole:(MDAccountRole*)role NOTNULL(1);

@end

/*
 *  Targets container. This is used as parameter of API methods that accept targets (both types, connection and post targets).
 *  Also it provides API compatible format to create the required parameters for related services method calls.
 */
@interface MDTargets : NSObject

/*
 * Creates a container with the targets array provided as varargs. The list must be nil terminated.
 * @param firstObject, ... Nil terminated array of MDTarget objects.
 */
+ (MDTargets*)instanceWithTargets:(MDTarget*)firstObject, ... NS_REQUIRES_NIL_TERMINATION;

/*
 * Adds a new target to the container.
 * @param target the target to add. Can't be nil.
 */
- (void)addTarget:(MDTarget*)target NOTNULL(1);

/*
 * Returns the ammount of targets this container has.
 */
- (NSUInteger)count;

/*
 * Provides API compatible target parameters.
 */
- (NSDictionary*)apiFormat;

@end
