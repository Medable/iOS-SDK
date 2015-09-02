//
//  MDOrg.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * When you sign up with Medable, you are provisioned your own unique Medable Organization, or “Org.” 
 * All of your data is secured within your org, and it is impossible to access data from other orgs or
 * for other orgs to access data in yours. Each org is identified with an OrganizationId, and all data
 * within your org is keyed to that Id.
 */
@interface MDOrg : MDObjectInstance

/// Name of the organization.
@property (nonatomic, readonly) NSString* name;

/// ETag for the bundle.
@property (nonatomic, readonly) NSString* bundleVersion;

/// ETag for the schemas.
@property (nonatomic, readonly) NSString* schemasETag;

/// Organization's locale
@property (nonatomic, readonly) NSString* locale;

/// The Org’s code, used to access the api, uniquely identifies the org.
@property (nonatomic, readonly) NSString* code;

/// File property value of the Org's logo
@property (nonatomic, readonly) MDFilePropertyValue* logo;

/// Facet corresponding to the icon for this Org
@property (nonatomic, readonly) MDFacet* favicon;

/// The Org’s configured roles.
@property (nonatomic, readonly) NSArray* roles;

/// The Org’s configured applications.
@property (nonatomic, readonly) NSArray* apps;

/// Org configuration settings.
@property (nonatomic, readonly) NSDictionary* configuration;

/// Org registration settings.
@property (nonatomic, readonly) NSDictionary* registration;

/// Org security settings.
@property (nonatomic, readonly) NSDictionary* security;

/// The Org state.
@property (nonatomic, readonly) NSString* state;

/// The Org website, available for use as a variable in email templates (org.website).
@property (nonatomic, readonly) NSString* website;

/**
 * Convenience method to find the role in the roles array to match a given role name.
 *
 * @param roleName Name of the role.
 * @return Account role instance that matches the name, nil if none do.
 */
- (MDAccountRole*)accountRoleWithName:(NSString*)roleName NOTNULL(1);

@end
