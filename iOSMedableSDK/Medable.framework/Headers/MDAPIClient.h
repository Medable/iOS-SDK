//
//  MDAPIClient.h
//  iOSMedableSDK
//
//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// Forward declarations

@class MDFault;
@class MDAccount;
@class MDFile;
@class MDTeam;
@class MDConversation;
@class MDPatientFile;
@class MDProfileInfo;
@class MDAPIParameters;
@class MDConnection;
@class MDPost;
@class MDPostComment;
@class MDFeedDefinition;

@interface MDAPIClient : NSObject

/**
 * Current Organization instance.
 */
@property (nonatomic, readonly) MDOrg *currentOrg;

/**
 * Logged in user's account. Will be nil when nobody is logged in.
 */
@property (nonatomic, readonly) MDAccount* currentUser;

/**
 * Token string for APNS.
 */
@property (nonatomic, readonly) NSString* currentPushNotificationToken;

/**
 * Set this value if you've received an invitation and are activating an account with it. Typically contained as the
 * last element of a URL redirect to your app.
 */
@property (nonatomic, strong) NSString* invitationToken;

/**
 * Use this accessor to change the network logging level
 */
@property (nonatomic, assign) MDAPIClientNetworkLoggerLevel loggerLevel;

/**
 *  Returns the shared API client instance.
 */
+ (MDAPIClient*)sharedClient;

/**
 *  Stores current Apple Push Notification token.
 *  @param APN token received in UIApplicationDelegate's application:didRegisterForRemoteNotificationsWithDeviceToken:
 */
- (void)setPushNotificationToken:(NSData*)token;


#pragma mark - Root

/**
 * Obtain the current Organization's information. This will be downloaded once in an app's lifecycle.
 *
 * @param callback The callback for asynchronous return.
 */
- (void)getOrgInfoWithCallback:(void (^)(MDOrg* org, MDFault* fault))callback;

#pragma mark - Property pathing

/**
 * Retrieve the value of a property for a certain instance.
 *
 * @param instance The instance you are querying.
 * @param propertyPath The path, represented as a string, to the property being queried. This path can be any standard URL suffix.
 * @param callback The block that will fire asynchronously once the value is obtained.
 */
- (void)propertyValueWithInstance:(MDObjectInstance*)instance
                     propertyPath:(NSString*)propertyPath
                         callback:(void (^)(id value, MDFault* fault))callback;

/**
 * Modify the value of a property for a certain instance.
 *
 * @param instance The instance you are modifying.
 * @param propertyPath The path, represented as a string, to the property being modified. This path can be any standard URL suffix.
 * @param callback The block that will fire asynchronously once the service call returns.
 */
- (void)modifyPropertyValueForInstance:(MDObjectInstance*)instance
                          propertyPath:(NSString*)propertyPath
                                 value:(id)value
                              callback:(void (^)(MDObjectInstance* modifiedInstance, MDFault* fault))callback;


#pragma mark - Current account methods

/**
 *  Gets latest data for current logged in account
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)currentAccount:(void (^)(MDAccount* account, MDFault* fault))callback;

/**
 *  Activates an account.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)activateAccountWithToken:(NSString*)token callback:(void (^)(MDFault* fault))callback;

/**
 *  Request account verification resend.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)resendAccountVerificationWithCallback:(void (^)(MDFault* fault))callback;

/**
 *  Creates an account. User signup.
 *  @param firstName (required)
 *  @param lastName (required)
 *  @param email (required)
 *  @param mobile (required)
 *  @param password (required)
 *  @param gender
 *  @param dob
 *  @param role
 *  @param profileInfo
 *  @param thumbImage
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)registerAccountWithFirstName:(NSString*)firstName
                            lastName:(NSString*)lastName
                               email:(NSString*)email
                              mobile:(NSString*)mobile
                            password:(NSString*)password
                              gender:(NSString*)gender
                                 dob:(NSDate*)dob
                                role:(NSString*)role
                         profileInfo:(MDProfileInfo*)profileInfo
                          thumbImage:(UIImage *)thumbImage
                    customPropValues:(NSDictionary*)customPropValues
                            callback:(void (^)(MDAccount* account, MDFault* fault))callback;

/**
 *  Changes current account's password.
 *  @param currentPassword (required)
 *  @param newPassword (required)
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)updatePasswordWithCurrentPassword:(NSString*)currentPassword
                              newPassword:(NSString*)newPassword
                                 callback:(void (^)(MDFault* fault))callback;


#pragma mark - Authorization

/**
 *  Logout an authenticated session client.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)logout:(void (^)(MDFault* fault))callback;

/**
 *  Authenticates using email and password credentials, and returns the current account object.
 *  @param email
 *  @param password
 *  @param token
 *  @param singleUse
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)authenticateSessionWithEmail:(NSString*)email
                            password:(NSString*)password
                   verificationToken:(NSString*)token
                           singleUse:(BOOL)singleUse
                            callback:(void (^)(MDAccount* localUser, MDFault* fault))callback;

/**
 *  Requests a password reset.
 *  @param email
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)requestPasswordResetWithEmail:(NSString*)email
                             callback:(void (^)(MDFault* fault))callback;

/**
 *  Reset password.
 *  @param password
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)passwordResetWithToken:(NSString*)token
                      password:(NSString*)password
                      callback:(void (^)(MDFault* fault))callback;


#pragma mark - Connections

/**
 * List Connections
 *  @param parameters Construct parameters using MDAPIParameterFactory. 
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)listConnectionsWithParameters:(MDAPIParameters*)parameters
                             callback:(void (^)(NSArray* connections, NSNumber* hasMore, MDFault* fault))callback;

/**
 * - a context object's connections and invitations to/from the caller (optionally, within a given context). The resulting array will consist of account objects and invitation objects.
 *  @param context (required)
 *  @param contextId (required)
 *  @param parameters Construct parameters using MDAPIParameterFactory. 
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)listConnectionsWithContext:(NSString*)context
                          objectId:(MDObjectId*)objectId
                        parameters:(MDAPIParameters*)parameters
                          callback:(void (^)(NSArray* connections, NSNumber* hasMore, MDFault* fault))callback;

/**
 * Get connection by Id
 *  @param connectionId The id of the connection
 *  @param parameters Construct parameters using MDAPIParameterFactory. 
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)connectionWithId:(MDObjectId*)connectionId
              parameters:(MDAPIParameters*)parameters
                callback:(void (^)(MDConnection* connection, MDFault* fault))callback;

/**
 * Get connection by token for annonymous users
 *  @param token connection token
 *  @param parameters Construct parameters using MDAPIParameterFactory. 
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)connectionWithToken:(NSString*)token
                 parameters:(MDAPIParameters*)parameters
                   callback:(void (^)(MDConnection* connection, MDFault* fault))callback;

/**
 * Reject a collaboration invitation.
 *  @param token Invitation token.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)rejectConnectionWithToken:(NSString*)token
                         callback:(void (^)(MDFault* fault))callback;

/**
 * Test a collaboration.
 *  @param token Collaboration token.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)testCollaborationToken:(NSString*)token
                      callback:(void (^)(MDFault* fault))callback;

/**
 * Accept a collaboration invitation.
 *  @param token Invitation token.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)acceptConnectionWithToken:(NSString*)token
                         callback:(void (^)(MDFault* fault))callback;

/**
 * Create a new connection to an object instance and several targets.
 * 
 * @param context The name of the object class you are creating a connection in.
 * @param objectId The ID of the object instance for this class that's being connected.
 * @param targets An array of connection targets. Teams and accounts can be targeted. The caller must have 
 *  Connected access any team targets. For teams, a roles array will limit the connections to those
 *  members having the specified role(s).
 */
- (void)createConnectionWithContext:(NSString*)context
                           objectId:(MDObjectId*)objectId
                            targets:(MDTargets*)targets
                           callback:(void (^)(MDFault* fault))callback;

/**
 * Sends a collaboration invitation.
 *  @param email Email address of invitee
 *  @param context Context (required)
 *  @param objectId Context Object Id. Some contexts suppport creation upon invitation. See the collaborationCreatable of each context object.
 *  @param object Some contexts suppport creation upon invitation. In those cases the new object's details are provided in this dictionary.
 *  @param inviteeFirstName A placeholder name used for the invitation when no account exists
 *  @param inviteeLastName A placeholder name used for the invitation when no account exists
 *  @param transfer If true, transfers ownership to the invitee for supported contexts
 *  @param connect If true, also requests an account connection (Implicit for account invitations).
 *  @param accessLevel The access level to grant to the invitee. See the 'shareChain' for each context.
 *  @param role Upon acceptance, the invitee assumes the specified object role. Only required for patientFile and conversation contexts.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)inviteByEmail:(NSString*)email
     inviteeFirstName:(NSString*)inviteeFirstName
      inviteeLastName:(NSString*)inviteeLastName
              context:(NSString*)context
             objectId:(MDObjectId*)objectId
          accessLevel:(MDACLLevel)accessLevel
             callback:(void (^)(MDFault* fault))callback;

/**
 * Sends a collaboration invitation.
 *  @param accountId Account id of invitee
 *  @param context Context (required)
 *  @param objectId Context Object Id. Some contexts suppport creation upon invitation. See the collaborationCreatable of each context object.
 *  @param accessLevel The access level to grant to the invitee. See the 'shareChain' for each context.
 *  @param autoAccept setting this to YES, creates the connection directly, without waiting for user acceptance. This needs to be configured properly in the object definition.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)inviteByAccountId:(MDObjectId*)accountId
                  context:(NSString*)context
                 objectId:(MDObjectId*)objectId
              accessLevel:(MDACLLevel)accessLevel
               autoAccept:(NSNumber*)autoAccept
                 callback:(void (^)(MDFault* fault))callback;

/**
 * Sends a collaboration invitation.
 *  @param teamId Team id of invitees
 *  @param contet Context (required)
 *  @param objectId Context Object Id. Some contexts suppport creation upon invitation. See the collaborationCreatable of each context object.
 *  @param accessLevel The access level to grant to the invitee. See the 'shareChain' for each context.
 *  @param roles When the recipient is a team, the roles array limits invitations to those members having a matching role.
 *  @param autoAccept setting this to YES, creates the connection directly, without waiting for user acceptance. This needs to be configured properly in the object definition.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)inviteByTeamId:(MDObjectId*)teamId
               context:(NSString*)context
              objectId:(MDObjectId*)objectId
           accessLevel:(MDACLLevel)accessLevel
                 roles:(NSArray*)roles
            autoAccept:(NSNumber*)autoAccept
              callback:(void (^)(MDFault* fault))callback;

/**
 * Modify an existing connection.
 *
 * @param connectionId The Object ID of the connection instance.
 * @param body The payload contents with the modifications to the instance.
 * @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)updateConnectionWithId:(MDObjectId*)connectionId
                          body:(NSDictionary*)body
                      callback:(void (^)(MDConnection* connection, MDFault* fault))callback;

/**
 * Removes a collaboration.
 *  @param collaborationId Context Object Id (required)
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)removeConnectionWithId:(MDObjectId*)connectionId
                      callback:(void (^)(MDFault* fault))callback;

/**
 * Gets a connection's creator thumbnail
 *  @param tokenOrId Connection token or Id (required)
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)connectionCreatorThumbnailWithTokenOrId:(NSString*)tokenOrId
                                       callback:(MDImageOrFaultCallback)callback;

/**
 * Gets a connection's target thumbnail
 *  @param tokenOrId Connection token or Id (required)
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)connectionTargetThumbnailWithTokenOrId:(NSString*)tokenOrId
                                      callback:(MDImageOrFaultCallback)callback;


#pragma mark - Feed

/**
 * Get all post instances.
 *
 * @param parameters Construct parameters using MDAPIParameterFactory. 
 * @param callback Callback block called when the service call finishes. Check MDFault for errors.
 **/
- (void)listAllPostsWithParameters:(MDAPIParameters*)parameters
                          callback:(void (^)(NSArray* feed, NSNumber* hasMore, MDFault* fault))callback;

/**
 * Lists a context feed
 *  @param context Context (required)
 *  @param objectId Context Object Id (required)
 *  @param parameters Construct parameters using MDAPIParameterFactory. 
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)listFeedWithContext:(NSString*)context
                   objectId:(MDObjectId*)objectId
                 parameters:(MDAPIParameters*)parameters
                   callback:(void (^)(NSArray* feed, NSNumber* hasMore, MDFault* fault))callback;

/**
 * Lists the comments in a post
 *  @param post Post Object (required)
 *  @param parameters Construct parameters using MDAPIParameterFactory.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)listCommentsForPost:(MDPost*)post
                 parameters:(MDAPIParameters*)parameters
                   callback:(void (^)(NSArray* comments, NSNumber* hasMore, MDFault* fault))callback;

/**
 * Gets a feed post
 *  @param postId Post ObjectId (required)
 *  @param parameters Construct parameters using MDAPIParameterFactory. 
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)postWithId:(MDObjectId*)postId
        parameters:(MDAPIParameters*)parameters
          callback:(void (^)(MDPost* post, MDFault* fault))callback;

/**
 * Posts to a context's feed
 *  @param objectName Name of the Object posting to (required)
 *  @param objectId Object's Id (required)
 *  @param postType Post type. See each object's list of supported post types and segments.
 *  @param bodySegments An array of body segments
 *  @param targets An array of connection targets. Teams and accounts can be targeted. The caller must have
 *  Connected access any team targets. For teams, a roles array will limit the connections to those
 *  members having the specified role(s).
 *  @param voted
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)postToObject:(NSString *)objectName
            objectId:(MDObjectId *)objectId
            postType:(NSString*)postType
        bodySegments:(NSArray *)bodySegments
             targets:(MDTargets*)targets
               voted:(NSNumber*)voted
         finishBlock:(void (^)(MDPost* post, MDFault* fault))finishBlock;

/**
 * Posts a comment to a post
 *  @param postId Post ObjectId (required)
 *  @param bodySegments Array of body segments
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)postCommentToPost:(MDPost*)post
             bodySegments:(NSArray*)bodySegments
                    voted:(NSNumber*)voted
                 callback:(void (^)(MDPostComment* post, MDFault* fault))callback;

/**
 * Votes a post / comment
 *  @param postId Post ObjectId (required)
 *  @param commentId Optionally you could vote a comment by providing its commentId
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)votePostWithId:(MDObjectId*)postId
                 voted:(BOOL)voted
              callback:(void (^)(MDFault* fault))callback;

/**
 * Vote a Post Comment.
 *
 * @param commentId The Object ID of the post comment object.
 * @param voted Boolean value specifying the vote type.
 * @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */ 
- (void)voteCommentWithId:(MDObjectId*)commentId
                    voted:(BOOL)voted
                 callback:(void (^)(MDFault* fault))callback;

/**
 * Edits an existing post
 *  @param post Post Object (required)
 *  @param bodySegments Array of body segment.
 *  @param targets An array of connection targets. Teams and accounts can be targeted. The caller must have
 *  Connected access any team targets. For teams, a roles array will limit the connections to those
 *  members having the specified role(s).
 *  @param voted Whether this post gets voted.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)editPost:(MDPost *)post
    bodySegments:(NSArray *)bodySegments
         targets:(MDTargets*)targets
           voted:(NSNumber*)voted
        callback:(void (^)(MDPost* post, MDFault* fault))callback;

/**
 * Modify a post comment.
 *
 * @param bodySegments Array of body segments that specify the modifications being made.
 * @param voted Whether this post gets voted.
 * @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)editComment:(MDPostComment *)comment
       bodySegments:(NSArray *)bodySegments
              voted:(NSNumber*)voted
           callback:(void (^)(MDPostComment* postComment, MDFault* fault))callback;

/**
 * Deletes an existing post.
 *
 *  @param postId Post ObjectId (required)
 *  @param commentId Optionally you could delete a comment by providing its commentId
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)deletePostWithId:(MDObjectId*)postId
              parameters:(MDAPIParameters*)parameters
                callback:(void (^)(MDFault* fault))callback;

/**
 * Deletes an existing post comment.
 *
 *  @param commentId Post Comment ObjectId (required).
 *  @param parameters Extra parameters on the call.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)deleteCommentWithId:(MDObjectId*)commentId
                 parameters:(MDAPIParameters*)parameters
                   callback:(void (^)(MDFault* fault))callback;


#pragma mark - Notifications

/**
 * Lists current API notifications (not APN notifications)
 *  @param parameters Construct parameters using MDAPIParameterFactory. 
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)listNotificationsWithParameters:(MDAPIParameters*)parameters
                               callback:(void (^)(NSArray* notifications, NSNumber* hasMore, MDFault* fault))callback;

/**
 * Clears a notification
 *  @param notificaitonId Notification ID
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)clearNotificationWithId:(MDObjectId*)notificationId
                       callback:(void (^)(MDFault* fault))callback;

/**
 * Clears notifications by type / by context / by specific context object
 *  @param type limits the operation to a notification type
 *  @param context limits the operation to a context
 *  @param objectId limits the operation to an object
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)clearNotificationsWithType:(MDNotificationType)type
                           context:(NSString*)context
                          objectId:(MDObjectId*)objectId
                          callback:(void (^)(MDFault* fault))callback;

/**
 * Clears feed update (code 1) notifications. Returns the number of notifications removed.
 *  @param postsIds A subset of post ids to clear. If not present, all post notifications are cleared.
 *  @param postTypes A list of post types to clear. If not present, notifications for all post types are cleared.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)clearPostNotifcationsWithIDs:(NSArray*)postsIds
                           postTypes:(NSArray*)postTypes
                            callback:(void (^)(MDFault *))callback;

/**
 * Clears comment update (code 4) notifications. Returns the number of notifications removed.
 *  @param commentsIds A subset of comment ids to clear.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)clearCommentNotifcationsWithIDs:(NSArray*)commentsIds
                               callback:(void (^)(MDFault *))callback;


#pragma mark - Media Download

/**
 * General purpose download for a property's facet
 */
- (void)downloadFileAtPath:(NSString *)filePath
                  callback:(void (^)(id streamData, MDFault* fault))callback;


#pragma mark - Bundle

/**
 * Gets a bundle.
 *
 * @param bundleUrl The URL of the bundle.
 * @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)getBundleWithUrl:(NSString *)bundleUrl
                callback:(void (^)(NSDictionary *response, MDFault* fault))callback;


#pragma mark - Org

/**
 * Gets an Org object by Id.
 *
 * @param orgId The Id of the Org to retrieve.
 * @param parameters Construct parameters using MDAPIParameterFactory.
 * @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)orgWithId:(MDObjectId*)orgId
       parameters:(MDAPIParameters*)parameters
         callback:(void (^)(MDOrg* org, MDFault* fault))callback;

/**
 * Update an Org object by Id.
 *
 * @param orgId The Id of the Org to retrieve.
 * @param body Org body with properties and values to modify.
 * @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)updateOrgWithId:(MDObjectId*)orgId
                   body:(NSDictionary*)body
               callback:(void (^)(MDOrg* org, MDFault* fault))callback;

#pragma mark -
#pragma mark Context Objects
#pragma mark - Object

/**
 * Create a new object
 *
 * @param context The Context type you are posting to
 * @param body The information of the new object
 * @param callback The completion callback
 */
- (void)createObjectWithContext:(NSString*)context
                           body:(NSDictionary*)body
                       callback:(void (^)(MDObjectInstance* object, MDFault* fault))callback;

/**
 * Delete an existing object
 *
 * @param context The Context type you are deleting from
 * @param objectID The object ID to be deleted
 * @param reason Information about the reason for deleting it
 * @param callback The completion callback
 */
- (void)deleteObjectWithContext:(NSString*)context
                       objectId:(MDObjectId*)objectId
                         reason:(MDAPIParameters*)reason
                       callback:(void (^)(MDFault* fault))callback;

/**
 * Modify an existing object, it will only change those properties passed in the body
 *
 * @param object The object being modified
 * @param body A key/value mapping property paths to values
 * @param callback The completion callback
 */
- (void)editObject:(MDObjectInstance *)object
          withBody:(NSDictionary *)body
          callback:(void (^)(MDObjectInstance* object, MDFault* fault))callback;

/**
 * List context objects
 *  @param context Context (required)
 *  @param parameters Construct parameters using MDAPIParameterFactory. 
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)listObjectsWithContext:(NSString*)context
                    parameters:(MDAPIParameters*)parameters
                      callback:(void (^)(NSArray* objects, NSNumber* hasMore, MDFault* fault))callback;

/**
 * Gets a context object
 *  @param context Context (required)
 *  @param objectId Context ObjectId (required)
 *  @param parameters Construct parameters using MDAPIParameterFactory. 
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)objectWithContext:(NSString*)context
                 objectId:(MDObjectId*)objectId
               parameters:(MDAPIParameters*)parameters
                 callback:(void (^)(MDObjectInstance* object, MDFault* fault))callback;

/**
 * Updates a context object
 *  @param context Context (required)
 *  @param objectId Context ObjectId (required)
 *  @param body Object properties that are updated
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)updateObjectWithContext:(NSString*)context
                       objectId:(MDObjectId*)objectId
                           body:(NSDictionary*)body
                       callback:(void (^)(MDObjectInstance* object, MDFault* fault))callback;


#pragma mark - Account

/**
 * Updates context object
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)updateAccountWithID:(MDObjectId*)userID
                  firstName:(NSString*)firstName
                   lastName:(NSString*)lastName
                     gender:(NSString*)gender
                     mobile:(NSString*)mobile
                        dob:(NSString*)dob
                profileInfo:(MDProfileInfo*)profileInfo
                   favorite:(NSNumber*)favorite
                preferences:(NSDictionary*)preferences
                      image:(UIImage*)image
           customPropValues:(NSDictionary*)customPropValues
                finishBlock:(void (^)(MDAccount* account, MDFault* fault))finishBlock;

/**
 * Deletes context object
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)deleteAccountWithId:(MDObjectId*)accountId
                     reason:(MDAPIParameters*)reason
                   callback:(void (^)(MDFault* fault))callback;


#pragma mark - Patient File

/**
 * List context objects
 *  @param parameters Construct parameters using MDAPIParameterFactory. 
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)listPatientFilesWithParameters:(MDAPIParameters*)parameters
                              callback:(void (^)(NSArray* patientFiles, NSNumber* hasMore, MDFault* fault))callback;

/**
 * Gets a context object
 *  @param objectId Context ObjectId (required)
 *  @param parameters Construct parameters using MDAPIParameterFactory. 
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)patientFileWithId:(MDObjectId*)patientFileId
               parameters:(MDAPIParameters*)parameters
                 callback:(void (^)(MDPatientFile* patientFile, MDFault* fault))callback;

/**
 * Creates a context object
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)createPatientfileWithFirstName:(NSString*)firstName
                              lastName:(NSString*)lastName
                                   dob:(NSDate*)dob
                                 email:(NSString*)email
                              favorite:(BOOL)favorite
                                gender:(MDGender)gender
                                   mrn:(NSString*)mrn
                                 phone:(NSString*)phone
                               account:(NSObject*)account
                                 image:(UIImage*)image
                           finishBlock:(void (^)(MDPatientFile* patientFile, MDFault* fault))finishBlock;

/**
 * Updates a context object
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)updatePatientFileWithId:(MDObjectId*)patientFileId
                      firstName:(NSString*)firstName
                       lastName:(NSString*)lastName
                            dob:(NSString*)dob
                          email:(NSString*)email
                       favorite:(NSNumber*)favorite
                         gender:(MDGender)gender
                            mrn:(NSString*)mrn
                          phone:(NSString*)phone
                          image:(UIImage*)image
               customPropValues:(NSDictionary*)customPropValues
                    finishBlock:(void (^)(MDPatientFile* patientFile, MDFault* fault))finishBlock;

/**
 * Deletes a context object
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)deletePatientfileWithId:(MDObjectId*)patientFileId
                         reason:(MDAPIParameters*)reason
                       callback:(void (^)(MDFault* fault))callback;


#pragma mark - Conversation

/**
 * List context objects
 *  @param parameters Construct parameters using MDAPIParameterFactory. 
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)listConversationsWithParameters:(MDAPIParameters*)parameters
                               callback:(void (^)(NSArray* conversations, NSNumber* hasMore, MDFault* fault))callback;

/**
 * Gets a context object
 *  @param objectId Context ObjectId (required)
 *  @param parameters Construct parameters using MDAPIParameterFactory. 
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)conversationWithId:(MDObjectId*)conversationId
                parameters:(MDAPIParameters*)parameters
                  callback:(void (^)(MDConversation* conversation, MDFault* fault))callback;

/**
 * Creates a context object
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)createConversationWithDescription:(NSString*)description
                                 favorite:(NSNumber*)favorite
                              patientFile:(MDPatientFile*)patientFile
                              attachments:(MDAttachmentMaps*)attachments
                         customPropValues:(NSDictionary*)customPropValues
                              finishBlock:(void (^)(MDConversation* conversation, MDFault* fault))finishBlock;

/**
 *  Updates a conversation's attachments by appending more attachments to the existing ones
 *  @param conversationId   The conversation's Id
 *  @param attachments      An array of attachments to append
 *  @param finishBlock
 */
- (void)updateConversationWithId:(MDObjectId*)conversationId
          byAppendingAttachments:(MDAttachmentMaps*)attachments
                     finishBlock:(void (^)(MDConversation* conversation, MDFault* fault))finishBlock;

/**
 *  Updates a conversation's attachments by replacing a particular attachment with a new one
 *  @param conversationId   The conversation's Id
 *  @param attachmentId     The Id of the attachment to replace
 *  @param attachment       An attachment and optional overlay for the attachment
 *  @param finishBlock
 */
- (void)updateConversationWithId:(MDObjectId*)conversationId
     byReplacingAttachmentWithId:(MDObjectId*)attachmentId
                      attachment:(MDAttachmentMaps*)attachment
                     finishBlock:(void (^)(MDConversation* conversation, MDFault* fault))finishBlock;

/**
 *  Updates a conversation's attachments by deleting a particular attachment
 *  @param conversationId   The conversation's Id
 *  @param attachmentId     The Id of the attachment to delete
 *  @param finishBlock
 */
- (void)updateConversationWithId:(MDObjectId*)conversationId
      byDeletingAttachmentWithId:(MDObjectId*)attachmentId
                     finishBlock:(void (^)(MDFault* fault))finishBlock;

/**
 * Updates a context object
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)updateConversationWithId:(MDObjectId*)conversationId
                     description:(NSString*)description
                     patientFile:(MDPatientFile*)patientFile
                        favorite:(NSNumber*)favorite
                customPropValues:(NSDictionary*)customPropValues
                     finishBlock:(void (^)(MDConversation* conversation, MDFault* fault))finishBlock;

/**
 * Deletes a context object
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)deleteConversationWithId:(MDObjectId*)conversationId
                          reason:(MDAPIParameters*)reason
                        callback:(void (^)(MDFault* fault))callback;


#pragma mark - Team

/**
 * List context objects
 *  @param parameters Construct parameters using MDAPIParameterFactory. 
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)listTeamsWithParameters:(MDAPIParameters*)parameters
                       callback:(void (^)(NSArray* teams, NSNumber* hasMore, MDFault* fault))callback;

/**
 * Gets a context object
 *  @param objectId Context ObjectId (required)
 *  @param parameters Construct parameters using MDAPIParameterFactory. 
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)teamWithId:(MDObjectId*)teamId
        parameters:(MDAPIParameters*)parameters
          callback:(void (^)(MDTeam* team, MDFault* fault))callback;

/**
 * Creates a context object
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)createTeamWithName:(NSString*)name
               description:(NSString*)description
                  favorite:(NSNumber*)favorite
          customPropValues:(NSDictionary*)customPropValues
               finishBlock:(void (^)(MDTeam* team, MDFault* fault))finishBlock;

/**
 * Updates a context object
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)updateTeamWithId:(MDObjectId*)teamId
                    name:(NSString*)name
             description:(NSString*)description
                favorite:(NSNumber*)favorite
        customPropValues:(NSDictionary*)customPropValues
             finishBlock:(void (^)(MDTeam* team, MDFault* fault))finishBlock;

/**
 * Deletes a context object
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)deleteTeamWithId:(MDObjectId*)teamId
                  reason:(MDAPIParameters*)reason
                callback:(void (^)(MDFault* fault))callback;

@end
