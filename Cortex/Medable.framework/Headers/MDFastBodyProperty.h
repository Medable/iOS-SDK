//
//  MDFastBodyProperty.h
//  Medable
//
//  Copyright © 2015 Medable. All rights reserved.
//

#import "MDBaseBodyProperty.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Simple workaround for adding properties without having to retrieve the property definition.
 *
 * Use this class to attach the mapping of a property name to it's value directly.
 */
@interface MDFastBodyProperty : MDBaseBodyProperty

/**
 * This will be returned as the API representation of the propery value.
 * You should ensure that the dictionary maps the property name to its intended value.
 * Important: The content can be set only once.
 */
@property (nonatomic, strong, nullable) NSDictionary *content;

+ (instancetype)fastBodyWithContent:(NSDictionary *)content;

@end

NS_ASSUME_NONNULL_END
