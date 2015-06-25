//
//  NSDate+MongoDB.h
//  iOSMedableSDK
//
//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * NSDate extension to convert MDObjectId to NSDate.
 */
@interface NSDate (MongoDB)

/**
 * Converts a MDObjectId to NSDate object.
 *  @param objectId The object id to convert
 */
+ (NSDate*)dateFromObjectId:(MDObjectId*)objectId NOTNULL(1);

@end
