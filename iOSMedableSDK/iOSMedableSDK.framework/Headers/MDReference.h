//
//  MDReference.h
//  iOSMedableSDK
//
//  
//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MDObjectInstance;

@interface MDReference : NSObject

@property (nonatomic, readonly) MDObjectId* Id;
@property (nonatomic, readonly) NSString* object;
@property (nonatomic, readonly) NSString* path;
@property (nonatomic, readonly) MDObjectInstance* expandedObjectReference;

- (instancetype)initWithValue:(id)value NOTNULL(1);
- (BOOL)isExpanded;

@end
