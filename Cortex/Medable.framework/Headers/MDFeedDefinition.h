//
//  MDFeedDefinition.h
//  Medable
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MDPostDefinition;

NS_ASSUME_NONNULL_BEGIN

/**
 * Defines the form of the Feed of a certain class of objects.
 * Put another way, it specifies the types of posts and what their forms are.
 */
@interface MDFeedDefinition : NSObject

/// Array of definitions for each possible post type in this instance.
@property (nonatomic, readonly) NSArray *postDefinitions;


// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

/**
 * Initializer.
 *
 * @param definitions The array of post definition attributes.
 * @return The initialized feed definition object.
 */
- (instancetype)initWithPostDefinitions:(NSArray *)definitions;

/**
 * Get a single post definition from it's type.
 *
 * @param postType Name of the post (also called it's type).
 * @return The Post Definition with this name, or nil if none match it.
 */
- (nullable MDPostDefinition*)postDefinitionWithType:(NSString*)postType;

/**
 *  Debug helper. Useful to get a minimum valid json representation of this object.
 **/
- (NSArray*)friendlyRepresentation;

/// Base Definition for the object of this feed
@property (nonatomic, weak, readonly) MDBaseDefinition *baseDefinition;

@end

NS_ASSUME_NONNULL_END
