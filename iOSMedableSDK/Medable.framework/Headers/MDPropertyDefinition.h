//
//  MDPropertyDefinition.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MDBaseDefinition;

/**
 * Basic property types.
 *
 * Except unknown, base or set, all of these can be declared as Array types too,
 * in which case their type strings will end with the suffix [].
 */
typedef enum : NSInteger
{
    /// Uninitialized or unknown
    MDPropertyTypeBaseUnknown = -1,
    
    /// Base type, shouldn't be used for instances.
    MDPropertyTypeBase = 1,
    
    /// Boolean.
    MDPropertyTypeBoolean,
    
    /// Dictionary-like type (or hash maps) without any form restrictions.
    MDPropertyTypeAny,
    
    /// Dates.
    MDPropertyTypeDate,
    
    /// Dictionary-like type (or hash maps) with specific form restrictions (strict specification).
    MDPropertyTypeDocument,
    
    /// Files.
    MDPropertyTypeFile,
    
    /// Numbers.
    MDPropertyTypeNumber,
    
    /// Object unique identifiers.
    MDPropertyTypeObjectId,
    
    /// References.
    MDPropertyTypeReference,
    
    /// Srings.
    MDPropertyTypeString,
    
    /// Sets (not used in public types).
    MDPropertyTypeSet
} MDPropertyType;

/**
 * Property definitions specify how the type of a property is handled.
 */
@interface MDPropertyDefinition : NSObject

/// Name.
@property (nonatomic, readonly) NSString *name;

/// Human readable string, localized to the Org's locale.
@property (nonatomic, readonly) NSString *label;

/// Whether it's optional.
@property (nonatomic, readonly) NSNumber *optional;

/// Whether it's required.
@property (nonatomic, readonly) NSNumber *required;

/// Whether it's read only.
@property (nonatomic, readonly) NSNumber *readOnly;

/// Whether it can be searched.
@property (nonatomic, readonly) NSNumber *searchable;

/// Caller's create access.
@property (nonatomic, readonly) MDACLLevel createAccess;

/// Caller's read access.
@property (nonatomic, readonly) MDACLLevel readAccess;

/// Caller's update access.
@property (nonatomic, readonly) MDACLLevel updateAccess;

/// Caller's delete access.
@property (nonatomic, readonly) MDACLLevel deleteAccess;

/// Caller's pull access.
@property (nonatomic, readonly) MDACLLevel pullAccess;

/// Caller's push access.
@property (nonatomic, readonly) MDACLLevel pushAccess;

/// Unique identifier.
@property (nonatomic, readonly) MDObjectId* Id;

/// Type of the property.
@property (nonatomic, readonly) MDPropertyType type;

/// Access control list.
@property (nonatomic, readonly) NSArray* acl;

/// List of dependencies.
@property (nonatomic, readonly) NSArray* dependencies;

/// List of facet definitions for File property types.
@property (nonatomic, readonly) NSArray* facetDefinitions;

/// Boolean for whether this property is an array.
@property (nonatomic, readonly) NSNumber* isArray;

/// Boolean for whether this property is virtual.
@property (nonatomic, readonly) NSNumber* isVirtual;

/// List of value validators.
@property (nonatomic, readonly) NSArray* validators;

@property (nonatomic, readonly) NSDictionary* doc;

/// For date properties use date only format or complete date. Respectively 'YYYY'-'DD'-'MM' OR 'yyyy'-'MM'-'dd'T'HH':'mm':'SS'.000Z' i.e. 1983-05-05T00:00:00.000Z
@property (nonatomic, readonly) NSNumber* dateOnly;

/// Subproperties in case it's a Document type.
@property (nonatomic, readonly) NSArray *properties;

/// Path of this property
@property (nonatomic, readonly) NSString *path;

/// Points to the parent property definition if it has one, nil otherwise.
@property (nonatomic, weak, readonly) MDPropertyDefinition *parent;

/// Points to the parent property definition if it has one, nil otherwise.
@property (nonatomic, weak, readonly) MDBaseDefinition *baseDefinition;


// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

/**
 * Get the subproperty that matches a certain name.
 */
- (nullable MDPropertyDefinition *)subPropertyWithName:(NSString *)name;

/**
 * Convert string to property type (enum).
 *
 * @param type String representing the type.
 * @return The type that corresponds to the string if there is one, `MDPropertyTypeBaseUnknown` otherwise.
 */
+ (MDPropertyType)propertyTypeFromString:(NSString*)type;

/**
 * Convert property type (enum) to string.
 *
 * @param type Enum matching the type.
 * @return The string that corresponds to the type if it's a valid enum value, nil otherwise.
 */
+ (nullable NSString*)stringFromPropertyType:(MDPropertyType)type;

/**
 * Create a property definition from it's attributes.
 *
 * @param attributes Property definition attributes.
 * @return MDPropertyDefinition The constructed property's definition.
 *
 * @warning It's not encouraged to use this method directly.
 */
+ (MDPropertyDefinition*)propertyWithAttributes:(NSDictionary *)attributes;

/**
 * Construct a list of properties from an array of attributes.
 *
 * @parm attributes Attribute list.
 * @return Property array.
 *
 * @warning It's not encouraged to use this method directly.
 */
+ (nullable NSArray*)propertiesWithAttributes:(NSArray *)attributes;

#pragma mark - Access Control

/**
 * Can a caller create this property with a certain access level.
 *
 * @param access Access level.
 * @return True if a caller with this access level can create this property.
 */
- (BOOL)isCreatableWithAccess:(MDACLLevel)access;

/**
 * Can a caller read this property with a certain access level.
 *
 * @param access Access level.
 * @return True if a caller with this access level can read this property.
 */
- (BOOL)isReadableWithAccess:(MDACLLevel)access;

/**
 * Can a caller update this property with a certain access level.
 *
 * @param access Access level.
 * @return True if a caller with this access level can update this property.
 */
- (BOOL)isUpdatableWithAccess:(MDACLLevel)access;

/**
 * Can a caller delete this property with a certain access level.
 *
 * @param access Access level.
 * @return True if a caller with this access level can delete this property.
 */
- (BOOL)isDeletableWithAccess:(MDACLLevel)access;

/**
 * Can a caller pull this property with a certain access level.
 *
 * @param access Access level.
 * @return True if a caller with this access level can pull this property.
 */
- (BOOL)canPullWithAccess:(MDACLLevel)access;

/**
 * Can a caller push this property with a certain access level.
 *
 * @param access Access level.
 * @return True if a caller with this access level can push this property.
 */
- (BOOL)canPushWithAccess:(MDACLLevel)access;

/**
 *  Debug helper. Useful to get a minimum valid json representation of this object.
 **/
- (NSDictionary*)friendlyRepresentation;

@end

NS_ASSUME_NONNULL_END
