//
//  MDPropertyContainer.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Helper protocol for any object containing a mapping between property names and their values.
 *
 * Given the recursive nature of some property types (like Document and Array types), this allows
 * users of these classes (which store their subproperties in different ways) a consistent access
 * point to the subproperty values.
 *
 * @see MDObjectInstance, MDDocumentPropertyInstance, MDArrayPropertyInstance
 */
@protocol MDPropertyContainer <NSObject>

@required

/**
 * Maps property names to proprety instances.
 *
 * @see MDPropertyInstance
 */
- (NSDictionary *)propertyValues;

@end
