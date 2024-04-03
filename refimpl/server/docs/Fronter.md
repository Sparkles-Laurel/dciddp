# Fronter

## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Id** | Pointer to **string** | The ID of the fronter | [optional] 
**Name** | Pointer to **string** | The name of the fronter | [optional] 
**Pronouns** | Pointer to [**[]Pronoun**](Pronoun.md) | Pronouns of the fronter | [optional] 

## Methods

### NewFronter

`func NewFronter() *Fronter`

NewFronter instantiates a new Fronter object
This constructor will assign default values to properties that have it defined,
and makes sure properties required by API are set, but the set of arguments
will change when the set of required properties is changed

### NewFronterWithDefaults

`func NewFronterWithDefaults() *Fronter`

NewFronterWithDefaults instantiates a new Fronter object
This constructor will only assign default values to properties that have it defined,
but it doesn't guarantee that properties required by API are set

### GetId

`func (o *Fronter) GetId() string`

GetId returns the Id field if non-nil, zero value otherwise.

### GetIdOk

`func (o *Fronter) GetIdOk() (*string, bool)`

GetIdOk returns a tuple with the Id field if it's non-nil, zero value otherwise
and a boolean to check if the value has been set.

### SetId

`func (o *Fronter) SetId(v string)`

SetId sets Id field to given value.

### HasId

`func (o *Fronter) HasId() bool`

HasId returns a boolean if a field has been set.

### GetName

`func (o *Fronter) GetName() string`

GetName returns the Name field if non-nil, zero value otherwise.

### GetNameOk

`func (o *Fronter) GetNameOk() (*string, bool)`

GetNameOk returns a tuple with the Name field if it's non-nil, zero value otherwise
and a boolean to check if the value has been set.

### SetName

`func (o *Fronter) SetName(v string)`

SetName sets Name field to given value.

### HasName

`func (o *Fronter) HasName() bool`

HasName returns a boolean if a field has been set.

### GetPronouns

`func (o *Fronter) GetPronouns() []Pronoun`

GetPronouns returns the Pronouns field if non-nil, zero value otherwise.

### GetPronounsOk

`func (o *Fronter) GetPronounsOk() (*[]Pronoun, bool)`

GetPronounsOk returns a tuple with the Pronouns field if it's non-nil, zero value otherwise
and a boolean to check if the value has been set.

### SetPronouns

`func (o *Fronter) SetPronouns(v []Pronoun)`

SetPronouns sets Pronouns field to given value.

### HasPronouns

`func (o *Fronter) HasPronouns() bool`

HasPronouns returns a boolean if a field has been set.


[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


