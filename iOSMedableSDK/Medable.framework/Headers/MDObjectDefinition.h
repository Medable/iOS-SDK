//
//  MDContext.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MDPropertyDefinition.h"
#import "MDFeedDefinition.h"

/**
 Main class to store model information about a custom object.
 Instances of this class represent individual schemas obtained
 via the `MDSchemaManager`.
 
 This information can be conceived as all model information regarding
 a certain class of objects.
 
 See `MDObjectInstance` for model information about an instance.
 
 The principal instance variables are the name (plural and regular),
 the Id and properties (which is the array of properties defined for
 instances of this object class.
 */
@interface MDObjectDefinition : NSObject

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
 The Object Id of the class this belongs to.
 */
@property (nonatomic, readonly) MDObjectId* context;

/**
 Array of tags.
 */
@property (nonatomic, readonly) NSArray* tags;

/**
 Whether it has been favorited by the current user.
 
 @warning Remember to use boolValue for this as a C-style conditional
 of this value will yield YES even though the boolValue may be NO.
 */
@property (nonatomic, readonly) NSNumber *favorite;

@property (nonatomic, readonly) NSArray* shareChain;

/**
 Number representing the boolean value of whether this object is taggable.
 
 @warning Remember to use boolValue for this as a C-style conditional
 of this value will yield YES even though the boolValue may be NO.
 */
@property (nonatomic, readonly) NSNumber *taggable;

/**
 The `MDObjectID` of this object.
 */
@property (nonatomic, readonly) MDObjectId* Id;

/**
 Last updated date.
 */
@property (nonatomic, readonly) NSDate* updated;

/// Object definition version.
@property (nonatomic, readonly) NSUInteger version;
@property (nonatomic, readonly) NSNumber *allowConnections;
@property (nonatomic, readonly) NSArray* geo;
@property (nonatomic, readonly) MDACLLevel access;
@property (nonatomic, readonly) NSArray* defaultAcl;
@property (nonatomic, readonly) NSNumber *isTransferable;
@property (nonatomic, readonly) NSArray* createAcl;


@property (nonatomic, readonly) NSArray* feedConfig;

/**
 Contains model information about the feed for instances of this object class.
 
 This involves the type of posts that can be performed on instances.
 
 @see MDObjectDefinition
 */
@property (nonatomic, readonly) MDFeedDefinition *feedDefinition;

/**
 The `MDObjectId` of the organization this class belongs to.
 */
@property (nonatomic, readonly) MDObjectId* org;

/// Version of the context.
@property (nonatomic, readonly) NSUInteger contextVersion;

/// Date of creation
@property (nonatomic, readonly) NSDate* created;

/**
 Whether this object class is extensible. Many base classes
 like Account are.
 */
@property (nonatomic, readonly) NSNumber *isExtensible;

/**
 Whether this is extended.
 */
@property (nonatomic, readonly) NSNumber *isExtended;

/**
 Whether this a custom class instead of a base one.
 */
@property (nonatomic, readonly) NSNumber *isCustom;

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
