//
//  MDObjectDefinition.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MDObjectDefinition.h"
#import "MDPropertyContainer.h"

@interface MDObjectInstance : NSObject
<MDPropertyContainer>

/**
 * Unique Id of this object.
 */
@property (nonatomic, readonly) MDObjectId* Id;

/**
 * Object definition's Id
 */
@property (nonatomic, readonly) MDObjectDefinition* object;

/**
 *  The account id of the context creator
 */
@property (nonatomic, readonly) MDReference* creator;

/**
 * The account id of the context owner
 */
@property (nonatomic, readonly) MDReference* owner;

/**
 * The date the latest update was made to a context’s properties
 */
@property (nonatomic, readonly) NSDate* updated;

/**
 * The account id of the context updater
 */
@property (nonatomic, readonly) MDReference* updater;

/**
 * The current caller’s level of access to the context
 */
@property (nonatomic, readonly) MDACLLevel access;

/**
 *
 */
@property (nonatomic, readonly) NSNumber* archived;

/**
 *
 */
@property (nonatomic, readonly) NSDate* archiveDate;

/**
 *
 */
@property (nonatomic, readonly) MDReference* archiver;

/**
 * Marked as favorite
 */
@property (nonatomic, readonly) NSNumber* favorite;

/**
 * True if there are any active or pending connections for this context.
 */
@property (nonatomic, readonly) NSNumber* shared;

/**
 *
 */
@property (nonatomic, readonly) NSArray* tags;

/**
 *
 */
@property (nonatomic, readonly) NSUInteger version;

/**
 *
 */
@property (nonatomic, readonly) NSUInteger contextVersion;

/**
 *
 */
@property (nonatomic, readonly) NSDate* created;

/**
 *
 */
@property (nonatomic, readonly) NSDictionary* baseProperties;

/**
 *
 */
@property (nonatomic, readonly) NSDictionary* customProperties;

/**
 * A list of connection objects. Connections might be either in active or pending state.
 *
 * This property is nil unless synchronizeConnectionsWithParameters:callback: is called and there are available posts for this object.
 */
@property (nonatomic, readonly) NSArray* connections;

/**
 * The object feed. This allows a single call to get both an object and it's first page of posts. Feed query arguments are supported.
 *
 * This property is nil unless synchronizePostsWithParameters:callback: is called and there are available posts for this object.
 */
@property (nonatomic, readonly) NSArray* posts;


- (id)valueForPropertyWithName:(NSString*)name NOTNULL(1);
- (MDPropertyType)typeForPropertyWithName:(NSString*)name NOTNULL(1);

- (NSDictionary*)baseValueWithPropertyName:(NSString*)name NOTNULL(1);
- (NSNumber*)booleanValueWithPropertyName:(NSString*)name NOTNULL(1);
- (NSDictionary*)anyValueWithPropertyName:(NSString*)name NOTNULL(1);
- (NSDate*)dateValueWithPropertyName:(NSString*)name NOTNULL(1);
- (NSDictionary*)documentValueWithPropertyName:(NSString*)name NOTNULL(1);
- (NSDictionary*)filesValueWithPropertyName:(NSString*)name NOTNULL(1);
- (NSNumber*)numberValueWithPropertyName:(NSString*)name NOTNULL(1);
- (MDObjectId*)objectIdValueWithPropertyName:(NSString*)name NOTNULL(1);
- (MDReference*)referenceValueWithPropertyName:(NSString*)name NOTNULL(1);
- (NSString*)stringValueWithPropertyName:(NSString*)name NOTNULL(1);

/**
 * Update the receiver with the latest data from the backend.
 *
 * @param parameter Extra parameters in the API call. Connections and posts may be included here.
 * @param callback The asynchronous callback, called upon receiving a response from the backend.
 */
- (void)synchronizeObjectWithParameters:(MDAPIParameters *)parameters
                               callback:(MDObjectFaultCallback)callback;

/**
 * Update the receiver with the latest data from the backend.
 * This is the special call to update connections and be able to expand connections' subproperties, since it's not possible to do so
 * using the synchronizeObjectWithParameters:callback: method.
 *
 * @param parameter Extra parameters in the API call. Connections and posts may be included here.
 * @param callback The asynchronous callback, called upon receiving a response from the backend.
 */
- (void)synchronizeConnectionsWithParameters:(MDAPIParameters *)parameters
                                    callback:(MDObjectFaultCallback)callback;

/**
 * Update the receiver with the latest data from the backend.
 * This is the special call to update posts and be able to expand posts' subproperties, since it's not possible to do so
 * using the synchronizeObjectWithParameters:callback: method.
 *
 * @param parameter Extra parameters in the API call. Connections and posts may be included here.
 * @param callback The asynchronous callback, called upon receiving a response from the backend.
 */
- (void)synchronizePostsWithParameters:(MDAPIParameters *)parameters
                              callback:(MDObjectFaultCallback)callback;


@end
