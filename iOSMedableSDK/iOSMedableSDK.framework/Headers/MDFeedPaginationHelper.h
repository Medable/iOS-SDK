//
//  MDFeedPaginationHelper.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import "MDObjectsPaginationHelper.h"

@class MDPost;

@interface MDFeedPaginationHelper : MDObjectsPaginationHelper

@property (nonatomic, strong) MDAPIParameters* customParameters;

- (MDFeedPaginationHelper*)initWithContextObject:(MDObjectInstance*)contextObject
                                        pageSize:(NSUInteger)pageSize
                                        delegate:(id<MDObjectsPaginationHelperDelegate>)delegate NOTNULL(1,3);

- (void)synchronizeObject:(MDPost*)post
             withCallback:(MDObjectCallback)callback NOTNULL(1);

@end
