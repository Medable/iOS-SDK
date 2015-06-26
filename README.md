About the Medable SDK
======

Welcome to the iOS Client SDK for [Medable](https://www.medable.com). This library provides a wrapper for the [Medable API](https://dev.medable.com/) as well as several helper tools to directly integrate those features to your iOS application.

The Medable iOS SDK is targeted to be used in apps that have a base SDK of iOS 7 and the following instructions are targeted for Xcode 6 users, consider updating if you have an older version.

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

### Linker

Add a linker flag (-ObjC), this allows you to use class extensions provided by our framework.

+ In XCode, click in your project’s root, select ‘Build Settings’ tab on the right, and search for ‘other linker flags’.
+ Double click on the right side of it.
+ Press the plus button.
+ And write ‘-Objc’, without the quotes.

Also, be sure to include the following system frameworks:

+ ImageIO.framework
+ SystemConfiguration.framework
+ CoreText.framework
+ MobileCoreServices.framework
+ QuartzCore.framework
+ CoreLocation.framework
+ CFNetwork.framework
+ CoreGraphics.framework

Swift
-----

The Medable is written in Objective-C but using it from your Swift application is pretty straightforward. Just add a bridging header to your app target:

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

    let client = MDAPIClient.sharedClient()

**Warning:** *There is currently no nullability annotations in the public Objective-C headers. This means that Swift will import your declarations as implicitly unwrapped optionals: `Type!`.*

This means that using explicit non optional types will be allowed at compilation time but might crash your app (with an `EXC_BAD_INSTRUCTION` exception). See for instance this code:

    client.getOrgInfoWithCallback { ( org: MDOrg!, fault: MDFault!) -> Void in

        self.status?.text = "Error"
    
        var alert : UIKit.UIAlertController = UIAlertController()
        alert.title = "Error"
        alert.message = fault.message

The fault object itself is optional, but since the Objective-C code isn't annotated for nullability, this is not explicitly stated and the compiler allows the developer to use non optional types.

**Solution: Use optional types.**

Using optional types explicitly will force the compiler to check your usage for you:


    client.getOrgInfoWithCallback { ( org: MDOrg?, fault: MDFault?) -> Void in

        self.status?.text = "Error"
            
        var alert : UIKit.UIAlertController = UIAlertController()
        alert.title = "Error"
        alert.message = fault.message

This will issue an error due to the use of an unwrapped optional and force you to write the corresponding wrappers.

*As a general rule of thumb, assume values will be nullable.*

Integration
------

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

### Download new content from the server

The REST API includes a Bundle API that enables orgs to store versioned, localized, often-changing string tables and property lists. Using MDContentDownloader as shown in the sample app, you can check for new content on application startup. There are two notifications indicating the beginning and end of the content download so you can give visual feedback, if needed.

Optional Integration Steps
------
### Set log level
```objective-c
// Setup network calls. Log to console in debug builds.
[MDAPIClient sharedClient].loggerLevel = MDAPIClientNetworkLoggerLevelInfo;

// If not set, the default loggerLevel is MDAPIClientNetworkLoggerLevelDebug.
```

### Handling particular events by listening to notifications.

kMDNotificationAPIServerErrorDidOccur: This notification comes with the corresponding MDFault object, ready to be handled. Fault codes are listed in MDConstants.h.

kMDNotificationUserDidLogout: This notification is used to forward the app to the login screen. This notification is thrown when the user logs out, or when API session is over because of an error or session timeout.

Note: More notifications are defined in MDConstants.h.


Example use cases - going beyond simple API calls
------
The following use cases reference many Medable objects. Please refer to the <a href="https://dev.medable.com/#objects" target="_blank">API documentation</a> for more information on Medable objects and their properties.

### How do I get the images (attachments) for a <a href="https://dev.medable.com/#conversation-attachments-property" target="_blank">conversation</a>?
```objective-c
[aConversation
 imagesWithCallback:^(NSString* imageId, UIImage *image)
 {
     if (image)
     {
         dispatch_async(dispatch_get_main_queue(), ^{
			// Set image to UI object
         });
     }
 }];
```
### How do I get the thumbnail of an <a href="https://dev.medable.com/#account-image-property" target="_blank">account</a>?
```objective-c
[anAccount thumbnailWithCallback:^(UIImage *image, MDFault *fault)
{
     if (image)
     {
         dispatch_async(dispatch_get_main_queue(), ^{
			// Set image to UI object
         });
     }
}];
```

### How do I get the account thumbnail for the creator of a <a href="https://dev.medable.com/#connection-creator-property" target="_blank">connection</a>?
```objective-c
[aConnection thumbnailWithCallback:^(UIImage *image, MDFault *fault)
{
     if (image)
     {
         dispatch_async(dispatch_get_main_queue(), ^{
			// Set image to UI object
         });
     }
}];
```

### How do I use the synchronize methods?

All objects have three synchronize methods that receive parameters such as includes, expands, paths filters, etc --
one for the object itself, one for posts, and one for connections. The reason for three methods instead of one is that each uses the base route to each resourse, providing for more access, and more options for the parameter inputs.

A conversation expanding its patientFile property:
```objective-c
[aConversation synchronizeObjectWithParameters:[MDAPIParameterFactory parametersWithExpandPaths:@[ kPatientFileKey ]]
                                      callback:^(id object, MDFault *fault)
{

}];
```
An account expanding account.connections.context:
```objective-c
[anAccount
 synchronizeConnectionsWithParameters:[MDAPIParameterFactory parametersWithExpandPaths:@[ kContextKey ]]
 callback:^(MDAccount* updatedAccount, MDFault *fault)
 {

 }];
```

An account with its posts:
```objective-c
[anAccount
 synchronizePostsWithParameters:nil
 callback:^(MDAccount* updatedAccount, MDFault *fault)
 {

 }];
```

### How do I use the asset manager to encrypt and cache media?
```objective-c
UIImage* imageToSave;
NSData* imageData = UIImageJPEGRepresentation(imageToSave, 1.0f);
NSString* fileName = @"aGoodFileNameHere";

[[MDAssetManager sharedManager]
 saveData:imageData
 fileName:fileName
 finishBlock:^{
     
 }];
```
That image is saved in an encrypted cache on disk, which works on a per user basis and is encrypted with a different key for different users. Those keys change when the account's password is changed, as explained in the API documentation.

### How do I use the SDK to manage <a href="https://dev.medable.com/#custom-objects" target="_blank">custom objects</a>?
```objective-c
// Let's suppose you have a custom object named 'c_aCustomObject', with a string property called 'c_aCustomProp1' and a number property called 'c_aCustomProp2'
// in addition to the base properties, inherited from MDObjectInstance, which is the base class for all objects.

// Get its definition
MDObjectDefinition* aCustomObjectDefinition = [[MDSchemaManager sharedInstance] objectWithName:@"c_aCustomObject"];

// You could get all of its custom property definitions like this:
NSArray* customProperties = [aCustomObjectDefinition customProperties];

// Or you could get the properties definitions by name, like this:
MDPropertyDefinition* aCustomProp1Definition = [aCustomObjectDefinition propertyWithName:@"c_aCustomProp1"];
MDPropertyDefinition* aCustomProp2Definition = [aCustomObjectDefinition propertyWithName:@"c_aCustomProp2"];

// From there you could check what type of primitive each property is
MDPropertyType type1 = aCustomProp1Definition.type;      // That type would be MDPropertyTypeString
MDPropertyType type2 = aCustomProp2Definition.type;      // That type would be MDPropertyTypeNumber

// Also, you can check if that object has a feed definition, and access all the post types it supports, each post's segments, comment definitions, etc
// Starting from here:
MDFeedDefinition* aCustomObjectFeedDefinition = [aCustomObjectDefinition feedDefinition];

// We could get all the posts' definitions for the posts its feed accepts
NSArray* postDefinitions = [aCustomObjectFeedDefinition postDefinitions];

// That would be an array of these objects:
MDPostDefinition* postDefinition = [postDefinitions firstObject];

// Let's check the different segments this type of post has
NSArray* postSegments = [postDefinition body];

MDPostSegmentDefinition* aPostSegmentDefinition = [postSegments firstObject];

// And the different comments' definitions for this particular type of post.
// Notice that the comments definitions are also segment defintions, since they share the same structure.
NSArray* comments = [postDefinition comments];
MDPostSegmentDefinition* commentDefinition = [comments firstObject];

// Ok, enough of structure for now. That's the definition world. Then we have the instances world. That is, object instances with all those
// definitions. Let's say we want to modify an instance of this custom object of type 'c_aCustomObject'.
MDObjectInstance* aCustomObjectInstance;

NSDictionary* body = @{ aCustomProp1Definition.name: @"a string value for prop 1",
                        aCustomProp2Definition.name: @(7) };

[[MDAPIClient sharedClient]
 editObject:aCustomObjectInstance
 withBody:body
 callback:^(MDObjectInstance *object, MDFault *fault)
 {
     if (!fault)
     {
         // You did great, and successfully modded the instance.
     }
 }];

// As you see, you can get any information you need form an object, either custom or not, by accessing its definitions' reference properties.
```

### How do I post to a feed?

##### References
- [File](https://dev.medable.com/?objective_c#files)
- [Post](https://dev.medable.com/?objective_c#posts)

##### Sample code
```objective-c

/*
   - In this case, let's suppose we have an object whose feed definition consists of posts of type "c_post".
   - Each "c_post" has two body segments called "c_text" --of type String, and "c_image" --of type File[], that is, an array of File objects.
   - Each File object is composed by four facets, called "c_original", "c_overlay", "c_thumbnail" and "c_content".
   - There are two facet processors, that take "c_original" and "c_overlay" as inputs and produce "c_content" --the original image with the overlay included, and "c_thumbnail" --a reduced version of "c_content".
*/

// Let's create a post with a message saying "Hi, this is a post with text and images", and two images, one with overlay and one without overlay.

// The context object
MDObjectInstance *contextObject;

// Message
NSString *text = @"Hi, this is a post with text and images";
    
// Images
// faceImage is the UIImage with the picture of the patient's face
// chestImage is the UIImage with the picture of the patient's chest
// faceOverlay is the UIImage with the transparent overlay to cover the patient's face
UIImage *faceImage;
UIImage *faceOverlay;
UIImage *chestImage;

// Prepare the body segments
NSMutableArray *postSegments = [NSMutableArray new];

// Get the object's feed definition
MDFeedDefinition *feedDefinition = contextObject.object.feedDefinition;

// Get the post's definition
MDPostDefinition *postDefinition = [feedDefinition postDefinitionWithType:@"c_post"];

for (MDPostSegmentDefinition *segmentDefinition in postDefinition.body)
{
    // Configure the Text segment
    if ([segmentDefinition.name isEqualToString:@"c_text"] &&
        [text length])
    {
        MDCallingPostSegment *textSegment = [MDCallingPostSegment new];
        textSegment.postName = segmentDefinition.name;
        
        // Get the post segment property definition
        [postSegment addProperty:@"c_text" withValue:text];
        
        // Add the post body's text segment
        [postSegments addObject:[textSegment apiFormat]];
    }
    
    // Configure the Image segment
    else if ([segmentDefinition.name isEqualToString:@"c_image"])
    {
        // Get the post segment property's definition
        MDPostSegmentPropertyDefinition *propertyDefinition = [segmentDefinition propertyWithName:@"c_image"];
        
        MDCallingPostSegment *imagesSegment = [MDCallingPostSegment new];
        imagesSegment.postName = segmentDefinition.name;
        
        // It's an array of Files... In this case, we have 2
        NSMutableArray* files = [[NSMutableArray alloc] initWithCapacity:2];

        MDFileParameterValue* faceWithOverlayFile = [MDFileParameterValue new];
        [faceWithOverlayFile addImage:faceImage forFacetNamed:@"c_original" inProperty:propertyDefinition];
        [faceWithOverlayFile addImage:overlay forFacetNamed:@"c_overlay" inProperty:propertyDefinition];

        MDFileParameterValue* chestWOOverlayFile = [MDFileParameterValue new];
        [chestWOOverlayFile addImage:chestImage forFacetNamed:@"c_original" inProperty:propertyDefinition];
            
        [files addObject:faceWithOverlayFile];
        [files addObject:chestWOOverlayFile];
        
        [imagesSegment addProperty:@"c_image" withValue:files];

        [postSegments addObject:[imagesSegment apiFormat]];
    }
}

[[MDAPIClient sharedClient]
 postToObject:[contextObject.object pluralNameForAPICalls]
 objectId:contextObject.Id
 postType:@"c_post"
 bodySegments:postSegments
 targets:nil
 voted:nil
 finishBlock:^(MDPost *post, MDFault *fault)
 {
     if (fault)
     {
            // Fault handling
     }
 }];
```

### Why can't I mod an object instance? why is that there are no setters?

All the modifications need to go through the api, and then you need to synchronize your object instance. This is to make it easier to avoid inconsistences between the client and the api.
That’s why all the modifications are done through MDAPIClient object modification methods.
