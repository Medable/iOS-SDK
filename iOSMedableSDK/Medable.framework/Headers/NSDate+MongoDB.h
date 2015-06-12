//
//  NSDate+MongoDB.h
//  iOSMedableSDK
//
//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDate (MongoDB)

+ (NSDate*)dateFromObjectId:(MDObjectId*)objectId NOTNULL(1);

@end
