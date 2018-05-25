//
//  MDBodyProperty.h
//  Medable
//
//  Copyright © 2015 Medable. All rights reserved.
//

#import "MDBaseBodyProperty.h"

NS_ASSUME_NONNULL_BEGIN

@class MDPropertyDefinition;

/**
 * Base class for POST body properties that contain the property's definition to perform type checking.
 *
 * @see MDSimpleBodyProperty
 */
@interface MDBodyProperty : MDBaseBodyProperty

/**
 * Convenience initializer for body properties with their definition.
 *
 * @param propertyDefinition The MDPropertyDefinition instance representing the property this instance will contain. Use MDSchemaManager to get object and property definitions.
 * @return Initialized instance.
 */
+ (instancetype)bodyPropertyWithDefinition:(MDPropertyDefinition *)propertyDefinition;

/**
 * Initialize body properties with their definition.
 *
 * @param propertyDefinition The MDPropertyDefinition instance representing the property this instance will contain. Use MDSchemaManager to get object and property definitions.
 * @return Initialized instance.
 */
- (instancetype)initWithPropertyDefinition:(MDPropertyDefinition *)propertyDefinition;

@end

NS_ASSUME_NONNULL_END
