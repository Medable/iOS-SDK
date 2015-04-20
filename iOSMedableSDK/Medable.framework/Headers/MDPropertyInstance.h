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

/**
 * A string property instance.
 */
@interface MDStringPropertyInstance : MDPropertyInstance

/// The value of the property instance.
@property (nonatomic, readonly) NSString *value;

@end;

/**
 * A date property instance.
 */
@interface MDDatePropertyInstance : MDPropertyInstance

/// The value of the property instance.
@property (nonatomic, readonly) NSDate *value;

@end;

/**
 * A number property instance.
 */
@interface MDNumberPropertyInstance : MDPropertyInstance

/// The value of the property instance.
@property (nonatomic, readonly) NSNumber *value;

@end;

/**
 * An object ID property instance.
 */
@interface MDObjectIdPropertyInstance : MDPropertyInstance

@property (nonatomic, readonly) MDObjectId *value;

@end

/**
 * A reference property instance.
 */
@interface MDReferencePropertyInstance : MDPropertyInstance

/// The value of the property instance.
@property (nonatomic, readonly) MDReference *value;

@end

/**
 * A boolean property instance.
 */
@interface MDBooleanPropertyInstance : MDPropertyInstance

/// The value of the property instance.
@property (nonatomic, readonly) NSValue *value;

@end;

/**
 * An array property instance.
 */
@interface MDArrayPropertyInstance : MDPropertyInstance <MDPropertyContainer>

/// The underlying base type (the type of objects this array stores).
@property (nonatomic, readonly) MDPropertyType baseType;

/// Unique identifier.
@property (nonatomic, readonly) MDObjectId *Id;

/// The value of the property instance.
@property (nonatomic, readonly) NSArray *value;

@end;

/**
 * A File property instance.
 */
@interface MDFilePropertyInstance : MDPropertyInstance

/// The value of the property instance.
@property (nonatomic, readonly) MDFilePropertyValue *value;

@end;

/**
 * A property instance of type Any.
 * Since the value can be anything, there is no need to redefine the original 
 * underlying value type, which is already of type id.
 */
@interface MDAnyPropertyInstance : MDPropertyInstance

@end;

/**
 * A Document property instance.
 */
@interface MDDocumentPropertyInstance : MDPropertyInstance <MDPropertyContainer>

/// Maps property names to MDPropertyInstance instances.
@property (nonatomic, readonly) NSDictionary *value;

@end;
