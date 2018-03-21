//
//  MDACLObject.h
//  Medable
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Encapsulates a single access control object. It matches a target, a type and an access level.
 *
 * @see MDACLLevel MDACLAccessType
 */
@interface MDACLObject : NSObject

/// Id of this access control object.
@property (nonnull, nonatomic, readonly) MDObjectId* Id;

/// Access level of the object.
@property (nonatomic, readonly) MDACLLevel allow;

/// Access level of the object as role Id. If this is set allow will be MDACLLevelNotSet.
@property (nullable, nonatomic, readonly) MDObjectId* allowRoleId;

/// The access object's target.
@property (nonnull, nonatomic, readonly) NSString* target;

/// The type of the target in the object.
@property (nonatomic, readonly) MDACLAccessType type;

/**
 * Helper method to construct an access control object from a dictionary mapping it's attributes.
 *
 * @param attributes A dictionary mapping this object's attributes. Keys tributes _id, allow, target and type are expected.
 * @return The MDACLObject instance that maps to the parameter.
 */
+ (nonnull MDACLObject*)aclObjectWithAttributes:(nonnull NSDictionary*)attributes;

/**
 * Helper method to construct a list of access control objects.
 *
 * @param attributes The array of object attributes.
 * @return The Array mapping each object.
 * @see aclObjectWithAttributes:
 */
+ (nullable NSArray<MDACLObject*> *)aclObjectsWithAttributes:(nonnull NSArray*)attributes;

@end
