//
//  MDObjectsPaginationHelper.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

/**
 * Helper class for object pagination.
 */
@interface MDObjectsPaginationHelper : NSObject

/**
 * Use it to check if there are more pages to load.
 */
@property (nonatomic, readonly) BOOL morePagesToLoad;

/**
 * Initializer passing page size and delegate.
 *
 * @param pageSize The size of the pages in the results.
 * @return The newly created instance.
 */
- (MDObjectsPaginationHelper*)initWithPageSize:(NSUInteger)pageSize;

/**
 * Load paginated list.
 *
 * @param callback Asynchronous callback, called on return of the API call.
 */
- (void)loadNextPageWithCallback:(MDObjectCallback)callback NOTNULL(1);

/**
 * Load new page.
 *
 * @param callback Asynchronous callback, called on return of the API call.
 */
- (void)loadObjectsNewerThan:(MDObjectId*)objecId callback:(MDObjectCallback)callback NOTNULL(1,2);

/**
 * Reset, will start loading from page 0 again.
 */
- (void)resetPagination;

@end
