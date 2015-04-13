//
//  MDPropertyDefinition.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSInteger
{
    MDPropertyTypeBaseUnknown = -1,
    MDPropertyTypeBase = 1,
    MDPropertyTypeBoolean,
    MDPropertyTypeAny,
    MDPropertyTypeDate,
    MDPropertyTypeDocument,
    MDPropertyTypeFile,
    MDPropertyTypeNumber,
    MDPropertyTypeObjectId,
    MDPropertyTypeReference,
    MDPropertyTypeString,
    MDPropertyTypeSet
} MDPropertyType;

@interface MDPropertyDefinition : NSObject

@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly) NSString *label;
@property (nonatomic, readonly) NSNumber *optional;
@property (nonatomic, readonly) NSNumber *required;
@property (nonatomic, readonly) NSNumber *searchable;
@property (nonatomic, readonly) MDACLLevel createAccess;
@property (nonatomic, readonly) MDACLLevel readAccess;
@property (nonatomic, readonly) MDACLLevel updateAccess;
@property (nonatomic, readonly) MDACLLevel deleteAccess;
@property (nonatomic, readonly) MDACLLevel pullAccess;
@property (nonatomic, readonly) MDACLLevel pushAccess;
@property (nonatomic, readonly) MDObjectId* Id;
@property (nonatomic, readonly) MDPropertyType type;
@property (nonatomic, readonly) NSArray* acl;
@property (nonatomic, readonly) NSArray* dependencies;
@property (nonatomic, readonly) NSArray* processors;
@property (nonatomic, readonly) NSNumber* isArray;
@property (nonatomic, readonly) NSNumber* isVirtual;
@property (nonatomic, readonly) NSArray* validators;
@property (nonatomic, readonly) NSDictionary* doc;

@property (nonatomic, readonly) NSArray *properties;

+ (MDPropertyType)propertyTypeFromString:(NSString*)type NOTNULL(1);
+ (NSString*)stringFromPropertyType:(MDPropertyType)type;

+ (MDPropertyDefinition*)propertyWithAttributes:(NSDictionary *)attributes NOTNULL(1);
+ (NSArray*)propertiesWithAttributes:(NSArray *)attributes NOTNULL(1);

- (BOOL)isCreatableWithAccess:(MDACLLevel)access;
- (BOOL)isReadableWithAccess:(MDACLLevel)access;
- (BOOL)isUpdatableWithAccess:(MDACLLevel)access;
- (BOOL)isDeletableWithAccess:(MDACLLevel)access;
- (BOOL)canPullWithAccess:(MDACLLevel)access;
- (BOOL)canPushWithAccess:(MDACLLevel)access;

@end
