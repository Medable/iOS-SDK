//
//  MDTeam.h
//  iOSMedableSDK
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MDObjectInstance.h"

/**
 * Teams contain a set of accounts and can be used for collaborating in groups. Teams can also
 * be used in place of users when creating collaborations as a means to invite multiple accounts
 * at once.
 */
@interface MDTeam : MDObjectInstance

/**
 * A short description of the team.
 */
@property (nonatomic, readonly) NSString* teamDescription;

/**
 * Integer representing the number of team members.
 */
@property (nonatomic, readonly) NSNumber* memberCount;

/**
 * Team name.
 */
@property (nonatomic, readonly) NSString* name;

/**
 * Whether the team contains a member with a given member identifier.
 *
 * @param Id Unique identifier of the member.
 * @return True if the team contains this member, False otherwise.
 */
- (BOOL)containsMemberWithId:(MDObjectId*)Id NOTNULL(1);

/**
 * List of pending invitations.
 */
- (NSArray*)invitations;

@end
