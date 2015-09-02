//
//  MDFeedPaginationHelper.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import "MDObjectsPaginationHelper.h"

@class MDPost;


/**
 * Pagination helper for feeds.
 */
@interface MDFeedPaginationHelper : MDObjectsPaginationHelper

/// Extra API parameters.
@property (nonatomic, strong) MDAPIParameters* customParameters;

/**
 * Initialize feed pagination helper.
 *
 * @param contextObject The context object, or instance for the feed.
 * @param pageSize Size of resulting pages.
 * @param delegate Delegate.
 * @return The feed object pagination helper instance.
 */
- (MDFeedPaginationHelper*)initWithContextObject:(MDObjectInstance*)contextObject
                                        pageSize:(NSUInteger)pageSize;

@end
