//
//  MDPostBody.h
//  Medable
//
//  Copyright © 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MDBaseBodyProperty;

/**
 * Represents a the POST body of a backend post.
 */
@interface MDPostBody : NSObject

/**
 * Add a property to a segment of a given name.
 *
 * @param segmentName The name of the segment where this property belongs.
 * @param property The property that will go in this segment.
 */
- (void)addProperty:(NSString *)segmentName
           property:(MDBaseBodyProperty *) property;

/**
 * Add an entire segment in one operation.
 *
 * @param segmentName Name of the segment.
 * @param segmentInfo Dictionary mapping property names to their values.
 */
- (void)addFastSegment:(NSString *)segmentName
           segmentInfo:(NSDictionary *)segmentInfo;

/**
 * API representation of the POST body for this post.
 */
- (NSDictionary *)apiRepresentation;

@end
