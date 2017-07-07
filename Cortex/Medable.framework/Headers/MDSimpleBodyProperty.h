//
//  MDSimpleBodyProperty.h
//  Medable
//
//  Copyright © 2015 Medable. All rights reserved.
//

#import "MDBodyProperty.h"

/**
 * Simple body properties. Use instances of this class to construct all simple POST body properties:
 *
 * - String.
 * - Boolean.
 * - Date.
 * - ObjectId.
 * - Reference.
 * - Number.
 */
@interface MDSimpleBodyProperty : MDBodyProperty

/**
 * The string representation of the value in the property.
 */
@property (nonatomic, readonly) NSString *value;

/**
 * Initialize with a string value.
 */
- (instancetype)initWithPropertyDefinition:(MDPropertyDefinition *)propertyDefinition value:(NSString *)value;

/**
 * Initialize with a boolean value.
 */
- (instancetype)initWithPropertyDefinition:(MDPropertyDefinition *)propertyDefinition boolValue:(BOOL)boolValue;

/**
 * Initialize with a date value.
 */
- (instancetype)initWithPropertyDefinition:(MDPropertyDefinition *)propertyDefinition dateValue:(NSDate *)dateValue;

/**
 * Initialize with an object Id value.
 */
- (instancetype)initWithPropertyDefinition:(MDPropertyDefinition *)propertyDefinition objectIdValue:(MDObjectId *)objectIdValue;

/**
 * Initialize with a reference value.
 */
- (instancetype)initWithPropertyDefinition:(MDPropertyDefinition *)propertyDefinition referenceValue:(MDReference *)referenceValue;

/**
 * Initialize with a number value.
 */
- (instancetype)initWithPropertyDefinition:(MDPropertyDefinition *)propertyDefinition numberValue:(NSNumber *)numberValue;

@end
