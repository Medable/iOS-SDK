//
//  MDReference.h
//  Medable
//
//  
//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MDObjectInstance;

/**
 * A reference type, this can be expanded or not.
 */
@interface MDReference : NSObject

/**
 * Unique identifier.
 */
@property (nonatomic, readonly) MDObjectId *Id;

/**
 * Object class' name.
 */
@property (nullable, nonatomic, readonly) NSString *object;

/**
 * URL path of this reference.
 */
@property (nullable, nonatomic, readonly) NSString *path;

/**
 * Expanded object of the reference (nil when not expanded).
 */
@property (nullable, nonatomic, readonly) MDObjectInstance *expandedObjectReference;

/**
 * When the reference can't be expanded, or something wrong happens with the reference, the server returns a fault.
 * In these cases only Id and fault are set. The rest of the properties are all `nil`.
 */
@property (nullable, nonatomic, readonly) MDFault *fault;

/**
 * Initialize a reference with a value.
 *
 * @param value Value of the reference, can be expanded or not.
 * @return The reference value instance. When the referenced object cannot be found server side, only Id and fault are set.
 */
- (instancetype)initWithValue:(id)value;

/**
 * Whether this reference is expanded (contains the information) or just referenced.
 *
 * @return Whether this reference is expanded (contains the information) or just referenced.
 */
- (BOOL)isExpanded;

@end

NS_ASSUME_NONNULL_END
