//
//  MDFileUpload.h
//  Medable
//
//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Information necessary to upload a file to a File's property facet.
 *
 * An SDK user should likely avoid using this class directly as the SDK
 * already expects bare files and will perform the upload on its own.
 */
@interface MDFileUpload : NSObject

/**
 * The file name used when posting this facet value.
 */
@property (nonatomic, readonly) NSString *fileName;

/**
 * The name of the upload.
 */
@property (nonatomic, readonly) NSString *name;

/**
 * The state the file is in currently.
 */
@property (nonatomic, readonly) MDFileState state;

/**
 * Maximum file size (bytes) to be uploaded.
 */
@property (nonatomic, readonly) NSUInteger maxFileSize;

/**
 * Upload key for this file upload.
 */
@property (nonatomic, readonly) NSString *uploadKey;

/**
 * Upload method for this file upload.
 */
@property (nonatomic, readonly) NSString *uploadMethod;

/**
 * Upload URL to use on this upload.
 */
@property (nonatomic, readonly) NSString *uploadUrl;

/**
 * Array of fields that must be included when uploading this file.
 */
@property (nonatomic, readonly) NSArray *fields;


// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

/**
 * Upload mime type
 *
 * @return the mime type of the upload if available.
 */
- (nullable NSString*)mimeType;

/**
 * Refresh MDFileUpload headers.
 *
 * Upload headers have an expiration date (normally 15'). Note: You only need to deal with this if you're handling file uploads manually. Otherwise Cortex takes care of this.
 *
 * @param callback Asynchronous callback. Boolean parameters is BOOL succeeded, and indicates if the refresh was successful.
 */
- (void)refreshUploadWithCallback:(MDBoolCallback)callback;

@end

NS_ASSUME_NONNULL_END
