## Cortex iOS

#### v1.8.8

- Base Instance - Custom property parsers - Return nil if property is not present.
- Parameter Factory - Fix for merging sort and where parameters.

---

#### v1.8.7

- Adds convenience initializer for creating instances of MDBody, MDFastBodyProperty.
- Improvements to MDFileBodyProperty.
- Adds faster ways for adding File attachments to MDBody (POST body) objects using the new MDFastFileBodyProperty.
- Adds a NSData extension to extract the mime type from an instance by analyzing its file signature (not all mime types are supported).
- Adds a pendingUploads getter for MDFilePropertyValue.
- Adds a method to add NSData to the local assets cache through its corresponding MDFacet.
- Fixes cache bug on create/update objects.
- MDBaseInstance - Adds a method to get the value (Medable Primitive) of a property inside a "path" (Document inner properties).
- MDPaginationHelper - Changed the way the pagination helper builds the query parameters. Adapted to API v2.9.8's new format.

---

#### v1.8.6

- MDAPIClient - Fixed typo in method signature: `registerContext:pluralContext:type:withClass:`.

---

#### v1.8.5

- MDAPIClient - Added support for getting a list of objects from a path.
- MDPaginationHelper - Added a paginator that paginates a list of objects in a path. Improved docs. Fixed a cacheResults bug.
- MDPaginationManager - Added constructor for a paginator that paginates a list of objects in a path. Improved docs.

---

#### v1.8.4

- MDPaginationManager - Thread safe.

---

#### v1.8.3

- MDPaginationManager - Improvements.
- MDPaginationHelper - Improvements.

---

#### v1.8.2

- MDPaginationManager - Improvements.
- MDPaginationHelper - Improvements.

---

#### v1.8.1

- API Client - Custom context/class registration - added support for paginating subclasses.
Paginator helper - added support for paginating subclasses.
- API Client - Support for getting List properties.
- MDPaginationHelper - Added support for list property pagination. Added convenience initializers. Removed type parameter since that's not needed here. Improvements.
- MDPaginationManager - Added a pagination manager to handle pagination helper instances, and make pagination handling easier.

---

#### v1.8.0

- Better custom class support: Added a way to register/map context with classes. This way the APIClient is able to return instances of custom classes/objects (subclasses of MDObjectInstance) for when using bundled routes.
- New paginator helper class. More flexible and uses recommended pagination query parameters.
- Added nullability annotations for better Swift translation / code auto-completion.
- Added deprecated annotations for unavailable init/new methods.
- MDBaseInstance - Adds convenience method to get the value of an array property.
- MDLocalFault - Exposed factory method, so devs are able to create custom local faults without having to subclass.
- MDOrg - Bugfix: the property is called "configuration" and the constant is "Configuration".
- MDGeneralBlocks - Added typedefs for List block callbacks for better Swift translation and code auto-completion.
- Removed Legal Agreement classes (deprecaded). Also removed old methods from MDBundle.
- MDObjectId - added ObjectId validation.
- MDAPIParameterFactory - Added nullability annotations and changed NSString to NSObject for gt/gte/eq... parameters.
- README.md - Removed unneeded integration steps (for the manual integration way).
- Sample apps - Swift sample app - Updated swift syntax to latest swift.

---
