//
//  NSOrderedDictionary.h
//  Medable
//
//  
//  Copyright (c) 2014 medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSOrderedDictionary : NSObject

+ (instancetype)dictionaryWithOrderedKeys:(NSArray*)orderedKeys
                        forOrderedObjects:(NSArray*)orderedObjects NOTNULL(1,2);

- (instancetype)initWithOrderedKeys:(NSArray*)orderedKeys
                  forOrderedObjects:(NSArray*)orderedObjects NOTNULL(1,2);

- (NSArray*)allKeys;
- (NSArray*)allValues;

- (id)objectForKey:(id<NSCopying>)key;

- (void)addObject:(id)object
           forKey:(id<NSCopying>)key NOTNULL(1);

@end
