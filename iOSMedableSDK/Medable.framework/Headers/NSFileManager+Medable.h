//
//  NSFileManager+Medable.h
//  Patient
//
//  
//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSFileManager (Medable)

- (NSString*)cacheDirectoryPath;

- (NSString*)currentUserPath;
- (BOOL)deleteCurrentUserDiskCache;
- (BOOL)deleteCurrentUserTempFiles;

/*
 *  @Warning The image is not encrypted using this method. Use MDAssetManager instead if you want it to be encrypted.
 */
- (void)saveImageToCacheDirectory:(UIImage*)image
                         fileName:(NSString*)fileName
                              png:(BOOL)png
                         callback:(MDBoolCallback)callback NOTNULL(1,2,4);

@end
