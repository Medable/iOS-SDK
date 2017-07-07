//
//  MDPost.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MDBaseInstance.h"

@class MDConversation;
@class MDPostSegment;

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
@interface MDPost : MDBaseInstance

/**
 * The object context that the post is associated with
 */
@property (nonatomic, readonly) MDReference* context;

/**
 * Reference to the definition of this post.
 */
@property (nonatomic, readonly) MDPostDefinition* postDefinition;

/**
 * The account that updated the post
 */
@property (nonatomic, readonly) MDReference* updater;

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

// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

/**
 * Update the receiver with the latest data from the backend.
 * This is the special call to update comments and be able to expand comments' subproperties, since it's not possible to do so
 * using the synchronizeObjectWithParameters:callback: method.
 *
 * @param parameters Extra parameters in the API call.
 * @param callback The asynchronous callback, called upon receiving a response from the backend.
 */
- (void)synchronizeCommentsWithParameters:(MDAPIParameters *)parameters
                                 callback:(MDObjectFaultCallback)callback;

/**
 * Get the body segment with name.
 *
 * @param name The name of the post segment.
 */
- (MDPostSegment*)bodySegmentWithName:(NSString*)name;

@end

