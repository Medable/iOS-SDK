Installing the Medable iOS SDK
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

That's it, you are now ready to use the Medable SDK. Head on over to the [Integration](iosIntegration.md) guide to continue your setup.

Install the framework manually
------

[Download the latest version](https://www.medable.com/downloads/ios/sdk/latest) and place it wherever you like inside your project structure.

##### Now let's link your project against the framework

+ In XCode, click in your project's root, select 'General' tab on the right, and scroll up until you see the 'Linked Frameworks and Libraries' section.
+ Press the plus button.
+ Select 'Add other...', browse to where you put the framework, select it and click 'Open'.
+ Now hit build and check everything goes well. 
+ Good!, now you have your project linked to iOSMedableSDK.framework.

##### Now let's link your project against required frameworks

Enable Core Location services

+ In XCode, click in your project's root, select 'General' tab on the right, and scroll up until you see the 'Linked Frameworks and Libraries' section.
+ Press the plus button.
+ Search and add CoreLocation.framework.
+ Add an entry to your app's info.plist file with this key NSLocationWhenInUseUsageDescription. The value you use for this is the message users will be presented when asking for permission to use location services.
+ Now hit build and check everything goes well.

### Linker

Add a linker flag (-ObjC), this allows you to use class extensions provided by our framework.

+ In XCode, click in your project's root, select 'Build Settings' tab on the right, and search for 'other linker flags'.
+ Double click on the right side of it.
+ Press the plus button.
+ And write '-ObjC', without the quotes.

Also, be sure to include the following system frameworks:

+ ImageIO.framework
+ SystemConfiguration.framework
+ CoreText.framework
+ MobileCoreServices.framework
+ QuartzCore.framework
+ CoreLocation.framework
+ CFNetwork.framework
+ CoreGraphics.framework

----

If you are planning to develop in Swift, you might want to consider reading [A note about Swift and the Medable iOS SDK](swift.md).

Now, continue with the [Medable iOS SDK Integration Guide](iosIntegration.md).
