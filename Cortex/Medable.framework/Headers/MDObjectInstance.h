//
//  MDObjectDefinition.h
//  Medable
//
//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MDBaseInstance.h"
#import "MDObjectDefinition.h"

/**
 * An object instance is a concrete object of a given class, also known as a context.
 * Each instance follows the form given by the Definition of that class.
 *
 * @see MDObjectDefinition
 */
@interface MDObjectInstance : MDBaseInstance

/**
 * The account id of the context owner.
 */
@property (nonatomic, readonly) MDReference* owner;

/**
 * The account id of the context updater.
 */
@property (nonatomic, readonly) MDReference* updater;

/**
 * Object definition for this instance. Note that the definition class is a subinstance of the base definition.
 */
@property (nonatomic, readonly) MDObjectDefinition* object;

/**
 * Whether it's marked as favorite by the current user.
 */
@property (nonatomic, readonly) NSNumber* favorite;


/**
 * Version number of the context.
 */
@property (nonatomic, readonly) NSUInteger contextVersion;

/**
 * Creates an object instance form the attributes provided.
 */
+ (instancetype)objectInstanceWithAttributes:(NSDictionary*)attributes;

// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

/**
 * Update the receiver with the latest data from the backend.
 * This is the special call to update connections and be able to expand connections' subproperties, since it's not possible to do so
 * using the synchronizeObjectWithParameters:callback: method.
 *
 * @param parameters Extra parameters in the API call. Connections and posts may be included here.
 * @param callback The asynchronous callback, called upon receiving a response from the backend.
 */
- (void)synchronizeConnectionsWithParameters:(MDAPIParameters *)parameters
                                    callback:(MDObjectFaultCallback)callback;

/**
 * Update the receiver with the latest data from the backend.
 * This is the special call to update posts and be able to expand posts' subproperties, since it's not possible to do so
 * using the synchronizeObjectWithParameters:callback: method.
 *
 * @param parameters Extra parameters in the API call. Connections and posts may be included here.
 * @param callback The asynchronous callback, called upon receiving a response from the backend.
 */
- (void)synchronizePostsWithParameters:(MDAPIParameters *)parameters
                              callback:(MDObjectFaultCallback)callback;

@end
