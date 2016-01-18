//
//  MDBaseInstance.h
//  iOSMedableSDK
//
//  Copyright © 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MDBaseDefinition.h"
#import "MDReference.h"
#import "MDPropertyContainer.h"

/**
 * An instance is a concrete object of a given class, not necessarily a context.
 * Each instance follows the form given by the Definition of that class.
 *
 * @see MDBaseDefinition
 */
@interface MDBaseInstance : NSObject
    <MDPropertyContainer>

/**
 * Unique Id of this object.
 */
@property (nonatomic, readonly) MDObjectId* Id;

/**
 * Base object definition for this instance.
 */
@property (nonatomic, readonly) MDBaseDefinition* object;

/**
 *  A reference to the account id of the context creator.
 */
@property (nonatomic, readonly) MDReference* creator;


/**
 * The date the latest update was made to a context’s properties.
 */
@property (nonatomic, readonly) NSDate* updated;

/**
 * The current caller’s level of access to the context.
 */
@property (nonatomic, readonly) MDACLLevel access;

/**
 * Whether this context is archived.
 */
@property (nonatomic, readonly) NSNumber* archived;

/**
 * Date of archival for the context.
 */
@property (nonatomic, readonly) NSDate* archiveDate;

/**
 * A reference to the account ID of the archiver.
 */
@property (nonatomic, readonly) MDReference* archiver;

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
@property (nonatomic, readonly) NSArray* connections;

/**
 * The object feed. This allows a single call to get both an object and it's first page of posts. Feed query arguments are supported.
 *
 * This property is nil unless synchronizePostsWithParameters:callback: is called and there are available posts for this object.
 */
@property (nonatomic, readonly) NSArray* posts;

/**
 * Get the value for a given property name. This name can correspond to either a base or custom property.
 *
 * A property name is mapped to a `MDPropertyInstance`. This return's that property instance's value.
 *
 * @return Value for the property instance mapped to this property name.
 *
 * @see MDPropertyInstance
 */
- (id)valueForPropertyWithName:(NSString*)name NOTNULL(1);

/**
 * Type (enum) of a given property.
 *
 * @param The name of the property.
 * @return The property's type if a property with this name exists, `MDPropertyTypeBaseUnknown` otherwise.
 *
 * @see MDPropertyDefinition
 */
- (MDPropertyType)typeForPropertyWithName:(NSString*)name NOTNULL(1);

/**
 * Boolean value (represented by a Number) of the property.
 *
 * @param name Property name.
 * @return The number representing the bool value for this property.
 */
- (NSNumber*)booleanValueWithPropertyName:(NSString*)name NOTNULL(1);

/**
 * Dictionary value of the property of type Any.
 *
 * @param name Property name.
 * @return The dictionary representing the value for this property.
 */
- (NSDictionary*)anyValueWithPropertyName:(NSString*)name NOTNULL(1);

/**
 * Date value of the property of type Date.
 *
 * @param name Property name.
 * @return The date representing the value for this property.
 */
- (NSDate*)dateValueWithPropertyName:(NSString*)name NOTNULL(1);

/**
 * Dictionary value of the property of type Document.
 *
 * @param name Property name.
 * @return The dictionary representing the value for this property.
 */
- (NSDictionary*)documentValueWithPropertyName:(NSString*)name NOTNULL(1);

/**
 * Dictionary value of the property of type File.
 *
 * @param name Property name.
 * @return The dictionary representing the value for this property.
 */
- (NSDictionary*)filesValueWithPropertyName:(NSString*)name NOTNULL(1);

/**
 * Number value of the property of type Number.
 *
 * @param name Property name.
 * @return The number representing the value for this property.
 */
- (NSNumber*)numberValueWithPropertyName:(NSString*)name NOTNULL(1);

/**
 * ObjectID value of the property of type ObjectID.
 *
 * @param name Property name.
 * @return The `MDObjectID` instance representing the value for this property.
 */
- (MDObjectId*)objectIdValueWithPropertyName:(NSString*)name NOTNULL(1);

/**
 * Reference value of the property of type Reference.
 *
 * @param name Property name.
 * @return The `MDReference` instance representing the value for this property.
 */
- (MDReference*)referenceValueWithPropertyName:(NSString*)name NOTNULL(1);

/**
 * String value of the property of type String.
 *
 * @param name Property name.
 * @return The string representing the value for this property.
 */
- (NSString*)stringValueWithPropertyName:(NSString*)name NOTNULL(1);

/**
 * Update the receiver with the latest data from the backend.
 *
 * @param parameter Extra parameters in the API call. Connections and posts may be included here.
 * @param callback The asynchronous callback, called upon receiving a response from the backend.
 */
- (void)synchronizeObjectWithParameters:(MDAPIParameters *)parameters
                               callback:(MDObjectFaultCallback)callback;

@end