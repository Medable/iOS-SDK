//
//  MDLegalAgreement.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

/**
 * Legal agreement.
 */
@interface MDLegalAgreement : NSObject

/// Name.
@property (nonatomic, readonly) NSString* name;

/// Title.
@property (nonatomic, readonly) NSString* title;

/// Version.
@property (nonatomic, readonly) NSString* version;

/// Value.
@property (nonatomic, readonly) NSString* value;

/// Target.
@property (nonatomic, readonly) NSString* target;

/**
 * Initializer.
 *
 * @param name Name.
 * @param dictionary Information about the agreement.
 * @return Initialized object.
 */
- (MDLegalAgreement*)initWithName:(NSString*)name dictionary:(NSDictionary*)dictionary NOTNULL(1);

/**
 * Prompt the user for acceptance of this legal agreement.
 *
 * @param callback Asynchronous callback called after the user agrees / disagrees on the legal agreement.
 */
- (void)promptUserForAcceptanceWithCallback:(MDBoolCallback)callback NOTNULL(1);

/**
 * Whether the user is pending acceptance of an agreement.
 *
 * @param agreement The legal agreement.
 * @return Whether the user has pending agreement on the legal agreement.
 */
- (BOOL)isAcceptPendingForAgreement:(MDLegalAgreement*)agreement NOTNULL(1);

/// Whether this agreement targets the current user.
- (BOOL)targetsCurrentUser;

@end
