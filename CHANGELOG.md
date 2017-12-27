## Cortex iOS

#### v1.9.15

- `MDUploadOperations`
   - Failed upload operations contain the associated `NSError` through the `responseError` property.
- Bug fixes and improvements.

#### v1.9.14

- `MDFileUpload`
   - Added serialization/deserialization support.

#### v1.9.13

- Bug fixes and improvements.

#### v1.9.12

- `NSData+Mime`: Added support for mimeExtension. Better mime detection.
- `MDFileBodyProperty`: Added a method without mime, where mime detection is used.

#### v1.9.11

- `MDAPIClient`
   - Added support for custom HTTP headers.
- `Facet` - Renamed 'filename' to 'cacheFilename' which was the generated file name used for the local cache, and added the real Facet 'filename' property.
- Bug fixes and improvements.

#### v1.9.10

- `MDAPIClient` - Added support for Medable Faults in HTTP 200 responses. Cortex will call fault callbacks in these cases.

#### v1.9.9

- Bug fixes and improvements.
- `MDAssetManager` - Now supports caching of non-sensitive data in a non-encrypted cache for when there is no active session, that is, there is no logged in user.
- `NSFileManager+Medable` - Added more helper methods to store non-encrypted data. However, if you want those to be cached by `MDAssetManager`, store the data through it.
- `MDFacet` - Improvements and bug fixes on caching data.

#### v1.9.8

- Bug fixes and improvements.

#### v1.9.7

- `MDAPIClient` 
   - `downloadFileAtPath` - Support for other than images.
   - Don't compress jpeg images before uploading.
   - Better documentation.
- `MDUploadOperation` 
   - Added refresh upload headers mechanism --this is automatic.
   - Better documentation. 
   - Added annotations to avoid instance creation.
- `MDFileUpload` 
   - Added nullability annotations. 
   - Better documentation.
- `MDAPIParameters` 
   - Added basic support for pipelines.
   - Improvements.
   - Marked some factory methods as deprecated. Will be removed in a future version.
- `MDAttachmentMaps` 
   - Marked as deprecated. 
- `MDImageOverlayPair` 
   - Marked as deprecated.
- `MDFileBodyProperty` 
   - Return the generated file name to be able to map the upload with the notifications from `MDUploadOperations`.
- `MDFilePropertyValue` 
   - Better typing for array properties.
- `MDFacet` 
   - Added nullability annotations. Changed the type of isPrivate from `BOOL` to `NSNumber`. Better documentation. 
- `MDFilePropertyValue` 
   - Better typing for array properties. Added nullability annotations. Fixed documentation. 
- `MDBodyProperty` 
   - Added convenience initializer.

---

#### v1.9.6

- `MDAPIClient` - Added support for custom login routes, and custom login with optional HTTP headers.
- `MDFault` - Better support for parsing XML errors coming from the server.

---

#### v1.9.5

- `MDAPIParameterFactory` 
    - Added support for adding parameters from an array of parameters (Improving Swift support).
    - Added ordered sort support for complex sort queries.
    - `parametersWithSort` - marked as deprecated.
- Bug fixes and improvements.

---

#### v1.9.4

- `MDAPIClient` - File uploads for the `NSDictionary` approach of create/updateObject methods are now more flexible. Full documentation [here](https://docs.medable.com/docs/code-samples#section-file-upload).
- `MDSchemaManager`:
   - Contexts can be queried by singular and plural name. 
   - Deprecated `objectwithPluralName:`. 
   - Optimized search context. 
   - Optimized schemas disk storage. 
- `MDBaseInstance` - synchronizeObject - made parameters and callback optional.
- `MDObjectInstance` - `synchronizePosts` / `synchronizeConnections` - made parameters and callback optional parameters. 
- `MDObjectInstance` - `synchronizePosts` - marked as deprecated.

---

#### v1.9.3

- `MDAPIClient`
   - Removed "startLocationServices" since it's not used internally.
   - Updated methods documentation. Marked deprecated methods.
- `MDSerialization` - Added this class to serialize/deserialize data.
- `MDDateUtilities` - Exposed the internal date formatter so the time zone can be changed. - **Note:** It is not used anymore to serialize/deserialize dates within: `MDAPIClient`, `MDAccount`, `MDOrg`, or custom object classes. - Default time zone is local time zone.
- Marked old base objects as deprecated.
- Bug fixes and improvements.

---

#### v1.9.2

- `MDUploadOperations` - Improved return types of methods for better Swift translation.
- `MDAPIClient`
   - routeWithComponents - updated doc.
   - Added login method, marked the less intuitive authenticateSession as deprecated.
- Documentation - All documentation is now in docs.medable.com.
- `MDDateUtilities` - Fixed typo in constant.

---

#### v1.9.1

- Feed related routes - Marked as deprecated.
- Account - Update route - Added support for modifying the account's time zone.
- MDDateUtilities - Exposed the date format strings.
- MDAPIClient - Registration - Added an optional timeZone to bind the account to.
- Org / Account - Added timeZone property.
- Org header - Better documentation.
- Account - Removed fullName.
- Added a NSDate+TimeZoneChange extension to convert the receiver between time zones.

---

#### v1.8.9

- Updated definition objects.
- Pagination Helper - Improvements.

---

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
