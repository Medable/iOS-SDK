//
//  MDFeedDefinition.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MDPostDefinition;

/**
 * Defines the form of the Feed of a certain class of objects.
 * Put another way, it specifies the types of posts and what their forms are.
 */
@interface MDFeedDefinition : NSObject

/// Array of definitions for each possible post type in this instance.
@property (nonatomic, readonly) NSArray *postDefinitions;

/**
 * Initializer.
 *
 * @param definitions The array of post definition attributes.
 * @return The initialized feed definition object.
 */
- (instancetype)initWithPostDefinitions:(NSArray *)definitions NOTNULL(1);

/**
 * Get a single post definition from it's type.
 *
 * @param postType Name of the post (also called it's type).
 * @return The Post Definition with this name, or nil if none match it.
 */
- (MDPostDefinition*)postDefinitionWithType:(NSString*)postType NOTNULL(1);

@end
