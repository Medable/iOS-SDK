//
//  MDPostSegmentDefinition.h
//  iOSMedableSDK
//
//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Definition of properties within post segments.
 *
 * @see MDPost, MDPostDefinition, MDPropertyDefinition
 */
@class MDPostSegmentPropertyDefinition;

@interface MDPostSegmentDefinition : NSObject

/// Human readable label in the Org's locale
@property (nonatomic, readonly) NSString *label;

/// Property name (used when indexing).
@property (nonatomic, readonly) NSString *name;

/// Minimum required.
@property (nonatomic, readonly) NSNumber *minRequired;

/// Maximum allowed.
@property (nonatomic, readonly) NSNumber *maxAllowed;

/// Subproperty definitions.
@property (nonatomic, readonly) NSArray* properties;

/// Caller's read access.
@property (nonatomic, readonly) MDACLLevel readAccess;

/// Caller's create access.
@property (nonatomic, readonly) MDACLLevel createAccess;

/**
 * Get one subproperty's definition from it's name.
 *
 * @param name The name of the property in this segment.
 * @return The subproperty definition if one exists, nil otherwise.
 */
- (MDPostSegmentPropertyDefinition *)propertyWithName:(NSString *)name NOTNULL(1);

/**
 *  Debug helper. Useful to get a minimum valid json representation of this object.
 **/
- (NSDictionary*)friendlyRepresentation;

@end
