//
//  MDImageOverlayPair.h
//  iOSMedableSDK
//
//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MDImageOverlayPair : NSObject

@property (nonatomic, readonly) UIImage* image;
@property (nonatomic, readonly) UIImage* overlay;

+ (MDImageOverlayPair*)pairWithImage:(UIImage*)image overlay:(UIImage*)overlay NOTNULL(1);

@end