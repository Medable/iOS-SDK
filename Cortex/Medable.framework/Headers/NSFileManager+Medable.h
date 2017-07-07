//
//  NSFileManager+Medable.h
//  Patient
//
//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSFileManager (Medable)

- (NSString*)cacheDirectoryPath;
- (nullable NSString*)currentUserPath;

- (BOOL)deleteCurrentUserDiskCache;
- (BOOL)deleteCurrentUserTempFiles;

/*
 *  @Warning The image is not encrypted using this method. Use MDAssetManager instead if you want it to be encrypted.
 */
- (void)saveImageToCacheDirectory:(UIImage*)image
                         fileName:(NSString*)fileName
                              png:(BOOL)png
                         callback:(MDBoolCallback)callback;

@end

NS_ASSUME_NONNULL_END
