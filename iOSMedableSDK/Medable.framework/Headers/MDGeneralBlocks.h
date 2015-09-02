//
//  MDGeneralBlocks.h
//  iOSMedableSDK
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#ifndef iOSMedableSDK_MDGeneralBlocks_h
#define iOSMedableSDK_MDGeneralBlocks_h

@class MDFault;

typedef void (^MDNoArgumentCallback)(void);
typedef void (^MDObjectCallback)(id object);
typedef void (^MDObjectFaultCallback)(id object, MDFault* fault);
typedef void (^MDBoolArgumentCallback)(BOOL boolean);
typedef void (^MDPicsUpdateBlock)(NSString* imageId, UIImage* image, MDDataSource source, MDFault* fault);
typedef void (^MDUIntegerCallback)(NSUInteger integer);
typedef void (^MDImageCallback)(UIImage* image);
typedef void (^MDFaultCallback)(MDFault* fault);
typedef void (^MDImageOrFaultCallback)(UIImage* image, MDFault* fault);
typedef void (^MDDataWithSourceOrFaultCallback)(NSData *data, MDDataSource source, MDFault* fault);
typedef void (^MDImageWithSourceOrFaultCallback)(UIImage* image, MDDataSource source, MDFault* fault);
typedef void (^MDObjectBoolCallback)(id object, BOOL condition);

#endif
