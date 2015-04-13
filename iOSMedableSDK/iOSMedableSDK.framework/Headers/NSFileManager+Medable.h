//
//  NSFileManager+Medable.h
//  Patient
//
//  
//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSFileManager (Medable)

- (NSString *)cacheDirectoryPath;
- (NSString *)documentsDirectoryPath;

- (NSString *)cacheDirectoryPathForUserID:(NSString *)inUserID;
- (NSString *)documentsDirectoryPathForUserID:(NSString *)inUserID;

- (NSString *)currentUserPath;
- (NSString *)imagesDiskCachePath;
- (NSString *)pathForContext:(NSString *)context contextID:(NSString *)contextID NOTNULL(1,2);
- (void)deleteCurrentDiskCache;

- (NSString *)imageCacheDirectoryForUserID:(NSString *)inUserID;

- (NSString *)saveImageToCacheDirectory:(UIImage *)image forUserID:(NSString *)inUserID;
- (void)deleteGeneralCacheDirectoryForUserID:(NSString *)inUserID;
- (void)removePhotoAtPath:(NSString *)inPath;


@end
