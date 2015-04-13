//
//  MDDateUtilities.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

/// Standard date format string used by the backend.
extern NSString* const kDateFormatString;

/// Long date format string used by the backend.
extern NSString* const kDateFormatStringLong;

/**
 * Utility class with date conversion tools.
 */
@interface MDDateUtilities : NSObject

/// Static default date formatter
+ (NSDateFormatter*)dateFormatter;

///  Date from long formatted string
+ (NSDate*)dateFromWapiDobString:(NSString*)dobStringFromWapi NOTNULL(1);

/// Date from string with yyyy-MM-dd format
+ (NSDate*)dateFromYYYYMMDDString:(NSString*)yyyymmddString NOTNULL(1);

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
 * @return Formatted date string from 'age' years ago.
 */
+ (NSString*)formattedDayOfBirthFromAge:(NSUInteger)age;

/**
 * Get a date string from a date.
 *
 * @param date Original date.
 * @return Formatted date string from the date.
 */
+ (NSString*)formattedDayOfBirthFromDate:(NSDate*)date;

@end
