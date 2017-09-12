//
//  MDBaseInstance.h
//  Medable
//
//  Copyright © 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MDBaseDefinition.h"
#import "MDReference.h"
#import "MDFilePropertyValue.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * An instance is a concrete object of a given class, not necessarily a context.
 * Each instance follows the form given by the Definition of that class.
 *
 * @see MDBaseDefinition
 */
@interface MDBaseInstance : NSObject

/**
 * Unique Id of this object.
 */
@property (nonatomic, readonly) MDObjectId* Id;

/**
 * Base object definition for this instance.
 */
@property (nonatomic, readonly) MDBaseDefinition* object;

/**
 Type of definition. Used for subclassing definitions.
 */
@property (nullable, nonatomic, readonly) NSString *subclassType;

/**
 *  A reference to the account id of the context creator.
 */
@property (nonatomic, readonly) MDReference* creator;

/**
 * Creation date.
 */
@property (nonatomic, readonly) NSDate* created;

/**
 * The date the latest update was made to a context’s properties.
 */
@property (nullable, nonatomic, readonly) NSDate* updated;

/**
 ETag is (re)generated on an instance whenever it is updated.
 */
@property (nullable, nonatomic, readonly) NSString *ETag;

/**
 * The current caller’s level of access to the context.
 */
@property (nonatomic, readonly) MDACLLevel access;

/**
 * The Id of the roles that have access to the context.
 */
@property (nullable, nonatomic, readonly) NSArray<MDObjectId*>* accessRoles;

/**
 * True if there are any active or pending connections for this context.
 */
@property (nonatomic, readonly) NSNumber* shared;

/**
 * Maps base property keys to their values.
 */
@property (nonatomic, readonly) NSDictionary* baseProperties;

/**
 * Maps custom property keys to their values, these custom properties have a "c_" prefix.
 */
@property (nonatomic, readonly) NSDictionary* customProperties;

/**
 * A list of connection objects. Connections might be either in active or pending state.
 *
 * This property is nil unless synchronizeConnectionsWithParameters:callback: is called and there are available posts for this object.
 */
@property (nullable, nonatomic, readonly) NSArray<MDConnection*>* connections;

/**
 * The object feed. This allows a single call to get both an object and it's first page of posts. Feed query arguments are supported.
 *
 * This property is nil unless synchronizePostsWithParameters:callback: is called and there are available posts for this object.
 */
@property (nullable, nonatomic, readonly) NSArray<MDPost*>* posts DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");


// unavailable
+ (nonnull instancetype)new NS_UNAVAILABLE;

// unavailable init
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Get the value for a given property name. This name can correspond to either a base or custom property.
 *
 * A property name is mapped to a `MDPropertyInstance`. This return's that property instance's value.
 *
 * @param name Property name.
 * @return Value for the property instance mapped to this property name.
 *
 * @see MDPropertyInstance
 */
- (nullable id)valueForPropertyWithName:(NSString*)name;

/**
 * Get the value for a given property at a path. This path can correspond to either a base or custom property.
 * Notice that pathing to a property only makes sense for properties inside Document properties.
 *
 * A property path is mapped to a `MDPropertyInstance`. This return's that property instance's value.
 *
 * @param path Path to the property. The path components should be separated by dots '.'. i.e.: path.to.property.propertyName
 * @return Value for the property instance mapped to this property name.
 *
 * @see MDPropertyInstance
 */
- (nullable id)valueForPropertyAtPath:(NSString*)path;

/**
 * Get the value for a given property at a path. This path can correspond to either a base or custom property.
 * Notice that pathing to a property only makes sense for properties inside Document properties.
 *
 * A property path is mapped to a `MDPropertyInstance`. This return's that property instance's value.
 *
 * @param pathComponents Path to the property. The components of the array are the components of the path. i.e.: [ path, to, property, propertyName ].
 * @return Value for the property instance mapped to this property name.
 *
 * @see MDPropertyInstance
 */
- (nullable id)valueForPropertyAtPathWithComponents:(NSArray<NSString *> *)pathComponents;

/**
 * Type (enum) of a given property.
 *
 * @param name The name of the property.
 * @return The property's type if a property with this name exists, `MDPropertyTypeBaseUnknown` otherwise.
 *
 * @see MDPropertyDefinition
 */
- (MDPropertyType)typeForPropertyWithName:(NSString*)name;

/**
 * Boolean value (represented by a Number) of the property.
 *
 * @param name Property name.
 * @return The number representing the bool value for this property.
 */
- (nullable NSNumber*)booleanValueWithPropertyName:(NSString*)name;

/**
 * Dictionary value of the property of type Any.
 *
 * @param name Property name.
 * @return The dictionary representing the value for this property.
 */
- (nullable NSDictionary*)anyValueWithPropertyName:(NSString*)name;

/**
 * Date value of the property of type Date.
 *
 * @param name Property name.
 * @return The date representing the value for this property.
 */
- (nullable NSDate*)dateValueWithPropertyName:(NSString*)name;

/**
 * Dictionary value of the property of type Document.
 *
 * @param name Property name.
 * @return The dictionary representing the value for this property.
 */
- (nullable NSDictionary*)documentValueWithPropertyName:(NSString*)name;

/**
 * Dictionary value of the property of type File.
 *
 * @param name Property name.
 * @return The MDFilePropertyValue representing the value for this property.
 */
- (nullable MDFilePropertyValue*)fileValueWithPropertyName:(NSString*)name;

/**
 * Number value of the property of type Number.
 *
 * @param name Property name.
 * @return The number representing the value for this property.
 */
- (nullable NSNumber*)numberValueWithPropertyName:(NSString*)name;

/**
 * ObjectID value of the property of type ObjectID.
 *
 * @param name Property name.
 * @return The `MDObjectID` instance representing the value for this property.
 */
- (nullable MDObjectId*)objectIdValueWithPropertyName:(NSString*)name;

/**
 * Reference value of the property of type Reference.
 *
 * @param name Property name.
 * @return The `MDReference` instance representing the value for this property.
 */
- (nullable MDReference*)referenceValueWithPropertyName:(NSString*)name;

/**
 * String value of the property of type String.
 *
 * @param name Property name.
 * @return The string representing the value for this property.
 */
- (nullable NSString*)stringValueWithPropertyName:(NSString*)name;

/**
 * Convenience method to get the value of an array property.
 *
 * @param name Name of the property.
 * @return Value of the array property.
 */
- (nullable NSArray*)arrayValueForPropertyWithName:(NSString*)name;

/**
 * Update the receiver with the latest data from the backend.
 *
 * @param parameters Extra parameters in the API call. Connections and posts may be included here.
 * @param callback The asynchronous callback, called upon receiving a response from the backend.
 */
- (void)synchronizeObjectWithParameters:(MDAPIParameters *)parameters
                               callback:(MDObjectFaultCallback)callback;

@end

NS_ASSUME_NONNULL_END
