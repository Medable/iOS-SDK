FAQ
------

### Why can't I mod an object instance? why is that there are no setters?

All the modifications need to go through the api, and then you need to synchronize your object instance. This is to make it easier to avoid inconsistences between the client and the api.
That’s why all the modifications are done through MDAPIClient object modification methods.


### About parameters validation in MDAPIClient

MDAPIClient's header is annotated with nullability annotations; this enables compile time parameter nullability checksfor the methods listed in MDAPIClient's header file. Remember that XCode 6.3+ is needed for this to work properly. Read more about nullability annotations [here](https://developer.apple.com/swift/blog/?id=25).

Besides that, required parameters are checked at runtime. If something is wrong, you'll get a MDLocalFault object in any method's callback block, providing validation error details. Also, these MDLocalFault obejcts are broadcasted inside NSNotifications using the default NSNotificationCenter. The notification name is **kMDNotificationLocalFaultNotification**. These are specially useful for when the validation error is that there's no callback block.

In general, MDLocalFault objects are used to inform the user about error that are not related to the API server (MDFault objects are used for this), or when some API unrelated network issue was detected.

You can handle such notifications the following way:
```objective-c
// First, listen for that kind of notifications
[[NSNotificationCenter defaultCenter]
 addObserver:self
 selector:@selector(handleLocalFault:)
 name:kMDNotificationLocalFaultNotification
 object:nil];

...

// Handling
- (void)handleLocalFault:(NSNotification*)notif
{
    MDLocalFault* localFault = (MDLocalFault*)notif.object;
    
    // Print details
    NSLog(@"Local notification: %@", localFault.description);
    
    // Handle
    ...
}
```
