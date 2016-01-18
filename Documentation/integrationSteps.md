Integration Steps
=====

### Add the Environments.plist configuration file

The Sample App contains an example configuration file, containing such things as your org code, api key, and target domain. The compound base URL produced will look like https://api.dev.medable.com/medable/v2.

+ Copy this file to your project and add a reference to it so you see it in your project’s navigator.
+ Configure values in Environments.plist.

Note: If you have your project and our sample app opened, locate Environments.plist file in our Sample project, drag and drop the file to your project and make sure you check “Copy items into destination group’s folder (if needed)’ when you get the popup.


### Add an entry in the Info.plist file

The SDK uses this setup at runtime to read values from the Environments.plist file.
+ Locate your project’s Info.plist file. In XCode 5 it’s located in ‘Supporting Files’ group. The file is called ‘YourProjectName-Info.plist’.
+ Select it, right click and select ‘Add Row’.
+ Specify ‘Configuration’ for Key and ‘${CONFIGURATION}’ for Value. Type is ‘String’ by default. Put those strings without the ‘’.
+ Save.

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
