//
//  MDGeneralBlocks.h
//  iOSMedableSDK
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

@class MDObjectInstance;

@class MDPatientFile;
@class MDConversation;
@class MDTeam;

@class MDConnection;

@class MDPost;
@class MDPostComment;

@class MDNotification;

@class MDFault;

typedef void (^MDNoArgumentCallback)(void);
typedef void (^MDObjectCallback)(NSObject * _Nullable object);
typedef void (^MDDataCallback)(NSData * _Nullable data);
typedef void (^MDErrorCallback)(NSError * _Nullable error);
typedef void (^MDObjectFaultCallback)(id _Nullable object, MDFault * _Nullable fault);
typedef void (^MDObjectInstanceFaultCallback)(MDObjectInstance * _Nullable instance, MDFault * _Nullable fault);
typedef void (^MDBoolCallback)(BOOL boolean);
typedef void (^MDPicsUpdateBlock)(NSString * _Nullable imageId, UIImage * _Nullable image, MDDataSource source, MDFault * _Nullable fault);
typedef void (^MDUIntegerCallback)(NSUInteger integer);
typedef void (^MDImageCallback)(UIImage * _Nullable image);
typedef void (^MDFaultCallback)(MDFault * _Nullable fault);
typedef void (^MDImageOrFaultCallback)(UIImage * _Nullable image, MDFault * _Nullable fault);
typedef void (^MDDataWithSourceOrFaultCallback)(NSData * _Nullable data, MDDataSource source, MDFault * _Nullable fault);
typedef void (^MDImageWithSourceOrFaultCallback)(UIImage * _Nullable image, MDDataSource source, MDFault * _Nullable fault);
typedef void (^MDObjectBoolCallback)(NSObject * _Nullable object, BOOL condition);

// lists
typedef void (^MDObjectListFaultCallback)(NSArray<MDObjectInstance*> * _Nullable objects, NSNumber * _Nullable hasMore, MDFault * _Nullable fault);

typedef void (^MDPatientFileListFaultCallback)(NSArray<MDPatientFile*> * _Nullable patientFiles, NSNumber * _Nullable hasMore, MDFault * _Nullable fault);
typedef void (^MDConversationListFaultCallback)(NSArray<MDConversation*> * _Nullable conversations, NSNumber * _Nullable hasMore, MDFault * _Nullable fault);
typedef void (^MDTeamListFaultCallback)(NSArray<MDTeam*> * _Nullable conversations, NSNumber * _Nullable hasMore, MDFault * _Nullable fault);

typedef void (^MDConnectionListFaultCallback)(NSArray<MDConnection*> * _Nullable connections, NSNumber * _Nullable hasMore, MDFault * _Nullable fault);

typedef void (^MDPostListFaultCallback)(NSArray<MDPost*> * _Nullable posts, NSNumber * _Nullable hasMore,  MDFault * _Nullable fault);
typedef void (^MDCommentListFaultCallback)(NSArray<MDPostComment*> * _Nullable comments, NSNumber * _Nullable hasMore,  MDFault * _Nullable fault);

typedef void (^MDNotificationListFaultCallback)(NSArray<MDNotification*> * _Nullable notifications, NSNumber * _Nullable hasMore,  MDFault * _Nullable fault);
