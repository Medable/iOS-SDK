//
//  MDAccount.h
//  iOSMedableSDK
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MDObjectInstance.h"

/**
 * Base class representing an account.
 */
@interface MDAccount : MDObjectInstance

/**
 * First Name
 */
@property (nonatomic, readonly) NSString* firstName;

/**
 * Last Name
 */
@property (nonatomic, readonly) NSString* lastName;

/**
 * Account holder gender.
 */
@property (nonatomic, readonly) MDGender gender;

/**
 * The email address for the account and must be unique within the Org.
 */
@property (nonatomic, readonly) NSString* email;

/**
 * Mobile phone number. Required for 2-factor authentication.
 */
@property (nonatomic, readonly) NSString* mobile;

/**
 * Account roles (e.g. Provider, Administrator, Developer). Accounts can have more than one role.
 */
@property (nonatomic, readonly) NSArray* roles;

/**
 * True if the account must be activated before use. Dependant on Org settings.
 */
@property (nonatomic, readonly) NSNumber* activationRequired;

/**
 * An integer representing the access held by the account on the object in context. This property is set in the results or Object.connections and the GET /collaboration/:context/:objectId route
 */
@property (nonatomic, readonly) MDACLLevel connectionAccess;

/**
 * The account profile image.
 */
@property (nonatomic, readonly) MDFilePropertyValue* image;

/**
 * List of teams that the Account belongs to.
 */
@property (nonatomic, readonly) NSArray* teams;

/**
 * Institutional affiliation of the provider.
 */
@property (nonatomic, readonly) NSString* affiliation;

/**
 * National Provider Identifier number
 */
@property (nonatomic, readonly) NSString* npi;

/**
 * State of provider verification (e.g. unverified, processing, verified, revoked)
 */
@property (nonatomic, readonly) NSString* state;

/**
 * State/province where provider is licensed to practice
 */
@property (nonatomic, readonly) NSString* licenseState;

/**
 * State/province license number
 */
@property (nonatomic, readonly) NSString* licenseNumber;

/**
 * Specialty of provider
 */
@property (nonatomic, readonly) NSString* specialty;

/**
 * Account holder date of birth
 */
@property (nonatomic, readonly) NSString* dob;

/**
 * A dictionary with preferences like 'notifications'
 */
@property (nonatomic, readonly) NSDictionary* preferences;

/**
 * Current state for the account. (e.g. unverified, verified)
 */
@property (nonatomic, readonly) MDAccountState accountState;

/**
 * Current locale of the Account for localization.
 */
@property (nonatomic, readonly) NSString* locale;

/**
 * True if the account is locked. A locked account cannot sign-in.
 */
@property (nonatomic, readonly) NSNumber* locked;


/**
 * Returns True if the account has a role with this name.
 *
 * @param roleName The name of the role, examples can include the constants `kAdminKey`, `kProviderKey`, etc.
 * @return True if the account has a role with this name, False otherwise.
 */
- (BOOL)hasAccountRoleWithName:(NSString*)roleName;

/**
 * Returns whether the receiver is connected to the parameter account.
 *
 * @param accountId Id of the other account.
 * @return True if the receiver is connected to the account, False otherwise.
 */
- (BOOL)isConnectedWithId:(MDObjectId*)accountId NOTNULL(1);

/**
 * Returns whether the receiver has sent an invitation to the parameter account.
 *
 * @param Id Id of the other account.
 * @return True if the receiver has invited the other account, False otherwise.
 */
- (BOOL)sentInviteToId:(MDObjectId*)Id NOTNULL(1);

/**
 * Get the account's thumbnail image.
 *
 * @param callback The asynchronous callback where the image is returned.
 */
- (void)thumbnailWithCallback:(MDImageOrFaultCallback)callback NOTNULL(1);

/**
 * Assemble the full name on the account.
 *
 * @return Full Name.
 */
- (NSString*)fullName;

@end
