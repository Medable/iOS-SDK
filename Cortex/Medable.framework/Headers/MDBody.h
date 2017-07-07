//
//  MDBody.h
//  Medable
//
//  Copyright © 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MDBaseBodyProperty;

/**
 * Representation of an HTTP POST body.
 */
@interface MDBody : NSObject

/**
 * Add the value of a property in the body.
 *
 * @param property The property instance.
 */
- (void)addProperty:(MDBaseBodyProperty *_Nonnull) property;

/**
 * API Representation of this POST body.
 */
- (NSDictionary * _Nonnull )apiRepresentation;

@end
