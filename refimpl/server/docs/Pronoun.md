# Pronoun

## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Subject** | Pointer to **string** | The subject pronoun | [optional] 
**Object** | Pointer to **string** | The object pronoun | [optional] 
**Possessive** | Pointer to **string** | The possessive pronoun | [optional] 
**PossessiveDeterminer** | Pointer to **string** | The possessive determiner | [optional] 
**Reflexive** | Pointer to **string** | The reflexive pronoun | [optional] 

## Methods

### NewPronoun

`func NewPronoun() *Pronoun`

NewPronoun instantiates a new Pronoun object
This constructor will assign default values to properties that have it defined,
and makes sure properties required by API are set, but the set of arguments
will change when the set of required properties is changed

### NewPronounWithDefaults

`func NewPronounWithDefaults() *Pronoun`

NewPronounWithDefaults instantiates a new Pronoun object
This constructor will only assign default values to properties that have it defined,
but it doesn't guarantee that properties required by API are set

### GetSubject

`func (o *Pronoun) GetSubject() string`

GetSubject returns the Subject field if non-nil, zero value otherwise.

### GetSubjectOk

`func (o *Pronoun) GetSubjectOk() (*string, bool)`

GetSubjectOk returns a tuple with the Subject field if it's non-nil, zero value otherwise
and a boolean to check if the value has been set.

### SetSubject

`func (o *Pronoun) SetSubject(v string)`

SetSubject sets Subject field to given value.

### HasSubject

`func (o *Pronoun) HasSubject() bool`

HasSubject returns a boolean if a field has been set.

### GetObject

`func (o *Pronoun) GetObject() string`

GetObject returns the Object field if non-nil, zero value otherwise.

### GetObjectOk

`func (o *Pronoun) GetObjectOk() (*string, bool)`

GetObjectOk returns a tuple with the Object field if it's non-nil, zero value otherwise
and a boolean to check if the value has been set.

### SetObject

`func (o *Pronoun) SetObject(v string)`

SetObject sets Object field to given value.

### HasObject

`func (o *Pronoun) HasObject() bool`

HasObject returns a boolean if a field has been set.

### GetPossessive

`func (o *Pronoun) GetPossessive() string`

GetPossessive returns the Possessive field if non-nil, zero value otherwise.

### GetPossessiveOk

`func (o *Pronoun) GetPossessiveOk() (*string, bool)`

GetPossessiveOk returns a tuple with the Possessive field if it's non-nil, zero value otherwise
and a boolean to check if the value has been set.

### SetPossessive

`func (o *Pronoun) SetPossessive(v string)`

SetPossessive sets Possessive field to given value.

### HasPossessive

`func (o *Pronoun) HasPossessive() bool`

HasPossessive returns a boolean if a field has been set.

### GetPossessiveDeterminer

`func (o *Pronoun) GetPossessiveDeterminer() string`

GetPossessiveDeterminer returns the PossessiveDeterminer field if non-nil, zero value otherwise.

### GetPossessiveDeterminerOk

`func (o *Pronoun) GetPossessiveDeterminerOk() (*string, bool)`

GetPossessiveDeterminerOk returns a tuple with the PossessiveDeterminer field if it's non-nil, zero value otherwise
and a boolean to check if the value has been set.

### SetPossessiveDeterminer

`func (o *Pronoun) SetPossessiveDeterminer(v string)`

SetPossessiveDeterminer sets PossessiveDeterminer field to given value.

### HasPossessiveDeterminer

`func (o *Pronoun) HasPossessiveDeterminer() bool`

HasPossessiveDeterminer returns a boolean if a field has been set.

### GetReflexive

`func (o *Pronoun) GetReflexive() string`

GetReflexive returns the Reflexive field if non-nil, zero value otherwise.

### GetReflexiveOk

`func (o *Pronoun) GetReflexiveOk() (*string, bool)`

GetReflexiveOk returns a tuple with the Reflexive field if it's non-nil, zero value otherwise
and a boolean to check if the value has been set.

### SetReflexive

`func (o *Pronoun) SetReflexive(v string)`

SetReflexive sets Reflexive field to given value.

### HasReflexive

`func (o *Pronoun) HasReflexive() bool`

HasReflexive returns a boolean if a field has been set.


[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


