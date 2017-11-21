//
//  MDFilePropertyInstance.h
//  Medable
//
//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MDFacet.h"

NS_ASSUME_NONNULL_BEGIN

@class MDFileUpload;

/**
 * The value of a File Property.
 */
@interface MDFilePropertyValue : MDFacet

/**
 * Array of pending file uploads.
 */
@property (nullable, nonatomic, readonly) NSArray<MDFileUpload *> *uploads;

/**
 * Array of facets.
 */
@property (nonatomic, readonly) NSArray<MDFacet *> *facets;


// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

/**
 * The single upload for a file of a certain name.
 *
 * @param name The name used as the value of a facet when posting or editing a File property.
 * @return The file upload information for this facet.
 */
- (nullable MDFileUpload *)uploadForName:(NSString *)name;

/**
 * Pending uploads for this File property.
 *
 * @return The pending uploads for this File property.
 */
- (nullable NSArray<MDFileUpload *> *)pendingUploads;

/**
 * Get the File's facet that matches a certain name.
 *
 * @param name The name of the facet.
 * @return The facet object representing that facet.
 */
- (nullable MDFacet *)facetForName:(NSString *)name;

/**
 * Get the File's facet for a pending upload.
 *
 * @param upload The upload object.
 * @return The facet object for that upload.
 */
- (nullable MDFacet *)facetForUpload:(MDFileUpload *)upload;

@end

NS_ASSUME_NONNULL_END
