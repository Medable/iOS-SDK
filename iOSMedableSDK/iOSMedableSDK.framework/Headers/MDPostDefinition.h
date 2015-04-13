//
//  MDPostDefinition.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MDPostDefinition : NSObject

@property (nonatomic, readonly) NSString *label;
@property (nonatomic, readonly) MDACLLevel readAccess;
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

- (MDPostSegmentDefinition*)commentSegmentDefinitionWithName:(NSString*)definitionName NOTNULL(1);
- (MDPostSegmentDefinition*)segmentDefinitionWithName:(NSString*)definitionName NOTNULL(1);

@end
