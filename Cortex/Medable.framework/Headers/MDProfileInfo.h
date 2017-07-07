//
//  MDProfileInfo.h
//  Medable
//
//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Profile information wrapper.
 */
@interface MDProfileInfo : NSObject

/**
 * Create a profile info object.
 *
 * @param specialty Provider's specialty.
 * @param affiliation Provider's affiliation.
 * @param npi Provider's NPI.
 * @param licenseState Provider's license state.
 * @param licenseNumber Provider's license number.
 */
+ (MDProfileInfo*)profileInfoWithSpecialty:(NSString*)specialty
                               affiliation:(NSString*)affiliation
                                       npi:(NSString*)npi
                              licenseState:(NSString*)licenseState
                             licenseNumber:(NSString*)licenseNumber;

/// Dictionary representation of the profile information.
- (NSDictionary*)dictionaryRepresentation;

@end
