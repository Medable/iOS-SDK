//
//  MDPropertyInstance.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MDFilePropertyValue;

/**
 * A basic property value, it stores the value itself and a reference to the definition.
 */
@interface MDPropertyInstance : NSObject

/**
 * Create a property instance with it's definition and value.
 *
 * @param value Value.
 * @param propertyDefinition The definition of this property.
 *
 * @warning It's not encouraged for SDK users to use this method directly.
 */
+ (instancetype)propertyInstanceWithDefinition:(MDPropertyDefinition *)propertyDefinition value:(id)value;

/// The definition of this property instance.
@property (nonatomic, readonly) MDPropertyDefinition *definition;

/// The value of the property instance.
@property (nonatomic, readonly) id value;

@end
