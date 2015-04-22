//
//  MDObjectsPaginationHelper.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

@class MDObjectId;

/**
 * Pagination helper delegate.
 */
@protocol MDObjectsPaginationHelperDelegate <NSObject>

@required

/**
 * Get the last element returned in the previous result. Typically it's implemented by returning 
 * the last object in an ordered collection.
 *
 * @param results The previous results.
 * @return The Object ID of the last object.
 */
- (MDObjectId*)lastObjectIdFromResults:(id)results NOTNULL(1);

@end

/**
 * Helper class for object pagination.
 */
@interface MDObjectsPaginationHelper : NSObject

/**
 * Initializer passing page size and delegate.
 *
 * @param pageSize The size of the pages in the results.
 * @param delegate MDObjectsPaginationHelperDelegate object.
 * @return The newly created instance.
 */
- (MDObjectsPaginationHelper*)initWithPageSize:(NSUInteger)pageSize
                                      delegate:(id<MDObjectsPaginationHelperDelegate>)delegate NOTNULL(2);

/**
 * Load paginated list.
 *
 * @param callback Asynchronous callback, called on return of the API call.
 */
- (void)checkToLoadPaginatedObjectsWithCallback:(MDObjectCallback)callback NOTNULL(1);

/**
 * Load new page.
 *
 * @param callback Asynchronous callback, called on return of the API call.
 */
- (void)checkToLoadNewObjectsWithCallback:(MDObjectCallback)callback NOTNULL(1);

/**
 * Reset, will start loading from page 0 again.
 */
- (void)resetPagination;

@end
