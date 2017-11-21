//
//  MDAttachmentMaps.h
//  Medable
//
//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Helper to construct post segment parameters.
 */
DEPRECATED_MSG_ATTRIBUTE("This class will be removed in future versions.")
@interface MDAttachmentMaps : NSObject

/*
 *  Adds a new mapping pair
 */
- (void)addPair:(nonnull MDImageOverlayPair*)pair;

/**
 *  Return all the mapped pairs. Overlays are optional.
 */
- (nonnull NSArray*)pairs;

/**
 *  Returns a representation of the mappings. Use this to send as parameter in the body
 *  before uploading. i.e. when creating an object with image uploads.
 */
- (nonnull NSArray*)apiFormat;

- (nonnull UIImage*)imageWithFilename:(nonnull NSString*)filename;

@end
