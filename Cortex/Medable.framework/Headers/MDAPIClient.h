//
//  MDAPIClient.h
//  Medable
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
@class MDBody;
@class MDPostBody;

NS_ASSUME_NONNULL_BEGIN

@interface MDAPIClient : NSObject

/**
 * Current Organization instance.
 */
@property (nonatomic, readonly, nullable) MDOrg *currentOrg;

/**
 * Logged in user's account. Will be nil when nobody is logged in.
 */
@property (nonatomic, readonly, nullable) MDAccount* currentUser;

/**
 * Token string for APNS.
 */
@property (nonatomic, readonly, nullable) NSString* currentPushNotificationToken;

/**
 * Set this value if you've received an invitation and are activating an account with it. Typically contained as the
 * last element of a URL redirect to your app.
 */
@property (nonatomic, strong, nullable) NSString* invitationToken;

/**
 * Use this accessor to change the network logging level
 */
@property (nonatomic, assign) MDAPIClientNetworkLoggerLevel loggerLevel;

/**
 *  @return The API client singleton instance.
 */
+ (MDAPIClient*)sharedClient;

// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

/**
 * Start location services. In iOS8+ this requests location permissions to the user only if the app
 * has an entry for the key NSLocationWhenInUseUsageDescription.
 */
- (void)startLocationServices;

/**
 *  Stores current Apple Push Notification token.
 *  @param token APN token received in UIApplicationDelegate's application:didRegisterForRemoteNotificationsWithDeviceToken:
 */
- (void)setPushNotificationToken:(nullable NSData*)token;


#pragma mark - Context class registration

/**
 *  Registers a context with a class.
 *
 *  Use this method to register custom classes to be used for when instanciating custom objects. If no class is registred for a context, instances of that context will be instances of `MDObjectInstance` objects.
 *
 *  @param context Singular context name. Required.
 *  @param pluralContext Plural context name. Required.
 *  @param type Optionally used for when there is a Medable object with a type and more than one class client side representing each one of those objects. For more information check the documentation here: https://docs.medable.com/v2.9.7/reference#object-types .
 *  @param aClass Class to be used to instanciate custom objects with context or pluralContext. aClass must be a subclass of `MDObjectInstance`.
 *  @return Returns whether the registration was successful or not.
 */
+ (BOOL)registerContext:(NSString *)context pluralContext:(NSString *)pluralContext type:(nullable NSString *)type withClass:(Class)aClass;

/**
 *  Returns information about regustered custom contexts.
 */
+ (NSString *)registeredContexts;


#pragma mark - Custom Routes

/**
 * Method to create routes for the custom route methods below.
 *
 * @param routeComponents the components to create the route.
 * @return The route components of the array are prefixed with the base URL. If routeComponents is nil, the base URL is returned.
 */
+ (NSString*)routeWithComponents:(nullable NSArray*)routeComponents;

/**
 * GET method
 *
 * @param path Custom route. Use routeWithComponents: to create the paths.
 * @param parameters Construct parameters using MDAPIParameterFactory.
 */
- (void)getPath:(NSString *)path
     parameters:(nullable MDAPIParameters *)parameters
        success:(void (^)(NSURLSessionDataTask *task, id responseObject))success
        failure:(void (^)(NSURLSessionDataTask *task, MDFault *fault))failure;

/**
 * POST method
 *
 * @param path Custom route. Use routeWithComponents: to create the paths.
 * @param parameters Construct parameters using MDAPIParameterFactory.
 */
- (void)postPath:(NSString *)path
      parameters:(nullable MDAPIParameters *)parameters
         success:(void (^)(NSURLSessionDataTask *task, id responseObject))success
         failure:(void (^)(NSURLSessionDataTask *task, MDFault *fault))failure;

/**
 * PUT method
 *
 * @param path Custom route. Use routeWithComponents: to create the paths.
 * @param parameters Construct parameters using MDAPIParameterFactory.
 */
- (void)putPath:(NSString *)path
     parameters:(nullable MDAPIParameters *)parameters
        success:(void (^)(NSURLSessionDataTask *task, id responseObject))success
        failure:(void (^)(NSURLSessionDataTask *task, MDFault *fault))failure;

/**
 * DELETE method
 *
 * @param path Custom route. Use routeWithComponents: to create the paths.
 * @param parameters Construct parameters using MDAPIParameterFactory.
 */
- (void)deletePath:(NSString *)path
        parameters:(nullable MDAPIParameters *)parameters
           success:(void (^)(NSURLSessionDataTask *task, id responseObject))success
           failure:(void (^)(NSURLSessionDataTask *task, MDFault *fault))failure;

/**
 * PATCH method
 *
 * @param path Custom route. Use routeWithComponents: to create the paths.
 * @param parameters Construct parameters using MDAPIParameterFactory.
 */
- (void)patchPath:(NSString *)path
       parameters:(nullable MDAPIParameters *)parameters
          success:(void (^)(NSURLSessionDataTask *task, id responseObject))success
          failure:(void (^)(NSURLSessionDataTask *task, MDFault *fault))failure;


#pragma mark - Root

/**
 * Obtain the public Organization's information.
 *
 * @param callback The callback for asynchronous return.
 */
- (void)getPublicOrgInfoWithCallback:(void (^)(NSDictionary* __nullable orgInfo, MDFault* __nullable fault))callback;

#pragma mark - Property pathing

/**
 * Retrieve the value of a property for a certain instance.
 *
 * @param instance The instance you are querying.
 * @param propertyPath The path, represented as a string, to the property being queried. This path can be any standard URL suffix.
 * @param parameters Construct parameters using MDAPIParameterFactory.
 * @param callback The block that will fire asynchronously once the value is obtained.
 */
- (void)propertyValueWithInstance:(MDObjectInstance*)instance
                     propertyPath:(NSString*)propertyPath
                       parameters:(nullable MDAPIParameters*)parameters
                         callback:(MDObjectFaultCallback)callback;

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
                              callback:(void (^)(MDObjectInstance* __nullable modifiedInstance, MDFault* __nullable fault))callback;


#pragma mark - Current account methods

/**
 *  Gets latest data for current logged in account
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)currentAccount:(void (^)(MDAccount* __nullable account, MDFault* __nullable fault))callback;

/**
 *  Activates an account.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)activateAccountWithToken:(NSString*)token callback:(MDFaultCallback)callback;

/**
 *  Request account verification resend.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)resendAccountVerificationWithCallback:(MDFaultCallback)callback;

/**
 *  Creates an account. User signup.
 *  @param firstName (required)
 *  @param lastName (required)
 *  @param email (required)
 *  @param mobile (required)
 *  @param password (required)
 *  @param gender Gender
 *  @param dob Date of birth
 *  @param role Account role
 *  @param profileInfo Packed profile info
 *  @param thumbImage Thumbnail image
 *  @param timeZone Account's time zone
 *  @param customPropValues Dictionary used to pass custom property values.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)registerAccountWithFirstName:(NSString*)firstName
                            lastName:(NSString*)lastName
                               email:(NSString*)email
                              mobile:(NSString*)mobile
                            password:(NSString*)password
                              gender:(nullable NSString*)gender
                                 dob:(nullable NSDate*)dob
                                role:(nullable NSString*)role
                         profileInfo:(nullable MDProfileInfo*)profileInfo
                          thumbImage:(nullable UIImage *)thumbImage
                            timeZone:(nullable NSTimeZone *)timeZone
                    customPropValues:(nullable NSDictionary*)customPropValues
                            callback:(void (^)(MDAccount* __nullable account, MDFault* __nullable fault))callback;

/**
 *  Changes current account's password.
 *  @param currentPassword (required)
 *  @param newPassword (required)
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)updatePasswordWithCurrentPassword:(NSString*)currentPassword
                              newPassword:(NSString*)newPassword
                                 callback:(MDFaultCallback)callback;


#pragma mark - Authentication

/**
 *  Logout an authenticated session client.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)logout:(MDFaultCallback)callback;

/**
 *  Authenticates using email and password credentials, and returns the current account object.
 *  @param email Account email
 *  @param password Account password
 *  @param token 2 factor authentication verification token
 *  @param singleUse Single use
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)authenticateSessionWithEmail:(NSString*)email
                            password:(NSString*)password
                   verificationToken:(nullable NSString*)token
                           singleUse:(BOOL)singleUse
                            callback:(void (^)(MDAccount* __nullable localUser, MDFault* __nullable fault))callback;

/**
 *  Requests a password reset.
 *  @param email Email of the associated account
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)requestPasswordResetWithEmail:(NSString*)email
                             callback:(MDFaultCallback)callback;

/**
 *  Reset password.
 *  @param token Password request generated token
 *  @param password Password
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)passwordResetWithToken:(NSString*)token
                      password:(NSString*)password
                      callback:(MDFaultCallback)callback;


#pragma mark - Connections

/**
 * List Connections
 *  @param parameters Construct parameters using MDAPIParameterFactory.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)listConnectionsWithParameters:(nullable MDAPIParameters*)parameters
                             callback:(MDConnectionListFaultCallback)callback;

/**
 * - a context object's connections and invitations to/from the caller (optionally, within a given context). The resulting array will consist of account objects and invitation objects.
 *  @param context (required)
 *  @param objectId (required)
 *  @param parameters Construct parameters using MDAPIParameterFactory.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)listConnectionsWithContext:(NSString*)context
                          objectId:(MDObjectId*)objectId
                        parameters:(nullable MDAPIParameters*)parameters
                          callback:(MDConnectionListFaultCallback)callback;

/**
 * Get connection by Id
 *  @param connectionId The id of the connection
 *  @param parameters Construct parameters using MDAPIParameterFactory.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)connectionWithId:(MDObjectId*)connectionId
              parameters:(nullable MDAPIParameters*)parameters
                callback:(void (^)(MDConnection* __nullable connection, MDFault* __nullable fault))callback;

/**
 * Get connection by token for annonymous users
 *  @param token connection token
 *  @param parameters Construct parameters using MDAPIParameterFactory.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)connectionWithToken:(NSString*)token
                 parameters:(nullable MDAPIParameters*)parameters
                   callback:(void (^)(MDConnection* __nullable connection, MDFault* __nullable fault))callback;

/**
 * Reject a collaboration invitation.
 *  @param token Invitation token.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)rejectConnectionWithToken:(NSString*)token
                         callback:(MDFaultCallback)callback;

/**
 * Test a collaboration.
 *  @param token Collaboration token.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)testCollaborationToken:(NSString*)token
                      callback:(MDFaultCallback)callback;

/**
 * Accept a collaboration invitation.
 *  @param token Invitation token.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)acceptConnectionWithToken:(NSString*)token
                         callback:(MDFaultCallback)callback;

/**
 * Create a new connection to an object instance and several targets.
 *
 * @param context The name of the object class you are creating a connection in.
 * @param objectId The ID of the object instance for this class that's being connected.
 * @param targets An array of connection targets. Teams and accounts can be targeted. The caller must have
 *  Connected access any team targets. For teams, a roles array will limit the connections to those
 *  members having the specified role(s).
 * @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)createConnectionWithContext:(NSString*)context
                           objectId:(MDObjectId*)objectId
                            targets:(MDTargets*)targets
                           callback:(MDFaultCallback)callback;

/**
 * Sends a collaboration invitation.
 *  @param email Email address of invitee
 *  @param inviteeFirstName A placeholder name used for the invitation when no account exists
 *  @param inviteeLastName A placeholder name used for the invitation when no account exists
 *  @param context Context
 *  @param objectId Context Object Id. Some contexts suppport creation upon invitation. See the collaborationCreatable of each context object.
 *  @param accessLevel The access level to grant to the invitee. See the 'shareChain' for each context.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)inviteByEmail:(NSString*)email
     inviteeFirstName:(nullable NSString*)inviteeFirstName
      inviteeLastName:(nullable NSString*)inviteeLastName
              context:(NSString*)context
             objectId:(MDObjectId*)objectId
          accessLevel:(MDACLLevel)accessLevel
             callback:(MDFaultCallback)callback;

/**
 * Sends a collaboration invitation.
 *  @param accountId Account id of invitee
 *  @param context Context
 *  @param objectId Context Object Id. Some contexts support creation upon invitation. See the collaborationCreatable of each context object.
 *  @param accessLevel The access level to grant to the invitee. See the 'shareChain' for each context.
 *  @param autoAccept setting this to YES, creates the connection directly, without waiting for user acceptance. This needs to be configured properly in the object definition.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)inviteByAccountId:(MDObjectId*)accountId
                  context:(NSString*)context
                 objectId:(MDObjectId*)objectId
              accessLevel:(MDACLLevel)accessLevel
               autoAccept:(nullable NSNumber*)autoAccept
                 callback:(MDFaultCallback)callback;

/**
 * Sends a collaboration invitation.
 *  @param teamId Team id of invitees
 *  @param context Context
 *  @param objectId Context Object Id. Some contexts support creation upon invitation. See the collaborationCreatable of each context object.
 *  @param accessLevel The access level to grant to the invitee. See the 'shareChain' for each context.
 *  @param roles When the recipient is a team, the roles array limits invitations to those members having a matching role.
 *  @param autoAccept setting this to YES, creates the connection directly, without waiting for user acceptance. This needs to be configured properly in the object definition.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)inviteByTeamId:(MDObjectId*)teamId
               context:(NSString*)context
              objectId:(MDObjectId*)objectId
           accessLevel:(MDACLLevel)accessLevel
                 roles:(nullable NSArray*)roles
            autoAccept:(nullable NSNumber*)autoAccept
              callback:(MDFaultCallback)callback;

/**
 * Removes a collaboration.
 *  @param connectionId Connection Object Id (required)
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)removeConnectionWithId:(MDObjectId*)connectionId
                      callback:(MDFaultCallback)callback;

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
- (void)listAllPostsWithParameters:(nullable MDAPIParameters*)parameters
                          callback:(MDPostListFaultCallback)callback DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Lists a context feed
 *  @param context Context (required)
 *  @param objectId Context Object Id (required)
 *  @param parameters Construct parameters using MDAPIParameterFactory.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)listFeedWithContext:(NSString*)context
                   objectId:(MDObjectId*)objectId
                 parameters:(nullable MDAPIParameters*)parameters
                   callback:(MDPostListFaultCallback)callback DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Lists the comments in a post
 *  @param post Post Object (required)
 *  @param parameters Construct parameters using MDAPIParameterFactory.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)listCommentsForPost:(MDPost*)post
                 parameters:(nullable MDAPIParameters*)parameters
                   callback:(MDCommentListFaultCallback)callback DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Gets a feed post
 *  @param postId Post ObjectId (required)
 *  @param parameters Construct parameters using MDAPIParameterFactory.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)postWithId:(MDObjectId*)postId
        parameters:(nullable MDAPIParameters*)parameters
          callback:(void (^)(MDPost* __nullable post, MDFault* __nullable fault))callback DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Posts to a context's feed
 *  @param objectName Name of the Object posting to (required)
 *  @param objectId Object's Id (required)
 *  @param postType Post type. See each object's list of supported post types and segments.
 *  @param bodySegments An array of body segments
 *  @param targets An array of connection targets. Teams and accounts can be targeted. The caller must have
 *  Connected access any team targets. For teams, a roles array will limit the connections to those
 *  members having the specified role(s).
 *  @param voted Set this post as voted
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)postToObject:(NSString *)objectName
            objectId:(MDObjectId *)objectId
            postType:(NSString*)postType
        bodySegments:(NSArray *)bodySegments
             targets:(nullable MDTargets*)targets
               voted:(nullable NSNumber*)voted
            callback:(void (^)(MDPost* __nullable post, MDFault* __nullable fault))callback DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Posts to a context's feed
 *  @param objectName Name of the Object posting to (required)
 *  @param objectId Object's Id (required)
 *  @param postType Post type. See each object's list of supported post types and segments.
 *  @param bodySegmentsObject A `MDPostBody` instance that represents the segments of the post type.
 *  @param targets An array of connection targets. Teams and accounts can be targeted. The caller must have
 *  Connected access any team targets. For teams, a roles array will limit the connections to those
 *  members having the specified role(s).
 *  @param voted Set this post as voted
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)postToObject:(NSString *)objectName
            objectId:(MDObjectId *)objectId
            postType:(NSString*)postType
  bodySegmentsObject:(MDPostBody *)bodySegmentsObject
             targets:(nullable MDTargets*)targets
               voted:(nullable NSNumber*)voted
            callback:(void (^)(MDPost* __nullable post, MDFault* __nullable fault))callback DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Posts a comment to a post
 *  @param post Post instance (required)
 *  @param bodySegments Array of body segments
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)postCommentToPost:(MDPost*)post
             bodySegments:(NSArray*)bodySegments
                    voted:(nullable NSNumber*)voted
                 callback:(void (^)(MDPostComment* __nullable post, MDFault* __nullable fault))callback DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Posts a comment to a post
 *  @param post Post instance (required)
 *  @param commentBody An 'MDPostBody' object with the comment data
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)postCommentToPost:(MDPost*)post
              commentBody:(MDPostBody *)commentBody
                    voted:(NSNumber*)voted
                 callback:(void (^)(MDPostComment* __nullable post, MDFault* __nullable fault))callback DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Votes a post / comment
 *  @param postId Post ObjectId (required)
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)votePostWithId:(MDObjectId*)postId
                 voted:(BOOL)voted
              callback:(MDFaultCallback)callback DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Vote a Post Comment.
 *
 * @param commentId The Object ID of the post comment object.
 * @param voted Boolean value specifying the vote type.
 * @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)voteCommentWithId:(MDObjectId*)commentId
                    voted:(BOOL)voted
                 callback:(MDFaultCallback)callback DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

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
         targets:(nullable MDTargets*)targets
           voted:(nullable NSNumber*)voted
        callback:(void (^)(MDPost* __nullable post, MDFault* __nullable fault))callback DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Edits an existing post
 *  @param post Post Object (required)
 *  @param postBody Post body instance with the editing post data.
 *  @param targets An array of connection targets. Teams and accounts can be targeted. The caller must have
 *  Connected access any team targets. For teams, a roles array will limit the connections to those
 *  members having the specified role(s).
 *  @param voted Whether this post gets voted.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)editPost:(MDPost *)post
        postBody:(MDPostBody *)postBody
         targets:(MDTargets*)targets
           voted:(NSNumber*)voted
        callback:(void (^)(MDPost* __nullable post, MDFault* __nullable fault))callback DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Modify a post comment.
 *
 * @param comment MDPostComment object.
 * @param bodySegments Array of body segments that specify the modifications being made.
 * @param voted Whether this post gets voted.
 * @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)editComment:(MDPostComment *)comment
       bodySegments:(NSArray *)bodySegments
              voted:(nullable NSNumber*)voted
           callback:(void (^)(MDPostComment* __nullable postComment, MDFault* __nullable fault))callback DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Modify a post comment.
 *
 * @param comment MDPostComment object.
 * @param commentBody Comment body instance with the data of the fields being edited.
 * @param voted Whether this post gets voted.
 * @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)editComment:(MDPostComment *)comment
        commentBody:(MDPostBody *)commentBody
              voted:(nullable NSNumber*)voted
           callback:(void (^)(MDPostComment* __nullable postComment, MDFault* __nullable fault))callback DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Deletes an existing post.
 *
 *  @param postId Post ObjectId (required)
 *  @param parameters Extra parameters on the call.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)deletePostWithId:(MDObjectId*)postId
              parameters:(nullable MDAPIParameters*)parameters
                callback:(MDFaultCallback)callback DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Deletes an existing post comment.
 *
 *  @param commentId Post Comment ObjectId (required).
 *  @param parameters Extra parameters on the call.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)deleteCommentWithId:(MDObjectId*)commentId
                 parameters:(nullable MDAPIParameters*)parameters
                   callback:(MDFaultCallback)callback DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");


#pragma mark - Notifications

/**
 * Lists current API notifications (not APN notifications)
 *  @param parameters Construct parameters using MDAPIParameterFactory.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)listNotificationsWithParameters:(nullable MDAPIParameters*)parameters
                               callback:(MDNotificationListFaultCallback)callback;

/**
 * Clears a notification
 *  @param notificationId Notification ID
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)clearNotificationWithId:(MDObjectId*)notificationId
                       callback:(MDFaultCallback)callback;

/**
 * Clears notifications by type / by context / by specific context object
 *  @param type limits the operation to a notification type
 *  @param context limits the operation to a context
 *  @param objectId limits the operation to an object
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)clearNotificationsWithType:(MDNotificationType)type
                           context:(nullable NSString*)context
                          objectId:(nullable MDObjectId*)objectId
                          callback:(MDFaultCallback)callback;

/**
 * Clears feed update (code 1) notifications. Returns the number of notifications removed.
 *  @param postsIds A subset of post ids to clear. If not present, all post notifications are cleared.
 *  @param postTypes A list of post types to clear. If not present, notifications for all post types are cleared.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)clearPostNotificationsWithIDs:(NSArray*)postsIds
                            postTypes:(nullable NSArray*)postTypes
                             callback:(MDFaultCallback)callback;

/**
 * Clears comment update (code 4) notifications. Returns the number of notifications removed.
 *  @param commentsIds A subset of comment ids to clear.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)clearCommentNotificationsWithIDs:(NSArray*)commentsIds
                                callback:(MDFaultCallback)callback;


#pragma mark - Media Upload / Download

/**
 * General purpose upload for a property's facet
 */
+ (void)uploadData:(NSData *)data forUpload:(MDFileUpload*)upload;

/**
 * General purpose file download. Provide full path.
 */
+ (void)downloadFileAtPath:(NSString *)filePath
                  callback:(void (^)(id __nullable streamData, MDFault* __nullable fault))callback;


#pragma mark - Bundle

/**
 * Gets the app's bundle.
 *
 * @param bundleUrl The URL of the bundle.
 * @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)getBundleWithUrl:(NSString *)bundleUrl
                callback:(void (^)(NSDictionary* __nullable response, MDFault* __nullable fault))callback;


#pragma mark - Org

/**
 * Gets an Org object by Id.
 *
 * @param orgId The Id of the Org to retrieve.
 * @param parameters Construct parameters using MDAPIParameterFactory.
 * @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)orgWithId:(MDObjectId*)orgId
       parameters:(nullable MDAPIParameters*)parameters
         callback:(void (^)(MDOrg* __nullable org, MDFault* __nullable fault))callback;

/**
 * Update an Org object by Id.
 *
 * @param orgId The Id of the Org to retrieve.
 * @param body Org body with properties and values to modify.
 * @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)updateOrgWithId:(MDObjectId*)orgId
                   body:(NSDictionary*)body
               callback:(void (^)(MDOrg* __nullable org, MDFault* __nullable fault))callback;

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
                       callback:(MDObjectInstanceFaultCallback)callback;

/**
 * Create a new object
 *
 * @param context The Context type you are posting to
 * @param body The representation for the new object in it's body format
 * @param callback The completion callback
 */
- (void)createObjectWithContext:(NSString*)context
                     bodyObject:(MDBody*)body
                       callback:(MDObjectInstanceFaultCallback)callback;

/**
 * Delete an existing object
 *
 * @param context The Context type you are deleting from
 * @param objectId The object ID to be deleted
 * @param reason Information about the reason for deleting it
 * @param callback The completion callback
 */
- (void)deleteObjectWithContext:(NSString*)context
                       objectId:(MDObjectId*)objectId
                         reason:(nullable MDAPIParameters*)reason
                       callback:(MDFaultCallback)callback;

/**
 * List context objects
 *  @param context Context (required)
 *  @param parameters Construct parameters using MDAPIParameterFactory.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)listObjectsWithContext:(NSString*)context
                    parameters:(nullable MDAPIParameters*)parameters
                      callback:(MDObjectListFaultCallback)callback;

/**
 * List context objects' list properties
 *  @param context Context (required)
 *  @param objectId ObjectId (required)
 *  @param listPropertyName The name of the list property (required)
 *  @param parameters Construct parameters using MDAPIParameterFactory.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)listObjectsWithContext:(NSString*)context
                      objectId:(MDObjectId*)objectId
                  listProperty:(NSString *)listPropertyName
                    parameters:(nullable MDAPIParameters*)parameters
                      callback:(MDObjectListFaultCallback)callback;

/**
 * List objects from a list properties
 *  @param path Path to a list property (required)
 *  @param parameters Construct parameters using MDAPIParameterFactory.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)listObjectsWithPath:(NSString*)path
                 parameters:(nullable MDAPIParameters*)parameters
                   callback:(MDObjectListFaultCallback)callback;

/**
 * Gets a context object
 *  @param context Context (required)
 *  @param objectId Context ObjectId (required)
 *  @param parameters Construct parameters using MDAPIParameterFactory.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)objectWithContext:(NSString*)context
                 objectId:(MDObjectId*)objectId
               parameters:(nullable MDAPIParameters*)parameters
                 callback:(MDObjectInstanceFaultCallback)callback;

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
                       callback:(MDObjectInstanceFaultCallback)callback;

/**
 * Updates a context object
 *  @param context Context (required)
 *  @param objectId Context ObjectId (required)
 *  @param bodyObj Body object properties that are to be updated
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)updateObjectWithContext:(NSString*)context
                       objectId:(MDObjectId*)objectId
                     bodyObject:(MDBody*)bodyObj
                       callback:(MDObjectInstanceFaultCallback)callback;


#pragma mark - Account

/**
 * Updates context object
 *  @param userID Account object Id
 *  @param firstName First name
 *  @param lastName Last name
 *  @param gender Gender
 *  @param dob Date of birth
 *  @param profileInfo Packed profile info
 *  @param favorite Set this account as favorite
 *  @param preferences Account preferences
 *  @param image Account thumbnail image
 *  @param timeZone Account's time zone
 *  @param customPropValues Account custom properties and values
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)updateAccountWithID:(MDObjectId*)userID
                  firstName:(nullable NSString*)firstName
                   lastName:(nullable NSString*)lastName
                     gender:(nullable NSString*)gender
                     mobile:(nullable NSString*)mobile
                        dob:(nullable NSString*)dob
                profileInfo:(nullable MDProfileInfo*)profileInfo
                   favorite:(nullable NSNumber*)favorite
                preferences:(nullable NSDictionary*)preferences
                      image:(nullable UIImage*)image
                   timeZone:(nullable NSTimeZone*)timeZone
           customPropValues:(nullable NSDictionary*)customPropValues
                   callback:(void (^)(MDAccount* __nullable account, MDFault* __nullable fault))callback;

/**
 * Deletes context object
 *  @param accountId MDObjectId the Id of the account to be deleted.
 *  @param reason MDAPIParameters deletion reason.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)deleteAccountWithId:(MDObjectId*)accountId
                     reason:(nullable MDAPIParameters*)reason
                   callback:(MDFaultCallback)callback;


#pragma mark - Patient File

/**
 * List context objects
 *  @param parameters Construct parameters using MDAPIParameterFactory.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)listPatientFilesWithParameters:(nullable MDAPIParameters*)parameters
                              callback:(MDPatientFileListFaultCallback)callback;

/**
 * Gets a context object
 *  @param patientFileId Context ObjectId (required)
 *  @param parameters Construct parameters using MDAPIParameterFactory.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)patientFileWithId:(MDObjectId*)patientFileId
               parameters:(nullable MDAPIParameters*)parameters
                 callback:(void (^)(MDPatientFile* __nullable patientFile, MDFault* __nullable fault))callback;

/**
 * Creates a context object
 *  @param firstName Patient first name
 *  @param lastName Patient last name
 *  @param dob Patient date of birth
 *  @param email Patient email
 *  @param favorite Set as favorite
 *  @param gender Patient gender
 *  @param mrn Patient MRN
 *  @param phone Patient phone
 *  @param account Patient account Id
 *  @param image Patient avatar image
 *  @param customPropValues Patient custom properties and values
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)createPatientfileWithFirstName:(NSString*)firstName
                              lastName:(NSString*)lastName
                                   dob:(NSDate*)dob
                                 email:(nullable NSString*)email
                              favorite:(BOOL)favorite
                                gender:(MDGender)gender
                                   mrn:(nullable NSString*)mrn
                                 phone:(nullable NSString*)phone
                               account:(nullable NSObject*)account
                                 image:(nullable UIImage*)image
                      customPropValues:(nullable NSDictionary*)customPropValues
                              callback:(void (^)(MDPatientFile* __nullable patientFile, MDFault* __nullable fault))callback;

/**
 * Updates a context object
 *  @param patientFileId PatientFile object Id
 *  @param firstName Patient first name
 *  @param lastName Patient last name
 *  @param dob Patient date of birth
 *  @param email Patient email
 *  @param favorite Set as favorite
 *  @param gender Patient gender
 *  @param mrn Patient MRN
 *  @param phone Patient phone
 *  @param image Patient avatar image
 *  @param customPropValues Patient custom properties and values
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)updatePatientFileWithId:(MDObjectId*)patientFileId
                      firstName:(nullable NSString*)firstName
                       lastName:(nullable NSString*)lastName
                            dob:(nullable NSString*)dob
                          email:(nullable NSString*)email
                       favorite:(nullable NSNumber*)favorite
                         gender:(MDGender)gender
                            mrn:(nullable NSString*)mrn
                          phone:(nullable NSString*)phone
                          image:(nullable UIImage*)image
               customPropValues:(nullable NSDictionary*)customPropValues
                       callback:(void (^)(MDPatientFile* __nullable patientFile, MDFault* __nullable fault))callback;

/**
 * Deletes a context object
 *  @param patientFileId PatientFile object Id
 *  @param reason Construct reason parameters using MDAPIParameterFactory.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)deletePatientfileWithId:(MDObjectId*)patientFileId
                         reason:(nullable MDAPIParameters*)reason
                       callback:(MDFaultCallback)callback;


#pragma mark - Conversation

/**
 * List context objects
 *  @param parameters Construct parameters using MDAPIParameterFactory.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)listConversationsWithParameters:(nullable MDAPIParameters*)parameters
                               callback:(MDConversationListFaultCallback)callback;

/**
 * Gets a context object
 *  @param conversationId Context ObjectId (required)
 *  @param parameters Construct parameters using MDAPIParameterFactory.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)conversationWithId:(MDObjectId*)conversationId
                parameters:(nullable MDAPIParameters*)parameters
                  callback:(void (^)(MDConversation* __nullable conversation, MDFault* __nullable fault))callback;

/**
 * Creates a conversation object
 *
 *  @param description Conversation description
 *  @param favorite Set this conversation as favorite
 *  @param patientFile Associated PatientFile object
 *  @param attachments Conversation's attachments
 *  @param customPropValues Conversation custom properties and values
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)createConversationWithDescription:(nullable NSString*)description
                                 favorite:(nullable NSNumber*)favorite
                              patientFile:(nullable MDPatientFile*)patientFile
                              attachments:(nullable MDAttachmentMaps*)attachments
                         customPropValues:(nullable NSDictionary*)customPropValues
                                 callback:(void (^)(MDConversation* __nullable conversation, MDFault* __nullable fault))callback;

/**
 *  Updates a conversation's attachments by appending more attachments to the existing ones
 *  @param conversationId The conversation's Id
 *  @param attachments An array of attachments to append
 *  @param callback Asynchronous callback called when this task is done
 */
- (void)updateConversationWithId:(MDObjectId*)conversationId
          byAppendingAttachments:(MDAttachmentMaps*)attachments
                        callback:(void (^)(MDConversation* __nullable conversation, MDFault* __nullable fault))callback;

/**
 *  Updates a conversation's attachments by replacing a particular attachment with a new one
 *  @param conversationId The conversation's Id
 *  @param attachmentId The Id of the attachment to replace
 *  @param attachment An attachment and optional overlay for the attachment
 *  @param callback Asynchronous callback called when this task is done
 */
- (void)updateConversationWithId:(MDObjectId*)conversationId
     byReplacingAttachmentWithId:(MDObjectId*)attachmentId
                      attachment:(MDAttachmentMaps*)attachment
                        callback:(void (^)(MDConversation* __nullable conversation, MDFault* __nullable fault))callback;

/**
 *  Updates a conversation's attachments by deleting a particular attachment
 *  @param conversationId The conversation's Id
 *  @param attachmentId The Id of the attachment to delete
 *  @param callback Asynchronous callback called when this task is done
 */
- (void)updateConversationWithId:(MDObjectId*)conversationId
      byDeletingAttachmentWithId:(MDObjectId*)attachmentId
                        callback:(MDFaultCallback)callback;

/**
 * Updates a context object
 *  @param conversationId Conversation object Id
 *  @param description Conversation description
 *  @param patientFile Conversation associated PatientFile object
 *  @param favorite Set this converstaion as favorite
 *  @param customPropValues Conversation custom properties and values
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)updateConversationWithId:(MDObjectId*)conversationId
                     description:(nullable NSString*)description
                     patientFile:(nullable MDPatientFile*)patientFile
                        favorite:(nullable NSNumber*)favorite
                customPropValues:(nullable NSDictionary*)customPropValues
                        callback:(void (^)(MDConversation* __nullable conversation, MDFault* __nullable fault))callback;

/**
 * Deletes a context object
 *  @param conversationId Conversation object Id
 *  @param reason Create reason parameters with MDAPIParameterFactory
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)deleteConversationWithId:(MDObjectId*)conversationId
                          reason:(nullable MDAPIParameters*)reason
                        callback:(MDFaultCallback)callback;


#pragma mark - Team

/**
 * List context objects
 *  @param parameters Construct parameters using MDAPIParameterFactory.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)listTeamsWithParameters:(nullable MDAPIParameters*)parameters
                       callback:(MDTeamListFaultCallback)callback;

/**
 * Gets a context object
 *  @param teamId Context ObjectId (required)
 *  @param parameters Construct parameters using MDAPIParameterFactory.
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)teamWithId:(MDObjectId*)teamId
        parameters:(nullable MDAPIParameters*)parameters
          callback:(void (^)(MDTeam* __nullable team, MDFault* __nullable fault))callback;

/**
 * Creates a context object
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)createTeamWithName:(NSString*)name
               description:(NSString*)description
                  favorite:(nullable NSNumber*)favorite
          customPropValues:(nullable NSDictionary*)customPropValues
                  callback:(void (^)(MDTeam* __nullable team, MDFault* __nullable fault))callback;

/**
 * Updates a context object
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)updateTeamWithId:(MDObjectId*)teamId
                    name:(nullable NSString*)name
             description:(nullable NSString*)description
                favorite:(nullable NSNumber*)favorite
        customPropValues:(nullable NSDictionary*)customPropValues
                callback:(void (^)(MDTeam* __nullable team, MDFault* __nullable fault))callback;

/**
 * Deletes a context object
 *  @param callback Callback block called when the service call finishes. Check MDFault for errors.
 */
- (void)deleteTeamWithId:(MDObjectId*)teamId
                  reason:(nullable MDAPIParameters*)reason
                callback:(MDFaultCallback)callback;

@end

NS_ASSUME_NONNULL_END
