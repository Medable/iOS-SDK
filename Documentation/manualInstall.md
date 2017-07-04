Manual iOS SDK Installation
====

[Download the latest version](https://github.com/Medable/iOS-SDK/tree/master/iOSMedableSDK/Medable.framework) and place it wherever you like inside your project structure.

##### Now let’s link your project against the framework

+ In XCode, click in your project’s root, select ‘General’ tab on the right, and scroll up until you see the ‘Linked Frameworks and Libraries’ section.
+ Press the plus button.
+ Select ‘Add other…’, browse to where you put the framework, select it and click ‘Open’.
+ Now hit build and check everything goes well. 
+ Good!, now you have your project linked to Medable.framework.

##### Now let’s link your project against required frameworks

Enable Core Location services

+ In XCode, click in your project’s root, select ‘General’ tab on the right, and scroll up until you see the ‘Linked Frameworks and Libraries’ section.
+ Press the plus button.
+ Search and add CoreLocation.framework.
+ Add an entry to your app's info.plist file with this key NSLocationWhenInUseUsageDescription. The value you use for this is the message users will be presented when asking for permission to use location services.
+ Now hit build and check everything goes well.

### Linker

Add a linker flag (-ObjC), this allows you to use class extensions provided by our framework.

+ In XCode, click in your project’s root, select ‘Build Settings’ tab on the right, and search for ‘other linker flags’.
+ Double click on the right side of it.
+ Press the plus button.
+ And write `-ObjC`.
