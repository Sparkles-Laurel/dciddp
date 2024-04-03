# DefaultApi

All URIs are relative to *http://localhost*

| Method | HTTP request | Description |
|------------- | ------------- | -------------|
| [**systemPost**](DefaultApi.md#systemPost) | **POST** /system | Create a new plural system |
| [**systemSystemFrontersGet**](DefaultApi.md#systemSystemFrontersGet) | **GET** /system/{system}/fronters | Retrieves the current fronters&#39; API paths |
| [**systemSystemFrontersPut**](DefaultApi.md#systemSystemFrontersPut) | **PUT** /system/{system}/fronters | Set the fronter of a plural system |
| [**systemSystemGet**](DefaultApi.md#systemSystemGet) | **GET** /system/{system} | Get plural system information |
| [**systemSystemMemberMemberGet**](DefaultApi.md#systemSystemMemberMemberGet) | **GET** /system/{system}/member/{member} | Get member information |
| [**systemSystemMemberMemberPronounsGet**](DefaultApi.md#systemSystemMemberMemberPronounsGet) | **GET** /system/{system}/member/{member}/pronouns | Get member pronouns |
| [**systemSystemMembersPost**](DefaultApi.md#systemSystemMembersPost) | **POST** /system/{system}/members | Add a new member to a plural system |


<a name="systemPost"></a>
# **systemPost**
> system systemPost(partial-system)

Create a new plural system

    Create a new plural system with the specified name and pronouns

### Parameters

|Name | Type | Description  | Notes |
|------------- | ------------- | ------------- | -------------|
| **partial-system** | [**partial-system**](../Models/partial-system.md)|  | |

### Return type

[**system**](../Models/system.md)

### Authorization

[bearerHttpAuthentication](../README.md#bearerHttpAuthentication)

### HTTP request headers

- **Content-Type**: application/json
- **Accept**: application/json

<a name="systemSystemFrontersGet"></a>
# **systemSystemFrontersGet**
> List systemSystemFrontersGet(system)

Retrieves the current fronters&#39; API paths

    Retrieves the list of the current fronter(s)

### Parameters

|Name | Type | Description  | Notes |
|------------- | ------------- | ------------- | -------------|
| **system** | **String**| The ID of the system | [default to null] |

### Return type

[**List**](../Models/fronter.md)

### Authorization

No authorization required

### HTTP request headers

- **Content-Type**: Not defined
- **Accept**: application/json

<a name="systemSystemFrontersPut"></a>
# **systemSystemFrontersPut**
> systemSystemFrontersPut(system, request\_body)

Set the fronter of a plural system

    Set the fronter of a plural system to the specified member

### Parameters

|Name | Type | Description  | Notes |
|------------- | ------------- | ------------- | -------------|
| **system** | **String**| The ID of the system | [default to null] |
| **request\_body** | [**List**](../Models/string.md)|  | |

### Return type

null (empty response body)

### Authorization

No authorization required

### HTTP request headers

- **Content-Type**: application/json
- **Accept**: application/json

<a name="systemSystemGet"></a>
# **systemSystemGet**
> system systemSystemGet(system)

Get plural system information

    Retrieve information about a plural system

### Parameters

|Name | Type | Description  | Notes |
|------------- | ------------- | ------------- | -------------|
| **system** | **String**| The ID of the system | [default to null] |

### Return type

[**system**](../Models/system.md)

### Authorization

No authorization required

### HTTP request headers

- **Content-Type**: Not defined
- **Accept**: application/json

<a name="systemSystemMemberMemberGet"></a>
# **systemSystemMemberMemberGet**
> member systemSystemMemberMemberGet(system, member)

Get member information

    Retrieve information about a member of a plural system

### Parameters

|Name | Type | Description  | Notes |
|------------- | ------------- | ------------- | -------------|
| **system** | **String**| The ID of the system | [default to null] |
| **member** | **String**| The ID of the member | [default to null] |

### Return type

[**member**](../Models/member.md)

### Authorization

No authorization required

### HTTP request headers

- **Content-Type**: Not defined
- **Accept**: application/json

<a name="systemSystemMemberMemberPronounsGet"></a>
# **systemSystemMemberMemberPronounsGet**
> List systemSystemMemberMemberPronounsGet(system, member)

Get member pronouns

    Retrieve pronouns of a member of a plural system

### Parameters

|Name | Type | Description  | Notes |
|------------- | ------------- | ------------- | -------------|
| **system** | **String**| The ID of the system | [default to null] |
| **member** | **String**| The ID of the member | [default to null] |

### Return type

[**List**](../Models/pronoun.md)

### Authorization

[bearerHttpAuthentication](../README.md#bearerHttpAuthentication)

### HTTP request headers

- **Content-Type**: Not defined
- **Accept**: application/json

<a name="systemSystemMembersPost"></a>
# **systemSystemMembersPost**
> member systemSystemMembersPost(system, partial-member)

Add a new member to a plural system

    Add a new member to a plural system with the specified name and pronouns

### Parameters

|Name | Type | Description  | Notes |
|------------- | ------------- | ------------- | -------------|
| **system** | **String**| The ID of the system | [default to null] |
| **partial-member** | [**partial-member**](../Models/partial-member.md)|  | |

### Return type

[**member**](../Models/member.md)

### Authorization

No authorization required

### HTTP request headers

- **Content-Type**: application/json
- **Accept**: application/json

