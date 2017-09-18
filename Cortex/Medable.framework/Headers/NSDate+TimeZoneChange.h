//
//  NSDate+TimeZoneChange.h
//
//  Copyright © 2017 Medable Inc. All rights reserved.
//  Unauthorized use, modification, or reproduction is prohibited.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDate (TimeZoneChange)

/**
 Converts the receiver to "UTC" interpreting it is in "local time zone".
 @return converted instance.
 */
- (NSDate*)dateFromLocalToUTC;

/**
 Converts the receiver to "local time zone" interpreting it is in "UTC".
 @return converted instance.
 */
- (NSDate*)dateFromUTCToLocal;

/**
 Converts the receiver from `originTimeZone` to `destinationTimeZone`.
 @param originTimeZone the origin time zone.
 @param destinationTimeZone the destination time zone.
 @return converted instance.
 */
- (NSDate*)dateFromTimeZone:(NSTimeZone *)originTimeZone toTimeZone:(NSTimeZone *)destinationTimeZone;

@end

NS_ASSUME_NONNULL_END
