//
//  MDBodyProperty.h
//  Medable
//
//  Copyright © 2015 Medable. All rights reserved.
//

#import "MDBaseBodyProperty.h"

@class MDPropertyDefinition;

/**
 * Base class for POST body properties that contain the property's definition to perform type checking.
 *
 * @see MDSimpleBodyProperty
 */
@interface MDBodyProperty : MDBaseBodyProperty

/**
 * Initialize body properties with their definition.
 *
 * @param propertyDefinition The MDPropertyDefinition instance representing the property this instance will contain.
 */
- (instancetype)initWithPropertyDefinition:(MDPropertyDefinition *)propertyDefinition;

@end
