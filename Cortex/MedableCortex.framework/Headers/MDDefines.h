//
//  MDDefines.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#ifndef iOSMedableSDK_MDDefines_h
#define iOSMedableSDK_MDDefines_h


#ifdef INFO_PLIST
#define STRINGIFY(_x)        _x
#else
#define STRINGIFY(_x)      # _x
#endif

#define STRX(x)			x

#define kAPIVersion                     @"v2"

#define IS_IPHONE5 (([[UIScreen mainScreen] bounds].size.height-568)?NO:YES)

#define IS_IOS7_OR_LESS (floor(NSFoundationVersionNumber)<=NSFoundationVersionNumber_iOS_7_0)
#define IS_IOS6_OR_LESS (floor(NSFoundationVersionNumber)<=NSFoundationVersionNumber_iOS_6_1)
#define IS_IOS5_OR_LESS (floor(NSFoundationVersionNumber)<=NSFoundationVersionNumber_iOS_5_0)

//Breaks a little bit from the norm, but the above IS_IOS7_OR_LESS doesn't account
//for iOS 7.1, the most common version (this could have been fixed but this version is clearer)
#define IS_OS_8_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)

#endif
