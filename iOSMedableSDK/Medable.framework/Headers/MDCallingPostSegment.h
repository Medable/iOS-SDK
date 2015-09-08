//
//  MDCallingPostSegment.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Helper class to assemble individual segments in a post body.
 */
@interface MDCallingPostSegment : NSObject

/**
 * The name of the post this segment belongs to.
 */
@property (nonatomic, strong) NSString *postName;

/**
 * Arrays of properties matched to their values contained in this segment.
 * Each entry in the array is a dictionary that maps the two.
 */
- (NSArray*)allProperties;

/**
 * Add an entry mapping a property name to a value.
 *
 * @param propertyName The name of the property being mapped.
 * @param value The value for this property.
 */
- (void)addProperty:(NSString *)propertyName withValue:(NSObject *)value;

/**
 * Convert to API format to use in an API call.
 *
 * @return API ready value corresponding to this segment.
 */
- (NSDictionary *)apiFormat;

@end
