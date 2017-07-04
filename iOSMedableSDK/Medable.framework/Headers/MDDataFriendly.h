//
//  MDDataFriendly.h
//  iOSMedableSDK
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

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
+ (nullable NSString*)genderLongStringFromShortString:(NSString*)genderString;

/**
 * Get the short gender string from the enumerated value.
 *
 * @param gender Gender value.
 * @return The short string that corresponds to the gender parameter.
 */
+ (nullable NSString*)genderShortStringFromGender:(MDGender)gender;

/**
 * Enumeration value from gender string (short or long format).
 *
 * @param genderString String representing gender (short or long format).
 * @return Enumeration value corresponding to the parameter. Will return unspecified if no match is found.
 */
+ (MDGender)genderFromString:(NSString*)genderString;

/**
 * State of account from it's service reported state (as string).
 *
 * @param stateString Service reported state of the account.
 * @return Account state value corresponding to the parameter.
 */
+ (MDAccountState)accountStateFromString:(NSString*)stateString;


/**
 * Adorn plain phone number with standard numeration forms.
 *
 * @param mobileNumber Phone number. e.g. 5551231234
 * @return Masked version of the phone number. e.g. (555) 123-1234
 */
+ (nullable NSString*)maskedPhoneNumberWithPlainNumber:(NSString*)mobileNumber;

/**
 * Remove adornments from phone number.
 *
 * @param mobileNumber Adorned phone number.
 * @return Unadorned phone number.
 */
+ (nullable NSString*)plainPhoneNumberFromMaskedPhoneNumber:(NSString*)mobileNumber;


// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
