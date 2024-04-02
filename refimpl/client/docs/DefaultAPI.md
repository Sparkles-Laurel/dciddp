# DefaultAPI

All URIs are relative to *http://localhost*

Method | HTTP request | Description
------------- | ------------- | -------------
[**DefaultAPI_systemPost**](DefaultAPI.md#DefaultAPI_systemPost) | **POST** /system | Create a new plural system
[**DefaultAPI_systemSystemFrontersGet**](DefaultAPI.md#DefaultAPI_systemSystemFrontersGet) | **GET** /system/{system}/fronters | Retrieves the current fronters&#39; API paths
[**DefaultAPI_systemSystemFrontersPut**](DefaultAPI.md#DefaultAPI_systemSystemFrontersPut) | **PUT** /system/{system}/fronters | Set the fronter of a plural system
[**DefaultAPI_systemSystemGet**](DefaultAPI.md#DefaultAPI_systemSystemGet) | **GET** /system/{system} | Get plural system information
[**DefaultAPI_systemSystemMemberMemberGet**](DefaultAPI.md#DefaultAPI_systemSystemMemberMemberGet) | **GET** /system/{system}/member/{member} | Get member information
[**DefaultAPI_systemSystemMemberMemberPronounsGet**](DefaultAPI.md#DefaultAPI_systemSystemMemberMemberPronounsGet) | **GET** /system/{system}/member/{member}/pronouns | Get member pronouns
[**DefaultAPI_systemSystemMembersPost**](DefaultAPI.md#DefaultAPI_systemSystemMembersPost) | **POST** /system/{system}/members | Add a new member to a plural system


# **DefaultAPI_systemPost**
```c
// Create a new plural system
//
// Create a new plural system with the specified name and pronouns
//
system_t* DefaultAPI_systemPost(apiClient_t *apiClient, partial_system_t *partial_system);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**partial_system** | **[partial_system_t](partial_system.md) \*** |  | 

### Return type

[system_t](system.md) *


### Authorization

[bearerHttpAuthentication](../README.md#bearerHttpAuthentication)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DefaultAPI_systemSystemFrontersGet**
```c
// Retrieves the current fronters' API paths
//
// Retrieves the list of the current fronter(s)
//
list_t* DefaultAPI_systemSystemFrontersGet(apiClient_t *apiClient, char *system);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**system** | **char \*** | The ID of the system | 

### Return type

[list_t](fronter.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DefaultAPI_systemSystemFrontersPut**
```c
// Set the fronter of a plural system
//
// Set the fronter of a plural system to the specified member
//
void DefaultAPI_systemSystemFrontersPut(apiClient_t *apiClient, char *system, list_t *request_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**system** | **char \*** | The ID of the system | 
**request_body** | **[list_t](char.md) \*** |  | 

### Return type

void

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DefaultAPI_systemSystemGet**
```c
// Get plural system information
//
// Retrieve information about a plural system
//
system_t* DefaultAPI_systemSystemGet(apiClient_t *apiClient, char *system);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**system** | **char \*** | The ID of the system | 

### Return type

[system_t](system.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DefaultAPI_systemSystemMemberMemberGet**
```c
// Get member information
//
// Retrieve information about a member of a plural system
//
member_t* DefaultAPI_systemSystemMemberMemberGet(apiClient_t *apiClient, char *system, char *member);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**system** | **char \*** | The ID of the system | 
**member** | **char \*** | The ID of the member | 

### Return type

[member_t](member.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DefaultAPI_systemSystemMemberMemberPronounsGet**
```c
// Get member pronouns
//
// Retrieve pronouns of a member of a plural system
//
list_t* DefaultAPI_systemSystemMemberMemberPronounsGet(apiClient_t *apiClient, char *system, char *member);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**system** | **char \*** | The ID of the system | 
**member** | **char \*** | The ID of the member | 

### Return type

[list_t](pronoun.md) *


### Authorization

[bearerHttpAuthentication](../README.md#bearerHttpAuthentication)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DefaultAPI_systemSystemMembersPost**
```c
// Add a new member to a plural system
//
// Add a new member to a plural system with the specified name and pronouns
//
member_t* DefaultAPI_systemSystemMembersPost(apiClient_t *apiClient, char *system, partial_member_t *partial_member);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**system** | **char \*** | The ID of the system | 
**partial_member** | **[partial_member_t](partial_member.md) \*** |  | 

### Return type

[member_t](member.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

