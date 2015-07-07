//
//  MDTypedefs.h
//  iOSMedableSDK
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#pragma mark - Console log levels

typedef enum : NSUInteger
{
    MDAPIClientNetworkLoggerLevelOff,
    MDAPIClientNetworkLoggerLevelDebug,
    MDAPIClientNetworkLoggerLevelInfo,
    MDAPIClientNetworkLoggerLevelWarn,
    MDAPIClientNetworkLoggerLevelError,
    MDAPIClientNetworkLoggerLevelFatal = MDAPIClientNetworkLoggerLevelOff,
} MDAPIClientNetworkLoggerLevel;

#pragma mark - Gender

typedef enum : NSUInteger
{
    MDGenderUnspecified = 0,
    MDGenderMale,
    MDGenderFemale
} MDGender;

#pragma mark - Account state

typedef enum : NSUInteger
{
    MDAccountStateUnverified,
    MDAccountStateProcessing,
    MDAccountStateVerified
} MDAccountState;


#pragma mark - ACL typedefs
/*
 AccessLevels:
 Public: 1,              // can scan a minimum of public object details (ie. thumbnail image, name. eg. members on the same team)
 Connected: 2,           // can read non-private object details (ie. 'colleagues' get this access level)
 Reserved: 3,            // reserved for a future release
 Read: 4,                // can read all object details
 Share: 5,               // can share/invite others to the object context (eg. update colleagues) promote/demote access at this level or lower.
 Update: 6,              // can update the object properties (base and accessible profiles)
 Delete: 7,              // can delete the object
 Admin: 8                // can administer the object (assign org roles and edit acl entries)
 */

typedef enum : NSInteger
{
    MDACLLevelNotSet = -1,
    MDACLLevelUniversallyReadable = 0,
    MDACLLevelPublic = 1,
    MDACLLevelConnected = 2,
    MDACLLevelReserved = 3,
    MDACLLevelRead = 4,
    MDACLLevelShare = 5,
    MDACLLevelUpdate = 6,
    MDACLLevelDelete = 7,
    MDACLLevelAdmin = 8
} MDACLLevel;

inline static bool isAccessLevel(MDACLLevel level)
{
    bool retVal = ((level > MDACLLevelNotSet) &&
                   (level <= MDACLLevelAdmin));
    
    return retVal;
}

typedef enum : NSUInteger
{
    MDACLAccessTargetAccount = 1,
    MDACLAccessTargetTeam = 2,
    MDACLAccessTargetRole = 3
} MDACLAccessTarget;

#pragma mark - MDNotifications

typedef enum : NSInteger
{
    MDNotificationTypeNotSpecified = -1,
    MDNotificationTypePostUpdate,
    MDNotificationTypeConnectionCreated,
    MDNotificationTypeInvitation,
    MDNotificationTypeTransferRequest,
    MDNotificationTypeCommentUpdate
} MDNotificationType;

typedef enum : NSUInteger
{
    MDNotificationContextColleague,
    MDNotificationContextConversation,
    MDNotificationContextTeam,
    MDNotificationContextOrg,
    MDNotificationContextPatient,
} MDNotificationContext;

#pragma mark - MDProfileInfo

typedef enum : NSUInteger
{
    MDProfileInfoTypeProvider,
    MDProfileInfoTypePatient
} MDProfileInfoType;

#pragma mark - Data Sources

typedef enum : NSUInteger
{
    MDDataSourceNone = 0,
    MDDataSourceCache,
    MDDataSourceRemote
} MDDataSource;

#pragma mark - File States

typedef enum : NSUInteger
{
    /*
     Currently in https://github.com/medable/DermTapAPI/blob/object-definitions/lib/consts.js
     
     Pending: 0, // waiting for upload
     Processing: 1,  // transcoding, manual processing, etc.
     Ready: 2, // can be streamed
     Error: 3, // error state (error included in segment. still alive)
     Dead: 4, // unrecoverable error or too many retry attempts
     */

    MDFileStatePending = 0,     // wait and try again later
    MDFileStateProcessing = 1,  // idem to pending
    MDFileStateReady = 2,       // go go go! download
    MDFileStateError = 3,       // you're gonna get a kStreamMediaError, 500. Inside the facet, the facet's gonna have a fault object.
    MDFileStateDead = 4,        // idem to error
    
    MDFileStateUnknown = 999
} MDFileState;

#pragma mark - Connection states

typedef enum : NSUInteger
{
    MDConnectionStatePending = 0,
    MDConnectionStateActive
} MDConnectionState;

typedef enum : NSUInteger
{
    MDPendingConnectionTypeIncoming = 0,
    MDPendingConnectionTypeOutgoing
} MDPendingConnectionType;
