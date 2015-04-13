//
//  MDProcessor.h
//  iOSMedableSDK
//

//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MDProcessor : NSObject

@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly) NSString *label;
@property (nonatomic, readonly) MDObjectId* Id;
@property (nonatomic, readonly) NSString *type;
@property (nonatomic, readonly) NSArray *mimes;
@property (nonatomic, readonly) NSNumber *location;
@property (nonatomic, readonly) NSString* source;
@property (nonatomic, readonly) BOOL allowUpload;
@property (nonatomic, readonly) BOOL isDefault;
@property (nonatomic, readonly) BOOL passMimes;
@property (nonatomic, readonly) BOOL private;
@property (nonatomic, readonly) BOOL required;

+ (MDProcessor*)processorWithAttributes:(NSDictionary *)attributes NOTNULL(1);

- (BOOL)supportsMimeType:(NSString *)mimeType;

@end
