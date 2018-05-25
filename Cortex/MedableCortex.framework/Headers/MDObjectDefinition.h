//
//  MDContext.h
//  Medable
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MDBaseDefinition.h"
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
@interface MDObjectDefinition : MDBaseDefinition

/**
 Contains model information about the feed for instances of this object class.
 
 This involves the type of posts that can be performed on instances.
 
 @see MDObjectDefinition
 */
@property (nonatomic, readonly) MDFeedDefinition *feedDefinition DEPRECATED_MSG_ATTRIBUTE("Will be removed in future releases.");

// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

@end
