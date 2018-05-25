//
//  MDArrayBodyProperty.h
//  Medable
//
//  Copyright © 2015 Medable. All rights reserved.
//

#import "MDBodyProperty.h"

/**
 * Array property.
 *
 * Note that subproperties being added to this array should be initiliazed with the same property definition as this instance.
 */
@interface MDArrayBodyProperty : MDBodyProperty

/**
 * Add an element to the array property value.
 *
 * @param property The instance of the sub element in the array. This instance should be initiliazed with the same property definition as this instance.
 */
-(void)addProperty:(MDBodyProperty * _Nonnull) property;

@end
