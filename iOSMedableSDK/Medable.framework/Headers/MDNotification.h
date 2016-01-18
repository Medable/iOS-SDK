//
//  MDNotification.h
//  iOSMedableSDK
//
//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MDNotificationManager.h"
#import "MDBaseInstance.h"

@class MDObjectId;
@class MDReference;

/**
 * Notifications are created as a result of modifications to contexts, posts and comment begin created or edited,
 * invitations to connect and context ownership transfer requests.
 * An Organization can setup an app for Apple Push Notification Service (APNs), and users can set preferences for
 * how to receive notifications, through APNs or via email.
 *
 * Notifications are automatically cleared for posts and comments when they are retrieved using the API. Otherwise,
 * clients should manually clear them using the notifications API.
 */
@interface MDNotification : MDBaseInstance

/**
 * The context for which the notification was created.
 */
@property (nonatomic, readonly) MDReference* context;

/**
 * Enumeration of the context the notification belongs to. Should only be used for default classes and not custom ones.
 */
@property (nonatomic, readonly) MDNotificationContext contextEnumerated;

/**
 * Type-specific metadata
 */
@property (nonatomic, readonly) NSDictionary* meta;

/**
 * Notification Type.
 */
@property (nonatomic, readonly) MDObjectId* type;

/**
 * Type enumeration.
 *
 * @see MDNotificationType
 */
@property (nonatomic, readonly) MDNotificationType typeEnumerated;

/**
 * Returns the ObjectId representing the type of notification.
 *
 * @param type type of notification
 *
 * @return MDObjectId representing the type of notification.
 */
+ (MDObjectId*)typeIdWithType:(MDNotificationType)type;

/**
 * Create a new notification object from a received notification.
 *
 * @param notifAttributes Notification information, as received.
 *
 * @return Instance representing the received notification.
 */
- (instancetype)initWithAttributes:(NSDictionary *)attributes NOTNULL(1);

@end
