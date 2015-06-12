//
//  MDAttachmentMaps.h
//  iOSMedableSDK
//
//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Helper to construct post segment parameters.
 */

@interface MDAttachmentMaps : NSObject

/*
 *  Adds a new mapping pair
 */
- (void)addPair:(MDImageOverlayPair*)pair NOTNULL(1);

/**
 *  Return all the mapped pairs. Overlays are optional.
 */
- (NSArray*)pairs;

/**
 *  Returns a representation of the mappings. Use this to send as parameter in the body
 *  before uploading. i.e. when creating an object with image uploads.
 */
- (NSArray*)apiFormat;

- (UIImage*)imageWithFilename:(NSString*)filename NOTNULL(1);

@end
