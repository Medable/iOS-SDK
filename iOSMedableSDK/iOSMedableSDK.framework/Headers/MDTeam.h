//
//  MDTeam.h
//  iOSMedableSDK
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MDObjectInstance.h"

@interface MDTeam : MDObjectInstance

/**
 * A short description of the team
 */
@property (nonatomic, readonly) NSString* teamDescription;

/**
 * Integer representing the number of team members
 */
@property (nonatomic, readonly) NSNumber* memberCount;

/**
 * Team name
 */
@property (nonatomic, readonly) NSString* name;

- (BOOL)containsMemberWithId:(MDObjectId*)Id NOTNULL(1);
- (NSArray*)invitations;

@end
