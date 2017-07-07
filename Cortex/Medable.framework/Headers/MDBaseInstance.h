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
 * The date the latest update was made to a context’s properties.
 */
@property (nullable, nonatomic, readonly) NSDate* updated;

/**
 * The current caller’s level of access to the context.
 */
@property (nonatomic, readonly) MDACLLevel access;

/**
 * Whether this context is archived.
 */
@property (nullable, nonatomic, readonly) NSNumber* archived;

/**
 * Date of archival for the context.
 */
@property (nullable, nonatomic, readonly) NSDate* archiveDate;

/**
 * A reference to the account ID of the archiver.
 */
@property (nullable, nonatomic, readonly) MDReference* archiver;

/**
 * True if there are any active or pending connections for this context.
 */
@property (nonatomic, readonly) NSNumber* shared;

/**
 * Set of tags in the context.
 */
@property (nonatomic, readonly) NSArray* tags;

/**
 * Version number of the instance.
 */
@property (nonatomic, readonly) NSUInteger version;

/**
 * Creation date.
 */
@property (nonatomic, readonly) NSDate* created;

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
@property (nullable, nonatomic, readonly) NSArray* connections;

/**
 * The object feed. This allows a single call to get both an object and it's first page of posts. Feed query arguments are supported.
 *
 * This property is nil unless synchronizePostsWithParameters:callback: is called and there are available posts for this object.
 */
@property (nullable, nonatomic, readonly) NSArray* posts;


// unavailable
+ (nonnull instancetype)new NS_UNAVAILABLE;

// unavailable init
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Get the value for a given property name. This name can correspond to either a base or custom property.
 *
 * A property name is mapped to a `MDPropertyInstance`. This return's that property instance's value.
 *
 * @return Value for the property instance mapped to this property name.
 *
 * @see MDPropertyInstance
 */
- (nullable id)valueForPropertyWithName:(NSString*)name;

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
