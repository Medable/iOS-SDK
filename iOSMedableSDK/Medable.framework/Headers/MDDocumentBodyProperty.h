//
//  MDDocumentBodyProperty.h
//  iOSMedableSDK
//
//  Copyright © 2015 Medable. All rights reserved.
//

#import "MDBodyProperty.h"

/**
 * Document property. Subproperties added to this should be initialized with the right property definition's subproperties.
 */
@interface MDDocumentBodyProperty : MDBodyProperty

/**
 * Add an entry to the document proprety with the value of a subproperty.
 *
 * @param property The subproperty.
 */
- (void)addProperty:(MDBaseBodyProperty *) property;

@end
