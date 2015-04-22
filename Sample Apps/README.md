About the Sample Apps
======

Both these applications cover basic setup of the Medable SDK only, used from within an iOS application (in Swift and Objective-C flavors).

The setup was performed by these steps:

1. Create a new application project (Single view application).
2. Add a Podfile specifying the dependency on the Medable SDK.
3. Run `pod install`.
4. Open the generated Workspace.
5. Add some sample code to the view controller.
6. In the Swift version, add an Objective-C Bridging Header by following the Swift setup from the Readme.

Provision Your Organization
=======

For these samples to work, you must provision your own Organization within the system.

Head over to our [Signup Page](https://signup.medable.com) and fill in your Organization's data or contact us by filling the contact form.

After you have provisioned your Organization, replace the values in the project's `Environments.plist` file with yours.

**Note:** The `Configuration` key in the project's `Info.plist` file points to one of the environments in your `Environments.plist` file, make sure you fill that one first for testing purposes.

License
=======

Sample code and the Medable SDK library are available under the BSD 3-Clause license. See the root LICENSE file for more info.