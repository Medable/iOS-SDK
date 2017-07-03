//
//  MDPostDefinition.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Definition of a post type, this includes definitions on all the segments the post must include.
 */
@interface MDPostDefinition : NSObject

/// User ready string representing the name of the post type in the Org's locale.
@property (nonatomic, readonly) NSString *label;

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

/**
 * Get one comment segment definition from it's name.
 *
 * @param definitionName Name of the segment.
 * @return The post segment definition that corresponds to this name, nil if none do.
 */
- (MDPostSegmentDefinition*)commentSegmentDefinitionWithName:(NSString*)definitionName NOTNULL(1);

/**
 * Get one segment definition from it's name.
 *
 * @param definitionName Name of the segment.
 * @return The post segment definition that corresponds to this name, nil if none do.
 */
- (MDPostSegmentDefinition*)segmentDefinitionWithName:(NSString*)definitionName NOTNULL(1);

@end
