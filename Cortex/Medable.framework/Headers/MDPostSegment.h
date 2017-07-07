//
//  MDPostSegment.h
//  Medable
//
//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * An instance of a segment inside of a post.
 */
@interface MDPostSegment : NSObject

/// Definition for this segment
@property (nonatomic, readonly) MDPostSegmentDefinition* segmentDefinition;

/**
 * Attributes of the segment, mapping property names to property values
 *
 * @see MDPropertyInstance
 */
@property (nonatomic, readonly) NSDictionary* attributes;

/**
 * Create post segment.
 *
 * @param attributes Original attributes matching property names to it's values from a JSON reply.
 * @param definition Context definition of the segment.
 *
 * @warning Users of the SDK are encourage to avoid calling this method directly.
 */
+ (MDPostSegment*)postSegmentWithAttributes:(NSDictionary*)attributes definition:(MDPostSegmentDefinition*)definition;


// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

/**
 * Get the value of a property.
 *
 * @param propertyName Name of the property.
 * @return The value of the property if it exists, nil otherwise.
 */
- (nullable id)valueForPropertyWithName:(NSString*)propertyName;

/**
 * Get the value of a property from it's definition.
 *
 * @param propertyDefinition Definition of the property.
 * @return The value of the property if it exists, nil otherwise.
 */
- (nullable id)valueForProperty:(MDPostSegmentPropertyDefinition*)propertyDefinition;

@end

NS_ASSUME_NONNULL_END
