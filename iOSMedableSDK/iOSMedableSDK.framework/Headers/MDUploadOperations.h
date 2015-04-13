//
//  MDOperationsProgress.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const kOperationProgressChangedNotification;

@interface MDUploadOperation : NSObject

@property (nonatomic, readonly) NSURLSessionDataTask *operation;
@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly) NSNumber *progressNumber;
@property (nonatomic, readonly) NSString *fileName;
@property (nonatomic, readonly) NSDictionary *body;
@property (nonatomic, readonly) NSData *data;
@property (nonatomic, readonly) NSString *mimeType;
@property (nonatomic, readonly) NSProgress *operationProgress;

@end

@interface MDUploadOperations : NSObject

+ (MDUploadOperations *)instance;

+ (NSArray *)ongoingOperations;
+ (NSArray *)completedOperations;
+ (NSArray *)failedOperations;
+ (void)flushOperations;

+ (void)retryOperation:(MDUploadOperation *)operation;

@end
