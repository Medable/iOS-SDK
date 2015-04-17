//
//  MDPostSegmentPropertyDefinition.h
//  iOSMedableSDK
//
//  Copyright (c) 2015 Medable. All rights reserved.
//

#import "MDPropertyDefinition.h"

/**
 * Segment's property definition. They extend basic property definitions.
 */
@interface MDPostSegmentPropertyDefinition : MDPropertyDefinition

@property (nonatomic, readonly) NSNumber *canPull;
@property (nonatomic, readonly) NSNumber *writeOnCreate;
@property (nonatomic, readonly) NSNumber *canPush;
@property (nonatomic, readonly) NSNumber *maxShift;
@property (nonatomic, readonly) NSArray *filters;
@property (nonatomic, readonly) NSNumber *isPublic;
@property (nonatomic, readonly) NSNumber *uniqueValues;
@property (nonatomic, readonly) NSNumber *minItems;
@property (nonatomic, readonly) NSNumber *maxItems;
@property (nonatomic, readonly) NSNumber *trim;
@property (nonatomic, readonly) NSNumber *lowercase;
@property (nonatomic, readonly) NSNumber *uppercase;

@end
