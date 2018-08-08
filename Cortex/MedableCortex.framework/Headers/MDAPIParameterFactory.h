//
//  MDAPIParameterFactory.h
//  Medable
//
//  Copyright (c) 2014 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MDPropertyDefinition.h"

@class MDObjectId;
@class MDAccountRole;

NS_ASSUME_NONNULL_BEGIN

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
- (void)addParametersWithParameters:(MDAPIParameters*)parameters DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version. Use `addParameters:` instead.");

/**
 * Add parameters from a dictionary.
 *
 * @param parameters The parameter collection in a dictionary format. key = parameter name, value = parameter value.
 */
- (void)addParametersWithDictionary:(NSDictionary *)parameters;

/**
 * Current aggregated parameters in NSDicitionary format. Useful for debugging purposes.
 *
 * @returns the current aggregated parameters in NSDictionary format.
 */
- (NSDictionary *)apiParameters;

/**
 * Current parameters in a format used by `MDAPIClient` internally for making the service calls.
 *
 * @returns The current parameters a format used by `MDAPIClient` internally for making the service calls.
 */
- (NSObject *)apiParametersForHTTPRequest;

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
 * Add custom parameters from an array.
 *
 * @param customParameters The parameters array.
 * @return The instance representing the parameters in the array.
 */
+ (MDAPIParameters*)parametersWithArrayParameters:(NSArray*)customParameters;

/**
 * Add custom parameters from a "primitive". This is used in request body contents.
 *
 * @param primitive The primitive represented as a `NSNumber`. i.e.: true/false, 1, 34.55, etc.
 * @return The instance representing the parameters.
 */
+ (MDAPIParameters*)parametersWithPrimitive:(NSNumber *)primitive;

/**
 * Add custom parameters from a "primitive". This is used in request body contents.
 *
 * @param primitive The primitive represented as a `NSString`. i.e.: "something".
 * @return The instance representing the parameters.
 */
+ (MDAPIParameters*)parametersWithStringPrimitive:(NSString *)primitive;

/**
 * Adding this parameter will filter results by a minimum access level.
 *
 * @param accessLevel The minium access level to filter with.
 * @result The paramter collection containing the minimum access level parameter only.
 */
+ (MDAPIParameters*)parametersWithMinimumAccessLevel:(MDACLLevel)accessLevel DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

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
+ (MDAPIParameters*)parametersWithLimitPaths:(NSArray*)paths prefixPath:(nullable NSString*)prefixPath;

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
 * @param where Where filter parameters.
 * @param prefixPath String a string path to prefix paths. i.e. prefix.path.to.property.where={ where params here }
 * @result The parameter collection containing a parameter that will filter results.
 */
+ (MDAPIParameters*)parametersWithWhere:(NSDictionary*)where prefixPath:(nullable NSString*)prefixPath;

/**
 * Grouping queries.
 *
 * @param group Group contents. i.e.: { "_id", "c_someReference._id", "count": { "$count": "_id" } }.
 * @param prefixPath String a string path to prefix paths. i.e. prefix.path.to.property.group={ group params here }
 * @result The parameter collection containing a parameter that will filter results.
 */
+ (MDAPIParameters*)parametersWithGroup:(NSDictionary *)group prefixPath:(nullable NSString*)prefixPath;

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

/*
 * Pipeline aggregation.
 *
 * For more information, please refer to: https://docs.medable.com/reference#pipeline .
 *
 * @param stages An array with the pipeline stages.
 * @param prefixPath A dot separated string path to prefix the operator. i.e. prefix.path.to.property.pipeline=[ { stage 1}, ..., { stageN } ]
 * @result The generated pipeline parameter.
 */
+ (MDAPIParameters*)parametersWithPipelineStages:(NSArray<NSDictionary *> *)stages prefixPath:(nullable NSString*)prefixPath;

/**
 * Sorting and filtering queries.
 *
 * @param sortParams Sorting parameters.
 * @param where Sorting filter parameters.
 * @result The parameter collection containing a parameter that will sort and filter results.
 */
+ (MDAPIParameters*)parametersWithSort:(NSDictionary*)sortParams where:(NSDictionary*)where DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version. Use parametersOrderedWithSort:prefixPath: or parametersWithWhere:prefixPath: instead");

/**
 * Creates a parameter with a set of include and/or exclude post types.  Both parameters
 * are optional, but at least one must include one or more elements.
 *
 * @param includePostTypes Post types to include.
 * @param excludePostTypes Post types to exclude.
 * @result The parameter collection containing a the list of include and/or exclude post types.
 */
+ (MDAPIParameters*)parametersWithIncludePostTypes:(nullable NSArray*)includePostTypes
                                  excludePostTypes:(nullable NSArray*)excludePostTypes DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Creates a parameter to limit objects with a particular favorite value.
 *
 * @param favorites Whether it should target favorited or not favorited objects.
 * @result The parameter collection containing a parameter specifying whether results should be favorited ones or not.
 */
+ (MDAPIParameters*)parametersWithFavorites:(BOOL)favorites DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Creates a parameter to limit the result to a certain set of objects.
 *
 * @param objects The list of objects to limit the results to.
 * @result The parameter collection containing a parameter specifying which objects to limit results to.
 */
+ (MDAPIParameters*)parametersWithObjects:(NSArray*)objects DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Creates a parameter to limit the list of connections to those in a pending or active state.
 *
 * @param connectionState The state of the connection to limit the results to.
 * @result The parameter collection containing a parameter specifying which connection state to limit results to.
 */
+ (MDAPIParameters*)parametersWithConnectionState:(MDConnectionState)connectionState DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Creates a parameter to limit the list of connections to those in a particular pending state.
 * Creator only shows invitations by the caller. Target only shows invitations to the caller. Enum [creator, target]
 *
 * @param pendingConnectionType The state of the connection to limit the results to.
 * @result The parameter collection containing a parameter specifying which connection state to limit results to.
 */
+ (MDAPIParameters*)parametersWithPendingConnectionType:(MDPendingConnectionType)pendingConnectionType DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Creates a parameter to limit the results to those involving the specified account. Cannot be combined with the “patientFile”
 * argument, by which it is superseded.
 *
 * @param accountId The account Id to limit to.
 * @result The parameter collection containing a parameter specifying which account to limit results to.
 */
+ (MDAPIParameters*)parametersWithAccountId:(MDObjectId*)accountId DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Creates a parameter to limit the results to those posts created by the specified account id. Cannot be combined
 * with the “filterCaller” argument, which it supersedes.
 *
 * @param accountId The account Id to limit to.
 * @result The parameter collection containing a parameter specifying which account to limit results to.
 */
+ (MDAPIParameters*)parametersWithCreatorId:(MDObjectId*)accountId DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Creates a parameter to limit the results by excluding the caller.
 *
 * @result The parameter collection containing a parameter specifying to filter out the caller in the results.
 */
+ (MDAPIParameters*)parametersWithFilterCaller DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Creates a parameter to limit the results by only including the targeted IDs.
 *
 * @param postTargetsIdsArray A list of post targets. Only targeted posts where all the participants are included will be returned.
 * @result The parameter collection containing a parameter specifying to include only targeted posts.
 */
+ (MDAPIParameters*)parametersWithPostTargets:(NSArray*)postTargetsIdsArray DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Creates a parameter to limit the results by only including a patient file. annot be combined with
 * the “account” argument, which it supersedes.
 *
 * @param patientFileId The patient you wish to filter for.
 * @result The parameter collection containing a parameter specifying to include only a certain patient file.
 */
+ (MDAPIParameters*)parametersWithPatientFileId:(MDObjectId*)patientFileId DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

/**
 * Creates a parameter to specify a notification type.
 *
 * @param notificationType The type (ObjectId) of the notifications.
 * @result The parameter specifying the type of notifications.
 */
+ (MDAPIParameters*)parametersWithNotificationType:(MDObjectId*)notificationType DEPRECATED_MSG_ATTRIBUTE("Will be removed in future version.");

// unavailable init
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

