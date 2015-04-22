About the Medable SDK
======

Welcome to the iOS Client SDK for [Medable](https://www.medable.com). This library provides a wrapper for the [backend API](https://dev.medable.com/) as well as several helper tools to directly integrate those features to your iOS application.

The Medable iOS SDK is targeted to be used in apps that have a base SDK of iOS 7 and the following instructions are targeted for Xcode 5 users, consider updating if you have an older version.

Installation
======

Using Cocoapods
------

#### Step 1: Download CocoaPods

[CocoaPods](http://cocoapods.org) is a dependency manager for Objective-C, which automates and simplifies the process of using 3rd-party libraries like Medable in your projects.

CocoaPods is distributed as a ruby gem, and is installed by running the following commands in your Terminal:

    $ sudo gem install cocoapods
    $ pod setup

> Depending on your Ruby installation, you may not have to run as `sudo` to install the cocoapods gem.

#### Step 2: Create a Podfile

Project dependencies to be managed by CocoaPods are specified in a file called `Podfile`. Create this file in the same directory as your Xcode project (`.xcodeproj`) file.

Copy and paste the following lines into the file:  
    
    platform :ios, '7.0'
    pod 'Medable'

#### Step 3: Install Dependencies

Now you can install the dependencies in your project:

    $ pod install

From now on, be sure to always open the generated Xcode workspace (`.xcworkspace`) instead of the project file when building your project:

    $ open <YourProjectName>.xcworkspace

That's it, you are now ready to use the Medable SDK. Head on over to the [Integration](#integration) guide to continue your setup.

Install the framework manually
------

[Download the latest version](https://www.medable.com/downloads/ios/sdk/latest) and place it wherever you like inside your project structure.

##### Now let’s link your project against the framework

+ In XCode, click in your project’s root, select ‘General’ tab on the right, and scroll up until you see the ‘Linked Frameworks and Libraries’ section.
+ Press the plus button.
+ Select ‘Add other…’, browse to where you put the framework, select it and click ‘Open’.
+ Now hit build and check everything goes well. 
+ Good!, now you have your project linked to iOSMedableSDK.framework.

##### Now let’s link your project against required frameworks

Enable Core Location services

+ In XCode, click in your project’s root, select ‘General’ tab on the right, and scroll up until you see the ‘Linked Frameworks and Libraries’ section.
+ Press the plus button.
+ Search and add CoreLocation.framework.
+ Add an entry to your app's info.plist file with this key NSLocationWhenInUseUsageDescription. The value you use for this is the message users will be presented when asking for permission to use location services.
+ Now hit build and check everything goes well.

Integration
------

### Add the Environments.plist configuration file

The Sample App contains an example configuration file, containing such things as your org code, api key, and target domain. The compound base URL produced will look like https://api.dev.medable.com/medable/v1.

+ Copy this file to your project and add a reference to it so you see it in your project’s navigator.
+ Configure values in Environments.plist.

Note: If you have your project and our sample app opened, locate Environments.plist file in our Sample project, drag and drop the file to your project and make sure you check “Copy items into destination group’s folder (if needed)’ when you get the popup.


### Add an entry in the Info.plist file

The SDK uses this setup at runtime to read values from the Environments.plist file.
+ Locate your project’s Info.plist file. In XCode 5 it’s located in ‘Supporting Files’ group. The file is called ‘YourProjectName-Info.plist’.
+ Select it, right click and select ‘Add Row’.
+ Specify ‘Configuration’ for Key and ‘${CONFIGURATION}’ for Value. Type is ‘String’ by default. Put those strings without the ‘’.
+ Save.


### Add a linker flag (-ObjC)

This linker flag allows you to use class extensions provided by our framework.

+ In XCode, click in your project’s root, select ‘Build Settings’ tab on the right, and search for ‘other linker flags’.
+ Double click on the right side of it.
+ Press the plus button.
+ And write ‘-Objc’, without the quotes.

### Setup Imports

+ You can either add one general import in your pch file (YourProjectName-Prefix.pch) and forget about it (eg. `#import <Medable/Medable.h>`)
+ or import SDK classes one by one on demand in different places of your project (eg. `#import <Medable/MDAccount.h>`).

### Initialize the Assets Manager

+ Add `[MDAssetsManager sharedManager]` to your app's application:didFinishLaunchingWithOptions: method delegate.

Note: The Assets Manager must be initialized before authentication.

### Download new content from the server

The REST API includes a Bundle API that enables orgs to store versioned, localized, often-changing string tables and property lists. Using MDContentDownloader as shown in the sample app, you can check for new content on application startup. There are two notifications indicating the beginning and end of the content download so you can give visual feedback, if needed.

Optional Integration Steps
------

### Handling particular events by listening to notifications.

kMDNotificationAPIServerErrorDidOccur: This notification comes with the corresponding MDFault object, ready to be handled. Fault codes are listed in MDConstants.h.

kMDNotificationUserDidLogout: This notification is used to forward the app to the login screen. This notification is thrown when the user logs out, or when API session is over because of an error or session timeout.

Note: More notifications are defined in MDConstants.h.

### A few more things the Sample App covers...

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
