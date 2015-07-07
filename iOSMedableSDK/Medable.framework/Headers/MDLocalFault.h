//
//  MDLocalFault.h
//  iOSMedableSDK
//
//  Created by fer on 6/7/15.
//  Copyright (c) 2015 Medable. All rights reserved.
//

#import "MDFault.h"

/**
 * MDLocalFault objects are used to inform the user about error that are not related to the API server (MDFault objects are used for this), or when some API unrelated network issue was detected.
 * Also, required parameters are checked at runtime. If something is wrong, you'll get a MDLocalFault object in any method's callback block, providing validation error details. Also, these MDLocalFault obejcts are broadcasted inside NSNotifications using the default NSNotificationCenter. The notification name is kMDNotificationLocalFaultNotification. These are specially useful for when the validation error is that there's no callback block.
 **/
@interface MDLocalFault : MDFault

@end