//
//  MDDateUtilities.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

typedef enum : NSUInteger
{
    MDDateUtilitiesFormatYYYYMMDD,  // yyyy-MM-dd                           i.e. 1983-12-31
    MDDateUtilitiesFormatLong,      // yyyy'-'MM'-'dd'T'HH':'mm':'SS'.000Z' i.e. 1983-12-31T00:00:00.000Z
    MDDateUtilitiesFormatLong2      // yyyy'-'MM'-'dd HH':'mm':'ss Z        i.e. 1983-12-31 00:00:00 +0000
} MDDateUtilitiesFormat;

NS_ASSUME_NONNULL_BEGIN

extern NSString* const kDateFormatString;
extern NSString* const kDateFormatStringLong;
extern NSString* const kDateFormatStringLong2;

/**
 * Utility class with date conversion tools.
 */
@interface MDDateUtilities : NSObject

/*
 * The date formatter used to make the conversions.
 *
 * You can change the time zone. Default is local time zone.
 *
 * @return the date formatter used to make the conversions.
 */
+ (NSDateFormatter*)dateFormatter;

/**
 * Convert a date string of a specified format to an NSDate object
 *
 * @param dateString Date string.
 * @param format Date format of the string.
 * @return A date object.
 */
+ (nullable NSDate*)dateFromString:(NSString*)dateString format:(MDDateUtilitiesFormat)format;

/**
 * Convert a date string to an NSDate object. It tries with both MDDateUtilitiesFormat.
 *
 * @param dateString Date string.
 * @return A date object.
 */
+ (nullable NSDate*)dateFromString:(NSString*)dateString;

/**
 * Get a string from a date.
 *
 * @param date Original date.
 * @param format Date format of the returned string.
 * @return Formatted date string from the date, in the specified format.
 */
+ (nullable NSString*)stringFromDate:(NSDate*)date format:(MDDateUtilitiesFormat)format;

/**
 * Get number of years from date of birth string.
 *
 * @param dob Date of birth string in standard format.
 * @return An unsigned integer with the number of years from that birth date.
 */
+ (NSUInteger)ageFromDateOfBirth:(NSDate*)dob;

/**
 * Get a birth date from a person's age.
 *
 * @param age Unsigned integer with age (number of years of the person).
 * @return Date from 'age' years ago.
 */
+ (nullable NSDate*)dobFromAge:(NSUInteger)age;

/**
 * Get a birth date string from a person's age.
 *
 * @param age Unsigned integer with age (number of years of the person).
 * @param format Date format of the returned string.
 * @return Formatted date string from 'age' years ago, in the specified format.
 */
+ (nullable NSString*)dobStringFromAge:(NSUInteger)age format:(MDDateUtilitiesFormat)format;


// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
