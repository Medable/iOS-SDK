//
//  MDAPIPathFactory.h
//  Medable
//
//  Copyright © 2017 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Helper class to assemble path strings.
 */
@interface MDAPIPathFactory : NSObject

/**
 * Constructs a dot separated path string from it's path components.
 *
 * i.e.: component1.component2.lastComponent
 *
 * @param pathComponents Array of individual path components.
 * @return The string representing the assembled path.
 */
+ (NSString*)pathStringWithComponents:(NSArray*)pathComponents;

/**
 * Constructs a dot separated path string from it's path components.
 *
 * i.e.: component1.component2.lastComponent
 *
 * @param pathComponent variadic list of components. Requires nil termination.
 * @return The string representing the assembled path.
 */
+ (NSString*)pathWithComponents:(NSString*)pathComponent, ... NS_REQUIRES_NIL_TERMINATION;

// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
