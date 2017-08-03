//
//  MDBody.h
//  Medable
//
//  Copyright © 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MDBaseBodyProperty;

NS_ASSUME_NONNULL_BEGIN

/**
 * Representation of an HTTP POST body.
 */
@interface MDBody : NSObject

/**
 * Convenience initializer for creanting a POST body with properties.
 *
 * @return Initialized instance.
 */
+ (instancetype)bodyWithProperties:(NSArray<MDBaseBodyProperty *> *)properties;

/**
 * Add the value of a property in the body.
 *
 * @param property The body property instance.
 */
- (void)addProperty:(MDBaseBodyProperty *)property;

/**
 * Add the values of a properties array in the body.
 *
 * @param properties An array of body property instances.
 */
- (void)addProperties:(NSArray<MDBaseBodyProperty *> *)properties;

/**
 * API Representation of this POST body.
 */
- (NSDictionary *)apiRepresentation;

@end

NS_ASSUME_NONNULL_END
