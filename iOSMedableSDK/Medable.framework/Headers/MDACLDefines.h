//
//  MDACLDefines.h
//  iOSMedableSDK
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Helper class that defines static access levels.
 */
@interface MDACLDefines : NSObject

#pragma mark - Access Levels

/// Public: A principal with this access can scan public details (eg, Org logo).
+ (MDACLLevel)aclLevelPublic;

///Connected: Granted when making Connections, and typically provides read access to context properties.
+ (MDACLLevel)aclLevelConnected;

///Reserved: Reserved for a future release.
+ (MDACLLevel)aclLevelReserved;

///Read: Grants access to private context properties. For example, accounts get read access to themselves and can read the account’s email property.
+ (MDACLLevel)aclLevelRead;

///Share: Those with share access can create connections to a context using object’s Share Chain
+ (MDACLLevel)aclLevelShare;

///Update: Update access typically provides write access to context properties.
+ (MDACLLevel)aclLevelUpdate;

///Delete: Grants access to delete delete/archive a context.
+ (MDACLLevel)aclLevelDelete;

///Admin: Administrator access.
+ (MDACLLevel)aclLevelAdmin;

#pragma mark - Targets

/// Type value used when targeting accounts. Set this as the type and accompany it with an account ID to connect to other accounts.
+ (MDACLAccessTarget)aclAccessTargetAccount;

/// Type value used when targeting teams. Set this as the type and accompany it with a team ID to connect to other teams.
+ (MDACLAccessTarget)aclAccessTargetTeam;

/// Type value used when targeting roles.
+ (MDACLAccessTarget)aclAccessTargetRole;

#pragma mark - Helpers

/**
 * Convert a number to an access level value.
 *
 * @param aclNumber The number object (e.g. as received via a network call) corresponding to an access level.
 * @return The access level value corresponding to the parameter.
 */
+ (MDACLLevel)aclLevelFromNumber:(nonnull NSNumber*)aclNumber;

@end
