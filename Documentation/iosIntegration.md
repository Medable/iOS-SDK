Medable iOS SDK Integration Guide
====

### Add the Environments.plist configuration file

The Sample App contains an example configuration file, containing such things as your org code, api key, and target domain. The compound base URL produced will look like https://api.dev.medable.com/medable/v2.

+ Copy this file to your project and add a reference to it so you see it in your project's navigator.
+ Configure values in Environments.plist.

Note: If you have your project and our sample app opened, locate Environments.plist file in our Sample project, drag and drop the file to your project and make sure you check 'Copy items into destination group's folder (if needed)' when you get the popup.


### Add an entry in the Info.plist file

The SDK uses this setup at runtime to read values from the Environments.plist file.
+ Locate your project's Info.plist file. In XCode 5 it's located in 'Supporting Files' group. The file is called 'YourProjectName-Info.plist'.
+ Select it, right click and select 'Add Row'.
+ Specify 'Configuration' for Key and '${CONFIGURATION}' for Value. Type is 'String' by default. Put those strings without the ''.
+ Save.

### Setup Imports

+ You can either add one general import in your pch file (YourProjectName-Prefix.pch) and forget about it (eg. `#import <Medable/Medable.h>`)
+ or import SDK classes one by one on demand in different places of your project (eg. `#import <Medable/MDAccount.h>`).

### Download new content from the server

The REST API includes a Bundle API that enables orgs to store versioned, localized, often-changing string tables and property lists. Using MDContentDownloader as shown in the sample app, you can check for new content on application startup. There are two notifications indicating the beginning and end of the content download so you can give visual feedback, if needed.

Optional Integration Steps
------

### Set log level
```objective-c
// Change log level
[Medable client].loggerLevel = MDAPIClientNetworkLoggerLevelDebug;

// If not set, the default loggerLevel is MDAPIClientNetworkLoggerLevelInfo.
```

### Handling particular events by listening to notifications.

kMDNotificationAPIServerErrorDidOccur: This notification comes with the corresponding MDFault object, ready to be handled. Fault codes are listed in MDConstants.h.

kMDNotificationUserDidLogout: This notification is used to forward the app to the login screen. This notification is thrown when the user logs out, or when API session is over because of an error or session timeout.

Note: More notifications are defined in MDConstants.h.
