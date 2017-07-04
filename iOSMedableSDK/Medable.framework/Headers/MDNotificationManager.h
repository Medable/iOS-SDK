//
//  MDNotificationManager.h
//  Medable
//
//  Copyright (c) 2014 Medable. All rights reserved.
//

#import "MDNotification.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Local notification manager.
 */
@interface MDNotificationManager : NSObject

/// Singleton instance.
+ (MDNotificationManager*)sharedManager;

/**
 * Add a list of notifications as unattended.
 * This will update your app's badge number.
 *
 * @param notifications Array of unattended notifications.
 */
- (void)loadNotificationsWithArray:(NSArray*)notifications;

/**
 * Add a single notification as unattended.
 * This will update your app's badge number by increasing it by 1.
 *
 * @param notification Unattended notifications.
 */
- (BOOL)addNotification:(MDNotification*)notification;

/**
 * Single that a notification has been tended to.
 * This will update your app's badge number by decreasing it by 1 provided this
 * is part of the list of unattended notifications.
 *
 * @param notification Unattended notification.
 */
- (void)removeNotification:(MDNotification*)notification;

/**
 * Get the notification that matches a certain unique identifier.
 *
 * @param notificationId The unique identifier of the notification.
 * @return The notification object that matches this identifier, or nil if none do.
 */
- (nullable MDNotification*)notificationWithId:(MDObjectId*)notificationId;

- (NSSet*)notificationsWithType:(MDNotificationType)type
                        context:(MDNotificationContext)context
                      contextId:(nullable MDObjectId*)contextId
        optionalMetadataFilters:(nullable NSDictionary*)optionalMetadataFilters;

/**
 * List of unattended notifications.
 */
- (NSArray*)currentNotifications;

/**
 * Force a synchronization of unattended notifications.
 */
- (void)synchNotificationsWithServer;   // try not to call it for networking performance

@end

NS_ASSUME_NONNULL_END
