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

/// Unique identifier.
@property (nonatomic, readonly) MDObjectId* Id;

/// All roles of the account.
@property (nonatomic, readonly) NSArray* all;

/// All included roles of the account.
@property (nonatomic, readonly) NSArray* include;

/// The name of the role.
@property (nonatomic, readonly) NSString* name;

@end
