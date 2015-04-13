//
//  MDLegalAgreementManager.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

extern NSString* const kTermsKey;
extern NSString* const kPrivacyKey;
extern NSString* const kBusinessAssociateAgreementKey;
extern NSString* const kConsentKey;

@interface MDLegalAgreementManager : NSObject

+ (MDLegalAgreementManager*)sharedManager;

- (NSString*)platformIdentifier;
- (void)setAgreementsFromDictionary:(NSDictionary*)dictionary NOTNULL(1);
- (void)clearAgreements;
- (BOOL)checkLegalAgreementsWithCallback:(MDBoolArgumentCallback)callback NOTNULL(1);

@end
