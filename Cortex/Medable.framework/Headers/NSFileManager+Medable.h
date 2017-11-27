//
//  NSFileManager+Medable.h
//  Patient
//
//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSFileManager (Medable)

/**
 * NSCachesDirectory
 *
 * @return NSCachesDirectory.
 */
- (NSString *)cacheDirectoryPath;

/**
 * Current user path if there's an ongoing session or nil otherwise.
 *
 * @return Current user path if there's an ongoing session or nil otherwise.
 */
- (nullable NSString *)currentUserPath;

- (BOOL)deleteCurrentUserDiskCache;
- (BOOL)deleteCurrentUserTempFiles;

/**
 *  Caches data
 *  @Warning The data is not encrypted using this method. Use MDAssetManager instead if you want it to be encrypted.
 *
 * @param data Data to be saved.
 * @param filePath file path including file name.
 * @param callback asynchronous callback block called once the operation finished. It has a BOOL parameter indicating success or failure.
 */
- (void)saveData:(NSData *)data
        filePath:(NSString *)filePath
        callback:(MDBoolCallback)callback;

/**
 *  Caches data in the cache directory or the user cache directory if there's a living valid session (user logged in).
 *
 *  @Warning The data is not encrypted using this method. Use MDAssetManager instead if you want it to be encrypted --this requires a logged in user.
 *
 * @param data Data to be saved.
 * @param fileName file path including file name.
 * @param callback asynchronous callback block called once the operation finished. It has a BOOL parameter indicating success or failure.
 */
- (void)saveDataToCacheDirectory:(NSData *)data
                        fileName:(NSString *)fileName
                        callback:(MDBoolCallback)callback;

/**
 *  Caches an image in the cache directory or the user cache directory if there's a living valid session (user logged in).
 *
 *  @Warning The image is not encrypted using this method. Use MDAssetManager instead if you want it to be encrypted --this requires a logged in user.
 *
 * @param image Data to be saved.
 * @param fileName file path including file name.
 * @param png pass in YES if the image should be encoded as a PNG image. It will be encoded as a JPG otherwise.
 * @param callback asynchronous callback block called once the operation finished. It has a BOOL parameter indicating success or failure.
 */
- (void)saveImageToCacheDirectory:(UIImage*)image
                         fileName:(NSString*)fileName
                              png:(BOOL)png
                         callback:(MDBoolCallback)callback;

@end

NS_ASSUME_NONNULL_END
