//
//  MDLegalAgreementManager.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

extern NSString* const kTermsKey;
extern NSString* const kPrivacyKey;
extern NSString* const kBusinessAssociateAgreementKey;
extern NSString* const kConsentKey;

/**
 * Legal agreements manager.
 */
@interface MDLegalAgreementManager : NSObject

/// Singleton instance.
+ (MDLegalAgreementManager*)sharedManager;

/// Identifier for this platform.
- (NSString*)platformIdentifier;

/**
 * Set the legal agreements from a downloaded attributes dictionary.
 *
 * @param dictionary Agreements in dictionary format.
 */
- (void)setAgreementsFromDictionary:(NSDictionary*)dictionary NOTNULL(1);

/// Clear all agreements from the manager.
- (void)clearAgreements;

/**
 * Check whether the user still has legal agreements to accept.
 *
 * @param callback The callback where the acceptance of agreements is returned on.
 * @return True if there are legal agreements still to accept.
 */
- (BOOL)checkLegalAgreementsWithCallback:(MDBoolCallback)callback NOTNULL(1);

@end
