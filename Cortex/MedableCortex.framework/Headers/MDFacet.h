//
//  MDFacet.h
//  Medable
//
//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

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

/**
 * ETag or hash value. This shouldn't concern most users but it's used by the system to know when to update a file.
 */
@property (nullable, nonatomic, readonly) NSString *ETag;

/**
 * The URL of this facet. Note: This is not always present.
 */
@property (nullable, nonatomic, readonly) NSURL *url;

/**
 * The path of this facet. i.e.: context name/object Id/property name or path to property/facet name, etc
 */
@property (nonatomic, readonly) NSString *path;

/**
 * Facet's name.
 */
@property (nonatomic, readonly) NSString *name;

/**
 * Not all facets correspond to an already uploaded file.
 * The state of the facet reflects where the content for this facet is at right now.
 *
 * @see MDFileState
 */
@property (nonatomic, readonly) MDFileState state;

/**
 * Location.
 */
@property (nonatomic, readonly) NSNumber* location;

/**
 * Mime type.
 */
@property (nullable, nonatomic, readonly) NSString* mime;

/**
 * Number of bytes.
 */
@property (nullable, nonatomic, readonly) NSNumber* size;

/**
 * Creator for the content of this facet.
 */
@property (nonatomic, readonly) MDObjectId* creator;

/**
 * Whether it's a private facet.
 */
@property (nullable, nonatomic, readonly) NSNumber *isPrivate;

/**
 * The filename.
 */
@property (nullable, nonatomic, readonly) NSString *filename;

/**
 * Constructed by using path+ETag, will end with kUnknownETag if it's unknown.
 */
@property (nonatomic, readonly) NSString *cacheFilename;


// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

/**
 * Get the facet's data. It will be served from cache if the cached value matches 
 * the ETag or downloaded otherwise.
 *
 * @param callback The asynchronous callback called when downloading is complete. Returned data can be either NSData or UIImage.
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
 * Locally cache an image or data for this facet. Since the ETag value is unknown, it will be cached
 * with a suffix of kUnknownETag.
 *
 * @warning Synchronize the parent object after making this call (the object instance that owns the File
 * property this facet belongs to) to make sure the cached image gets updated in Cache. If you fail to
 * do so and backend image is updated in the interim, then the cache will be out of sync with the backend
 * and the SDK will serve the incorrect image.
 */

/**
 * Cache image in local cache
 *
 * @param image The image to be encrypted and cached in local cache.
 */
- (void)cacheImage:(UIImage *)image;

/**
 * Cache image in local cache
 *
 * @param image The image to be encrypted and cached in local cache.
 * @param finishBlock Callback block called after the image has been cached, or if an error occurred. The callback block's parameter is a BOOL and indicates 'success'.
 */
- (void)cacheImage:(UIImage *)image finishBlock:(MDBoolCallback)finishBlock;

/**
 * Cache data in local cache
 *
 * @param data The data to be encrypted and cached in local cache.
 * @param finishBlock Callback block called after the image has been cached, or if an error occurred. The callback block's parameter is a BOOL and indicates 'success'.
 */
- (void)cacheData:(NSData *)data finishBlock:(MDBoolCallback)finishBlock;

@end

NS_ASSUME_NONNULL_END
