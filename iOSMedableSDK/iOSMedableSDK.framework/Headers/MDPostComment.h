//
//  MDPostComment.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

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
 *
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

- (void)synchronizeObjectWithParameters:(MDAPIParameters *)externalParameters
                               callback:(MDObjectFaultCallback)callback;

@end
