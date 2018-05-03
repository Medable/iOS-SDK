//
//  MDAccount.h
//  Medable
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
 * Name Prefix
 */
@property (nullable, nonatomic, readonly) NSString* namePrefix;

/**
 * First Name
 */
@property (nonnull, nonatomic, readonly) NSString* firstName;

/**
 * Middle Name
 */
@property (nullable, nonatomic, readonly) NSString* middleName;

/**
 * Last Name
 */
@property (nonnull, nonatomic, readonly) NSString* lastName;

/**
 * Name Suffix
 */
@property (nullable, nonatomic, readonly) NSString* nameSuffix;

/**
 * Name Additionals
 */
@property (nullable, nonatomic, readonly) NSArray<NSString *> *nameAdditionals;

/**
 * Account holder gender.
 */
@property (nonatomic, readonly) MDGender gender;

/**
 * The email address for the account and must be unique within the Org.
 */
@property (nonnull, nonatomic, readonly) NSString* email;

/**
 * Mobile phone number. Required for 2-factor authentication.
 */
@property (nonnull, nonatomic, readonly) NSString* mobile;

/**
 * Account roles (e.g. Provider, Administrator, Developer). Accounts can have more than one role.
 */
@property (nullable, nonatomic, readonly) NSArray<MDObjectId *> *roles;

/**
 * True if the account must be activated before use. Dependant on Org settings.
 */
@property (nullable, nonatomic, readonly) NSNumber* activationRequired;

/**
 * An integer representing the access held by the account on the object in context. This property is set in the results or Object.connections and the GET /collaboration/:context/:objectId route
 */
@property (nonatomic, readonly) MDACLLevel connectionAccess;

/**
 * The account profile image.
 */
@property (nullable, nonatomic, readonly) MDFilePropertyValue* image;

/**
 * Institutional affiliation of the provider.
 */
@property (nullable, nonatomic, readonly) NSString* affiliation;

/**
 * National Provider Identifier number
 */
@property (nullable, nonatomic, readonly) NSString* npi;

/**
 * State of provider verification (e.g. unverified, processing, verified, revoked)
 */
@property (nullable, nonatomic, readonly) NSString* state;

/**
 * State/province where provider is licensed to practice
 */
@property (nullable, nonatomic, readonly) NSString* licenseState;

/**
 * State/province license number
 */
@property (nullable, nonatomic, readonly) NSString* licenseNumber;

/**
 * Specialty of provider
 */
@property (nullable, nonatomic, readonly) NSString* specialty;

/**
 * Account holder date of birth
 */
@property (nullable, nonatomic, readonly) NSDate* dob;

/**
 * A dictionary with preferences like 'notifications'
 */
@property (nullable, nonatomic, readonly) NSDictionary* preferences;

/**
 * Current state for the account. (e.g. unverified, verified)
 */
@property (nonatomic, readonly) MDAccountState accountState;

/**
 * Current locale of the Account for localization.
 */
@property (nullable, nonatomic, readonly) NSString* locale;

/**
 * True if the account is locked. A locked account cannot sign-in.
 */
@property (nullable, nonatomic, readonly) NSNumber* locked;

/**
 * Account's time zone name.
 */
@property (nullable, nonatomic, readonly) NSString* timeZone;


/**
 * Returns True if the account has a role with this name.
 *
 * @param roleName The name of the role, examples can include the constants `kAdminKey`, `kProviderKey`, etc.
 * @return True if the account has a role with this name, False otherwise.
 */
- (BOOL)hasAccountRoleWithName:(nonnull NSString*)roleName;

/**
 * Returns whether the receiver is connected to the parameter account.
 *
 * @param accountId Id of the other account.
 * @return True if the receiver is connected to the account, False otherwise.
 */
- (BOOL)isConnectedWithId:(nonnull MDObjectId*)accountId;

/**
 * Returns whether the receiver has sent an invitation to the parameter account.
 *
 * @param Id Id of the other account.
 * @return True if the receiver has invited the other account, False otherwise.
 */
- (BOOL)sentInviteToId:(nonnull MDObjectId*)Id;

/**
 * Get the account's thumbnail image.
 *
 * @param callback The asynchronous callback where the image is returned.
 */
- (void)thumbnailWithCallback:(nonnull MDImageOrFaultCallback)callback;

@end
