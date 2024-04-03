# PartialMember

## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Name** | Pointer to **string** | The name of the member | [optional] 
**Pronouns** | Pointer to [**[]Pronoun**](Pronoun.md) | Pronouns of the member | [optional] 

## Methods

### NewPartialMember

`func NewPartialMember() *PartialMember`

NewPartialMember instantiates a new PartialMember object
This constructor will assign default values to properties that have it defined,
and makes sure properties required by API are set, but the set of arguments
will change when the set of required properties is changed

### NewPartialMemberWithDefaults

`func NewPartialMemberWithDefaults() *PartialMember`

NewPartialMemberWithDefaults instantiates a new PartialMember object
This constructor will only assign default values to properties that have it defined,
but it doesn't guarantee that properties required by API are set

### GetName

`func (o *PartialMember) GetName() string`

GetName returns the Name field if non-nil, zero value otherwise.

### GetNameOk

`func (o *PartialMember) GetNameOk() (*string, bool)`

GetNameOk returns a tuple with the Name field if it's non-nil, zero value otherwise
and a boolean to check if the value has been set.

### SetName

`func (o *PartialMember) SetName(v string)`

SetName sets Name field to given value.

### HasName

`func (o *PartialMember) HasName() bool`

HasName returns a boolean if a field has been set.

### GetPronouns

`func (o *PartialMember) GetPronouns() []Pronoun`

GetPronouns returns the Pronouns field if non-nil, zero value otherwise.

### GetPronounsOk

`func (o *PartialMember) GetPronounsOk() (*[]Pronoun, bool)`

GetPronounsOk returns a tuple with the Pronouns field if it's non-nil, zero value otherwise
and a boolean to check if the value has been set.

### SetPronouns

`func (o *PartialMember) SetPronouns(v []Pronoun)`

SetPronouns sets Pronouns field to given value.

### HasPronouns

`func (o *PartialMember) HasPronouns() bool`

HasPronouns returns a boolean if a field has been set.


[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


