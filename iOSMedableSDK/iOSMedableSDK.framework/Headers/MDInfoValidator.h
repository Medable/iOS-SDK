//
//  SignupInfo.h
//  Medable
//
//  
//  Copyright (c) 2014 Medable. All rights reserved.
//

typedef enum : NSUInteger
{
    MDInfoValidatorBundleTypeProviderSignup,
    MDInfoValidatorBundleTypePatientSignup,
    MDInfoValidatorBundleTypePatientProfile,
    MDInfoValidatorBundleTypeProviderProfile,
    MDInfoValidatorBundleTypeProviderVerification
} MDInfoValidatorBundleType;

@interface MDInfoValidator : NSObject

@property (nonatomic, strong) NSString* firstName;
@property (nonatomic, strong) NSString* lastName;
@property (nonatomic, strong) NSString* email;
@property (nonatomic, strong) NSString* phone;
@property (nonatomic, strong) NSString* password;
@property (nonatomic, strong) NSString* confirmPassword;
@property (nonatomic, strong) NSString* dateOfBirth;
@property (nonatomic, strong) NSString* gender;

// Provider specific
@property (nonatomic, strong) NSString* specialty;
@property (nonatomic, strong) NSString* affiliation;
@property (nonatomic, strong) NSString* mrn;
@property (nonatomic, strong) NSString* npi;
@property (nonatomic, strong) NSString* licenseState;
@property (nonatomic, strong) NSString* licenseNumber;


- (id)initWithType:(MDInfoValidatorBundleType)type;

- (BOOL)isValidWithInvalidMessagesCallback:(MDObjectCallback)callback;

@end
