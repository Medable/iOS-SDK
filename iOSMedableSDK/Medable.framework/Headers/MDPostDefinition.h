//
//  MDPostDefinition.h
//  iOSMedableSDK
//
//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MDBaseDefinition.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Definition of a post type, this includes definitions on all the segments the post must include.
 */
@interface MDPostDefinition : MDBaseDefinition

/// Read access on this definition.
@property (nonatomic, readonly) MDACLLevel readAccess;

/// Create access on this definition.
@property (nonatomic, readonly) MDACLLevel createAccess;
@property (nonatomic, readonly) NSNumber *active;
@property (nonatomic, readonly) NSString *postType;
@property (nonatomic, readonly) NSNumber *minItems;
@property (nonatomic, readonly) NSNumber *maxItems;
@property (nonatomic, readonly) NSNumber *allowComments;
@property (nonatomic, readonly) NSNumber *minCommentItems;
@property (nonatomic, readonly) NSNumber *archive;
@property (nonatomic, readonly) NSNumber *notifications;
@property (nonatomic, readonly) NSNumber *trackViews;
@property (nonatomic, readonly) NSNumber *editable;
@property (nonatomic, readonly) NSNumber *deletable;
@property (nonatomic, readonly) NSArray *contextReadAcl;
@property (nonatomic, readonly) NSArray *postCreateAcl;
@property (nonatomic, readonly) NSArray *postInstanceAcl;
@property (nonatomic, readonly) NSArray *body;
@property (nonatomic, readonly) NSArray *comments;


// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

/**
 * Get one comment segment definition from it's name.
 *
 * @param definitionName Name of the segment.
 * @return The post segment definition that corresponds to this name, nil if none do.
 */
- (nullable MDPostSegmentDefinition*)commentSegmentDefinitionWithName:(NSString*)definitionName;

/**
 * Get one segment definition from it's name.
 *
 * @param definitionName Name of the segment.
 * @return The post segment definition that corresponds to this name, nil if none do.
 */
- (nullable MDPostSegmentDefinition*)segmentDefinitionWithName:(NSString*)definitionName;

/**
 *  Debug helper. Useful to get a minimum valid json representation of this object.
 **/
- (NSDictionary*)friendlyRepresentation;

/// Base definition for this post type
@property (nonatomic, weak, readonly) MDBaseDefinition *baseDefinition;

@end

NS_ASSUME_NONNULL_END
