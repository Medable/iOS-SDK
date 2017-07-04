//
//  SignupInfo.h
//  Medable
//
//  
//  Copyright (c) 2014 Medable. All rights reserved.
//

/// Validator types that correspond to different states of validation.
typedef enum : NSUInteger
{
    /// Provider signup.
    MDInfoValidatorBundleTypeProviderSignup,
    
    /// Patient signup.
    MDInfoValidatorBundleTypePatientSignup,
    
    /// Patient profile.
    MDInfoValidatorBundleTypePatientProfile,
    
    /// Provider profile.
    MDInfoValidatorBundleTypeProviderProfile,
    
    /// Provider verification.
    MDInfoValidatorBundleTypeProviderVerification
} MDInfoValidatorBundleType;

/**
 * Input data validation object for accounts.
 */
@interface MDInfoValidator : NSObject

/// First name.
@property (nonatomic, strong) NSString* firstName;

/// Last name.
@property (nonatomic, strong) NSString* lastName;

/// First name.
@property (nonatomic, strong) NSString* email;

/// Phone number.
@property (nonatomic, strong) NSString* phone;

/// Password.
@property (nonatomic, strong) NSString* password;

/// Password confirmation.
@property (nonatomic, strong) NSString* confirmPassword;

/// Date of birth.
@property (nonatomic, strong) NSString* dateOfBirth;

/// Gender.
@property (nonatomic, strong) NSString* gender;

#pragma mark - Provider Specific

/// Provider specialty.
@property (nonatomic, strong) NSString* specialty;

/// Provider affiliation.
@property (nonatomic, strong) NSString* affiliation;

/// Provider MRN.
@property (nonatomic, strong) NSString* mrn;

/// Provider NPI.
@property (nonatomic, strong) NSString* npi;

/// Provider License State.
@property (nonatomic, strong) NSString* licenseState;

/// Provider License Number.
@property (nonatomic, strong) NSString* licenseNumber;


// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

/**
 * Initializer
 *
 * @param type Validator type.
 * @return The data validator instance.
 */
- (instancetype)initWithType:(MDInfoValidatorBundleType)type;

/**
 * Validate data.
 *
 * @param callback Asynchronous callback where messages for invalid fields are returned.
 * @return True if data validates, False otherwise.
 */
- (BOOL)isValidWithInvalidMessagesCallback:(MDObjectCallback)callback;

@end
