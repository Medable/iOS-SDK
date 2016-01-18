//
//  Medable.h
//  iOSMedableSDK
//
//  Copyright (c) 2014 Medable. All rights reserved.
//

#ifndef iOSMedableSDK_MDCommonImports_h
#define iOSMedableSDK_MDCommonImports_h

#import <UIKit/UIKit.h>

// General
#import "NXDebug.h"
#import "MDDefines.h"
#import "MDConstants.h"
#import "MDTypedefs.h"
#import "MDEnvironment.h"
#import "MDGeneralBlocks.h"

// Utils
#import "MDDataFriendly.h"
#import "MDDateUtilities.h"
#import "MDAPIParameterFactory.h"
#import "MDContentDownloader.h"
#import "MDLegalAgreement.h"
#import "MDLegalAgreementManager.h"
#import "MDDataValidator.h"
#import "MDInfoValidator.h"
#import "MDNotificationManager.h"
#import "MDAssetManager.h"
#import "MDUploadOperations.h"
#import "MDImageOverlayPair.h"
#import "MDAttachmentMaps.h"

// Model
#import "MDTarget.h"
#import "MDObjectId.h"
#import "MDReference.h"
#import "MDFault.h"
#import "MDLocalFault.h"
#import "MDAccountRole.h"
#import "MDNotification.h"
#import "MDProfileInfo.h"
#import "MDACLDefines.h"
#import "MDBundleManager.h"
#import "MDBundle.h"
#import "MDPropertyDefinition.h"
#import "MDFacetDefinition.h"
#import "MDACLObject.h"
#import "MDObjectDefinition.h"
#import "MDSchemaManager.h"
#import "MDBaseInstance.h"
#import "MDObjectInstance.h"
#import "MDPostSegmentPropertyDefinition.h"
#import "MDPostSegmentDefinition.h"
#import "MDPostDefinition.h"
#import "MDFeedDefinition.h"
#import "MDPost.h"
#import "MDPostComment.h"
#import "MDPostSegment.h"
#import "MDCallingPostSegment.h"
#import "MDPropertyInstance.h"
#import "MDFilePropertyValue.h"
#import "MDFileUpload.h"
#import "MDFacet.h"
#import "MDPropertyContainer.h"
#import "MDAccount.h"
#import "MDPatientFile.h"
#import "MDConversation.h"
#import "MDTeam.h"
#import "MDConnection.h"
#import "MDOrg.h"
#import "MDBody.h"
#import "MDArrayBodyProperty.h"
#import "MDBaseBodyProperty.h"
#import "MDBodyProperty.h"
#import "MDFastBodyProperty.h"
#import "MDFileBodyProperty.h"
#import "MDPostBody.h"
#import "MDSimpleBodyProperty.h"

// Pagination
#import "MDContextObjectPaginationHelper.h"
#import "MDObjectsPaginationHelper.h"
#import "MDFeedPaginationHelper.h"

// Client
#import "MDAPIClient.h"

// Extensions
#import "NSDate+MongoDB.h"
#import "NSDictionary+JSONPrettyString.h"
#import "NSArray+JSONPrettyString.h"
#import "NSDictionary+Path.h"
#import "NSDate+InternetDateTime.h"
#import "NSObject+JSONStringify.h"
#import "NSDictionary+RemoveNullObjects.h"
#import "NSFileManager+Medable.h"
#import "NSString+ThreeDigitsVersion.h"
#import "NSString+URLExtensions.h"
#import "NSDate+InternetDateTime.h"

#endif

@interface Medable : NSObject

/**
 * This will download your basic Organization information, which is required to communicate with the Medable backend.
 *
 * Place a call to this method within your application's delegate method (`didFinishLaunching`). Ideally, you should
 * check for the notifications with these names:
 *
 * - `kContentDownloadedDidStartDownloads` : Downloads started.
 * - `kContentDownloadedDidFinishDownloads` : Downloads completed.
 *
 * If the download fails and you don't retry it, then whenever an http request is made out to the Medable API, it will
 * first attempt to download this information before making the call.
 */
+ (void)start;

/**
 * Shared Medable API client (or singleton), same as calling `[MDAPIClient sharedClient]`.
 */
+ (MDAPIClient *)client;

@end