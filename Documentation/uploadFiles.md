Managing File Uploads
====

The iOS SDK features an upload operations manager, that takes care of the following tasks:

- Keep an up to date list of ongoing upload operations.
- Keep an up to date list of recently successfully completed operations.
- Keep an up to date list of recently failed operations.
- Keep a progress value (percentage expressed in the 0..1 range) for each operation.
- Emit notifications for every change in the manager:
	- Newly added upload.
	- Upload completed or failed.
	- Upload operation progress changed.

Notifications
----

Every time there is a significant event in the upload operations manager, it emits a notification using the string `kOperationProgressChangedNotification`, which is declared in `MDUploadOperations.h`:

```objective-c
/**
 * String used to notify that an upload operation has changed its state.
 *
 * This can happen when the upload operation is started, its progress has changed
 * or when it completes.
 */
extern NSString *const kOperationProgressChangedNotification;
```

As expressed in the comment, this notification is emitted for every change in the upload operations manager.

State
----

The state of all upload operations can be queried from the `MDUploadOperations` class by checking the the following class methods:

```objective-c
+ (NSArray *)ongoingOperations;

+ (NSArray *)completedOperations;

+ (NSArray *)failedOperations;
```

An ongoing operation is an upload task that is still uploading, i.e. it hasn't failed and it hasn't completed the upload yet.

Recently completed operations are short lived. After completion, the operation objects will stay in this list for at least 10 seconds. After this time, they'll be removed from the list.

Recently failed operations live a little longer. After failing, the operation objects will stay in this list for at least 1 minute. Again, after this time, they are be removed from the list.

Each operation is an instance of class `MDUploadOperation`. Here are some interesting features they provide:

- **Progress**: Use the `progressNumber` attribute to determine the progress percentage (measured in the 0..1 range) of the upload operation.
- **Data Task**: Use the `operation` property, of class `NSURLSessionDataTask` for the data task that the operation is using. You may call `cancel` on this object to cancel the upload.
- **File Name**: If you are uploading several things at once, the `fileName` property contains the name of the file being uploaded.
- **NSProgress**: Apple's `NSProgress` class allows for fine grain progress reporting, the `operationProgress` property returns the associated `NSProgress` object with this upload operations.

Cancel an Ongoing Operation
----

To cancel an ongoing operation, just call `cancel` on its data task, which you get from calling `operation` on the `MDUploadOperation` instance.

Here is code to cancel all ongoing operations:

```objective-c
- (void)cancelAllOperations
{
	//Copy into new array, as cancelling them may modify this original list
	NSArray *ongoingOperations = [[MDUploadOperations ongoingOperations] copy];

	for ( MDUploadOperation *uploadOperation in ongoingOperations )
	{
		[uploadOperation.operation cancel];
	}
}
```

Retry a Failed Operation
----

Any operation that has failed can be retried, it need not be in the failed operations set, but beware that the upload tokens used will eventually expire.

Here is code to retry all operations currently in the failed set:

```objective-c
- (void)retryAllFailedOperations
{
	//Copy into new array, as retrying them may modify this original list
	NSArray *failedOperations = [[MDUploadOperations failedOperations] copy];

	for ( MDUploadOperation *uploadOperation in failedOperations )
	{
		[MDUploadOperations retryOperation:uploadOperation];
	}
}
```

When you are done with this section, continue with [Listing Object Instances](listingObjects.md).