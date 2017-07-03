//
//  MDDataFriendly.h
//  iOSMedableSDK
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Helper class to convert data strings back and forth into human readable formats.
 */
@interface MDDataFriendly : NSObject

/**
 * Convert a short gender string to human readable format.
 *
 * @param genderString Short gender string (e.g. 'm' or 'f').
 * @return The human readable string using en locale after replacing occurrences of the short string with the long ones.
 */
+ (NSString*)genderLongStringFromShortString:(NSString*)genderString NOTNULL(1);

/**
 * Get the short gender string from the enumerated value.
 *
 * @param gender Gender value.
 * @return The short string that corresponds to the gender parameter.
 */
+ (NSString*)genderShortStringFromGender:(MDGender)gender;

/**
 * Enumeration value from gender string (short or long format).
 *
 * @param genderString String representing gender (short or long format).
 * @return Enumeration value corresponding to the parameter. Will return unspecified if no match is found.
 */
+ (MDGender)genderFromString:(NSString*)genderString NOTNULL(1);

/**
 * State of account from it's service reported state (as string).
 *
 * @param stateString Service reported state of the account.
 * @return Account state value corresponding to the parameter.
 */
+ (MDAccountState)accountStateFromString:(NSString*)stateString NOTNULL(1);


/**
 * Adorn plain phone number with standard numeration forms.
 *
 * @param mobileNumber Phone number. e.g. 5551231234
 * @return Masked version of the phone number. e.g. (555) 123-1234
 */
+ (NSString*)maskedPhoneNumberWithPlainNumber:(NSString*)mobileNumber;

/**
 * Remove adornments from phone number.
 *
 * @param mobileNumber Adorned phone number.
 * @return Unadorned phone number.
 */
+ (NSString*)plainPhoneNumberFromMaskedPhoneNumber:(NSString*)mobileNumber;

/**
 * Get the name of a diagnoses from it's value.
 *
 * @param value Diagnoses value.
 * @return The diagnoses name, as represented in the Org's bundle.
 */
+ (NSString*)diagnosisNameWithValue:(NSString*)value;

/**
 * Get the list of diagnoses from a dictionary of post segments.
 *
 * @param diagnosesSegment Post segments.
 * @return List of diagnoses names.
 */
+ (NSArray*)messageDiagnosisFromSegmentBody:(NSDictionary*)diagnosesSegment;

@end
