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
 * Method for creating random identifiers for paginators if providing an identifier is not what matters.
 *
 * @return A randomly generated identifier.
 */
+ (NSString *)randomId;

/**
 * Convenience initializer to paginate context objects.
 *
 * The field/property used for pagination is `_id`.
 *
 * @param identifier A string identifier for the paginator helper.
 * @param context The context name for the objects to be paginated.
 * @param pageSize The size of the page.
 * @param cacheResults Specifies whether to cache the results or not.
 * @param inverseOrder Pass in `YES` for inverse sorting of objects.
 * @return Initialized instance. `nil` if a paginator with the same `identifier` already exists.
 */
+ (nullable MDPaginationHelper *)paginatorWithIdentifier:(NSString *)identifier
                                                 context:(NSString *)context
                                                pageSize:(NSUInteger)pageSize
                                            cacheResults:(BOOL)cacheResults
                                            inverseOrder:(BOOL)inverseOrder;

/**
 * Convenience initializer to paginate list properties.
 *
 * The field/property used for pagination is `_id`. Use this initializer to paginate list properties inside a context: i.e: `GET /context/objectId/listProperty?listProperty.where={"_id":{"$gt":"lastValue"}}&limit=pageSize`
 *
 * @param identifier A string identifier for the paginator helper.
 * @param context The context name.
 * @param objectId The object Id.
 * @param listProperty The list property to be paginated.
 * @param pageSize The size of the page.
 * @param cacheResults Specifies whether to cache the results or not.
 * @param inverseOrder Pass in `YES` for inverse sorting of objects.
 * @return Initialized instance. `nil` if a paginator with the same `identifier` already exists.
 */
+ (nullable MDPaginationHelper *)listPropertyPaginatorWithIdentifier:(NSString *)identifier
                                                             context:(NSString *)context
                                                            objectId:(MDObjectId *)objectId
                                                        listProperty:(NSString *)listProperty
                                                            pageSize:(NSUInteger)pageSize
                                                        cacheResults:(BOOL)cacheResults
                                                        inverseOrder:(BOOL)inverseOrder;

/**
 * Convenience initializer to paginate a list in a path with _id as the paging field.
 *
 * The field/property used for pagination is `_id`. Use this initializer to paginate list properties with a path: i.e: `GET /path/to/listProperty?listProperty.where={"_id":{"$gt":"lastValue"}}&limit=pageSize`
 *
 * @param identifier A string identifier for the paginator helper.
 * @param path The path to the list property. The path ends with the property name. Don't finish the path with a trailing forward slash. ObjectIds might be used in the path and also in array subpathing. i.e.: path/to/listProperty
 * @param pageSize The size of the page.
 * @param cacheResults Specifies whether to cache the results or not.
 * @param inverseOrder Pass in `YES` for inverse sorting of objects.
 * @return Initialized instance. `nil` if a paginator with the same `identifier` already exists.
 */
+ (nullable MDPaginationHelper *)paginatorWithIdentifier:(NSString *)identifier
                                                    path:(NSString *)path
                                                pageSize:(NSUInteger)pageSize
                                            cacheResults:(BOOL)cacheResults
                                            inverseOrder:(BOOL)inverseOrder;

/**
 * Convenience initializer to paginate a list in a path with (optional) `pagingField` as the paging field.
 *
 * The field/property used for pagination is `_id`. Use this initializer to paginate list properties with a path: i.e: `GET /path/to/listProperty?listProperty.where={"_id":{"$gt":"lastValue"}}&limit=pageSize`
 *
 * @param identifier A string identifier for the paginator helper.
 * @param path The path to the list property. The path ends with the property name. Don't finish the path with a trailing forward slash. ObjectIds might be used in the path and also in array subpathing. i.e.: path/to/listProperty
 * @param pagingField The name of the field/property to use to paginate the objects. It has to be marked as indexed and unique in Medable API. If `nil` is passed, skip+limit pagination method is used.
 * @param pageSize The size of the page.
 * @param cacheResults Specifies whether to cache the results or not.
 * @param inverseOrder Pass in `YES` for inverse sorting of objects.
 * @return Initialized instance. `nil` if a paginator with the same `identifier` already exists.
 */
+ (nullable MDPaginationHelper *)paginatorWithIdentifier:(NSString *)identifier
                                                    path:(NSString *)path
                                             pagingField:(nullable NSString *)pagingField
                                                pageSize:(NSUInteger)pageSize
                                            cacheResults:(BOOL)cacheResults
                                            inverseOrder:(BOOL)inverseOrder;

/**
 * Convenience initializer to paginate context objects with a different paging field other than _id.
 *
 * @param identifier A string identifier for the paginator helper.
 * @param context The context name (plural context) for the objects to be paginated.
 * @param pagingField The name of the field/property to use to paginate the objects. It has to be marked as indexed and unique in Medable API. If `nil` is passed, skip+limit pagination method is used.
 * @param pageSize The size of the page.
 * @param cacheResults Specifies whether to cache the results or not.
 * @param inverseOrder Pass in `YES` for inverse sorting of objects.
 * @return Initialized instance. `nil` if a paginator with the same `identifier` already exists.
 */
+ (nullable MDPaginationHelper *)paginatorWithIdentifier:(NSString *)identifier
                                                 context:(NSString *)context
                                             pagingField:(nullable NSString *)pagingField
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
 * @return Returns YES if the paginator was successfully added. Returns NO if the paginator is already managed by this manager or if the identifier is not valid (i.e.: empty string, or identifier already in use).
 */
- (BOOL)addPaginator:(MDPaginationHelper *)paginator withIdentifier:(NSString *)identifier;

/**
 * Adds an already existing paginator. The identifier is created randomly when adding the paginator.
 *
 * @return Returns YES if the paginator was successfully added. Returns NO if the paginator couldn't be added.
 */
- (BOOL)addPaginator:(MDPaginationHelper *)paginator;

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
