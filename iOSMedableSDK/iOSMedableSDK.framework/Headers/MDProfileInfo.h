//
//  MDProfileInfo.h
//  iOSMedableSDK
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface MDProfileInfo : NSObject

+ (MDProfileInfo*)profileInfoWithSpecialty:(NSString*)specialty
                               affiliation:(NSString*)affiliation
                                       npi:(NSString*)npi
                              licenseState:(NSString*)licenseState
                             licenseNumber:(NSString*)licenseNumber;

- (NSDictionary*)dictionaryRepresentation;

@end
