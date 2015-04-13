//
//  MDAccountRole.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MDAccountRole : NSObject

@property (nonatomic, readonly) MDObjectId* Id;
@property (nonatomic, readonly) NSArray* all;
@property (nonatomic, readonly) NSArray* include;
@property (nonatomic, readonly) NSString* name;

@end
