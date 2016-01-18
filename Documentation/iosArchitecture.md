Architecture of the iOS SDK
====

The iOS SDK was developed with a few governing principles:

- Simplicity: strive to simplify the work of the app developer.
- Predictability, or Principle of Least Astonishment in code: the developer should know how to do things, regardless of whether they have done it in the past.
- Completeness: there are helper methods for the entire [Medable API](https://dev.medable.com) if there is a chance it will be needed for a mobile app.
- Extensibility: since the API evolves at a rapid pace, allow the inclusion of extra parameters of any form. This means that most new API features can be leveraged from an SDK that hasn't yet caught up with the backend API.
- Bonus: whenever possible, develop helper classes that solve common problems that app developers might encounter (e.g. string to date conversions, encrypted storage, value type checking, etc...).
- Empowerment: control of code being executed is still in the developer's hands. The iOS SDK does not perfom background tasks the app code hasn't started.

Following these principles you'll notice a few rules that appy to our Mobile SDK.

Data Synchronization
----

The iOS Medable SDK features an On-Demand Synchronous Client-Server structure when it comes to data synchronization. To understand what this means, read up on the [objc.io magazine on Data Synchronization](http://www.objc.io/issues/10-syncing-data/data-synchronization/).

Essentially this can be broken down into the following rules:

- Only metadata is downloaded preemptively, so this means the lightweight `*Definition` classes (e.g. `MDObjectDefinition` see the [Medable iOS SDK Reference](http://cocoadocs.org/docsets/Medable/)) but not the actual object instances.
- The SDK does not perform any data mirroring. There is no local DB mirroring data, when you download something via the library, the SDK only retains the returned objects in memory to hand them to the caller, but not longer than that.
- The memory data objects are inmutable, you can't modify them and have those changes reflected in the backend. To accomplish this, call the corresponding update method instead and use its result.

