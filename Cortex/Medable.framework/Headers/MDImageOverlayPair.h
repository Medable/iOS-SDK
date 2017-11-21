//
//  MDImageOverlayPair.h
//  Medable
//
//  Copyright (c) 2015 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

DEPRECATED_MSG_ATTRIBUTE("This class will be removed in future versions.")
@interface MDImageOverlayPair : NSObject

@property (nonatomic, readonly) UIImage* image;
@property (nullable, nonatomic, readonly) UIImage* overlay;

+ (MDImageOverlayPair*)pairWithImage:(UIImage*)image overlay:(nullable UIImage*)overlay;

// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
