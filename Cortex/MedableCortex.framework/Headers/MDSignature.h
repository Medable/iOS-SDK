//
//  MDSignature.h
//  Medable Cortex
//
//  Copyright © 2018 Medable. All rights reserved.
//

#import <MedableCortex/MedableCortex.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 21 CFR part 11 signature.
 */
@interface MDSignature : MDObjectInstance

/**
 * Signature context.
 */
@property (nonatomic, readonly) MDReference *context;

/**
 * Signing date.
 */
@property (nonatomic, readonly) NSDate* date;

/**
 * Signer full name.
 */
@property (nonatomic, readonly) NSString *signer;

/**
 * Signature value.
 */
@property (nonatomic, readonly) NSObject *value;

@end

NS_ASSUME_NONNULL_END
