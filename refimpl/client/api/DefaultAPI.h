#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/error.h"
#include "../model/fronter.h"
#include "../model/member.h"
#include "../model/partial_member.h"
#include "../model/partial_system.h"
#include "../model/pronoun.h"
#include "../model/system.h"


// Create a new plural system
//
// Create a new plural system with the specified name and pronouns
//
system_t*
DefaultAPI_systemPost(apiClient_t *apiClient, partial_system_t *partial_system);


// Retrieves the current fronters' API paths
//
// Retrieves the list of the current fronter(s)
//
list_t*
DefaultAPI_systemSystemFrontersGet(apiClient_t *apiClient, char *system);


// Set the fronter of a plural system
//
// Set the fronter of a plural system to the specified member
//
void
DefaultAPI_systemSystemFrontersPut(apiClient_t *apiClient, char *system, list_t *request_body);


// Get plural system information
//
// Retrieve information about a plural system
//
system_t*
DefaultAPI_systemSystemGet(apiClient_t *apiClient, char *system);


// Get member information
//
// Retrieve information about a member of a plural system
//
member_t*
DefaultAPI_systemSystemMemberMemberGet(apiClient_t *apiClient, char *system, char *member);


// Get member pronouns
//
// Retrieve pronouns of a member of a plural system
//
list_t*
DefaultAPI_systemSystemMemberMemberPronounsGet(apiClient_t *apiClient, char *system, char *member);


// Add a new member to a plural system
//
// Add a new member to a plural system with the specified name and pronouns
//
member_t*
DefaultAPI_systemSystemMembersPost(apiClient_t *apiClient, char *system, partial_member_t *partial_member);


