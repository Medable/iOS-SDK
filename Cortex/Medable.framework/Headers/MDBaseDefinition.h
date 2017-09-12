//
//  MDBaseDefinition.h
//  Medable
//
//  Copyright © 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MDACLObject;

NS_ASSUME_NONNULL_BEGIN

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
 The `MDObjectID` of this object.
 */
@property (nonatomic, readonly) MDObjectId* Id;

/**
 The context's object name.
 */
@property (nonatomic, readonly) NSString *object;

/**
 The object label.
 */
@property (nullable, nonatomic, readonly) NSString *label;

/**
 The object name.
 */
@property (nonatomic, readonly) NSString *name;

/**
 Based on the name, this is the name used in API routes. For example, to retrieve a list of c_thing objects, use "GET /c_things"
 */
@property (nonatomic, readonly) NSString *pluralName;

/**
 The lookup is used in context collections as the object property. We need a secondary lookup because all built-in contexts have the same _id, even across orgs.
 */
@property (nonatomic, readonly) MDObjectId *lookup;

/**
 The object description.
 */
@property (nonatomic, readonly) NSString *objectDescription;

/**
 All contexts objects of this type will have this acl merged with their instance acl.
 */
@property (nonatomic, readonly) NSArray<MDACLObject *> *defaultAcl;

/**
 These Acl targets are able to create context objects of this type.
 */
@property (nonatomic, readonly) NSArray<MDACLObject *> *createAcl;

/**
 These ACL targets are able to share context objects of this type. The entries defined which access levels and roles can be assigned by which targets.
 */
@property (nonatomic, readonly) NSArray<MDACLObject *> *shareAcl;

/**
 Allow ownership transfer for this context's objects.
 */
@property (nonatomic, readonly) NSNumber *allowTransfers;

/**
 If true, an ETag property is made available and is (re)generated on an instance whenever it is updated.
 */
@property (nonatomic, readonly) NSNumber *hasETag;

/**
 A caller can create a connection granting any level of access in the share chain, as long as it is less than his own.
 Note: Array of MDACLLevel numbers.
 */
@property (nonatomic, readonly) NSArray<NSNumber *> *shareChain;

/**
 Set to enable/disable sharing of contexts for this object.
 */
@property (nonatomic, readonly) NSNumber *allowConnections;

/**
 Options around connection requests, such as whether to auto-accept and send-notification.
 */
@property (nonatomic, readonly) NSDictionary *connectionOptions;

/**
 
 */
@property (nonatomic, readonly) NSDictionary *deletedProperties;

/**
 Whether this is extensible.
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
 Array of the base properties for this object class.
 
 This contains an NSArray of `MDObjectProperty`.
 */
@property (nonatomic, readonly) NSArray<MDPropertyDefinition *> *baseProperties;

/**
 Array of the custom properties for this object class.
 
 This contains an NSArray of `MDObjectProperty`.
 */
@property (nonatomic, readonly) NSArray<MDPropertyDefinition *> *customProperties;

/**
 Array of the subclass properties for this object sub classes.
 
 This is a dictionary with subclass 'types' as keys and the subclass properties `MDObjectProperty` as values.
 */
@property (nullable, nonatomic, readonly) NSDictionary<NSString *, NSArray<MDPropertyDefinition *> *> *subClassesProperties;


// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

/**
 Get the Property Definition for a property of a certain name.
 
 @param name The name of the property of this class.
 @param type The name of the subclass type (optional). Pass nil if it's not the case of a subclass or if you are looking for a non subclass property.
 
 @return The `MDPropertyDefinition` for the property if it exists, nil otherwise.
 
 @see MDPropertyDefinition hasPropertyWithName:
 */
- (nullable MDPropertyDefinition *)propertyWithName:(nonnull NSString*)name type:(nullable NSString*)type;

/**
 Check for property membership.
 
 @param name The property name.
 @param type The name of the subclass type (optional). Pass nil if it's not the case of a subclass or if you are looking for a non subclass property.
 
 @return YES if this class has property with this name.
 */
- (BOOL)hasPropertyWithName:(NSString*)name type:(nullable NSString*)type;

@end

NS_ASSUME_NONNULL_END
