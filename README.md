About the Medable SDK
======

Welcome to the iOS Client SDK for [Medable](https://www.medable.com). This library provides a wrapper for the [Medable API](https://dev.medable.com/) as well as several helper tools to directly integrate those features to your iOS application.

The Medable iOS SDK is targeted to be used in apps that have a base SDK of iOS 7 and the following instructions are targeted for Xcode 6 users, consider updating if you have an older version.

Installation
======

Using CocoaPods
------

#### Step 1: Download CocoaPods

[CocoaPods](http://cocoapods.org) is a dependency manager for Objective-C, which automates and simplifies the process of using 3rd-party libraries like Medable in your projects.

CocoaPods is distributed as a ruby gem, and is installed by running the following commands in your Terminal:

    $ sudo gem install cocoapods
    $ pod setup

> Depending on your Ruby installation, you may have to run as `sudo` to install the CocoaPods gem.

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

Manual Installation
------

Follow the [Manual Installation Guide](Documentation/manualInstall.md) for instructions on how to install the Medable iOS SDK manually.

Swift
-----

The Medable SDK is written in Objective-C but using it from your Swift application is straightforward. Just add a bridging header to your app target:

    //
    //  MedableSwift-Bridging-Header.h
    //  MedableSwift
    //
    //  Copyright (c) 2015 Medable Inc. All rights reserved.
    //

    #import <Medable/Medable.h>

Make sure your Build Settings for the app target specify the bridging header (the entry is called `Objective-C Bridging Header`):

    //:configuration = Debug
    SWIFT_OBJC_BRIDGING_HEADER = MedableSwift/MedableSwift-Bridging-Header.h
    
    //:configuration = Release
    SWIFT_OBJC_BRIDGING_HEADER = MedableSwift/MedableSwift-Bridging-Header.h

Finally, you can use Medable classes directly:

    let client = Medable.client()

Integration
=====

Configuring the Client
------

You need to provide a Medable Client Key and your Organization name to the SDK. The simplest way to do this is to add an entry to your app's ```plist``` file with this information.

Here is a template of that format:

```
"Medable" : 
{
    "ClientKey": "SomeObscureString",
    "Organization": "theclinic"
}
```

The next figure shows how this would look when viewing the main ```.plist``` file:

![Medable Entry](Documentation/png/dictionaryEntry.png)

Other optional entries in the "Medable" dictionary include:

- ```"url"```: Base URL of the medable backend, the default is ```"medable.com"```.
- ```"Protocol"```: HTTP protocol used to communicate with the backend, the default is ```"https"```.
- ```"APIPrefix"```: API Prefix of the backend, the default is ```"api"```.

It's possible to also define different environments for different build configurations (Debug, Release, etc) and even define your custom configurations. For a walkthrough of those steps, follow the [Advanced Integration Steps Guide](Documentation/integrationSteps.md).


Optional Integration Steps
------

### Start the Organization Content Download process along with your app

It's not required, but is a good idea anyway, to initialize the Medable SDK in your app delegate, to do so just place this line in your app delegate:

```objective-c
[Medable start];
```

You may also wish to register for notifications about that download process. To do so, check the [Advanced Integration Steps Guide](Documentation/integrationSteps.md) for further instructions.

The reason this is a good idea is that Medable will be required to download your Organization's data before it can make other HTTP requests, if you don't initialize the SDK, this will happen when you make your first request, delaying it marginally.

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

Getting Started
======

You can access the Medable iOS SDK API at [Cocoadocs](http://cocoadocs.org/docsets/Medable). The main API class is `MDAPIClient` which you can access by getting the shared client using this line:

```objective-c
MDAPIClient *medableAPI = [Medable client];
```

From there, check the SDK API, the examples or tutorials to accomplish specific things.

Examples
------

Check out the [Code Samples](Documentation/examples.md) for a few examples on how to get some specific things done with the Medable SDK.

Tutorials
------

Check out the [Tutorials](Documentation/tutorial.md)

FAQ
------

Some common questions and answers can be found in the [FAQ](Documentation/faq.md).
