//
//  MDDataValidator.h
//

//

/**
 * Validator types.
 */
typedef enum
{
    /// No validation.
    MDValidatorTypeNone,
    
    /// Validate for non empty string.
    MDValidatorTypeNotEmtpyString,
    
    /// String has no whitespaces.
    MDValidatorTypeStringWithNoSpaces,
    
    /// Validate email.
    MDValidatorTypeEmail,
    
    /// Validate phone number.
    MDValidatorTypePhoneNumber,
    
    /// Validate NPI.
    MDValidatorTypeNPI,
    
    /// Validate a verification code.
    MDValidatorTypeVerificationCode,
    
    /// Validate for positive number.
    MDValidatorTypeNumericPositive,
    
    /// Validate date.
    MDValidatorTypeDate
} MDValidatorType;

/**
 * General data validation.
 */
@interface MDDataValidator : NSObject

/**
 * Validate a string with a given validator type.
 *
 * @param candidate Input string.
 * @param validatorType Type of validation to perform on the candidate string.
 * @return True if the data validates.
 */
+ (BOOL)validateCandidate:(NSString*)candidate withValidatorType:(MDValidatorType)validatorType;

/**
 * Validate username.
 *
 * @param candidate Potential username.
 * @return True if the candidate string can be used as a username.
 */
+ (BOOL)validateUsername:(NSString *)candidate;

/**
 * Validate email.
 *
 * @param candidate Potential email.
 * @return True if the candidate is a valid email.
 */
+ (BOOL)validateEmail:(NSString *)candidate;

/**
 * Validate NPI.
 *
 * @param candidate
 * @return True if the candidate is a valid NPI.
 */
+ (BOOL)validateNPI:(NSString *)candidate;

/**
 * Validate date string.
 *
 * @param candidate Potential date represented as a string.
 * @return True if the candidate is a valid date.
 */
+ (BOOL)validateDate:(NSString*)candidate;

/**
 * Validate for a number within a certain numeric internal.
 *
 * @param candidate Number represented as string.
 * @param interval Range of valid values.
 * @return True if the candidate string represents a number within the provided interval.
 */
+ (BOOL)validateNumber:(NSString*)candidate insideInterval:(CGPoint)interval;

@end
