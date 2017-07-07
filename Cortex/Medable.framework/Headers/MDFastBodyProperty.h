//
//  MDFastBodyProperty.h
//  Medable
//
//  Copyright © 2015 Medable. All rights reserved.
//

#import "MDBaseBodyProperty.h"

/**
 * Simple workaround for adding properties without having to retrieve the property definition.
 *
 * Use this class to attach the mapping of a property name to it's value directly.
 */
@interface MDFastBodyProperty : MDBaseBodyProperty

/**
 * This will be returned as the API representation of the propery value.
 * You should ensure that the dictionary maps the property name to its intended value.
 */
@property (nonatomic, strong) NSDictionary *content;

@end
