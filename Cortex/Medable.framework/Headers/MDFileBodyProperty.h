//
//  MDFileBodyProperty.h
//  Medable
//
//  Copyright © 2015 Medable. All rights reserved.
//

#import "MDBodyProperty.h"

/**
 * File body property containing the attachments for the File property's facets.
 */
@interface MDFileBodyProperty : MDBodyProperty

/**
 * Add an attachment mapped to a facet.
 *
 * @param facetName Name of the facet that's getting the attachment.
 * @param mime Mime type of the attachment.
 * @param data Binary data being attached.
 */
- (void)addFacetAttachment:(NSString * _Nonnull) facetName
                      mime:(NSString * _Nonnull) mime
                      data:(NSData * _Nonnull) data;

@end
