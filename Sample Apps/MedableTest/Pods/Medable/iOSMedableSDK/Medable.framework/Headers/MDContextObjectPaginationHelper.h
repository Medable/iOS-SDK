//
//  MDContextObjectPaginationHelper.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import "MDObjectsPaginationHelper.h"

@class MDAPIParameters;

/**
 * Pagination helper for the context object.
 */
@interface MDContextObjectPaginationHelper : MDObjectsPaginationHelper

/// Extra API parameters.
@property (nonatomic, strong) MDAPIParameters* customParameters;

/// Search text, unused at the moment.
@property (nonatomic, strong) NSString* searchText;

/**
 * Initialize context pagination helper.
 *
 * @param context The name of the object class (or contexts).
 * @param pageSize Size of resulting pages.
 * @param baseParameters Base API parameters.
 * @param customParameters Custom API parameters.
 * @param delegate Delegate.
 * @return The context object pagination helper instance.
 */
- (MDContextObjectPaginationHelper*)initWithContext:(NSString*)context
                                           pageSize:(NSUInteger)pageSize
                                     baseParameters:(MDAPIParameters*)baseParameters
                                   customParameters:(MDAPIParameters*)customParameters
                                           delegate:(id<MDObjectsPaginationHelperDelegate>)delegate NOTNULL(1,5);

@end
