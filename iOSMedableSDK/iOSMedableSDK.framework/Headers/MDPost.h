//
//  MDPost.h
//  iOSMedableSDK
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MDConversation;

@interface MDPost : NSObject

/**
 * The unique identifer
 */
@property (nonatomic, readonly) MDObjectId* Id;

/**
 * The object that the post is associated with.
 */
@property (nonatomic, readonly) MDObjectDefinition* object;

/**
 * The object context that the post is associated with
 */
@property (nonatomic, readonly) MDReference* context;

@property (nonatomic, readonly) MDPostDefinition* postDefinition;

/**
 * The account that created the post
 */
@property (nonatomic, readonly) MDReference* creator;

/**
 * The updated Unix timestamp for the post when edited
 */
@property (nonatomic, readonly) NSDate* updated;

/**
 * The account that updated the post
 */
@property (nonatomic, readonly) MDReference* updater;

/**
 * The type of post being created. The type determines how the post is handled depending on the object feed configuration
 */
@property (nonatomic, readonly) NSString* type;

/**
 * The Account associated with the post. In Patient Files and Conversation, this is the account of the associated patient.
 */
@property (nonatomic, readonly) MDReference* account;

/**
 * The Patient File associated with the post.
 */
@property (nonatomic, readonly) MDReference* patientFile;

/**
 * True is the post has been explicitly targeted.
 */
@property (nonatomic, readonly) NSNumber* targeted;

/**
 * The targets of the post. Adding targets limits visibility to selected accounts and roles. The post creator is always included as a target.
 */
@property (nonatomic, readonly) NSArray* targets;

/**
 * Number of up votes on a post
 */
@property (nonatomic, readonly) NSNumber* votes;

/**
 * True if the calling principal has voted up the post.
 */
@property (nonatomic, readonly) NSNumber* voted;

/**
 * Comments
 */
@property (nonatomic, readonly) NSArray* comments;

/**
 * The array of configured feed definition segments, discriminated by name.
 */
@property (nonatomic, readonly) NSArray* body;

- (void)synchronizeObjectWithParameters:(MDAPIParameters *)externalParameters
                               callback:(MDObjectFaultCallback)callback;

@end

