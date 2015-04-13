//
//  MDDataValidator.h
//

//

typedef enum
{
    MDValidatorTypeNone,
    MDValidatorTypeNotEmtpyString,
    MDValidatorTypeStringWithNoSpaces,
    MDValidatorTypeEmail,
    MDValidatorTypePhoneNumber,
    MDValidatorTypeNPI,
    MDValidatorTypeVerificationCode,
    MDValidatorTypeNumericPositive,
    MDValidatorTypeDate
} MDValidatorType;

@interface MDDataValidator : NSObject

+ (BOOL)validateCandidate:(NSString*)candidate withValidatorType:(MDValidatorType)validatorType;
+ (BOOL)validateUsername:(NSString *)candidate;
+ (BOOL)validateEmail:(NSString *)candidate;
+ (BOOL)validateNPI:(NSString *)candidate;
+ (BOOL)validateDate:(NSString*)candidate;
+ (BOOL)validateNumber:(NSString*)candidate insideInterval:(CGPoint)interval;

@end
