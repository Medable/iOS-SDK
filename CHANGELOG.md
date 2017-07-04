## Cortex

### Change log

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

