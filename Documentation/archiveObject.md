Archiving Objects
====

You can't delete objects outright, but you can archive them and optionally provide a reason for archiving.

Assume `self.context` is an `MDObjectDefinition` and `object` is an instance of an object that adheres to this definition.

```objective-c
NSString *objectName = [self.context pluralNameForAPICalls];

MDAPIParameters *archiveReason = [MDAPIParameterFactory parametersWithArchiveObjectReason:@"Moving to new object model"];

[[Medable client]
	deleteObjectWithContext:objectName
	objectId:object.Id
	reason:archiveReason
	callback:^(MDFault* fault)
	{
		if ( fault != nil )
		{
			//Handle Fault
		}
		else
		{
			//Successful archive
		}
	}];
```

This is the last tutorial on the series, return to the [Tutorial Home](tutorial.md) for the full list of available tutorials.