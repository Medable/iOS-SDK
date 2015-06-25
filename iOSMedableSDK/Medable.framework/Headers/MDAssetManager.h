//
//  MDAssetManager.h
//  Medable
//
//  Copyright (c) 2014 Medable. All rights reserved.
//

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

/**
 * Decrypt a file stored in permanent storage.
 *
 * @param filename File name to decrypt.
 * @param callback Asynchronous return callback.
 */
- (void)decryptedDataWithFilename:(NSString*)filename
                         callback:(MDObjectCallback)callback NOTNULL(1,2);

/**
 * Get a file's data by retrieving it from it's most convenient location. Will pull from memory
 * if it's stored there.
 *
 * @param fileName The name of the file.
 * @param callback The asynchronous callback block to be called after processing has completed.
 */
- (void)dataFromFileWithName:(NSString*)fileName
                    callback:(MDDataWithSourceOrFaultCallback)callback NOTNULL(1,2);

/**
 * Conventional file moving which will also maintain internal consistencies in this class' instance.
 * Do not use NSFileManager to move files.
 *
 * @param origin Source file.
 * @param destination Destination file.
 * @return True if the source file was moved successfully to it's destination, False otherwise.
 */
- (BOOL)moveFile:(NSString *)origin to:(NSString *)destination;

/**
 * Store data to disk.
 *
 * @param data Binary data.
 * @param fileName The destination file.
 * @param finishBlock Asynchronous callback block to execute when processing is complete.
 */
- (void)saveData:(NSData*)data
        fileName:(NSString*)fileName
     finishBlock:(void (^)())finishBlock NOTNULL(1,2,3);

/**
 * Delete all files with file names matching a regular expression.
 *
 * @param regex The regular expression. All files that match this will be deleted.
 */
- (void)deleteAllFilesMatchingRegularExpression:(NSRegularExpression *)regex NOTNULL(1);

/**
 * Remove all cached images from the decrypted memory cache.
 */
- (void)cleanMemoryCache;

@end
