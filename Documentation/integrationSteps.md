Advanced Integration Steps
=====

### Provide baseUrl / organization / clientKey programmatically

+ To do this expose a `MDEnvironment` "hidden" method like this:

```Objective-C
@interface MDEnvironment ()
+ (MDEnvironment*)environmentWithBaseUrl:(NSString*)baseUrl
                            organization:(NSString*)organization
                               clientKey:(NSString*)clientKey;

@end

```

+ Then make sure the following call is the first SDK call or at least it is called before any other SDK call. Otherwise the values from Info.plist will be loaded!

```Objective-C
[MDEnvironment environmentWithBaseUrl:@"theBaseUrl"
                         organization:@"orgName"
                            clientKey:@"yourClientKey"];

// After that you can call either [MDAPIClient sharedClient] or [Medable start] to init the SDK.
```


### Setup Imports

+ You can either add one general import in your pch file (YourProjectName-Prefix.pch) and forget about it (eg. `#import <Medable/Medable.h>`)
+ or import SDK classes one by one on demand in different places of your project (eg. `#import <Medable/MDAccount.h>`).

### Download SDK content from the server

The REST API includes a Bundle API that enables orgs to store versioned, localized, often-changing string tables and property lists. Also, we have all the definitions information, handled by the MDSchemaManager singleton. As a **first step**, and even before sending the user to the login or registration screens, all this information needs to be downloaded from our servers; to do this, the simplest approach is to start the Medable SDK by adding this line to your app delegate method:

```objective-c
[Medable start];
```

Internally, it's calling `[MDContentDownloader checkForDownloads];`. Also, if you need to know how the download process is going, you should register for these notifications:

```objective-c
// First, register to listen to MDContentDownloader notifications
        [[NSNotificationCenter defaultCenter]
         addObserver:self
         selector:@selector(downloadStarted: )
         name:kContentDownloadedDidStartDownloads
         object:nil];
        
        [[NSNotificationCenter defaultCenter]
         addObserver:self
         selector:@selector(downloadFinished: )
         name:kContentDownloadedDidFinishDownloads
         object:nil];

...
[MDContentDownloader checkForDownloads];

...
// Handling the notifications
- (void)downloadStarted:(NSNotification*)notification
{
	// Show visual feedback... "Downloading..." or something
}

- (void)downloadFinished:(NSNotification*)notification
{
	// Continue to login screen
}
```
