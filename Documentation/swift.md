A note about Swift and the Medable SDK
====

The Medable SDK is written in Objective-C but using it from your Swift application is pretty straightforward. Just add a bridging header to your app target:

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

**Warning:** *There is currently no nullability annotations in the public Objective-C headers. This means that Swift will import your declarations as implicitly unwrapped optionals: `Type!`. Except in  MDAPIClient's header, which has such annotations.*

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