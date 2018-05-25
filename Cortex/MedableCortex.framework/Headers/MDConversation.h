//
//  MDConversation.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MDReference;

NS_ASSUME_NONNULL_BEGIN

/**
 * Care Conversations are centered around a patient and allow for users of different
 * roles to collaborate around that patient. A care conversation can be used for consults
 * among providers, for a virtual visit between a patient and provider(s), or for just 
 * about any care related interaction.
 */
DEPRECATED_MSG_ATTRIBUTE("This class will be removed in future versions.")
@interface MDConversation : MDObjectInstance

/**
 * The account that archived the conversation
 */
@property (nullable, nonatomic, readonly) MDReference* archivalAccount;

/**
 * The reason for archiving
 */
@property (nullable, nonatomic, readonly) NSString* archivalReason;

/**
 * The conversation description
 */
@property (nullable, nonatomic, readonly) NSString* conversationDescription;

/**
 * File[]
 */
@property (nullable, nonatomic, readonly) NSArray* attachments;

/**
 * The account context Id for the patient if connected to the conversation as an active participant.
 */
@property (nullable, nonatomic, readonly) MDReference* patientAccount;

/**
 * The Patient File for which the conversation was created. Once set, it cannot be changed.
 */
@property (nullable, nonatomic, readonly) MDReference* patientFile;

/**
 * Get the collaborators of this conversation
 *
 * @return collaborators of this conversation
 */
- (nullable NSArray*)collaborators;

/**
 * Check whether a colaborator is connected to this conversation.
 *
 * @param Id The collaborator's Id.
 * @return True if the collaborator is in the collaborators array, False otherwise.
 */
- (BOOL)isConnectedWithId:(MDObjectId*)Id;

/**
 * List invitations in this conversation that were created by the current user and haven't been accepted yet.
 *
 * @return The list of open invitations in this conversation.
 */
- (nullable NSArray*)sentInvitations;

/**
 * Whether the current user has invited a certain user.
 *
 * @param Id Account's Id.
 * @return True if the current user has invited the user with this account Id and that invitation hasn't been accepted yet.
 */
- (BOOL)sentInviteToId:(MDObjectId*)Id;

/**
 * Get the list of images in the conversation.
 *
 * @param callback The asynchronous callback block where the images are returned.
 */
- (void)imagesWithCallback:(MDPicsUpdateBlock)callback;

@end

NS_ASSUME_NONNULL_END
