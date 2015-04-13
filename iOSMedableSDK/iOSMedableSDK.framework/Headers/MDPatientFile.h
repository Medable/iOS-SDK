//
//  MDPatientFile.h
//  iOSMedableSDK
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MDObjectInstance.h"

@interface MDPatientFile : MDObjectInstance

/**
 * First name
 */
@property (nonatomic, readonly) NSString* firstName;

/**
 * Last name
 */
@property (nonatomic, readonly) NSString* lastName;

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
 * Patient age
 */
@property (nonatomic, readonly) NSNumber* age;

/**
 * The object context name
 */
@property (nonatomic, readonly) NSString* context;

/**
 * A description of the Patient File. The result varies depending on the caller's access level.
 */
@property (nonatomic, readonly) NSString* patientFileDescription;

/**
 * Patient date of birth
 */
@property (nonatomic, readonly) NSDate* dob;

/**
 * A patient email address
 */
@property (nonatomic, readonly) NSString* email;

/**
 * Patient gender
 */
@property (nonatomic, readonly) MDGender gender;

/**
 * The object image. To update it, set the property to the name of an uploaded file.
 */
@property (nonatomic, readonly) MDFilePropertyValue* image;

/**
 * Medical Record Number
 */
@property (nonatomic, readonly) NSString* mrn;

/**
 * The Org to which this object belongs.
 */
@property (nonatomic, readonly) MDReference* org;

/**
 * A patient contact phone number
 */
@property (nonatomic, readonly) NSString* phone;

- (void)thumbnailWithCallback:(MDImageOrFaultCallback)callback NOTNULL(1);
- (NSString*)fullName;

@end
