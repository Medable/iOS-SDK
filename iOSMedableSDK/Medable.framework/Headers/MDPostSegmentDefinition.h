//
//  MDPostSegmentDefinition.h
//  iOSMedableSDK
//
//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

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

/// Whether this post segment definition is part of a comment segment
@property (nonatomic, assign, readonly) BOOL isCommentSegment;

/// Base Definition for the object of this segment
@property (nonatomic, weak, readonly) MDBaseDefinition *baseDefinition;

/// Post Definition for this segment
@property (nonatomic, weak, readonly) MDPostDefinition *postDefinition;


// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

/**
 * Get one subproperty's definition from it's name.
 *
 * @param name The name of the property in this segment.
 * @return The subproperty definition if one exists, nil otherwise.
 */
- (nullable MDPostSegmentPropertyDefinition *)propertyWithName:(NSString *)name;

/**
 *  Debug helper. Useful to get a minimum valid json representation of this object.
 **/
- (NSDictionary*)friendlyRepresentation;

@end

NS_ASSUME_NONNULL_END
