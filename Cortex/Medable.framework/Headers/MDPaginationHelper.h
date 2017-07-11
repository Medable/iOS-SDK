//
//  MDPaginationHelper.h
//  Medable
//
//  Copyright © 2017 Medable. All rights reserved.
//

typedef NS_ENUM(NSInteger, PaginatorState) {
    PaginatorStateIdle = 0,
    PaginatorStateLoadingNextPage,
    PaginatorStateLoadingAllPages,
    PaginatorStateDestroyed
};

NS_ASSUME_NONNULL_BEGIN

@protocol MDPaginationHelperDelegate <NSObject>

@optional

/**
 * Called every time the paginator gets new results. If loadAllPages is called and the method below is implemented, then this method is not called for those results, only the other method.
 */
- (void)paginator:(MDPaginationHelper *)paginator didLoadResults:(nullable NSArray<MDObjectInstance*> *)objects hasMore:(nullable NSNumber *)hasMore fault:(nullable MDFault *)fault;

/**
 * If the delegate object implements this method then only this method will be called for loadAllPages results and the one above for loadNextPage results.
 * Otherwise all the results are sent to the delegate using the method above.
 */
- (void)paginator:(MDPaginationHelper *)paginator didLoadAllResults:(nullable NSArray<MDObjectInstance*> *)objects fault:(nullable MDFault *)fault;

@end

/**
 * Helper class for object pagination.
 */
@interface MDPaginationHelper : NSObject

/**
 * A string identifier for this paginator helper. 
 * This is set by the `MDPaginatorManager` when creating paginator helpers through the provided factory methods in the manager's class.
 */
@property (nullable, readonly) NSString *identifier;

/**
 * Set a delegate to receive results in delegate approach. Callback and delegate are not mutually exclusive.
 */
@property (nullable, weak) id<MDPaginationHelperDelegate> delegate;

/**
 * An alternative to the delegate approach to receive results. Both can be used at the same time.
 *
 * Note: Use with caution. The block is being copied and any strong reference that is captured by this.
 */
@property (nullable, copy) MDObjectListFaultCallback resultsCallback;

/**
 * Use this to add additional parameters like include / expand / etc.
 */
@property (nullable, strong) MDAPIParameters *customParameters;


/**
 * Unavailable.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 * Convenience initializer. The field/property used for pagination is `_id`.
 *
 * @param context The context name for the objects to be paginated.
 * @param pageSize The size of the page.
 * @param cacheResults Specifies whether to cache the results or not.
 * @param inverseOrder Pass in `YES` for inverse sorting of objects.
 * @return Initialized instance.
 */
+ (instancetype)paginatorWithContext:(NSString *)context pageSize:(NSUInteger)pageSize cacheResults:(BOOL)cacheResults inverseOrder:(BOOL)inverseOrder;

/**
 * Convenience initializer. The field/property used for pagination is `_id`.
 *
 * Use this initializer to paginate list properties inside a context: i.e: `GET /context/objectId/listProperty?listProperty.where={"_id":{"$gt":"lastValue"}}&limit=pageSize`
 *
 * @param context The context name.
 * @param objectId The object Id.
 * @param listProperty The list property to be paginated.
 * @param pageSize The size of the page.
 * @param cacheResults Specifies whether to cache the results or not.
 * @param inverseOrder Pass in `YES` for inverse sorting of objects.
 * @return Initialized instance.
 */
+ (instancetype)listPropertyPaginatorWithContext:(NSString *)context objectId:(MDObjectId *)objectId listProperty:(NSString *)listProperty pageSize:(NSUInteger)pageSize cacheResults:(BOOL)cacheResults inverseOrder:(BOOL)inverseOrder;

/**
 * Convenience Initializer.
 *
 * @param context The context name (plural context) for the objects to be paginated.
 * @param pagingField The name of the field/property to use to paginate the objects. It has to be marked as indexed and unique in Medable API.
 * @param pageSize The size of the page.
 * @param cacheResults Specifies whether to cache the results or not.
 * @param inverseOrder Pass in `YES` for inverse sorting of objects.
 * @return Initialized instance.
 */
+ (instancetype)paginatorWithContext:(NSString *)context pagingField:(NSString *)pagingField pageSize:(NSUInteger)pageSize cacheResults:(BOOL)cacheResults inverseOrder:(BOOL)inverseOrder;


/**
 * Unavailable init.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * Default initializer. The field/property used for pagination is `_id`.
 *
 * @param context The context name for the objects to be paginated.
 * @param pageSize The size of the page.
 * @param cacheResults Specifies whether to cache the results or not.
 * @param inverseOrder Pass in `YES` for inverse sorting of objects.
 * @return Initialized instance.
 */
- (instancetype)initWithContext:(NSString *)context pageSize:(NSUInteger)pageSize cacheResults:(BOOL)cacheResults inverseOrder:(BOOL)inverseOrder;

/**
 * Custom initializer. The field/property used for pagination is `_id`.
 *
 * Use this initializer to paginate list properties inside a context: i.e: `GET /context/objectId/listProperty?listProperty.where={"_id":{"$gt":"lastValue"}}&limit=pageSize`
 *
 * @param context The context name.
 * @param objectId The object Id.
 * @param listProperty The list property to be paginated.
 * @param pageSize The size of the page.
 * @param cacheResults Specifies whether to cache the results or not.
 * @param inverseOrder Pass in `YES` for inverse sorting of objects.
 * @return Initialized instance.
 */
- (instancetype)initWithContext:(NSString *)context objectId:(MDObjectId *)objectId listProperty:(NSString *)listProperty pageSize:(NSUInteger)pageSize cacheResults:(BOOL)cacheResults inverseOrder:(BOOL)inverseOrder;

/**
 * Default Initializer.
 *
 * @param context The context name (plural context) for the objects to be paginated.
 * @param pagingField The name of the field/property to use to paginate the objects. It has to be marked as indexed and unique in Medable API.
 * @param pageSize The size of the page.
 * @param cacheResults Specifies whether to cache the results or not.
 * @param inverseOrder Pass in `YES` for inverse sorting of objects.
 * @return Initialized instance.
 */
- (instancetype)initWithContext:(NSString *)context pagingField:(NSString *)pagingField pageSize:(NSUInteger)pageSize cacheResults:(BOOL)cacheResults inverseOrder:(BOOL)inverseOrder;

/**
 *  Current state for this paginator.
 */
- (PaginatorState)currentState;

/**
 * Load next page. Results through callback and / or delegate properties.
 * If the paginator is not in Idle state, this operation will be queued.
 */
- (void)loadNextPage;

/**
 * Loads all objects. Keeps loading pages until all the objects are loaded. Not recommended.
 * If the cache results is ON, and there are current cached results, and loadAllPages is called; the cached results are cleared.
 * If the paginator is not in Idle state, this operation will be queued.
 */
- (void)loadAllPages;

/**
 *  Cached results
 *
 * @return If cacheResults is `YES`, this method returns the cached results.
 */
- (NSArray<MDObjectInstance *> *)cachedPagedResults;

/**
 * Clears all cacheResults, restarts pagination.
 * If the paginator is not in Idle state, this operation will be queued.
 */
- (void)resetPagination;

/**
 * Destroys paginator and frees resources. This action is delayed and asynchronous.
 */
- (void)destroyPaginator;

@end

NS_ASSUME_NONNULL_END
