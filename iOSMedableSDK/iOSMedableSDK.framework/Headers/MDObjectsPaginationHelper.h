//
//  MDObjectsPaginationHelper.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

@class MDObjectId;

@protocol MDObjectsPaginationHelperDelegate <NSObject>
@required
- (MDObjectId*)lastObjectIdFromResults:(id)results NOTNULL(1);
@end

@interface MDObjectsPaginationHelper : NSObject

- (MDObjectsPaginationHelper*)initWithPageSize:(NSUInteger)pageSize
                                      delegate:(id<MDObjectsPaginationHelperDelegate>)delegate NOTNULL(2);

- (void)checkToLoadPaginatedObjectsWithCallback:(MDObjectCallback)callback NOTNULL(1);
- (void)checkToLoadNewObjectsWithCallback:(MDObjectCallback)callback NOTNULL(1);

- (void)synchronizeObjectWithId:(MDObjectId*)objectId withCallback:(MDObjectCallback)callback NOTNULL(1);

- (void)resetPagination;

@end
