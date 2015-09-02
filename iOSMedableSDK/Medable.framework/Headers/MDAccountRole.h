//
//  MDAccountRole.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * A role configured for an Organization. An account can have more than one role.
 */
@interface MDAccountRole : NSObject

/// The role identifier.
@property (nonatomic, readonly) MDObjectId* Id;

/// A list of all included roles, including those grouped inside any included roles. ObjectId[].
@property (nonatomic, readonly) NSArray* all;

/// Custom roles may be grouped to include other custom roles. Accounts holding the role will be also considered to hold the included roles. ObjectId[].
@property (nonatomic, readonly) NSArray* include;

/// The role name (eg. “Care Giver”).
@property (nonatomic, readonly) NSString* name;

@end
