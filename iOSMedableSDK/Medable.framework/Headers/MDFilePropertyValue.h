//
//  MDFilePropertyInstance.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MDFacet.h"

@class MDFileUpload;

/**
 * The value of a File Property.
 */
@interface MDFilePropertyValue : MDFacet

/// Array of MDFileUpload instances, this contains temporary information regarding where to upload files for this property.
@property (nonatomic, readonly) NSArray *uploads;

/// Array of MDFacet objects.
@property (nonatomic, readonly) NSArray *facets;


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
- (MDFileUpload *)uploadForName:(NSString *)name;

/**
 * Get the File's facet that matches a certain name.
 *
 * @param name The name of the facet.
 * @return The facet object representing that facet.
 */
- (MDFacet *)facetForName:(NSString *)name;

@end
