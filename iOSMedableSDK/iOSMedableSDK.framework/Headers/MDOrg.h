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
@interface MDOrg : NSObject

/// Unique Identified
@property (nonatomic, readonly) MDObjectId* Id;

/// Name of object class, which is "Org" in this case.
@property (nonatomic, readonly) NSString* object;

/// Access level the user has on this Org.
@property (nonatomic, readonly) MDACLLevel access;

/// Name of the organization.
@property (nonatomic, readonly) NSString* name;

/// ETag for the bundle.
@property (nonatomic, readonly) NSString* bundleETag;

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

/**
 * Convenience method to find the role in the roles array to match a given role name.
 *
 * @param roleName Name of the role.
 * @return Account role instance that matches the name, nil if none do.
 */
- (MDAccountRole*)accountRoleWithName:(NSString*)roleName NOTNULL(1);

/**
 * Synchronize this object with the latest from the backend.
 *
 * @param parameters Extra API parameters.
 * @param callback The asynchronous callback that gets called after the API call returns.
 */
- (void)synchronizeObjectWithParameters:(MDAPIParameters*)parameters
                               callback:(MDObjectFaultCallback)callback;

@end
