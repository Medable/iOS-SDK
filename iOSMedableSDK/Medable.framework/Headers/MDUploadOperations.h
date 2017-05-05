//
//  MDOperationsProgress.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * String used to notify that an upload operation has changed it's state.
 *
 * This can happen when the upload operation is started, it's progress has changed
 * or when it completes.
 */
extern NSString *const kOperationProgressChangedNotification;

/**
 * A single active upload operation.
 */
@interface MDUploadOperation : NSObject

///The underlying url session data task.
@property (nonatomic, readonly) NSURLSessionDataTask *operation;

/// The operation's name.
@property (nonatomic, readonly) NSString *name;

/// The number representing it's progress [0..1].
@property (nonatomic, readonly) NSNumber *progressNumber;

/// The name of the file being uploaded.
@property (nonatomic, readonly) NSString *fileName;

/// The body of this request.
@property (nonatomic, readonly) NSDictionary *body;

/// The binary blob of data being uploaded.
@property (nonatomic, readonly) NSData *data;

/// The mime type of the file being uploaded.
@property (nonatomic, readonly) NSString *mimeType;

/// The NSProgress object associated with the operation.
@property (nonatomic, readonly) NSProgress *operationProgress;

@property (nonatomic) id responseObject;

@end

/**
 * Upload Operations Manager, query this object for information about
 * active upload operations.
 */
@interface MDUploadOperations : NSObject

/// Singleton instance.
+ (MDUploadOperations *)instance;

/// List of file operations that are currently uploading a file.
+ (NSArray *)ongoingOperations;

/** 
 * List of recently completed operations.
 *
 * After completion, the operation objects will stay in this list for at least 10 seconds.
 * After this time, they'll be removed from the list.
 */
+ (NSArray *)completedOperations;

/**
 * List of recently failed operations.
 *
 * After failing, the operation objects will stay in this list for at least 1 minute.
 * After this time, they'll be removed from the list.
 */
+ (NSArray *)failedOperations;

/// Clear all operations from every queue. Ongoing operations won't be interrupted.
+ (void)flushOperations;

/**
 * Retry a failed operation. This will attempt to restart a failed operation using all
 * the original parameters.
 *
 * The operation need not be in the failed operations list.
 *
 * @param operation The failed operation.
 */
+ (void)retryOperation:(MDUploadOperation *)operation;

@end
