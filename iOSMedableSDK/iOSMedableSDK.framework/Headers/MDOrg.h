//
//  MDOrg.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MDOrg : NSObject

@property (nonatomic, readonly) MDObjectId* Id;
@property (nonatomic, readonly) NSString* object;
@property (nonatomic, readonly) MDACLLevel access;
@property (nonatomic, readonly) NSString* name;
@property (nonatomic, readonly) NSString* bundleETag;
@property (nonatomic, readonly) NSString* schemasETag;
@property (nonatomic, readonly) NSString* locale;
@property (nonatomic, readonly) NSString* code;
@property (nonatomic, readonly) MDFilePropertyValue* logo;
@property (nonatomic, readonly) MDFacet* favicon;
@property (nonatomic, readonly) NSArray* roles;

- (MDAccountRole*)accountRoleWithName:(NSString*)roleName NOTNULL(1);

- (void)synchronizeObjectWithParameters:(MDAPIParameters*)parameters
                               callback:(MDObjectFaultCallback)callback;

@end
