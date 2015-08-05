Updating Objects
====

To update an object, create an update body following the same rules you read about in [Creating an Object Instance (a.k.a. a Context)](creatingObjects.md). 

In this next example, assume `self.editingObject` is any object instance, and that `body` is a properly formed dictionary that maps a subset of this object's property names to the values you wish to update this object to:

```objective-c
    [[MDAPIClient sharedClient]
     updateObjectWithContext:[self.editingObject.object pluralNameForAPICalls]
     objectId:self.editingObject.Id
     body:body
     callback:^(MDObjectInstance* editedObject, MDFault *fault)
     {
        if ( fault != nil )
        {

     	}
     	else
     	{

     	}
     }];
```

Following the `Object` example in the simple approach to [Creating an Object Instance (a.k.a. a Context)](creatingObjects.md), this code will update only the value of `c_number` and `c_string` properties to new values:

```objective-c
MDAPIClient *client = [MDAPIClient sharedClient];

NSDictionary *body = 
	@{
		@"c_number" : @(31337),
		@"c_string" : @"Two roads diverged in a yellow wood",
	};
		
[[MDAPIClient sharedClient]
     updateObjectWithContext:[self.editingObject.object pluralNameForAPICalls] //This would yield @"c_objects"
     objectId:self.editingObject.Id
     body:body
     callback:^(MDObjectInstance* editedObject, MDFault *fault)
     {
        if ( fault != nil )
        {

     	}
     	else
     	{
     		
     	}
     }];
```

Next, continue with [Archiving Objects](archiveObject.md).
