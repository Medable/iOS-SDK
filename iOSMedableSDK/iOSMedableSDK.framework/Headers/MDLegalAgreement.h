//
//  MDLegalAgreement.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

@interface MDLegalAgreement : NSObject

@property (nonatomic, readonly) NSString* name;
@property (nonatomic, readonly) NSString* title;
@property (nonatomic, readonly) NSString* version;
@property (nonatomic, readonly) NSString* value;
@property (nonatomic, readonly) NSString* target;

- (MDLegalAgreement*)initWithName:(NSString*)name dictionary:(NSDictionary*)dictionary NOTNULL(1);

- (void)promptUserForAcceptanceWithCallback:(MDBoolArgumentCallback)callback NOTNULL(1);

- (BOOL)isAcceptPendingForAgreement:(MDLegalAgreement*)agreement NOTNULL(1);
- (BOOL)targetsCurrentUser;

@end
