//
//  MDFileBodyProperty.h
//  Medable
//
//  Copyright © 2015 Medable. All rights reserved.
//

#import "MDBodyProperty.h"

/**
 * Body property containing the value of the property of type 'Any'.
 */
@interface MDAnyBodyProperty : MDBodyProperty

@property (nonatomic, strong) NSObject *valueObject;

@end
