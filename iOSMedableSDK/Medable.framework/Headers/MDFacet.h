//
//  MDFacet.h
//  iOSMedableSDK
//
//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * A Facet is essentially a File's subproperty and in itself represents a single file.
 *
 * As an example, a conversation photo (under a single File property) might have 3 facets:
 *  - original
 *  - overlay
 *  - content
 *
 * The "content" facet refers to the composition of an original and it's overlay.
 */
@interface MDFacet : NSObject

/// ETag or hash value. This shouldn't concern most users but it's used by the system to know when to update a file.
@property (nonatomic, readonly) NSString *ETag;

/// The URL of this facet. Note: This is not always present.
@property (nonatomic, readonly) NSURL *url;

/// The path of this facet. i.e.: context name/object Id/property name or path to property/facet name, etc
@property (nonatomic, readonly) NSString *path;

/// Facet's name.
@property (nonatomic, readonly) NSString *name;

/**
 * Not all facets correspond to an already uploaded file.
 * The state of the facet reflects where the content for this facet is at right now.
 *
 * @see MDFileState
 */
@property (nonatomic, readonly) MDFileState state;

/// Location.
@property (nonatomic, readonly) NSNumber* location;

/// Mime type. Examples include "image/jpeg".
@property (nonatomic, readonly) NSString* mime;

/// Number of bytes.
@property (nonatomic, readonly) NSNumber* size;

/// Creator for the content of this facet.
@property (nonatomic, readonly) MDObjectId* creator;

/// Whether it's a private facet.
@property (nonatomic, readonly) BOOL isPrivate;

/// Constructed by using path+ETag, will end with kUnknownETag if it's unknown.
@property (nonatomic, readonly) NSString *fileName;


// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

/**
 * Get the facet's data. It will be served from cache if the cached value matches 
 * the ETag or downloaded otherwise.
 *
 * @param callback The asynchronous callback called when downloading is complete.
 */
- (void)fileDataWithCallback:(MDDataWithSourceOrFaultCallback)callback;

/**
 * Get the image represented by this facet. It will be served from cache if the cached value matches
 * the ETag or downloaded otherwise.
 *
 * @param callback The asynchronous callback called when downloading is complete.
 */
- (void)imageWithCallback:(MDImageWithSourceOrFaultCallback)callback;

/**
 * Checks the disk cache and returns if this facet is disk cached
 *
 * @return Returns if this facet is disk cached
 **/
- (BOOL)isCached;

/**
 * Locally cache an image for this facet. Since the ETag value is unknown, it will be cached
 * with a suffix of kUnknownETag.
 *
 * @warning Synchronize the parent object after making this call (the object instance that owns the File
 * property this facet belongs to) to make sure the cached image gets updated in Cache. If you fail to
 * do so and backend image is updated in the interim, then the cache will be out of sync with the backend
 * and the SDK will serve the incorrect image.
 */
- (void)cacheImage:(UIImage *)image;
- (void)cacheImage:(UIImage *)image finishBlock:(MDBoolCallback)finishBlock;

@end
