/*
 * DCIDDP
 *
 * The Decentralised Identity Dispatch Protocol (DCIDDP) is a protocol that allows for dispension  of name and pronoun information in a decentralised manner, for rendering in a user interface.  The protocol is designed to be simple, lightweight, and easy to implement. 
 *
 * API version: 1.0.0
 * Generated by: OpenAPI Generator (https://openapi-generator.tech)
 */

package openapi

import (
	"encoding/json"
	"net/http"
	"strings"

	"github.com/gorilla/mux"
)

// DefaultAPIController binds http requests to an api service and writes the service results to the http response
type DefaultAPIController struct {
	service DefaultAPIServicer
	errorHandler ErrorHandler
}

// DefaultAPIOption for how the controller is set up.
type DefaultAPIOption func(*DefaultAPIController)

// WithDefaultAPIErrorHandler inject ErrorHandler into controller
func WithDefaultAPIErrorHandler(h ErrorHandler) DefaultAPIOption {
	return func(c *DefaultAPIController) {
		c.errorHandler = h
	}
}

// NewDefaultAPIController creates a default api controller
func NewDefaultAPIController(s DefaultAPIServicer, opts ...DefaultAPIOption) Router {
	controller := &DefaultAPIController{
		service:      s,
		errorHandler: DefaultErrorHandler,
	}

	for _, opt := range opts {
		opt(controller)
	}

	return controller
}

// Routes returns all the api routes for the DefaultAPIController
func (c *DefaultAPIController) Routes() Routes {
	return Routes{
		"SystemPost": Route{
			strings.ToUpper("Post"),
			"/system",
			c.SystemPost,
		},
		"SystemSystemFrontersGet": Route{
			strings.ToUpper("Get"),
			"/system/{system}/fronters",
			c.SystemSystemFrontersGet,
		},
		"SystemSystemFrontersPut": Route{
			strings.ToUpper("Put"),
			"/system/{system}/fronters",
			c.SystemSystemFrontersPut,
		},
		"SystemSystemGet": Route{
			strings.ToUpper("Get"),
			"/system/{system}",
			c.SystemSystemGet,
		},
		"SystemSystemMemberMemberGet": Route{
			strings.ToUpper("Get"),
			"/system/{system}/member/{member}",
			c.SystemSystemMemberMemberGet,
		},
		"SystemSystemMemberMemberPronounsGet": Route{
			strings.ToUpper("Get"),
			"/system/{system}/member/{member}/pronouns",
			c.SystemSystemMemberMemberPronounsGet,
		},
		"SystemSystemMembersPost": Route{
			strings.ToUpper("Post"),
			"/system/{system}/members",
			c.SystemSystemMembersPost,
		},
	}
}

// SystemPost - Create a new plural system
func (c *DefaultAPIController) SystemPost(w http.ResponseWriter, r *http.Request) {
	partialSystemParam := PartialSystem{}
	d := json.NewDecoder(r.Body)
	d.DisallowUnknownFields()
	if err := d.Decode(&partialSystemParam); err != nil {
		c.errorHandler(w, r, &ParsingError{Err: err}, nil)
		return
	}
	if err := AssertPartialSystemRequired(partialSystemParam); err != nil {
		c.errorHandler(w, r, err, nil)
		return
	}
	if err := AssertPartialSystemConstraints(partialSystemParam); err != nil {
		c.errorHandler(w, r, err, nil)
		return
	}
	result, err := c.service.SystemPost(r.Context(), partialSystemParam)
	// If an error occurred, encode the error with the status code
	if err != nil {
		c.errorHandler(w, r, err, &result)
		return
	}
	// If no error, encode the body and the result code
	EncodeJSONResponse(result.Body, &result.Code, w)
}

// SystemSystemFrontersGet - Retrieves the current fronters' API paths
func (c *DefaultAPIController) SystemSystemFrontersGet(w http.ResponseWriter, r *http.Request) {
	params := mux.Vars(r)
	systemParam := params["system"]
	if systemParam == "" {
		c.errorHandler(w, r, &RequiredError{"system"}, nil)
		return
	}
	result, err := c.service.SystemSystemFrontersGet(r.Context(), systemParam)
	// If an error occurred, encode the error with the status code
	if err != nil {
		c.errorHandler(w, r, err, &result)
		return
	}
	// If no error, encode the body and the result code
	EncodeJSONResponse(result.Body, &result.Code, w)
}

// SystemSystemFrontersPut - Set the fronter of a plural system
func (c *DefaultAPIController) SystemSystemFrontersPut(w http.ResponseWriter, r *http.Request) {
	params := mux.Vars(r)
	systemParam := params["system"]
	if systemParam == "" {
		c.errorHandler(w, r, &RequiredError{"system"}, nil)
		return
	}
	requestBodyParam := []string{}
	d := json.NewDecoder(r.Body)
	d.DisallowUnknownFields()
	if err := d.Decode(&requestBodyParam); err != nil {
		c.errorHandler(w, r, &ParsingError{Err: err}, nil)
		return
	}
	result, err := c.service.SystemSystemFrontersPut(r.Context(), systemParam, requestBodyParam)
	// If an error occurred, encode the error with the status code
	if err != nil {
		c.errorHandler(w, r, err, &result)
		return
	}
	// If no error, encode the body and the result code
	EncodeJSONResponse(result.Body, &result.Code, w)
}

// SystemSystemGet - Get plural system information
func (c *DefaultAPIController) SystemSystemGet(w http.ResponseWriter, r *http.Request) {
	params := mux.Vars(r)
	systemParam := params["system"]
	if systemParam == "" {
		c.errorHandler(w, r, &RequiredError{"system"}, nil)
		return
	}
	result, err := c.service.SystemSystemGet(r.Context(), systemParam)
	// If an error occurred, encode the error with the status code
	if err != nil {
		c.errorHandler(w, r, err, &result)
		return
	}
	// If no error, encode the body and the result code
	EncodeJSONResponse(result.Body, &result.Code, w)
}

// SystemSystemMemberMemberGet - Get member information
func (c *DefaultAPIController) SystemSystemMemberMemberGet(w http.ResponseWriter, r *http.Request) {
	params := mux.Vars(r)
	systemParam := params["system"]
	if systemParam == "" {
		c.errorHandler(w, r, &RequiredError{"system"}, nil)
		return
	}
	memberParam := params["member"]
	if memberParam == "" {
		c.errorHandler(w, r, &RequiredError{"member"}, nil)
		return
	}
	result, err := c.service.SystemSystemMemberMemberGet(r.Context(), systemParam, memberParam)
	// If an error occurred, encode the error with the status code
	if err != nil {
		c.errorHandler(w, r, err, &result)
		return
	}
	// If no error, encode the body and the result code
	EncodeJSONResponse(result.Body, &result.Code, w)
}

// SystemSystemMemberMemberPronounsGet - Get member pronouns
func (c *DefaultAPIController) SystemSystemMemberMemberPronounsGet(w http.ResponseWriter, r *http.Request) {
	params := mux.Vars(r)
	systemParam := params["system"]
	if systemParam == "" {
		c.errorHandler(w, r, &RequiredError{"system"}, nil)
		return
	}
	memberParam := params["member"]
	if memberParam == "" {
		c.errorHandler(w, r, &RequiredError{"member"}, nil)
		return
	}
	result, err := c.service.SystemSystemMemberMemberPronounsGet(r.Context(), systemParam, memberParam)
	// If an error occurred, encode the error with the status code
	if err != nil {
		c.errorHandler(w, r, err, &result)
		return
	}
	// If no error, encode the body and the result code
	EncodeJSONResponse(result.Body, &result.Code, w)
}

// SystemSystemMembersPost - Add a new member to a plural system
func (c *DefaultAPIController) SystemSystemMembersPost(w http.ResponseWriter, r *http.Request) {
	params := mux.Vars(r)
	systemParam := params["system"]
	if systemParam == "" {
		c.errorHandler(w, r, &RequiredError{"system"}, nil)
		return
	}
	partialMemberParam := PartialMember{}
	d := json.NewDecoder(r.Body)
	d.DisallowUnknownFields()
	if err := d.Decode(&partialMemberParam); err != nil {
		c.errorHandler(w, r, &ParsingError{Err: err}, nil)
		return
	}
	if err := AssertPartialMemberRequired(partialMemberParam); err != nil {
		c.errorHandler(w, r, err, nil)
		return
	}
	if err := AssertPartialMemberConstraints(partialMemberParam); err != nil {
		c.errorHandler(w, r, err, nil)
		return
	}
	result, err := c.service.SystemSystemMembersPost(r.Context(), systemParam, partialMemberParam)
	// If an error occurred, encode the error with the status code
	if err != nil {
		c.errorHandler(w, r, err, &result)
		return
	}
	// If no error, encode the body and the result code
	EncodeJSONResponse(result.Body, &result.Code, w)
}
