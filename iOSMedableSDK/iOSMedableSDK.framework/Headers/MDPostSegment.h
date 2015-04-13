//
//  MDPostSegment.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MDPostSegment : NSObject

@property (nonatomic, readonly) MDPostSegmentDefinition* segmentDefinition;
@property (nonatomic, readonly) NSDictionary* attributes;

+ (MDPostSegment*)postSegmentWithAttributes:(NSDictionary*)attributes definition:(MDPostSegmentDefinition*)definition NOTNULL(1,2);

- (id)valueForPropertyWithName:(NSString*)propertyName NOTNULL(1);
- (id)valueForProperty:(MDPostSegmentPropertyDefinition*)propertyDefinition NOTNULL(1);

@end


@interface MDPostSegments : NSObject

/**
 *  Creates post segments
 */
+ (MDPostSegments*)postSegmentsWithText:(NSString*)text
                        imageAndOverlay:(NSDictionary*)imageAndOverlay
                              diagnoses:(NSArray*)diagnoses;

/**
 *  Creates post segments
 *	filesAndOverlays is a NSDictionary with:
 *      'key': filename / file upload name
 *      'object': overlay / overlay uplaod name
 *	Note: if no overlay set 'object': kEmptyString
 *	i.e.
 *	NSDictionary* filesAndOverlays = @{ @"fileUpload1", kEmptyString,
 *	                                    @"fileUpload2", @"fileUpload2Overlay" };
 */
+ (MDPostSegments*)postSegmentsWithFilesAndOverlays:(NSOrderedDictionary*)filesAndOverlays NOTNULL(1);

+ (MDPostSegments*)postSegmentsWithPostSegments:(MDPostSegments*)firstObject, ...;


/**
 *  Return all the file names that where configured by filesAndOverlays parameter
 */
- (NSArray*)files;

/**
 *  Checks if the file has an overlay and returns its name or nil if it doesn't have.
 */
- (NSString*)overlayForFile:(NSString*)file NOTNULL(1);

/**
 *  Serializes the object to the format the API expects.
 */
- (NSArray*)apiFormat;

@end