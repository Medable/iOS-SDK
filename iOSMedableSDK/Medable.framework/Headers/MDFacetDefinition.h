//
//  MDFacetDefinition.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * A definition counterpart to a File's facet.
 */
@interface MDFacetDefinition : NSObject

/// Name of the processor.
@property (nonatomic, readonly) NSString *name;

/// Human readable string, localized to the Org's locale.
@property (nonatomic, readonly) NSString *label;

/// Unique identifier.
@property (nonatomic, readonly) MDObjectId* Id;

/// String defining the type of this processor.
@property (nonatomic, readonly) NSString *type;

/// Acceptable mime types for this File property's facet.
@property (nonatomic, readonly) NSArray *mimes;

/// Location
@property (nonatomic, readonly) NSNumber *location;

/// Source.
@property (nonatomic, readonly) NSString* source;

/// Whether the processor allow for an upload.
@property (nonatomic, readonly) NSNumber* allowUpload;

/// Whether this is the default processor.
@property (nonatomic, readonly) NSNumber* isDefault;

/// Whether the caller should pass mime types.
@property (nonatomic, readonly) NSNumber* passMimes;

/// Whether this is a private facet.
@property (nonatomic, readonly) NSNumber* isPrivate;

/// Whether it's a required facet when uploading.
@property (nonatomic, readonly) NSNumber* required;

/**
 * Create a facet definition from their attributes.
 *
 * @param attributes Dictionary mapping the facet definition's attributes.
 * @return The resulting facet definition.
 *
 * @warning Usage of this method directly is not encouraged for SDK users on most cases.
 */
+ (MDFacetDefinition*)facetDefinitionWithAttributes:(NSDictionary *)attributes NOTNULL(1);

/**
 * Whether this facet supports a certain mime type.
 *
 * @param mimeType A properly formatted mime type string.
 * @return Whether the mime type is supported in this facet.
 */
- (BOOL)supportsMimeType:(NSString *)mimeType;

/**
 *  Debug helper. Useful to get a minimum valid json representation of this object.
 **/
- (NSDictionary*)friendlyRepresentation;

@end
