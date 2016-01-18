Creating Objects
====

This tutorial covers creating instances of custom objects. To create instance of base objects (Account, Care Conversations, etc.) focus on the individual API calls and their SDK wrappers.

The [API Documentation](https://dev.medable.com) has a thorough list of all API calls and their iOS SDK wrapper counterparts.

Following the Principle of Least Astonishment, values required for the different property types should be predictable. Here is a list of Medable types and the iOS SDK types you must use when passing along the values:

Medable Type | Objective-C | Swift
--- | --- | ---
`String` | `NSString` | `String`
`Number` | `NSNumber` | `Number`
`Bool` | `NSNumber` | `Number`
`Reference` | `NSString` | `String`
`Type[]` | `NSArray` | `[Type]`
`File` | `NSDictionary` | `[String: AnyObject]`
`Any` | `NSDictionary` | `[String: AnyObject]`
`Date` | `NSDate` | `NSDate`
`Document` | `NSDictionary` | `[String: AnyObject]`
`ObjectId` | `NSString` | `String`

A few notes of warning:

- For `Bool`, the `boolValue` call on the `NSNumber` must yield the value you intend to store (e.g. `YES` or `NO` in Objective-C).
- `ObjectId` and `Reference` both expect strings that represent the ID of a valid object.
- A `Document` is itself a recursive structure on the concept of an object and just like an object, it can hold many subproperties. As you would expect, the dictionary you must pass will map the subproperty names to values with the right types, following these same rules.

Creating the calling Body
----

Let's put it all together and create an object labeled `Object`, that has a name of `c_object` (plural `c_objects`).

We'll show three options for doing this, each presenting a tradeoff between the complexity of assembling the body and the explicitness of the approach. Meaning the easier they are to create, the more implicit aspects are hidden from the SDK user. You can use whichever method you prefer.

In both cases, we'll assume this about the `Object` object:

- It has properties named `c_date`, `c_bool`, `c_reference`, `c_number`, `c_document`, `c_string`, `c_any` and `c_stringArray`.
- Types for these properties should be self evident from their names.
- The `c_reference` is a `Reference` to an `Account`.
- The `c_document` property has only two subproperties: `c_stringOne` and `c_stringTwo`, both of type `String`.

### Direct Approach

The fastest way to construct the body of an API call is just to use the iOS SDK primitive type of `NSDictionary`. In it you only have to map property names to their values following the aforementioned mapping of API types to iOS values (e.g. a `String` takes an `NSString` or a `Document` takes an `NSDictionary` in `Objective-C`).

```objective-c
MDAPIClient *client = [Medable client];

NSDictionary *body = 
	@{
		@"c_date" : NSDate.date,
		@"c_bool" : @(YES),
		@"c_reference" : [client.currentUser.Id stringRepresentation],
		@"c_number" : @(42),
		@"c_document" : 
			@{
				@"c_stringOne" : @"String One",
				@"c_stringTwo" : @"String Two",
			},
		@"c_string" : @"String Value",
		@"c_any" : @{ @"c_anyKey" : @"any value"},
		@"c_stringArray" : @[ @"value 1", @"value 2", @"value 3"]
	};
		
[client createObjectWithContext:@"c_objects"
                           body:body
                       callback:^(MDObjectInstance *localObj, MDFault *fault)
       {
             //Callback
       }];
}
```

These two options are identical, but because of the local type checking, the former is recommended.

However, rest assured that the backend won't accept incorrect data. So you are not at risk of corrupting your backend storage, just at risk of making a faulty call.

### Simple Type Checking Approach

```objective-c
MDAPIClient *client = [Medable client];

MDObjectDefinition *object = [[MDSchemaManager sharedInstance] objectWithName:@"c_object"];

NSString *contextName = [object pluralNameForAPICalls];

MDPropertyDefinition *dateProperty = [object propertyWithName:@"c_date"];
MDPropertyDefinition *boolProperty = [object propertyWithName:@"c_bool"];
MDPropertyDefinition *referenceProperty = [object propertyWithName:@"c_reference"];
MDPropertyDefinition *numberProperty = [object propertyWithName:@"c_number"];
MDPropertyDefinition *documentProperty = [object propertyWithName:@"c_document"];
MDPropertyDefinition *stringProperty = [object propertyWithName:@"c_string"];
MDPropertyDefinition *anyProperty = [object propertyWithName:@"c_any"];
MDPropertyDefinition *stringArrayProperty = [object propertyWithName:@"c_stringArray"];

MDCustomClassParameter *body = [MDCustomClassParameter new];

BOOL success = YES;

success = success && [body addValue:NSDate.date forProperty:dateProperty];
success = success && [body addValue:@(YES) forProperty:boolProperty];
success = success && [body addValue:[client.currentUser.Id stringRepresentation] forProperty:referenceProperty];
success = success && [body addValue:@(42) forProperty:numberProperty];
success = success && [body addValue:
	@{
		@"c_stringOne" : @"String One",
		@"c_stringTwo" : @"String Two",
	} 
		forProperty:documentProperty];
success = success && [body addValue:@"String Value" forProperty:stringProperty];
success = success && [body addValue:@{ @"c_anyKey" : @"any value"} forProperty:anyProperty];
success = success && [body addValue:@[ @"value 1", @"value 2", @"value 3"] forProperty:stringArrayProperty];

if ( ! success ) 
{
      // Something went wrong when adding the values
}
else
{
		
       	[clientcreateObjectWithContext:[object pluralNameForApiCalls]
                                  body:body
                              callback:^(MDObjectInstance *localObj, MDFault *fault)
       {
             //Callback
       }];
}
```

### Object Oriented Approach

```objective-c
MDAPIClient *client = [Medable client];

MDObjectDefinition *object = [[MDSchemaManager sharedInstance] objectWithName:@"c_object"];

NSString *contextName = [object pluralNameForAPICalls];

MDPropertyDefinition *dateProperty = [object propertyWithName:@"c_date"];
MDPropertyDefinition *boolProperty = [object propertyWithName:@"c_bool"];
MDPropertyDefinition *referenceProperty = [object propertyWithName:@"c_reference"];
MDPropertyDefinition *numberProperty = [object propertyWithName:@"c_number"];
MDPropertyDefinition *documentProperty = [object propertyWithName:@"c_document"];
MDPropertyDefinition *stringProperty = [object propertyWithName:@"c_string"];
MDPropertyDefinition *anyProperty = [object propertyWithName:@"c_any"];
MDPropertyDefinition *stringArrayProperty = [object propertyWithName:@"c_stringArray"];

MDBody *body = [MDBody new];

MDSimpleBodyProperty *date = [[MDSimpleBodyProperty alloc] initWithPropertyDefinition:dateProperty dateValue:NSDate.date];
[body addProperty:date];

MDSimpleBodyProperty *boolVal = [[MDSimpleBodyProperty alloc] initWithPropertyDefinition:boolProperty boolValue:@(YES)];
[body addProperty:boolVal];

MDSimpleBodyProperty *reference = [[MDSimpleBodyProperty alloc] initWithPropertyDefinition:referenceProperty referenceValue:client.currentUser.creator];
[body addProperty:reference];

MDSimpleBodyProperty *number = [[MDSimpleBodyProperty alloc] initWithPropertyDefinition:numberProperty numberValue:@(42)];
[body addProperty:number];

MDDocumentBodyProperty *document = [[MDDocumentBodyProperty alloc] initWithPropertyDefinition:documentProperty];
MDPropertyDefinition *string1SubProp = [documentProperty subPropertyWithName:@"c_stringOne"];
MDPropertyDefinition *string2SubProp = [documentProperty subPropertyWithName:@"c_stringTwo"];

MDSimpleBodyProperty *stringSub1 = [[MDSimpleBodyProperty alloc] initWithPropertyDefinition:string1SubProp value:@"String One"];
[document addProperty:stringSub1];

MDSimpleBodyProperty *stringSub2 = [[MDSimpleBodyProperty alloc] initWithPropertyDefinition:string2SubProp value:@"String Two"];
[document addProperty:stringSub2];

[body addProperty:document];

MDSimpleBodyProperty *string = [[MDSimpleBodyProperty alloc] initWithPropertyDefinition:stringProperty value:@"String Value"];
[body addProperty:string];

MDArrayBodyProperty *array = [[MDArrayBodyProperty alloc] initWithPropertyDefinition:stringArrayProperty];

MDSimpleBodyProperty *string1 = [[MDSimpleBodyProperty alloc] initWithPropertyDefinition:stringArrayProperty value:@"value 1"];
[array addProperty:string1];
MDSimpleBodyProperty *string2 = [[MDSimpleBodyProperty alloc] initWithPropertyDefinition:stringArrayProperty value:@"value 2"];
[array addProperty:string2];
MDSimpleBodyProperty *string3 = [[MDSimpleBodyProperty alloc] initWithPropertyDefinition:stringArrayProperty value:@"value 3"];
[array addProperty:string3];

[body addProperty:array];

MDFastBodyProperty *any = [MDFastBodyProperty new];
any.content = @"c_anyKey" : @"any value"};

[body addProperty:any];

[clientcreateObjectWithContext:[object pluralNameForApiCalls]
		bodyObject:body
		callback:^(MDObjectInstance *localObj, MDFault *fault)
       		{
             	//Callback
       		}];
```

Files
---

`File` values are a special case and a separation from the API because:

- In the API, to upload a `File` value you pass a string representing the file name you wish to upload.
- The API then returns information about how to upload this file and in a follow up call you upload the multipart data that represents this file.

The iOS SDK does all of this for you. When uploading binary data, your body will contain all the necessary information and will pick a filename for you.

Following the two mentioned ways of creating the calling body, the value of a file property will either be contained in the dictionary that represents your body or it will be an instance of the `MDFileBodyProperty` class in your `MDBody` instance.


### Inside a Dictionary

When using the direct approach, just pass a dictionary mapping facet name strings to `UIImage` instances (if you want to upload an image) or to a dictionary that includes both the mime type and data (`NSData` instance).

- Non image files are allowed as facet values, you just have to pass an `NSDictionary` with the following keys and values:
	- `data`: An `NSData` instance representing the file.
	- `mime`: An `NSString` with the mime type of this file.
- For all of this, you can use the `NSMutableDictionary` alias `MDFileParameterValue`, defined in `MDAPIParameterFactory.h` and all the helpers methods defined below like `addImage:forFacetNamed:inProperty:` or `addData:withMimeType:forFacetNamed:inProperty:`.
- The default mime type for images is `"image/jpeg"` and a compression quality of a 100% is used.

To recap this, let's write it down as a general rule that applies when using the direct approach.

**The value of a `File` property is a `Dictionary` mapping facet names to facet values. A facet value can be an image (which will be uploaded as an `"image/jpeg"`) or a dictionary with keys `data` (an NSData instance) and `mime` (a mime type string).**

Even though these rules are meant to simplify the SDK user's job, nothing is easier than looking at examples.

#### Example

Remember, a single `File` property is composed by facets. A facet is a part of the whole and usually represents a single aspect of the file. Every `File` has a facet named `content`.

Let's imagine an example of a `File[]` property called `c_pictures` that stores an array of `File` values, each of which is a picture of a dermatological problem of the user.

Each `File` value in the array will have the same facets, which are:

- `c_original`: The original picture, only the original creator can read or write this.
- `c_overlay`: A facet accepting only `image/png` with transparency that will be placed on top of the original for the final result.
- `content`: The final composed image.

Now, in order for a value to be accepted into each `File`, at least `content` or `c_original` must be present and `content` can only appear alone as it's considered the final value. When `c_original` and `c_overlay` are present, the `content` facet will bring back the composed image of original+overlay, this happens as a post-processing step on the backend.

Now, if we are creating an object that has this `c_pictures` property, here is how we would assemble the body parameter of this object:

```objective-c
MDCustomClassParameter *body = [MDCustomClassParameter new];

//You could also use addValue:forProperty: if you have c_stringProperty's property definition.
body[@"c_stringProperty"] = @"value of the string property";

NSMutableArray *pictures = [NSMutableArray new];

MDFileParameterValue *pictureOne = [MDFileParameterValue new];
[pictureOne addImage:jpgImageInstance forFacetNamed:kContentKey inProperty:cPicturesPropertyDefinition];

MDFileParameterValue *pictureTwo = [MDFileParameterValue new];
[pictureTwo addImage:secondJpgImageInstance forFacetNamed:@"c_original" inProperty:cPicturesPropertyDefinition];
[pictureTwo addImage:pngImageInstance forFacetNamed:@"c_overlay" inProperty:cPicturesPropertyDefinition];

[pictures addObject:pictureOne];
[pictures addObject:pictureTwo];

//An alternative would be to do: body[@"c_pictures"] = pictures;
BOOL addedPicturesArray = [body addValue:pictures forProperty:cPicturesPropertyDefinition];

if ( ! addedPicturesArray )
{
	//There was a local problem when adding the array of pictures, at least one value didn't pass local validation
	return;
}

MDAPIClient *client = [Medable client];

[client createObjectWithContext:@"c_offices"
     body:body
     callback:^(MDObjectInstance* instance, MDFault *fault)
     {
 	 }];
```

### Object Oriented Approach to Files

Just use the `MDFileBodyProperty` class. It's documentation should be enough to make the operation of the class clear enough but even so consider these rules:

- Initialize the instance with the `File` property definition.
- Add the data for every facet you wish to upload, the parameters for mime type, data and facet name are all required every time.
- Internally the class will now which file names to use and will keep a mapping for posterior uploading to the backend.

#### Example

Let's follow the previous example of a `File[]` property called `c_pictures` that stores an array of `File` values, each of which is a picture of a dermatological problem of the user.

Each `File` value in the array will have the same facets, which are:

- `c_original`: The original picture, only the original creator can read or write this.
- `c_overlay`: A facet accepting only `image/png` with transparency that will be placed on top of the original for the final result.
- `content`: The final composed image.

Now, in order for a value to be accepted into each `File`, at least `content` or `c_original` must be present and `content` can only appear alone as it's considered the final value. When `c_original` and `c_overlay` are present, the `content` facet will bring back the composed image of original+overlay, this happens as a post-processing step on the backend.

Now, if we are creating an object that has this `c_pictures` property, here is how we would assemble the body parameter of this object assuming that `fileArrayProperty` has the `MDPropertyDefinition` for the `c_pictures` property:

```objective-c
MDBody *body = [MDBody new];

MDArrayBodyProperty *array = [[MDArrayBodyProperty alloc] initWithPropertyDefinition:cPicturesPropertyDefinition];

MDFileBodyProperty *pictureOne = [[MDFileBodyProperty alloc] initWithPropertyDefinition:cPicturesPropertyDefinition];
[pictureOne addFacetAttachment:kContentKey
                      mime:kMimeTypeImageJpeg
                      data:UIImageJPEGRepresentation(jpgImageInstance, 1.0)];

MDFileBodyProperty *pictureTwo = [[MDFileBodyProperty alloc] initWithPropertyDefinition:cPicturesPropertyDefinition];
[pictureTwo addFacetAttachment:@"c_original"
                      mime:kMimeTypeImageJpeg
                      data:UIImageJPEGRepresentation(secondJpgImageInstance, 1.0)];

[pictureTwo addFacetAttachment:@"c_overlay"
                      mime:kMimeTypeImagePng
                      data:UIImagePNGRepresentation(pngImageInstance)];

[array addProperty:pictureOne];
[array addProperty:pictureTwo];

[body addProperty:array];

MDAPIClient *client = [Medable client];

[client createObjectWithContext:@"c_offices"
     bodyObject:body
     callback:^(MDObjectInstance* instance, MDFault *fault)
     {
 	 }];
```


Once you have completed this, read about [Managing File Uploads](uploadFiles.md).