//
//  MDPropertyContainer.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MDPropertyContainer <NSObject>

@required

//Maps property names to proprety values
- (NSDictionary *)propertyValues;

@end
