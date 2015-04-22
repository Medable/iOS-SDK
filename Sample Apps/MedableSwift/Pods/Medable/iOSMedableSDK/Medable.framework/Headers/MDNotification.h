//
//  MDNotification.h
//  iOSMedableSDK
//
//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MDNotificationManager.h"

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
@interface MDNotification : NSObject

/**
 * The unique identifer
 */
@property (nonatomic, readonly) MDObjectId* Id;

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
 * Unique identifier of the object this notification corresponds to.
 */
@property (nonatomic, readonly) MDObjectId* object;

/**
 * Type.
 */
@property (nonatomic, readonly) NSNumber* type;

/**
 * Type enumeration.
 *
 * @see MDNotificationType
 */
@property (nonatomic, readonly) MDNotificationType typeEnumerated;

/**
 * Create a new notification object from a received notification.
 *
 * @param attributes Notification information, as received.
 *
 * @return Instance representing the received notification.
 */
- (instancetype)initWithAttributes:(NSDictionary *)attributes NOTNULL(1);

@end
