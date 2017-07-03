//
//  MDBundle.h
//  Medable
//
//  
//  Copyright (c) 2014 Medable. All rights reserved.
//

@class MDLegalAgreement;

/**
 * A bundle represents additional information about an Organization.
 *
 * @see MDOrg
 */
@interface MDBundle : NSObject

/// Which Organization this bundle belongs to.
@property (nonatomic, readonly) MDObjectId* org;

/**
 * Version of the bundle.
 *
 * @see bundleVersion
 */
@property (nonatomic, readonly) NSString* version;

/// Locale
@property (nonatomic, readonly) NSString* locale;

/// Strings mapping.
@property (nonatomic, readonly) NSDictionary* strings;

/// Custom faults information.
@property (nonatomic, readonly) NSDictionary* faults;

/// Symptoms enumeration.
@property (nonatomic, readonly) NSArray* symptoms;

/// Diagnoses enumeration.
@property (nonatomic, readonly) NSArray* diagnoses;

/// Treatments enumeration.
@property (nonatomic, readonly) NSArray* treatments;

/// List of latest legal agreements.
@property (nonatomic, readonly) NSDictionary* latestAgreements;

/// Tutorial.
@property (nonatomic, readonly) NSDictionary* tutorial;

/**
 * Get one of the legal agreements from it's name. Will go through the latestAgreements mapping.
 *
 * @param agreementName The name of the agreement.
 * @return The legal agreement that matches the name to the parameter.
 */
- (MDLegalAgreement*)agreementWithName:(NSString*)agreementName NOTNULL(1);

@end
