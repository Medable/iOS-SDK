//
//  MDDataFriendly.h
//  iOSMedableSDK
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MDDataFriendly : NSObject

+ (NSString*)genderLongStringFromShortString:(NSString*)genderString NOTNULL(1);
+ (NSString*)genderShortStringFromGender:(MDGender)gender;
+ (MDGender)genderFromString:(NSString*)genderString NOTNULL(1);
+ (MDAccountState)accountStateFromString:(NSString*)stateString NOTNULL(1);

+ (NSString*)maskedPhoneNumberWithPlainNumber:(NSString*)mobileNumber;
+ (NSString*)plainPhoneNumberFromMaskedPhoneNumber:(NSString*)mobileNumber;

+ (NSString*)diagnosisNameWithValue:(NSString*)value;
+ (NSArray*)messageDiagnosisFromSegmentBody:(NSDictionary*)diagnosesSegment;

@end
