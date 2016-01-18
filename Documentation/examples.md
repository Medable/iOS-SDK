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

[[Medable client]
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

[[Medable client]
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