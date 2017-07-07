//
//  MDFault.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Standard object for wrapping errors. Most object callbacks return an MDFault object
 * as well as the object they are expected to retrieve. Perform a nil check on the fault
 * parameter of the callback to ensure everything went without problems.
 */
@interface MDFault : NSObject

/// Fault's name.
@property (nonatomic, readonly) NSString* name;

/// Fault's code. See the API Documentation for standard error codes.
@property (nonatomic, readonly) NSString* code;

/// Fault's message, localized in the Org's locale.
@property (nonatomic, readonly) NSString* message;

/// Fault's path.
@property (nonatomic, readonly) NSString* path;

/// Fault's reason or explanation.
@property (nonatomic, readonly) NSString* reason;

/// Sub faults in this fault.
@property (nonatomic, readonly) NSArray* subfaults;

@end
