iOSSDK
======

iOS Client SDK for Medable

Integration Guide:
------

##### Get the framework

[Download the latest version](https://www.medable.com/downloads/ios/sdk/latest) and place it wherever you like inside your project structure.

##### Now let’s link your project against the framework

+ In XCode, click in your project’s root, select ‘General’ tab on the right, and scroll up until you see the ‘Linked Frameworks and Libraries’ section.
+ Press the plus button.
+ Select ‘Add other…’, browse to where you put the framework, select it and click ‘Open’.
+ Now hit build and check everything goes well. 
+ Good!, now you have your project linked to iOSMedableSDK.framework.

##### Add the Environments.plist configuration file

The Sample App contains an example configuration file, containing such things as your org code, api key, and target domain. The compound base URL produced will look like https://api.dev.medable.com/medable/v1.

+ Copy this file to your project and add a reference to it so you see it in your project’s navigator.
+ Configure values in Environments.plist.

Note: If you have your project and our sample app opened, locate Environments.plist file in our Sample project, drag and drop the file to your project and make sure you check “Copy items into destination group’s folder (if needed)’ when you get the popup.


##### Add an entry in the Info.plist file

The SDK uses this setup at runtime to read values from the Environments.plist file.
+ Locate your project’s Info.plist file. In XCode 5 it’s located in ‘Supporting Files’ group. The file is called ‘YourProjectName-Info.plist’.
+ Select it, right click and select ‘Add Row’.
+ Specify ‘Configuration’ for Key and ‘${CONFIGURATION}’ for Value. Type is ‘String’ by default. Put those strings without the ‘’.
+ Save.


##### Add a linker flag (-ObjC)

This linker flag allows you to use class extensions provided by our framework.

+ In XCode, click in your project’s root, select ‘Build Settings’ tab on the right, and search for ‘other linker flags’.
+ Double click on the right side of it.
+ Press the plus button.
+ And write ‘-ObjC’, without the quotes.

##### Setup Imports

+ You can either add one general import in your pch file (YourProjectName-Prefix.pch) and forget about it (eg. `#import <iOSMedableSDK/MDCommonImports.h>`)
+ or import SDK classes one by one on demand in different places of your project (eg. `#import <iOSMedableSDK/MDAccount.h>`).

##### Initialize the Assets Manager

+ Add `[MDAssetManager sharedManager]` to your app's application:didFinishLaunchingWithOptions: method delegate.

Note: The Assets Manager must be initialized before authentication.

##### Download new content from the server

The REST API includes a Bundle API that enables orgs to store versioned, localized, often-changing string tables and property lists. Using MDContentDownloader as shown in the sample app, you can check for new content on application startup. There are two notifications indicating the beginning and end of the content download so you can give visual feedback, if needed.

##### Import 3rd party classes

Our SDK uses the well known ‘AFNetworking’ (v2.0) framework as the communications base framework. 

Some bundled 3rd party classes are not included in MDCommonImports and need to be explicitly imported, the first of which is used to change the level of networking events logging to the console (very useful for debugging!).

  `#import <iOSMedableSDK/AFNetworkActivityLogger.h>`

The second is used to either enable or disable a spinning wheel on the status bar, to display visual feedback while any networking is happening in the background.

  `#import <iOSMedableSDK/AFNetworkActivityIndicatorManager.h>`

Optional Integration Steps
------

##### Setting of networking level
  
  `MDAppDelegate @ application:didFinishLaunchingWithOptions:`

##### Enabling spinning wheel on status bar to give feedback while there’s some networking happening in the background.

##### Handling particular events by listening to notifications.

kMDNotificationAPIServerErrorDidOccur: This notification comes with the corresponding MDFault object, ready to be handled. Fault codes are listed in MDConstants.h.

kMDNotificationUserDidLogout: This notification is used to forward the app to the login screen. This notification is thrown when the user logs out, or when API session is over because of an error or session timeout.

Note: More notifications are defined in MDConstants.h.

##### A few more things the Sample App covers...

<table>
  <thead><tr><th>What</th><th>Where</th></tr></thead>
  <tbody>
    <tr><td>Handling Push Notifications</td><td>See app delegate’s application:didReceiveRemoteNotification</td></tr>
    <tr><td>Sign In</td><td>MDLoginViewController @ loginUser method</td></tr>
    <tr><td>Sign Out</td><td>MDMainNavigationViewController @ handleMenuPickWithChoiceType: method</td></tr>
    <tr><td>Autologin / Recover session (while it’s not expired)</td><td>MDLoginViewController @ loginAfterSignUp method</td></tr>
    <tr><td>Request password reset</td><td>MDForgotPasswordViewController @ reset: method</td></tr>
    <tr><td>2fa Verification. Verify a new device with code received by SMS</td><td>MDVerifyDeviceViewController @ verify: method</td></tr>
    <tr><td>Get an account avatar thumbnail</td><td>MDProfileViewController @ fillDataFromUser method</td></tr>
    <tr><td>Send a Team invitation</td><td>MDTeamActivityViewController @ sendInvitationWithEmail: method</td></tr>
    <tr><td>Leave a Team</td><td>MDTeamActivityViewController @ handleMenuPickWithChoiceType: method</td></tr>
    <tr><td>Get team invitations</td><td>MDTeamListViewController @ checkForInvitations</td></tr>
    <tr><td>Get teams using pagination</td><td>MDTeamListViewController @ checkToLoadObjects method</td></tr>
    <tr><td>Get new teams using pagination</td><td>MDTeamListViewController @ checkToLoadNewObjects method</td></tr>
    <tr><td>Accept / Revoke team invitations</td><td>MDTeamListViewController @ askToAcceptWithInvitation: method</td></tr>
    <tr><td>Create a new team</td><td>MDTeamListViewController @ createTeamWithName: method</td></tr>
    <tr><td>Create a new feed post</td><td>MDNewPostViewController @ save: method</td></tr>
    <tr><td>Post a comment to a post</td><td>MDNewPostViewController @ save: method</td></tr>
  </tbody>
</table>
