//
//  MDPaginationHelper.h
//  iOSMedableSDK
//
//  Copyright © 2017 Medable. All rights reserved.
//

typedef NS_ENUM(NSInteger, PaginatorState) {
    PaginatorStateIdle = 0,
    PaginatorStateLoadingNextPage,
    PaginatorStateLoadingAllPages
};

NS_ASSUME_NONNULL_BEGIN

@protocol MDPaginationHelperDelegate <NSObject>
- (void)paginatorDidLoadResults:(nullable NSArray<MDObjectInstance*> *)objects hasMore:(nullable NSNumber *)hasMore fault:(nullable MDFault *)fault;

@optional
/**
 * If the delegate object implements this method then only this method will be called for loadAllPages results and the one above for loadNextPage results.
 * Otherwise all the results are sent to the delegate using the method above.
 */
- (void)paginatorDidLoadAllResults:(nullable NSArray<MDObjectInstance*> *)objects fault:(nullable MDFault *)fault;
@end

/**
 * Helper class for object pagination.
 */
@interface MDPaginationHelper : NSObject

// Set a delegate to receive results in delegate approach. Callback and delegate are not mutually exclusive.
@property (nullable, weak) id<MDPaginationHelperDelegate> delegate;

// Use this to add additional parameters like include / expand / etc.
@property (nullable, strong) MDAPIParameters *customParameters;


// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

/**
 * Default initializer. The field/property used for pagination is `_id`.
 *
 * @param pluralContext The context name (plural context) for the objects to be paginated.
 * @param pageSize The size of the page.
 * @param cacheResults Specifies whether to cache the results or not.
 * @param inverseOrder Pass in `YES` for inverse sorting of objects.
 * @return Initialized instance.
 */
- (instancetype)initWithPluralContext:(NSString *)pluralContext pageSize:(NSUInteger)pageSize cacheResults:(BOOL)cacheResults inverseOrder:(BOOL)inverseOrder;

/**
 * Custom Initializer.
 *
 * @param pluralContext The context name (plural context) for the objects to be paginated.
 * @param pagingField The name of the field/property to use to paginate the objects. It has to be marked as indexed and unique in Medable API.
 * @param pageSize The size of the page.
 * @param cacheResults Specifies whether to cache the results or not.
 * @param inverseOrder Pass in `YES` for inverse sorting of objects.
 * @return Initialized instance.
 */
- (instancetype)initWithPluralContext:(NSString *)pluralContext pagingField:(NSString *)pagingField pageSize:(NSUInteger)pageSize cacheResults:(BOOL)cacheResults inverseOrder:(BOOL)inverseOrder;

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

@end

NS_ASSUME_NONNULL_END
