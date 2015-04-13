//
//  MDObjectId.h
//  iOSMedableSDK
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MDObjectId : NSObject

+ (MDObjectId*)objectIdWithString:(NSString*)objectIdString NOTNULL(1);
- (NSString*)stringRepresentation;

@end
