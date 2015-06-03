//
//  MDPost.h
//  iOSMedableSDK
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MDConversation;

/**
 * Posts are messages that users can generate. They are associated with a source context, such as a 
 * Conversation or Account. Organizations create feed definitions through the Object administration interface.
 *
 * Posts are organized into post types and segments. A post type is the class of post, and segments are 
 * document types within the post itself. Each post type can be configured with various access permissions
 * and have multiple segments, each with its own set of custom properties. See the section on Feeds for more details.
 *
 * Each post type can also be configured to support Comments, each with their own configurable segments.
 *
 * This flexibility enables a multitude of use cases, from polls to question/answer to device data point storage.
 */
@interface MDPost : NSObject

/**
 * The unique identifer
 */
@property (nonatomic, readonly) MDObjectId* Id;

/**
 * The object that the post is associated with.
 */
@property (nonatomic, readonly) MDObjectDefinition* object;

/**
 * The object context that the post is associated with
 */
@property (nonatomic, readonly) MDReference* context;

/**
 * Reference to the definition of this post.
 */
@property (nonatomic, readonly) MDPostDefinition* postDefinition;

/**
 * The account that created the post
 */
@property (nonatomic, readonly) MDReference* creator;

/**
 * The updated Unix timestamp for the post when edited
 */
@property (nonatomic, readonly) NSDate* updated;

/**
 * The account that updated the post
 */
@property (nonatomic, readonly) MDReference* updater;

/**
 * The current caller’s level of access to the context
 */
@property (nonatomic, readonly) MDACLLevel access;

/**
 * The type of post being created. The type determines how the post is handled depending on the object feed configuration
 */
@property (nonatomic, readonly) NSString* type;

/**
 * The Account associated with the post. In Patient Files and Conversation, this is the account of the associated patient.
 */
@property (nonatomic, readonly) MDReference* account;

/**
 * The Patient File associated with the post.
 */
@property (nonatomic, readonly) MDReference* patientFile;

/**
 * True is the post has been explicitly targeted.
 */
@property (nonatomic, readonly) NSNumber* targeted;

/**
 * The targets of the post. Adding targets limits visibility to selected accounts and roles. The post creator is always included as a target.
 */
@property (nonatomic, readonly) NSArray* targets;

/**
 * Number of up votes on a post
 */
@property (nonatomic, readonly) NSNumber* votes;

/**
 * True if the calling principal has voted up the post.
 */
@property (nonatomic, readonly) NSNumber* voted;

/**
 * Comments
 */
@property (nonatomic, readonly) NSArray* comments;

/**
 * The array of configured feed definition segments, discriminated by name.
 */
@property (nonatomic, readonly) NSArray* body;

/**
 * Synchronize this object with the latest from the backend.
 *
 * @param parameters Extra API parameters.
 * @param callback Asynchronous callback where the results are passed.
 */
- (void)synchronizeObjectWithParameters:(MDAPIParameters *)parameters
                               callback:(MDObjectFaultCallback)callback;

@end

