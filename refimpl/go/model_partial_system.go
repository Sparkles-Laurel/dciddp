/*
 * DCIDDP
 *
 * The Decentralised Identity Dispatch Protocol (DCIDDP) is a protocol that allows for dispension  of name and pronoun information in a decentralised manner, for rendering in a user interface.  The protocol is designed to be simple, lightweight, and easy to implement. 
 *
 * API version: 1.0.0
 * Generated by: OpenAPI Generator (https://openapi-generator.tech)
 */

package openapi




type PartialSystem struct {

	// The ID of the system
	Id string `json:"id,omitempty"`

	// The name of the system
	Name string `json:"name,omitempty"`
}

// AssertPartialSystemRequired checks if the required fields are not zero-ed
func AssertPartialSystemRequired(obj PartialSystem) error {
	return nil
}

// AssertPartialSystemConstraints checks if the values respects the defined constraints
func AssertPartialSystemConstraints(obj PartialSystem) error {
	return nil
}
