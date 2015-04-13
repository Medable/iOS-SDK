//
//  MDPostSegmentDefinition.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MDPostSegmentPropertyDefinition;

@interface MDPostSegmentDefinition : NSObject

@property (nonatomic, readonly) NSString *label;
@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly) NSNumber *minRequired;
@property (nonatomic, readonly) NSNumber *maxAllowed;
@property (nonatomic, readonly) NSArray* properties;

@property (nonatomic, readonly) MDACLLevel readAccess;
@property (nonatomic, readonly) MDACLLevel createAccess;

- (MDPostSegmentPropertyDefinition *)propertyWithName:(NSString *)name NOTNULL(1);

@end
