//
//  MDAPIParameterFactory.h
//  Medable
//

//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MDObjectId;
@class MDAccountRole;

#import "MDPropertyDefinition.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Helper class to assemble path strings.
 */
@interface MDAPIPathFactory : NSObject

/**
 * Construct a path string from it's path components.
 *
 * @param pathComponents Array of individual path components.
 * @return The string representing the assembled path.
 */
+ (NSString*)pathStringWithComponents:(NSArray*)pathComponents;


/**
 * Construct a path string from it's path components.
 *
 * @param pathComponent variadic list of components. Requires nil termination.
 * @return The string representing the assembled path.
 */
+ (NSString*)pathWithComponents:(NSString*)pathComponent, ... NS_REQUIRES_NIL_TERMINATION;

// unavailable
+ (instancetype)new NS_UNAVAILABLE;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

@end

/**
 * Represents a collection of API parameters. These can be composed and aggregated on.
 */
@interface MDAPIParameters : NSObject

/**
 * Compose two parameter collections into one. This modifies the recipient object and adds the parameters from the argument.
 *
 * @param parameters The other parameter collection.
 */
- (void)addParameters:(MDAPIParameters*)parameters;
- (void)addParametersWithParameters:(MDAPIParameters*)parameters DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version. Use `addParameters:` instead.");;

/**
 * Add parameters from a dictionary instead of another collection.
 *
 * @param parameters The parameter collection in a dictionary format.
 */
- (void)addParametersWithDictionary:(NSDictionary*)parameters;

/**
 * @returns the current parameters in NSDictionary format.
 */
- (NSDictionary*)apiParameters;

/**
 * @returns the current parameters in NSDictionary format transformed to be used as query parameters
 */
- (NSDictionary*)apiParametersAsQueryValues;
@end

/**
 * Helper class to create all types of possible parameters the API can expect.
 *
 * @see MDAPIParameters
 */
@interface MDAPIParameterFactory : NSObject

/**
 * Combine several parameters into one. Takes a variable argument's list requiring nil termination.
 *
 * @param firstObject Variable argument's list with nil termination.
 * @return An instance with the combination of all parameter collections.
 */
+ (MDAPIParameters*)parametersWithParameters:(MDAPIParameters*)firstObject, ... NS_REQUIRES_NIL_TERMINATION;

/**
 * Combine several parameters into one.
 *
 * @param parameters An array of parameters to combine.
 * @return An instance with the combination of all parameter collections.
 */
+ (MDAPIParameters*)parametersWithParameterArray:(NSArray<MDAPIParameters *> *)parameters;

/**
 * Add custom parameters from a dictionary.
 *
 * @param customParameters The parameters dictionary.
 * @return The instance representing the parameters in the dictionary.
 */
+ (MDAPIParameters*)parametersWithCustomParameters:(NSDictionary*)customParameters;

/**
 * Adding this parameter will filter results by a minimum access level.
 *
 * @param accessLevel The minium access level to filter with.
 * @result The paramter collection containing the minimum access level parameter only.
 */
+ (MDAPIParameters*)parametersWithminimumAccessLevel:(MDACLLevel)accessLevel;

/**
 * Creates a parameter with a list of paths to expand from referenced ids. See each context object for
 * expandable properties. Items are expanded with the caller's access level (Public access is granted).
 *
 * @param paths Array with paths to expand.
 * @param prefixPath String a string path to prefix paths. i.e. prefix.path.to.property.include[]=pathsValues
 * @result The parameter collection containing all the expand paths.
 */
+ (MDAPIParameters*)parametersWithExpandPaths:(NSArray*)paths prefixPath:(nullable NSString*)prefixPath;

/**
 * Creates a parameter with a list of optional paths to include. See each context object for
 * optional properties.
 *
 * @param paths Array with paths to include.
 * @param prefixPath String a string path to prefix paths. i.e. prefix.path.to.property.include[]=pathsValues
 * @result The parameter collection containing all the include paths.
 */
+ (MDAPIParameters*)parametersWithIncludePaths:(NSArray*)paths prefixPath:(nullable NSString*)prefixPath;

/**
 * Creates a parameter with a list of paths you only wish to see returned. See each context object for
 * optional properties.
 *
 * @param paths Array with paths to limit the result to.
 * @param prefixPath String a string path to prefix paths. i.e. prefix.path.to.property.include[]=pathsValues
 * @result The parameter collection containing all the paths limitations.
 */
+ (MDAPIParameters*)parametersWithLimitPaths:(NSArray*)paths prefixPath:(nullable NSString*)prefixPath;;

/**
 * Creates a parameter with a limit on the resulting list.
 *
 * @param count The maximum amount of results. Can be between 1 and 100.
 * @result The parameter collection containing a parameter that will limit the amount of results.
 */
+ (MDAPIParameters*)parametersWithLimitResultsTo:(NSUInteger)count;

/**
 * Creates a parameter with a limit on the resulting list.
 *
 * @param count The maximum amount of results. Can be between 1 and 100.
 * @param prefixPath String a string path to prefix paths. i.e. prefix.path.to.property.limit=
 * @result The parameter collection containing a parameter that will limit the amount of results.
 */
+ (MDAPIParameters*)parametersWithLimitResultsTo:(NSUInteger)count prefixPath:(nullable NSString*)prefixPath;

/**
 * Creates a parameter with a skip count on the resulting list.
 *
 * @param count The amount of results to skip. Useful when getting paginated results.
 * @result The parameter collection containing a parameter that will skip the amount of results.
 */
+ (MDAPIParameters*)parametersWithSkip:(NSUInteger)count;

/**
 * Creates a parameter with a skip count on the resulting list.
 *
 * @param count The amount of results to skip. Useful when getting paginated results.
 * @param prefixPath String a string path to prefix paths. i.e. prefix.path.to.property.skip=
 * @result The parameter collection containing a parameter that will skip the amount of results.
 */
+ (MDAPIParameters*)parametersWithSkip:(NSUInteger)count prefixPath:(nullable NSString*)prefixPath;

/**
 * Sorting parameters.
 *
 * @param sortParams An array of sorting parameters. The array order is preserved. i.e.: [ { "_id": 1, "name": -1 }].
 * @param prefixPath String a string path to prefix paths. i.e. prefix.path.to.property.sort={ sort params here }
 * @result The parameter collection containing a parameter that will sort the results.
 */
+ (MDAPIParameters*)parametersWithOrderedSort:(NSArray<NSDictionary*>*)sortParams prefixPath:(nullable NSString*)prefixPath;

/**
 * Sorting parameters.
 *
 * Note: Building sort parameters with this method doesn't ensure sort parameter order since NSDictionary doesn't ensure key order.
 *          It is recommended to use the `parametersWithOrderedSort:prefixPath:` instead.
 *
 * @param sortParams Sorting parameters.
 * @param prefixPath String a string path to prefix paths. i.e. prefix.path.to.property.sort={ sort params here }
 * @result The parameter collection containing a parameter that will sort the results.
 */
+ (MDAPIParameters*)parametersWithSort:(NSDictionary*)sortParams prefixPath:(nullable NSString*)prefixPath DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version. Use parametersWithOrderedSort:prefixPath instead");

/**
 * Filtering queries.
 *
 * @param where Sorting filter parameters.
 * @param prefixPath String a string path to prefix paths. i.e. prefix.path.to.property.where={ where params here }
 * @result The parameter collection containing a parameter that will filter results.
 */
+ (MDAPIParameters*)parametersWithWhere:(NSDictionary*)where prefixPath:(nullable NSString*)prefixPath;

/*
 * Selects documents where the value of the property is greater than the passed in value.
 * Produces prefixPath.where={"propertyName": {"$gt": value}}
 */
+ (MDAPIParameters*)parametersWithPropertyName:(NSString*)propertyName greaterThan:(NSObject*)value prefixPath:(nullable NSString*)prefixPath;

/*
 * Selects documents where the value of the property is greater than or equal to the passed in value.
 * Produces prefixPath.where={"propertyName": {"$gte": value}}
 */
+ (MDAPIParameters*)parametersWithPropertyName:(NSString*)propertyName greaterThanOrEqualTo:(NSObject*)value prefixPath:(nullable NSString*)prefixPath;

/*
 * Selects documents where the value of the property is lesser than the passed in value.
 * Produces prefixPath.where={"propertyName": {"$lt": value}}
 */
+ (MDAPIParameters*)parametersWithPropertyName:(NSString*)propertyName lessThan:(NSObject*)value prefixPath:(nullable NSString*)prefixPath;

/*
 * Selects documents where the value of the property is lesser than or equal to the passed in value.
 * Produces prefixPath.where={"propertyName": {"$lte": value}}
 */
+ (MDAPIParameters*)parametersWithPropertyName:(NSString*)propertyName lessThanOrEqualTo:(NSObject*)value prefixPath:(nullable NSString*)prefixPath;

/*
 * Selects documents where the property matches any of the passed in values.
 * Produces prefixPath.where={"propertyName": {"$in": [ comma separated string values here ]}}
 */
+ (MDAPIParameters*)parametersWithPropertyName:(NSString*)propertyName matchesValues:(NSArray<NSString*>*)values prefixPath:(nullable NSString*)prefixPath;

/*
 * Selects documents where all passed in conditions are met.
 * Produces prefixPath.where={"$and": [ conditions here ] }
 */
+ (nullable MDAPIParameters*)parametersWithAndConditions:(NSArray<NSDictionary*>*)conditions prefixPath:(nullable NSString*)prefixPath;

/*
 * Selects documents where any passed in conditions are met.
 * Produces prefixPath.where={"$or": [ conditions here ] }
 */
+ (nullable MDAPIParameters*)parametersWithOrConditions:(NSArray<NSDictionary*>*)conditions prefixPath:(nullable NSString*)prefixPath;

/*
 * Selects documents where the string property matches the passed in regular expression.
 * Produces prefixPath.where={"propertyName": {"$regex": "regex here" }}
 */
+ (MDAPIParameters*)parametersWithPropertyName:(NSString*)propertyName matchesRegex:(NSString*)regex prefixPath:(nullable NSString*)prefixPath;

/*
 * Selects documents where the string property matches the passed in regular expression.
 * Produces prefixPath.where={"propertyName": {"$all": [ comma separated string values here ] }}
 */
+ (MDAPIParameters*)parametersWithPropertyName:(NSString*)propertyName containsAllValues:(NSArray<NSString*>*)values prefixPath:(nullable NSString*)prefixPath;

/*
 * Selects documents where the size of the array property matches the passed in values.
 * Produces prefixPath.where={"propertyName": {"$size": "size" }}
 */
+ (MDAPIParameters*)parametersWithPropertyName:(NSString*)propertyName sizeMatches:(NSNumber*)size prefixPath:(nullable NSString*)prefixPath;

/*
 * Selects documents where all properties of an array of document properties match the passed in expression. 
 *  $elemMatch does not limit the results within the array, but filters the entire document for contained entries.
 *
 * Produces prefixPath.where={"propertyName": {"$elemMatch": { "propName1": "value1", ..., "propNameN": "valuen" } }}
 */
+ (MDAPIParameters*)parametersWithPropertyName:(NSString*)propertyName elemMatches:(NSDictionary*)elemMatches prefixPath:(nullable NSString*)prefixPath;

/**
 * Sorting and filtering queries.
 *
 * @param sortParams Sorting parameters.
 * @param where Sorting filter parameters.
 * @result The parameter collection containing a parameter that will sort and filter results.
 */
+ (MDAPIParameters*)parametersWithSort:(NSDictionary*)sortParams where:(NSDictionary*)where DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version. Use parametersOrderedWithSort:prefixPath: or parametersWithWhere:prefixPath: instead");

/**
 * Creates a parameter with a reason for archiving the object.
 *
 * @param reason The reason for archiving.
 * @result The parameter collection containing a parameter that provide a reason for achiving.
 */
+ (MDAPIParameters*)parametersWithArchiveObjectReason:(NSString*)reason;

/**
 * Creates a parameter with a set of include and/or exclude post types.  Both parameters
 * are optional, but at least one must include one or more elements.
 *
 * @param includePostTypes Post types to include.
 * @param excludePostTypes Post types to exclude.
 * @result The parameter collection containing a the list of include and/or exclude post types.
 */
+ (MDAPIParameters*)parametersWithIncludePostTypes:(nullable NSArray*)includePostTypes
                                  excludePostTypes:(nullable NSArray*)excludePostTypes;

/**
 * Creates a parameter to limit objects with a particular favorite value.
 *
 * @param favorites Whether it should target favorited or not favorited objects.
 * @result The parameter collection containing a parameter specifying whether results should be favorited ones or not.
 */
+ (MDAPIParameters*)parametersWithFavorites:(BOOL)favorites;

/**
 * Creates a parameter to limit the result to a certain set of objects.
 *
 * @param objects The list of objects to limit the results to.
 * @result The parameter collection containing a parameter specifying which objects to limit results to.
 */
+ (MDAPIParameters*)parametersWithObjects:(NSArray*)objects;

/**
 * Creates a parameter to limit the list of connections to those in a pending or active state.
 *
 * @param connectionState The state of the connection to limit the results to.
 * @result The parameter collection containing a parameter specifying which connection state to limit results to.
 */
+ (MDAPIParameters*)parametersWithConnectionState:(MDConnectionState)connectionState;

/**
 * Creates a parameter to limit the list of connections to those in a particular pending state.
 * Creator only shows invitations by the caller. Target only shows invitations to the caller. Enum [creator, target]
 *
 * @param pendingConnectionType The state of the connection to limit the results to.
 * @result The parameter collection containing a parameter specifying which connection state to limit results to.
 */
+ (MDAPIParameters*)parametersWithPendingConnectionType:(MDPendingConnectionType)pendingConnectionType;

/**
 * Creates a parameter to limit the results to those involving the specified account. Cannot be combined with the “patientFile”
 * argument, by which it is superseded.
 *
 * @param accountId The account Id to limit to.
 * @result The parameter collection containing a parameter specifying which account to limit results to.
 */
+ (MDAPIParameters*)parametersWithAccountId:(MDObjectId*)accountId;

/**
 * Creates a parameter to limit the results to those posts created by the specified account id. Cannot be combined
 * with the “filterCaller” argument, which it supersedes.
 *
 * @param accountId The account Id to limit to.
 * @result The parameter collection containing a parameter specifying which account to limit results to.
 */
+ (MDAPIParameters*)parametersWithCreatorId:(MDObjectId*)accountId;

/**
 * Creates a parameter to limit the results by excluding the caller.
 *
 * @result The parameter collection containing a parameter specifying to filter out the caller in the results.
 */
+ (MDAPIParameters*)parametersWithFilterCaller;

/**
 * Creates a parameter to limit the results by only including the targeted IDs.
 *
 * @param postTargetsIdsArray A list of post targets. Only targeted posts where all the participants are included will be returned.
 * @result The parameter collection containing a parameter specifying to include only targeted posts.
 */
+ (MDAPIParameters*)parametersWithPostTargets:(NSArray*)postTargetsIdsArray;

/**
 * Creates a parameter to limit the results by only including a patient file. annot be combined with 
 * the “account” argument, which it supersedes.
 *
 * @param patientFileId The patient you wish to filter for.
 * @result The parameter collection containing a parameter specifying to include only a certain patient file.
 */
+ (MDAPIParameters*)parametersWithPatientFileId:(MDObjectId*)patientFileId;

/**
 * Creates a parameter to specify a notification type.
 *
 * @param notificationType The type (ObjectId) of the notifications.
 * @result The parameter specifying the type of notifications.
 */
+ (MDAPIParameters*)parametersWithNotificationType:(MDObjectId*)notificationType;

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

@end

/**
 * Helper class to check whether property values are accepted as proper values given a property definition.
 */
@interface MDCustomClassParameterFactory : NSObject

/**
 * Check the validity of any value to see if it can be used as the value of a given property. If so,
 * return the original.
 *
 * The checks performed follow a best effort approach and don't ensure the values will ultimately be
 * accepted by the backend. This is because many properties have value restrictions of varying complexity,
 * which may include valid ranges or javascript code to control the value's validity.
 *
 * Methods here perform mostly type checking tests.
 *
 * There is a correspondance between the original property definition type and the type of the value
 * being passed. These types should be self explanatory:
 *      `MDPropertyTypeBoolean`
 *      `MDPropertyTypeAny`
 *      `MDPropertyTypeDate`
 *      `MDPropertyTypeDocument`
 *      `MDPropertyTypeFile`
 *      `MDPropertyTypeNumber`
 *      `MDPropertyTypeObjectId`
 *      `MDPropertyTypeReference`
 *      `MDPropertyTypeString`
 *      Arrays
 *
 * @param propertyDefinition The property definition for the custom class we are checking.
 * @param value The value to check.
 * @return The passed value if the check holds, nil otherwise.
 */
+ (nullable id)checkPropertyValueForProperty:(MDPropertyDefinition *)propertyDefinition withValue:(id)value;

/**
 * Check the validity of an array for an array property type.
 * This method will do a recursive check on each individual item of the original to ensure it matches the
 * underlying property. For instance, if the original type is a String[] and the value parameter is an array
 * of several strings but one number, this method will ensure the check fails.
 *
 * @param propertyDefinition The property definition for the custom class we are checking, should
 *  correspond to an Array type.
 * @param value The value to check.
 * @return The passed array value if the check holds, nil otherwise.
 */
+ (nullable NSArray *)checkArrayValueForProperty:(MDPropertyDefinition *)propertyDefinition withValue:(NSArray *)value;

#pragma mark - Basic Types

/**
 * Check the validity of a String for a string property definition. This will not control any restrictions
 * this value may have, only that the type of value corresponds to the expectations of the property definition.
 *
 * @param propertyDefinition The property definition for the custom class we are checking, should
 *  correspond to an String type.
 * @param value The value to check.
 * @return The passed string value if the check holds, nil otherwise.
 */
+ (nullable NSString *)checkStringValueForProperty:(MDPropertyDefinition *)propertyDefinition withValue:(NSString *)value;

/**
 * Check the validity of a Number for a number property definition. This will not control any restrictions
 * this value may have, only that the type of value corresponds to the expectations of the property definition.
 *
 * @param propertyDefinition The property definition for the custom class we are checking, should
 *  correspond to an Number type.
 * @param value The value to check.
 * @return The passed number value if the check holds, nil otherwise.
 */
+ (nullable NSNumber *)checkNumberValueForProperty:(MDPropertyDefinition *)propertyDefinition withValue:(NSNumber *)value;

/**
 * Check the validity of a boolean value (represented by a number) for a boolean property definition. This will
 * not control any restrictions this value may have, only that the type of value corresponds to the expectations
 * of the property definition.
 *
 * @param propertyDefinition The property definition for the custom class we are checking, should
 *  correspond to an Bool type.
 * @param value The value to check.
 * @return The passed number value if the check holds, nil otherwise.
 */
+ (nullable NSNumber *)checkBoolValueForProperty:(MDPropertyDefinition *)propertyDefinition withValue:(NSNumber *)value;

/**
 * Check the validity of a Dictionary for a property definition of type Any. This will not control any restrictions
 * this value may have, only that the type of value corresponds to the expectations of the property definition.
 *
 * @param propertyDefinition The property definition for the custom class we are checking, should
 *  correspond to an Any type.
 * @param value The value to check.
 * @return The passed dictionary value if the check holds, nil otherwise.
 */
+ (nullable NSDictionary *)checkAnyValueForProperty:(MDPropertyDefinition *)propertyDefinition withValue:(NSDictionary *)value;

/**
 * Check the validity of a Dictionary for a Document property definition. This will not control any restrictions
 * this value may have, only that the type of value corresponds to the expectations of the property definition.
 *
 * @param propertyDefinition The property definition for the custom class we are checking, should
 *  correspond to a Document type.
 * @param value The value to check.
 * @return The passed dictionary value if the check holds, nil otherwise.
 */
+ (nullable NSDictionary *)checkDocumentValueForProperty:(MDPropertyDefinition *)propertyDefinition withValue:(NSDictionary *)value;

/**
 * Check the validity of a Date represented as a string for a date property definition. This will not control any restrictions
 * this value may have, only that the type of value corresponds to the expectations of the property definition.
 *
 * @param propertyDefinition The property definition for the custom class we are checking, should
 *  correspond to a Date type.
 * @param value The string value to check.
 * @return The passed date value (in a string format) if the check holds, nil otherwise.
 */
+ (nullable NSString *)checkDateValueForProperty:(MDPropertyDefinition *)propertyDefinition withValue:(NSString *)value;

/**
 * Check the validity of a String for an ObjectID property definition. This will not control any restrictions
 * this value may have, only that the type of value corresponds to the expectations of the property definition.
 *
 * @param propertyDefinition The property definition for the custom class we are checking, should
 *  correspond to an String type.
 * @param value The value to check.
 * @return The passed string value if the check holds, nil otherwise.
 */
+ (nullable NSString *)checkObjectIdValueForProperty:(MDPropertyDefinition *)propertyDefinition withValue:(NSString *)value;

/**
 * Check the validity of a String for a reference property definition. This will not control any restrictions
 * this value may have, only that the type of value corresponds to the expectations of the property definition.
 *
 * @param propertyDefinition The property definition for the custom class we are checking, should
 *  correspond to an Reference type.
 * @param value The value to check.
 * @return The passed string value if the check holds, nil otherwise.
 */
+ (nullable NSString *)checkReferenceValueForProperty:(MDPropertyDefinition *)propertyDefinition withValue:(NSString *)value;

/**
 * Check the validity of a Dictionary for a File property definition. This will control any mime type restrictions
 * this value may have.
 *
 * As an example, if a File's facet is expending a png overlay image but this passes a an UIImage alongside a .jpg
 * mime type, the checks will fail and the method returns nil.
 *
 * @param propertyDefinition The property definition for the custom class we are checking, should
 *  correspond to a File type.
 * @param value The value to check.
 * @return The passed dictionary value if the check holds, nil otherwise.
 */
+ (nullable NSDictionary *)checkFileValueForProperty:(MDPropertyDefinition *)propertyDefinition withValue:(NSDictionary *)value;

@end

/**
 * Wrapper for the body of a custom class parameter when creating or modifying instances.
 *
 * @see -addValue:forProperty:
 */
typedef NSMutableDictionary MDCustomClassParameter;

/**
 * Wrapper for the body of a File property's value.
 *
 * @see -addImage:forFacetNamed:
 * @see -addImageAsJpeg:compressionQuality:forFacetNamed:inProperty:
 * @see -addImageAsPng:forFacetNamed:inProperty:
 * @see -addData:withMimeType:forFacetNamed:inProperty:
 */
typedef NSMutableDictionary MDFileParameterValue;

/**
 * Parameter assembly extensions for mutable dictionaries.
 */
@interface NSMutableDictionary(MDExtensions)

#pragma mark - Custom Class Body

/**
 * Add a value to a custom class body parameter for a certain property, as given by it's definition.
 *
 * @param value The value being set for the property.
 * @param propertyDefinition The property's definition.
 * @return True if the value checks out for the property and was added to the body, False otherwise.
 */
- (BOOL)addValue:(id)value forProperty:(MDPropertyDefinition *)propertyDefinition;

#pragma mark - File Properties

/**
 * Add an image to File parameter's body for a certain facet. This method will check the expected mime type
 * and attempt to pass the parameter along those expectations.
 *
 * @param image The UIImage object.
 * @param facet The name of the facet in the File property.
 * @param propertyDefinition The property's definition.
 * @return True if the value checks out for the facet in the property and it was added to the body, False otherwise.
 */
- (BOOL)addImage:(UIImage *)image
   forFacetNamed:(NSString *)facet
      inProperty:(MDPropertyDefinition *)propertyDefinition;

/**
 * Add an image as .jpg to nthe File parameter's body for a certain facet.
 *
 * @param image The UIImage object.
 * @param compression A value between 0 and 1 representing the image's compression quality.
 * @param facet The name of the facet in the File property.
 * @param propertyDefinition The property's definition.
 * @return True if the image was added to the body, False otherwise.
 */
- (BOOL)addImageAsJpeg:(UIImage *)image
    compressionQuality:(CGFloat)compression
         forFacetNamed:(NSString *)facet
            inProperty:(MDPropertyDefinition *)propertyDefinition;

/**
 * Add an image as .png to File parameter's body for a certain facet.
 *
 * @param image The UIImage object.
 * @param facet The name of the facet in the File property.
 * @param propertyDefinition The property's definition.
 * @return True if the image was added to the body, False otherwise.
 */
- (BOOL)addImageAsPng:(UIImage *)image
        forFacetNamed:(NSString *)facet
           inProperty:(MDPropertyDefinition *)propertyDefinition;

/**
 * Add a binary data blob with a certain mime type to the facet value in a File's body.
 *
 * @param data The binary data blob.
 * @param mimeType The mime type of this data.
 * @param facet The name of the facet in the File property.
 * @param propertyDefinition The property's definition.
 * @return True if the data parameter was added properly, False otherwise.
 */
- (BOOL)addData:(NSData *)data
   withMimeType:(NSString *)mimeType
  forFacetNamed:(NSString *)facet
     inProperty:(MDPropertyDefinition *)propertyDefinition;

@end

NS_ASSUME_NONNULL_END
