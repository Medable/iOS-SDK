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

/*
 *  @Warning The image is not encrypted using this method. Use MDAssetManager instead if you want it to be encrypted.
 */
- (NSString*)saveImageToCacheDirectory:(UIImage*)image png:(BOOL)png NOTNULL(1);

@end
