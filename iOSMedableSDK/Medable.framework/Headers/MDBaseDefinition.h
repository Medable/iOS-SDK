//
//  MDBaseDefinition.h
//  iOSMedableSDK
//
//  Copyright © 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Main class to store model information about a custom object.
 Instances of this class represent individual schemas obtained
 via the `MDSchemaManager`.
 
 This information can be conceived as all model information regarding
 a certain class of objects.
 
 See `MDBaseInstance` for model information about an instance.
 
 The principal instance variables are the name (plural and regular),
 the Id and properties (which is the array of properties defined for
 instances of this object class.
 */
@interface MDBaseDefinition : NSObject

/**
 The name of the Object, this name is not for UI purposes.
 */
@property (nonatomic, readonly) NSString *name;

/**
 Plural name for the object, this is mostly used for making API calls.
 */
@property (nonatomic, readonly) NSString *pluralName;

/**
 If you need to display the name, use the label.
 
 It has 'en' localization.
 */
@property (nonatomic, readonly) NSString *label;

/**
 Array of the base properties for this object class.
 
 This contains an NSArray of `MDObjectProperty`.
 */
@property (nonatomic, readonly) NSArray *baseProperties;

/**
 Array of the custom properties for this object class.
 
 This contains an NSArray of `MDObjectProperty`.
 */
@property (nonatomic, readonly) NSArray *customProperties;

/**
 Whether this object class is extensible. Many base classes
 like Account are.
 */
@property (nonatomic, readonly) NSNumber *isExtensible;


/**
 Get the Property Definition for a property of a certain name.
 
 @param name The name of the property of this class.
 
 @return The `MDPropertyDefinition` for the property if it exists, nil otherwise.
 
 @see MDPropertyDefinition hasPropertyWithName:
 */
- (MDPropertyDefinition *)propertyWithName:(NSString*)name NOTNULL(1);

/**
 Check for property membership.
 
 @param name The property name.
 
 @return YES if this class has property with this name.
 */
- (BOOL)hasPropertyWithName:(NSString*)name NOTNULL(1);

/**
 Helper method to return the API ready string for making API calls.
 
 @return This will attempt to return self.pluralName but will roll back to self.name if that is nil.
 */
- (NSString *)pluralNameForAPICalls;

@end
