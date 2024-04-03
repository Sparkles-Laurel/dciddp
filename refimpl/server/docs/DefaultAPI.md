# \DefaultAPI

All URIs are relative to *http://localhost*

Method | HTTP request | Description
------------- | ------------- | -------------
[**SystemPost**](DefaultAPI.md#SystemPost) | **Post** /system | Create a new plural system
[**SystemSystemFrontersGet**](DefaultAPI.md#SystemSystemFrontersGet) | **Get** /system/{system}/fronters | Retrieves the current fronters&#39; API paths
[**SystemSystemFrontersPut**](DefaultAPI.md#SystemSystemFrontersPut) | **Put** /system/{system}/fronters | Set the fronter of a plural system
[**SystemSystemGet**](DefaultAPI.md#SystemSystemGet) | **Get** /system/{system} | Get plural system information
[**SystemSystemMemberMemberGet**](DefaultAPI.md#SystemSystemMemberMemberGet) | **Get** /system/{system}/member/{member} | Get member information
[**SystemSystemMemberMemberPronounsGet**](DefaultAPI.md#SystemSystemMemberMemberPronounsGet) | **Get** /system/{system}/member/{member}/pronouns | Get member pronouns
[**SystemSystemMembersPost**](DefaultAPI.md#SystemSystemMembersPost) | **Post** /system/{system}/members | Add a new member to a plural system



## SystemPost

> System SystemPost(ctx).PartialSystem(partialSystem).Execute()

Create a new plural system



### Example

```go
package main

import (
	"context"
	"fmt"
	"os"
	openapiclient "github.com/GIT_USER_ID/GIT_REPO_ID"
)

func main() {
	partialSystem := *openapiclient.NewPartialSystem() // PartialSystem | 

	configuration := openapiclient.NewConfiguration()
	apiClient := openapiclient.NewAPIClient(configuration)
	resp, r, err := apiClient.DefaultAPI.SystemPost(context.Background()).PartialSystem(partialSystem).Execute()
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error when calling `DefaultAPI.SystemPost``: %v\n", err)
		fmt.Fprintf(os.Stderr, "Full HTTP response: %v\n", r)
	}
	// response from `SystemPost`: System
	fmt.Fprintf(os.Stdout, "Response from `DefaultAPI.SystemPost`: %v\n", resp)
}
```

### Path Parameters



### Other Parameters

Other parameters are passed through a pointer to a apiSystemPostRequest struct via the builder pattern


Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **partialSystem** | [**PartialSystem**](PartialSystem.md) |  | 

### Return type

[**System**](System.md)

### Authorization

[bearerHttpAuthentication](../README.md#bearerHttpAuthentication)

### HTTP request headers

- **Content-Type**: application/json
- **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints)
[[Back to Model list]](../README.md#documentation-for-models)
[[Back to README]](../README.md)


## SystemSystemFrontersGet

> []Fronter SystemSystemFrontersGet(ctx, system).Execute()

Retrieves the current fronters' API paths



### Example

```go
package main

import (
	"context"
	"fmt"
	"os"
	openapiclient "github.com/GIT_USER_ID/GIT_REPO_ID"
)

func main() {
	system := "system_example" // string | The ID of the system

	configuration := openapiclient.NewConfiguration()
	apiClient := openapiclient.NewAPIClient(configuration)
	resp, r, err := apiClient.DefaultAPI.SystemSystemFrontersGet(context.Background(), system).Execute()
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error when calling `DefaultAPI.SystemSystemFrontersGet``: %v\n", err)
		fmt.Fprintf(os.Stderr, "Full HTTP response: %v\n", r)
	}
	// response from `SystemSystemFrontersGet`: []Fronter
	fmt.Fprintf(os.Stdout, "Response from `DefaultAPI.SystemSystemFrontersGet`: %v\n", resp)
}
```

### Path Parameters


Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
**system** | **string** | The ID of the system | 

### Other Parameters

Other parameters are passed through a pointer to a apiSystemSystemFrontersGetRequest struct via the builder pattern


Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------


### Return type

[**[]Fronter**](Fronter.md)

### Authorization

No authorization required

### HTTP request headers

- **Content-Type**: Not defined
- **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints)
[[Back to Model list]](../README.md#documentation-for-models)
[[Back to README]](../README.md)


## SystemSystemFrontersPut

> SystemSystemFrontersPut(ctx, system).RequestBody(requestBody).Execute()

Set the fronter of a plural system



### Example

```go
package main

import (
	"context"
	"fmt"
	"os"
	openapiclient "github.com/GIT_USER_ID/GIT_REPO_ID"
)

func main() {
	system := "system_example" // string | The ID of the system
	requestBody := []string{"Property_example"} // []string | 

	configuration := openapiclient.NewConfiguration()
	apiClient := openapiclient.NewAPIClient(configuration)
	r, err := apiClient.DefaultAPI.SystemSystemFrontersPut(context.Background(), system).RequestBody(requestBody).Execute()
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error when calling `DefaultAPI.SystemSystemFrontersPut``: %v\n", err)
		fmt.Fprintf(os.Stderr, "Full HTTP response: %v\n", r)
	}
}
```

### Path Parameters


Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
**system** | **string** | The ID of the system | 

### Other Parameters

Other parameters are passed through a pointer to a apiSystemSystemFrontersPutRequest struct via the builder pattern


Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------

 **requestBody** | **[]string** |  | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

- **Content-Type**: application/json
- **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints)
[[Back to Model list]](../README.md#documentation-for-models)
[[Back to README]](../README.md)


## SystemSystemGet

> System SystemSystemGet(ctx, system).Execute()

Get plural system information



### Example

```go
package main

import (
	"context"
	"fmt"
	"os"
	openapiclient "github.com/GIT_USER_ID/GIT_REPO_ID"
)

func main() {
	system := "system_example" // string | The ID of the system

	configuration := openapiclient.NewConfiguration()
	apiClient := openapiclient.NewAPIClient(configuration)
	resp, r, err := apiClient.DefaultAPI.SystemSystemGet(context.Background(), system).Execute()
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error when calling `DefaultAPI.SystemSystemGet``: %v\n", err)
		fmt.Fprintf(os.Stderr, "Full HTTP response: %v\n", r)
	}
	// response from `SystemSystemGet`: System
	fmt.Fprintf(os.Stdout, "Response from `DefaultAPI.SystemSystemGet`: %v\n", resp)
}
```

### Path Parameters


Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
**system** | **string** | The ID of the system | 

### Other Parameters

Other parameters are passed through a pointer to a apiSystemSystemGetRequest struct via the builder pattern


Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------


### Return type

[**System**](System.md)

### Authorization

No authorization required

### HTTP request headers

- **Content-Type**: Not defined
- **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints)
[[Back to Model list]](../README.md#documentation-for-models)
[[Back to README]](../README.md)


## SystemSystemMemberMemberGet

> Member SystemSystemMemberMemberGet(ctx, system, member).Execute()

Get member information



### Example

```go
package main

import (
	"context"
	"fmt"
	"os"
	openapiclient "github.com/GIT_USER_ID/GIT_REPO_ID"
)

func main() {
	system := "system_example" // string | The ID of the system
	member := "member_example" // string | The ID of the member

	configuration := openapiclient.NewConfiguration()
	apiClient := openapiclient.NewAPIClient(configuration)
	resp, r, err := apiClient.DefaultAPI.SystemSystemMemberMemberGet(context.Background(), system, member).Execute()
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error when calling `DefaultAPI.SystemSystemMemberMemberGet``: %v\n", err)
		fmt.Fprintf(os.Stderr, "Full HTTP response: %v\n", r)
	}
	// response from `SystemSystemMemberMemberGet`: Member
	fmt.Fprintf(os.Stdout, "Response from `DefaultAPI.SystemSystemMemberMemberGet`: %v\n", resp)
}
```

### Path Parameters


Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
**system** | **string** | The ID of the system | 
**member** | **string** | The ID of the member | 

### Other Parameters

Other parameters are passed through a pointer to a apiSystemSystemMemberMemberGetRequest struct via the builder pattern


Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------



### Return type

[**Member**](Member.md)

### Authorization

No authorization required

### HTTP request headers

- **Content-Type**: Not defined
- **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints)
[[Back to Model list]](../README.md#documentation-for-models)
[[Back to README]](../README.md)


## SystemSystemMemberMemberPronounsGet

> []Pronoun SystemSystemMemberMemberPronounsGet(ctx, system, member).Execute()

Get member pronouns



### Example

```go
package main

import (
	"context"
	"fmt"
	"os"
	openapiclient "github.com/GIT_USER_ID/GIT_REPO_ID"
)

func main() {
	system := "system_example" // string | The ID of the system
	member := "member_example" // string | The ID of the member

	configuration := openapiclient.NewConfiguration()
	apiClient := openapiclient.NewAPIClient(configuration)
	resp, r, err := apiClient.DefaultAPI.SystemSystemMemberMemberPronounsGet(context.Background(), system, member).Execute()
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error when calling `DefaultAPI.SystemSystemMemberMemberPronounsGet``: %v\n", err)
		fmt.Fprintf(os.Stderr, "Full HTTP response: %v\n", r)
	}
	// response from `SystemSystemMemberMemberPronounsGet`: []Pronoun
	fmt.Fprintf(os.Stdout, "Response from `DefaultAPI.SystemSystemMemberMemberPronounsGet`: %v\n", resp)
}
```

### Path Parameters


Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
**system** | **string** | The ID of the system | 
**member** | **string** | The ID of the member | 

### Other Parameters

Other parameters are passed through a pointer to a apiSystemSystemMemberMemberPronounsGetRequest struct via the builder pattern


Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------



### Return type

[**[]Pronoun**](Pronoun.md)

### Authorization

[bearerHttpAuthentication](../README.md#bearerHttpAuthentication)

### HTTP request headers

- **Content-Type**: Not defined
- **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints)
[[Back to Model list]](../README.md#documentation-for-models)
[[Back to README]](../README.md)


## SystemSystemMembersPost

> Member SystemSystemMembersPost(ctx, system).PartialMember(partialMember).Execute()

Add a new member to a plural system



### Example

```go
package main

import (
	"context"
	"fmt"
	"os"
	openapiclient "github.com/GIT_USER_ID/GIT_REPO_ID"
)

func main() {
	system := "system_example" // string | The ID of the system
	partialMember := *openapiclient.NewPartialMember() // PartialMember | 

	configuration := openapiclient.NewConfiguration()
	apiClient := openapiclient.NewAPIClient(configuration)
	resp, r, err := apiClient.DefaultAPI.SystemSystemMembersPost(context.Background(), system).PartialMember(partialMember).Execute()
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error when calling `DefaultAPI.SystemSystemMembersPost``: %v\n", err)
		fmt.Fprintf(os.Stderr, "Full HTTP response: %v\n", r)
	}
	// response from `SystemSystemMembersPost`: Member
	fmt.Fprintf(os.Stdout, "Response from `DefaultAPI.SystemSystemMembersPost`: %v\n", resp)
}
```

### Path Parameters


Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
**system** | **string** | The ID of the system | 

### Other Parameters

Other parameters are passed through a pointer to a apiSystemSystemMembersPostRequest struct via the builder pattern


Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------

 **partialMember** | [**PartialMember**](PartialMember.md) |  | 

### Return type

[**Member**](Member.md)

### Authorization

No authorization required

### HTTP request headers

- **Content-Type**: application/json
- **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints)
[[Back to Model list]](../README.md#documentation-for-models)
[[Back to README]](../README.md)

