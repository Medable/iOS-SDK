//
//  NSDate+MongoDB.h
//  Medable
//
//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * NSDate extension to convert MDObjectId to NSDate.
 */
@interface NSDate (MongoDB)

/**
 * Converts a MDObjectId to NSDate object.
 *  @param objectId The object id to convert
 */
+ (nullable NSDate*)dateFromObjectId:(MDObjectId*)objectId;

/**
 * Converts a Mongo DB ObjectId (String) to NSDate object.
 *  @param objectIdString The object id to convert
 */
+ (nullable NSDate*)dateFromMongoDBObjectIdString:(NSString*)objectIdString;

@end

NS_ASSUME_NONNULL_END
