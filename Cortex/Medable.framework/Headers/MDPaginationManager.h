//
//  MDPaginationManager.h
//  Medable
//
//  Copyright © 2017 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MDPaginationHelper;

NS_ASSUME_NONNULL_BEGIN

@interface MDPaginationManager : NSObject

/**
 * MDPaginationManager singleton getter.
 * @return The singleton instance for this class.
 */
+ (MDPaginationManager *)sharedInstance;

/**
 * Convenience initializer. The field/property used for pagination is `_id`.
 *
 * @param identifier A string identifier for the paginator helper.
 * @param context The context name for the objects to be paginated.
 * @param pageSize The size of the page.
 * @param cacheResults Specifies whether to cache the results or not.
 * @param inverseOrder Pass in `YES` for inverse sorting of objects.
 * @return Initialized instance.
 */
+ (MDPaginationHelper *)paginatorWithIdentifier:(NSString *)identifier
                                        context:(NSString *)context
                                       pageSize:(NSUInteger)pageSize
                                   cacheResults:(BOOL)cacheResults
                                   inverseOrder:(BOOL)inverseOrder;

/**
 * Convenience initializer. The field/property used for pagination is `_id`.
 *
 * Use this initializer to paginate list properties inside a context: i.e: `GET /context/objectId/listProperty?listProperty.where={"_id":{"$gt":"lastValue"}}&limit=pageSize`
 *
 * @param identifier A string identifier for the paginator helper.
 * @param context The context name.
 * @param objectId The object Id.
 * @param listProperty The list property to be paginated.
 * @param pageSize The size of the page.
 * @param cacheResults Specifies whether to cache the results or not.
 * @param inverseOrder Pass in `YES` for inverse sorting of objects.
 * @return Initialized instance.
 */
+ (MDPaginationHelper *)listPropertyPaginatorWithIdentifier:(NSString *)identifier
                                                    context:(NSString *)context
                                                   objectId:(MDObjectId *)objectId
                                               listProperty:(NSString *)listProperty
                                                   pageSize:(NSUInteger)pageSize
                                               cacheResults:(BOOL)cacheResults
                                               inverseOrder:(BOOL)inverseOrder;

/**
 * Convenience Initializer.
 *
 * @param identifier A string identifier for the paginator helper.
 * @param context The context name (plural context) for the objects to be paginated.
 * @param pagingField The name of the field/property to use to paginate the objects. It has to be marked as indexed and unique in Medable API.
 * @param pageSize The size of the page.
 * @param cacheResults Specifies whether to cache the results or not.
 * @param inverseOrder Pass in `YES` for inverse sorting of objects.
 * @return Initialized instance.
 */
+ (MDPaginationHelper *)paginatorWithIdentifier:(NSString *)identifier
                                        context:(NSString *)context
                                    pagingField:(NSString *)pagingField
                                       pageSize:(NSUInteger)pageSize
                                   cacheResults:(BOOL)cacheResults
                                   inverseOrder:(BOOL)inverseOrder;

/**
 * Unavailable.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * Unavailable.
 */
- (instancetype)new NS_UNAVAILABLE;

/**
 * Managed paginators.
 *
 * @return All managed paginators.
 */
- (nullable NSArray<MDPaginationHelper *> *)paginators;

/**
 * Get a paginator by identifier.
 *
 * @return A paginator with the speciefied identifier if present.
 */
- (nullable MDPaginationHelper *)paginatorWithIdentifier:(NSString *)identifier;

/**
 * Adds an already existing paginator with an identifier.
 *
 * @return Returns YES if the paginator was successfully added. Returns NO if the paginator is already managed by this manager or if the identifier is not valid (i.e.: empty string).
 */
- (BOOL)addPaginator:(MDPaginationHelper *)paginator withIdentifier:(NSString *)identifier;

/**
 * Remove a paginator.
 */
- (void)removePaginator:(MDPaginationHelper*)paginator;

/**
 * Remove all managed paginators.
 */
- (void)removeAllPaginators;

@end

NS_ASSUME_NONNULL_END
