//
//  MDPostSegment.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

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
+ (MDPostSegment*)postSegmentWithAttributes:(NSDictionary*)attributes definition:(MDPostSegmentDefinition*)definition NOTNULL(1,2);

/**
 * Get the value of a property.
 *
 * @param propertyName Name of the property.
 * @return The value of the property if it exists, nil otherwise.
 */
- (id)valueForPropertyWithName:(NSString*)propertyName NOTNULL(1);

/**
 * Get the value of a property from it's definition.
 *
 * @param propertyDefinition Definition of the property.
 * @return The value of the property if it exists, nil otherwise.
 */
- (id)valueForProperty:(MDPostSegmentPropertyDefinition*)propertyDefinition NOTNULL(1);

@end
