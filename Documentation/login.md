Creating Registration and Login modules
====

As a preamble, read the [API Documentation on Authentication](https://dev.medable.com/#authentication). In there you'll find extensive information about how sessions have to be managed to interact with the Medable API.

In this document we'll describe how to write a Registration, Login and Password Reset forms.

Registering
----

If you want a little preliminary information, read the [Register an Account](https://dev.medable.com/#register-an-account) endpoint information from the Medable API Documentation.

To register a user, you'll have to get this information from the user:

- Email.
- Name.
- Phone Number.

Also this next list of common information is usually provided:

- Password.
- Date of Birth.
- Gender.
- Avatar, or Account Profile Image.
- Role (e.g. pass the provider role for care providers).

For the full list, always refer to the API Documentation.

The iOS SDK code to register an account follows this format:

```objective-c
	[[Medable client]
  		registerAccountWithFirstName:@"Charles"
  		lastName:@"Best"
  		email:@"charles.best@example.org"
  		mobile:@"1-650-555-5555"
  		password:@"Thanks for the break, Banting!"
  		gender:@"m"
  		dob:[MDDateUtilities dateFromString:@"1899-02-27"]
  		role:nil
  		profileInfo:nil
  		thumbImage:nil
  		callback:^(MDAccount* account, MDFault *fault)
  		{
      		if ( fault != nil)
      		{
          		// Handle the error (e.g. show alert with fault.message)
      		}
      		else
      		{
          		// Check whether activation is required before authentication
          		BOOL requiresActivation = [account activationRequired] ? [[account activationRequired] boolValue] : NO;

          		// Handle the case when requiresActivation == YES here
      		}
  		}
  	];
```

Password Reset
----

For preliminary information, read the [Request a Password Reset API](https://dev.medable.com/#request-a-password-reset).

To request a password reset email, your app needs only to gather the Email of where it will be sent.

```objective-c
	[[Medable client]
 	 requestPasswordResetWithEmail:@"charles.best@medable.com"
 	 callback:^(MDFault* fault)
 		{
     		if (fault)
     		{
         		// Fault handling
     		}
     		else
     		{
     			// No fault
     		}
 		}];
```

Login
----

For more information, read the [Sign In API Documentation](https://dev.medable.com/#sign-in).

To sign in, you'll need to write a login form and provide at least the following information:

- Email.
- Password.

As always, for optional data always refer to the API documentation as there are optional parameters not listed here.

The SDK code required for a simple sign in is:

```objective-c
[[Medable client]
 authenticateSessionWithEmail:@"james@example.com"
 password:@"this is not my passphrase"
 verificationToken:nil
 singleUse:NO
 callback:^(MDAccount *localUser, MDFault *fault)
 {
     if ( localUser != nil )
     {

     }
     else if ( fault != nil )
     {
        if ([fault.code isEqual:kMDAPIErrorNewLocation] ||
             [fault.code isEqual:kMDAPIErrorUnverifiedLocation])
        {
            // Device verification handling
        }
        else
        {
			// Other faults handling
        }
     }
 }];
```

In case your Organization has enabled location verification and this user is using this device (location) for the first time then the response will have one of the two listed location verification errors. The user will receive an SMS text message to the phone number they used when registering with Medable which in turn should be passed in a consecutive authenticate call, like this:

```objective-c
[[Medable client]
 authenticateSessionWithEmail:@"james@example.com"
 password:@"this is not my passphrase"
 verificationToken:@"123123" //This was received via SMS to the phone
 singleUse:NO
 callback:^(MDAccount *localUser, MDFault *fault)
 {
     if ( localUser != nil )
     {

     }
     else
     {
         if (fault)
         {
            // Fault handling
         }
     }
 }];
```

After you have completed this, continue with [Modifying your Account tutorial](modifyAccount.md).