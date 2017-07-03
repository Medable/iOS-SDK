//
//  MDContentDownloader.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * A string used to fire notifications signaling when bundle downloading has started.
 */
extern NSString* const kContentDownloadedDidStartDownloads;

/**
 * A string used to fire notifications signaling when bundle downloading has finished.
 */
extern NSString* const kContentDownloadedDidFinishDownloads;

/**
 * Bundle download helper.
 */
@interface MDContentDownloader : NSObject

/**
 * Initialize the downloader. Copy the callback to be used every time a new bundle is downloaded by this object.
 *
 * @param callback The asynchronous callback block that will be called every time a new bundle is downloaded.
 */
- (id)initWithCallback:(MDNoArgumentCallback)callback NOTNULL(1);

/**
 * Get the latest bundle and download all class definition schemas. Call the asynchronous callback used
 * when initializing this object once this process is completed.
 */
- (void)checkForDownloads;

@end
