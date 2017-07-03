//
//  MDDateUtilities.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

typedef enum : NSUInteger
{
    MDDateUtilitiesFormatYYYYDDMM,  // YYYY-DD-MM
    MDDateUtilitiesFormatLong       // yyyy'-'MM'-'dd'T'HH':'mm':'SS'.000Z' i.e. 1983-05-05T00:00:00.000Z
} MDDateUtilitiesFormat;

/**
 * Utility class with date conversion tools.
 */
@interface MDDateUtilities : NSObject

/**
 * Convert a date string of a specified format to an NSDate object
 *
 * @param dateString Date of birth string.
 * @param format Date format of the string.
 * @return An unsigned integer with the number of years from that birth date.
 */
+ (NSDate*)dateFromString:(NSString*)dateString format:(MDDateUtilitiesFormat)format NOTNULL(1);

/**
 * Get number of years from date of birth string.
 *
 * @param dob Date of birth string in standard format.
 * @return An unsigned integer with the number of years from that birth date.
 */
+ (NSUInteger)ageFromDateOfBirth:(NSDate*)dob NOTNULL(1);

/**
 * Get a birth date from a person's age.
 *
 * @param age Unsigned integer with age (number of years of the person).
 * @return Date from 'age' years ago.
 */
+ (NSDate*)dobFromAge:(NSUInteger)age;

/**
 * Get a birth date string from a person's age.
 *
 * @param age Unsigned integer with age (number of years of the person).
 * @param format Date format of the returned string.
 * @return Formatted date string from 'age' years ago, in the specified format.
 */
+ (NSString*)dobStringFromAge:(NSUInteger)age format:(MDDateUtilitiesFormat)format;

/**
 * Get a date string from a date.
 *
 * @param date Original date.
 * @param format Date format of the returned string.
 * @return Formatted date string from the date, in the specified format.
 */
+ (NSString*)dobStringFromDate:(NSDate*)date format:(MDDateUtilitiesFormat)format;

@end
