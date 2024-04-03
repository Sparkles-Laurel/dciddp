# Documentation for DCIDDP

<a name="documentation-for-api-endpoints"></a>
## Documentation for API Endpoints

All URIs are relative to *http://localhost*

| Class | Method | HTTP request | Description |
|------------ | ------------- | ------------- | -------------|
| *DefaultApi* | [**systemPost**](Apis/DefaultApi.md#systempost) | **POST** /system | Create a new plural system |
*DefaultApi* | [**systemSystemFrontersGet**](Apis/DefaultApi.md#systemsystemfrontersget) | **GET** /system/{system}/fronters | Retrieves the current fronters' API paths |
*DefaultApi* | [**systemSystemFrontersPut**](Apis/DefaultApi.md#systemsystemfrontersput) | **PUT** /system/{system}/fronters | Set the fronter of a plural system |
*DefaultApi* | [**systemSystemGet**](Apis/DefaultApi.md#systemsystemget) | **GET** /system/{system} | Get plural system information |
*DefaultApi* | [**systemSystemMemberMemberGet**](Apis/DefaultApi.md#systemsystemmembermemberget) | **GET** /system/{system}/member/{member} | Get member information |
*DefaultApi* | [**systemSystemMemberMemberPronounsGet**](Apis/DefaultApi.md#systemsystemmembermemberpronounsget) | **GET** /system/{system}/member/{member}/pronouns | Get member pronouns |
*DefaultApi* | [**systemSystemMembersPost**](Apis/DefaultApi.md#systemsystemmemberspost) | **POST** /system/{system}/members | Add a new member to a plural system |


<a name="documentation-for-models"></a>
## Documentation for Models

 - [error](./Models/error.md)
 - [fronter](./Models/fronter.md)
 - [member](./Models/member.md)
 - [partial-member](./Models/partial-member.md)
 - [partial-system](./Models/partial-system.md)
 - [pronoun](./Models/pronoun.md)
 - [system](./Models/system.md)


<a name="documentation-for-authorization"></a>
## Documentation for Authorization

<a name="bearerHttpAuthentication"></a>
### bearerHttpAuthentication

- **Type**: HTTP Bearer Token authentication

