Modifying your Account
====

As a preamble, read up on the [API Documentation on Update Account](https://dev.medable.com/#update-an-account).

Because this is a modification call, there is no required field in the API call, so essentially you can update whatever field you want.

The following code

```objective-c
MDProfileInfo* profileInfo = [MDProfileInfo profileInfoWithSpecialty:@"Vascular Surgery"
                                                         affiliation:nil
                                                                 npi:@"7878766774"
                                                        licenseState:nil
                                                       licenseNumber:nil];

MDAccount *currentUser = [MDAPIClient sharedClient].currentUser;

[[MDAPIClient sharedClient]
 updateAccountWithID:currentUser.Id
 firstName:nil
 lastName:nil
 gender:nil
 mobile:nil
 dob:nil
 profileInfo:profileInfo
 favorite:nil
 preferences:nil
 image:nil
 customPropValues:nil
 finishBlock:^(MDAccount *account, MDFault *fault)
 {
     if (fault)
     {
         // Fault handling
     }
     else
     {
         // All good
     }
 }];
```

You'll notice there is a `customPropValues` parameter. This is the first of its type in the tutorial series and an important one to keep in mind.

As you might remember from the [Configure your Data Model](dataModel.md) tutorial, you can create custom objects with as many custom properties as you'd like and you can extend base objects as if they were custom objects too.

So, following a previous example, if you have extended the `Account` base object to include a property called "Allergies" that has a name `c_allergies` and type `[String]` (a.k.a String[] depending on your choice of syntax). Then you may pass a dictionary here with a mapping of `c_allergies` to an `NSArray` containing `NSString` instances.

Imagine you've written an allergies selection screen for your user and are updating their account with this information, the code would look something like this:

```objective-c
MDAccount *currentUser = [MDAPIClient sharedClient].currentUser;

NSArray *allergies = @[ @"starch", @"pollen"];
NSDictionary *customProperties = 
	@{
		@"c_allergies" = allergies
	};

[[MDAPIClient sharedClient]
 updateAccountWithID:currentUser.Id
 firstName:nil
 lastName:nil
 gender:nil
 mobile:nil
 dob:nil
 profileInfo:nil
 favorite:nil
 preferences:nil
 image:nil
 customPropValues:customProperties
 finishBlock:^(MDAccount *account, MDFault *fault)
 {
     if (fault)
     {
         // Fault handling
     }
     else
     {
         // All good
     }
 }];
```

Next up we'll be [Creating an Object Instance](creatingObjects.md). That is, an instance of a custom object defined in your data model.
