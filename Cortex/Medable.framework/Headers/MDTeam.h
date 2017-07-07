//
//  MDTeam.h
//  Medable
//
//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MDObjectInstance.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Teams contain a set of accounts and can be used for collaborating in groups. Teams can also
 * be used in place of users when creating collaborations as a means to invite multiple accounts
 * at once.
 */
@interface MDTeam : MDObjectInstance

/**
 * A short description of the team.
 */
@property (nullable, nonatomic, readonly) NSString* teamDescription;

/**
 * Integer representing the number of team members.
 */
@property (nullable, nonatomic, readonly) NSNumber* memberCount;

/**
 * Team name.
 */
@property (nonatomic, readonly) NSString* name;


// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

/**
 * Whether the team contains a member with a given member identifier.
 *
 * @param Id Unique identifier of the member.
 * @return True if the team contains this member, False otherwise.
 */
- (BOOL)containsMemberWithId:(MDObjectId*)Id;

/**
 * List of pending invitations.
 */
- (nullable NSArray*)invitations;

@end

NS_ASSUME_NONNULL_END
