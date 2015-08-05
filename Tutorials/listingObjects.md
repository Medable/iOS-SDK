Listing Objects
====

Listing all object of a given context is a simple task. But you have to be aware of the object's default access control as making this API call will only return those object that the caller can view. If the objects you are expecting in return are not part of the results, consider making connections to those objects.

```objective-c
MDAPIParameters* parameters = [MDAPIParameterFactory parametersWithLimitPaths:@[ kNameKey ]];

[[MDAPIClient sharedClient]
 listObjectsWithContext:kPluralAccountContext
 parameters:parameters
 callback:^(NSArray *objects, NSNumber *hasMore, MDFault *fault)
 {
     if (fault)
     {
         // Fault handling
     }
     else
     {
         // All good
     }
 }];
```

In this example, the code is listing all accounts, but by default a user only sees their account. The caller will have to invite the other user to connect (using their email) or they will need to be added to the same team.

Continue reading about [Updating an Object](updateObject.md).
