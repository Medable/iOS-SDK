//
//  MDPostComment.h
//  Medable
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MDBaseInstance.h"

/**
 * Comments are user-generated messages made in the context of a Post.
 *
 * Comment definitions, like Posts, are organized into segments. See the Post and Feeds sections for more details.
 *
 * @see MDFeedDefinition, MDPostDefinition
 */
DEPRECATED_MSG_ATTRIBUTE("This class will be removed in future versions.")
@interface MDPostComment : MDBaseInstance

/**
 * The account that updated the comment.
 */
@property (nonatomic, readonly) MDReference* updater;

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


// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

/**
 * Get the body segment with name.
 *
 * @param name The name of the post segment.
 */
- (MDPostSegment*)bodySegmentWithName:(NSString*)name;

@end
