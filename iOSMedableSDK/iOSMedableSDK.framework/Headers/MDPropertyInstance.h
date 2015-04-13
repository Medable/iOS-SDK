//
//  MDPropertyInstance.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MDFilePropertyValue;

@interface MDPropertyInstance : NSObject

+ (instancetype)propertyInstanceWithDefinition:(MDPropertyDefinition *)propertyDefinition value:(id)value;

@property (nonatomic, readonly) MDPropertyDefinition *definition;
@property (nonatomic, readonly) id value;

@end

@interface MDStringPropertyInstance : MDPropertyInstance

@property (nonatomic, readonly) NSString *value;

@end;

@interface MDDatePropertyInstance : MDPropertyInstance

@property (nonatomic, readonly) NSDate *value;

@end;

@interface MDNumberPropertyInstance : MDPropertyInstance

@property (nonatomic, readonly) NSNumber *value;

@end;

@interface MDObjectIdPropertyInstance : MDPropertyInstance

@property (nonatomic, readonly) MDObjectId *value;

@end

@interface MDReferencePropertyInstance : MDPropertyInstance

@property (nonatomic, readonly) MDReference *value;

@end

@interface MDBooleanPropertyInstance : MDPropertyInstance

@property (nonatomic, readonly) NSValue *value;

@end;

@interface MDArrayPropertyInstance : MDPropertyInstance <MDPropertyContainer>

@property (nonatomic, readonly) MDPropertyType baseType;
@property (nonatomic, readonly) MDObjectId *Id;
@property (nonatomic, readonly) NSArray *value;

@end;

@interface MDFilePropertyInstance : MDPropertyInstance

@property (nonatomic, readonly) MDFilePropertyValue *value;

@end;

@interface MDAnyPropertyInstance : MDPropertyInstance

//the value can be anything, so no need to redefine the original which is of type id

@end;

@interface MDDocumentPropertyInstance : MDPropertyInstance <MDPropertyContainer>

//The value maps property names to MDPropertyInstance instances
@property (nonatomic, readonly) NSDictionary *value;

@end;
