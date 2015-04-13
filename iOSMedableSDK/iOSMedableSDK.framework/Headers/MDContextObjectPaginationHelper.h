//
//  MDContextObjectPaginationHelper.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import "MDObjectsPaginationHelper.h"

@class MDAPIParameters;

@interface MDContextObjectPaginationHelper : MDObjectsPaginationHelper

@property (nonatomic, strong) MDAPIParameters* customParameters;
@property (nonatomic, strong) NSString* searchText;

- (MDContextObjectPaginationHelper*)initWithContext:(NSString*)context
                                           pageSize:(NSUInteger)pageSize
                                     baseParameters:(MDAPIParameters*)baseParameters
                                   customParameters:(MDAPIParameters*)customParameters
                                           delegate:(id<MDObjectsPaginationHelperDelegate>)delegate NOTNULL(1,5);

@end
