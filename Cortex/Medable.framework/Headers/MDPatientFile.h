//
//  MDPatientFile.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MDObjectInstance.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * The Patient File is for providers to use as a collection for patient info, data, and 
 * collaborations. A patient file can be connected directly to a patient account to facilitate
 * collaboration, through it’s account property.
 */
@interface MDPatientFile : MDObjectInstance

/**
 * First name
 */
@property (nullable, nonatomic, readonly) NSString* firstName;

/**
 * Last name
 */
@property (nullable, nonatomic, readonly) NSString* lastName;

/**
 * The Account id of the connected patient.
 */
@property (nonatomic, readonly) MDReference* account;

/**
 * True when the Patient account has Connected to the Patient File.
 */
@property (nonatomic, readonly) NSNumber* accountConnected;

/**
 * True when the account property has been set, but before the request has been accepted by the target.
 */
@property (nonatomic, readonly) NSNumber* connectionPending;

/**
 * Patient age.
 */
@property (nullable, nonatomic, readonly) NSNumber* age;

/**
 * A description of the Patient File. The result varies depending on the caller's access level.
 */
@property (nullable, nonatomic, readonly) NSString* patientFileDescription;

/**
 * Patient date of birth.
 */
@property (nonatomic, readonly) NSDate* dob;

/**
 * A patient email address.
 */
@property (nonatomic, readonly) NSString* email;

/**
 * Patient gender.
 */
@property (nonatomic, readonly) MDGender gender;

/**
 * The object image. To update it, set the property to the name of an uploaded file.
 */
@property (nullable, nonatomic, readonly) MDFilePropertyValue* image;

/**
 * Medical Record Number.
 */
@property (nullable, nonatomic, readonly) NSString* mrn;

/**
 * The Org to which this object belongs.
 */
@property (nonatomic, readonly) MDReference* org;

/**
 * A patient contact phone number.
 */
@property (nonatomic, readonly) NSString* phone;

/**
 * Patient thumbnail.
 *
 * @param callback Asynchronous callback where the results are returned.
 */
- (void)thumbnailWithCallback:(MDImageOrFaultCallback)callback;

/**
 * Helper function to assemble the full name of the patient.
 */
- (nullable NSString*)fullName;

@end

NS_ASSUME_NONNULL_END
