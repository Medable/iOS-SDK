//
//  MDPostComment.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Comments are user-generated messages made in the context of a Post.
 *
 * Comment definitions, like Posts, are organized into segments. See the Post and Feeds sections for more details.
 *
 * @see MDFeedDefinition, MDPostDefinition
 */
@interface MDPostComment : NSObject

/**
 * The unique identifer
 */
@property (nonatomic, readonly) MDObjectId* Id;

/**
 * The account that created the comment
 */
@property (nonatomic, readonly) MDReference* creator;

/**
 * A reference to the definition of this context's class.
 */
@property (nonatomic, readonly) MDObjectDefinition* object;

/**
 * The date the comment was last updated.
 */
@property (nonatomic, readonly) NSDate* updated;

/**
 * The account that updated the comment.
 */
@property (nonatomic, readonly) MDReference* updater;

/**
 * The current caller’s level of access to the context
 */
@property (nonatomic, readonly) MDACLLevel access;

/**
 * Body Segments
 */
@property (nonatomic, readonly) NSArray* body;

/**
 * Number of up votes on a comment
 */
@property (nonatomic, readonly) NSNumber* votes;

/**
 * True if the calling principal has voted up the comment.
 */
@property (nonatomic, readonly) NSNumber* voted;

/**
 * The post in which the comment was created.
 */
@property (nonatomic, readonly) MDReference* context;

/**
 * Reference to parent post
 */
@property (nonatomic, readonly) MDPost* parentPost;

/**
 * Synchronize this object with the latest from the backend.
 *
 * @param parameters Extra API parameters.
 * @param callback Asynchronous callback where the results are passed.
 */
- (void)synchronizeObjectWithParameters:(MDAPIParameters *)parameters
                               callback:(MDObjectFaultCallback)callback;

@end
