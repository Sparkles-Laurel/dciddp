# System

## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Id** | Pointer to **string** | The ID of the system | [optional] 
**Name** | Pointer to **string** | The name of the system | [optional] 
**Pronouns** | Pointer to **string** | The pronouns of the system | [optional] 
**Fronters** | Pointer to [**[]Fronter**](Fronter.md) | The current fronter of the system | [optional] 
**Members** | Pointer to [**[]Member**](Member.md) | The members of the system | [optional] 

## Methods

### NewSystem

`func NewSystem() *System`

NewSystem instantiates a new System object
This constructor will assign default values to properties that have it defined,
and makes sure properties required by API are set, but the set of arguments
will change when the set of required properties is changed

### NewSystemWithDefaults

`func NewSystemWithDefaults() *System`

NewSystemWithDefaults instantiates a new System object
This constructor will only assign default values to properties that have it defined,
but it doesn't guarantee that properties required by API are set

### GetId

`func (o *System) GetId() string`

GetId returns the Id field if non-nil, zero value otherwise.

### GetIdOk

`func (o *System) GetIdOk() (*string, bool)`

GetIdOk returns a tuple with the Id field if it's non-nil, zero value otherwise
and a boolean to check if the value has been set.

### SetId

`func (o *System) SetId(v string)`

SetId sets Id field to given value.

### HasId

`func (o *System) HasId() bool`

HasId returns a boolean if a field has been set.

### GetName

`func (o *System) GetName() string`

GetName returns the Name field if non-nil, zero value otherwise.

### GetNameOk

`func (o *System) GetNameOk() (*string, bool)`

GetNameOk returns a tuple with the Name field if it's non-nil, zero value otherwise
and a boolean to check if the value has been set.

### SetName

`func (o *System) SetName(v string)`

SetName sets Name field to given value.

### HasName

`func (o *System) HasName() bool`

HasName returns a boolean if a field has been set.

### GetPronouns

`func (o *System) GetPronouns() string`

GetPronouns returns the Pronouns field if non-nil, zero value otherwise.

### GetPronounsOk

`func (o *System) GetPronounsOk() (*string, bool)`

GetPronounsOk returns a tuple with the Pronouns field if it's non-nil, zero value otherwise
and a boolean to check if the value has been set.

### SetPronouns

`func (o *System) SetPronouns(v string)`

SetPronouns sets Pronouns field to given value.

### HasPronouns

`func (o *System) HasPronouns() bool`

HasPronouns returns a boolean if a field has been set.

### GetFronters

`func (o *System) GetFronters() []Fronter`

GetFronters returns the Fronters field if non-nil, zero value otherwise.

### GetFrontersOk

`func (o *System) GetFrontersOk() (*[]Fronter, bool)`

GetFrontersOk returns a tuple with the Fronters field if it's non-nil, zero value otherwise
and a boolean to check if the value has been set.

### SetFronters

`func (o *System) SetFronters(v []Fronter)`

SetFronters sets Fronters field to given value.

### HasFronters

`func (o *System) HasFronters() bool`

HasFronters returns a boolean if a field has been set.

### GetMembers

`func (o *System) GetMembers() []Member`

GetMembers returns the Members field if non-nil, zero value otherwise.

### GetMembersOk

`func (o *System) GetMembersOk() (*[]Member, bool)`

GetMembersOk returns a tuple with the Members field if it's non-nil, zero value otherwise
and a boolean to check if the value has been set.

### SetMembers

`func (o *System) SetMembers(v []Member)`

SetMembers sets Members field to given value.

### HasMembers

`func (o *System) HasMembers() bool`

HasMembers returns a boolean if a field has been set.


[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


