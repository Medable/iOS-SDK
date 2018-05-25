//
//  NSData+Mime.h
//  iOSMedableSDK
//
//  Created by Fernando Waigandt on 8/2/17.
//  Copyright © 2017 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (Mime)

/**
 * Guesses the mimeType from the signature in the NSData contents.
 * @return The guessed mimeType or 'application/octet-stream'.
 */
- (NSString *)mimeType;

/**
 * Guesses the mimeType and then tries to get the file extension for that mime type.
 * @return File extension commonly associated with the mime type, if it can be guessed from the signature of the data.
 */
- (NSString *)mimeExtension;

@end
