//
//  MDAssetManager.h
//  Medable
//
//  Copyright (c) 2014 Medable. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

extern NSErrorDomain const MDAssetManagerErrorDomain;

NS_ERROR_ENUM(MDAssetManagerErrorDomain)
{
    MDAssetManagerErrorUnknown =                    -1,
    MDAssetManagerErrorInvalidParameters =          -1000,
    MDAssetManagerErrorEncryptionFinishedAbruptly = -1001
};

/**
 * File manager to store encrypted files to persistent storage and (optionally) manage them
 * (unencrypted) in memory as well.
 */
@interface MDAssetManager : NSObject

/// Singleton instance
+ (MDAssetManager*)sharedManager;

/**
 *  Once an image is decrypted it keeps a reference to it, if somebody else asks for it
 *  the decrypted version is returned right away without going through the decryption process.
 *  Saves CPU, uses a lot of memory, because images are not freed since they are retained by the cache.
 */
@property (nonatomic, assign) BOOL useDecryptedDataMemoryCache;

// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// use the singleton
- (instancetype)init NS_UNAVAILABLE;

/**
 * Check if a file is disk cached.
 *
 * @param fileName The name of the file.
 * @return whether the file is cached.
 */
- (BOOL)isFileCachedWithFileName:(NSString*)fileName;

/**
 * Get a file's data by retrieving it from it's most convenient location. Will pull from memory
 * if it's stored there.
 *
 * @param fileName The name of the file.
 * @param callback The asynchronous callback block to be called after processing has completed.
 */
- (void)dataFromFileWithName:(NSString*)fileName
                    callback:(MDDataWithSourceOrFaultCallback)callback;

/**
 * Conventional file moving which will also maintain internal file inventories.
 * Do not use NSFileManager to move files that are managed by MDAssetManager.
 *
 * @param origin Source file.
 * @param destination Destination file.
 * @return An NSError if there was an error moving the source file to the destination.
 */
- (NSError *)moveFile:(NSString*)origin to:(NSString*)destination;

/**
 * Conventional file deletion which will also maintain internal file inventories.
 * Do not use NSFileManager to delete files that are managed by MDAssetManager.
 *
 * @param filename The name of the file (not the whole path).
 * @return An NSError if there was an error deleting the file.
 */
- (NSError *)deleteFileWithName:(NSString *)filename;

/**
 * Store data to disk.
 *
 * @param data Binary data.
 * @param fileName The destination file.
 * @param finishBlock Asynchronous callback block to execute when processing is complete.
 */
- (void)saveData:(NSData*)data
        fileName:(NSString*)fileName
     finishBlock:(MDBoolCallback)finishBlock;

/**
 * Delete all files with file names matching a regular expression.
 *
 * @param regex The regular expression. All files that match this will be deleted.
 */
- (void)deleteAllFilesMatchingRegularExpression:(NSRegularExpression*)regex;

/**
 * Remove all cached images from the decrypted memory cache.
 */
- (void)cleanMemoryCache;

@end

NS_ASSUME_NONNULL_END

