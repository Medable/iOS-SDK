//
//  MDBundle.h
//  Medable
//
//  
//  Copyright (c) 2014 Medable. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

/**
 * A bundle represents additional information about an Organization.
 *
 * @see MDOrg
 */
@interface MDBundle : NSObject

/// Which Organization this bundle belongs to.
@property (nonatomic, readonly) MDObjectId* org;

/**
 * Version of the bundle.
 *
 * @see bundleVersion
 */
@property (nonatomic, readonly) NSString* version;

/// Locale
@property (nonatomic, readonly) NSString* locale;

/// Strings mapping.
@property (nullable, nonatomic, readonly) NSDictionary* strings;

/// Custom faults information.
@property (nullable, nonatomic, readonly) NSDictionary* faults;

@end

NS_ASSUME_NONNULL_END
