//
//  MDFastFileBodyProperty.h
//  iOSMedableSDK
//
//  
//  Copyright © 2017 Medable. All rights reserved.
//

#import "MDFileBodyProperty.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * A fast unchecked version of MDFileBodyProperty.
 */
@interface MDFastFileBodyProperty : MDFileBodyProperty

/**
 * Convenience initializer for creating an instance of this class.
 *
 * @param propertyName The name of the File property.
 * @param contents A dictionary with the contents. It requires a specific format: the keys are the facet names, the values are NSData objects (the actual attachments).
 * @return An initialized instance.
 */
+ (instancetype)fastFileBodyWithProperty:(NSString*)propertyName contents:(NSDictionary *)contents;

/**
 * Convenience initializer for creating an instance of this class.
 *
 * @param propertyName The name of the File property.
 * @param facet The name of the facet inside the File property.
 * @param data The attachment data.
 * @return An initialized instance.
 */
+ (instancetype)fastFileBodyWithProperty:(NSString*)propertyName facet:(NSString *)facet data:(NSData *)data;

- (void)addFacetAttachment:(NSString *)facetName
                      mime:(NSString *)mime
                      data:(NSData *)data NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
