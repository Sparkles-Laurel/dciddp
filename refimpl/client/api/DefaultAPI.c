#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "DefaultAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)


// Create a new plural system
//
// Create a new plural system with the specified name and pronouns
//
system_t*
DefaultAPI_systemPost(apiClient_t *apiClient, partial_system_t *partial_system)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/system")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/system");




    // Body Param
    cJSON *localVarSingleItemJSON_partial_system = NULL;
    if (partial_system != NULL)
    {
        //string
        localVarSingleItemJSON_partial_system = partial_system_convertToJSON(partial_system);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_partial_system);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 201) {
    //    printf("%s\n","System created");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request");
    //}
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    system_t *elementToReturn = system_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_partial_system) {
        cJSON_Delete(localVarSingleItemJSON_partial_system);
        localVarSingleItemJSON_partial_system = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Retrieves the current fronters' API paths
//
// Retrieves the list of the current fronter(s)
//
list_t*
DefaultAPI_systemSystemFrontersGet(apiClient_t *apiClient, char *system)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/system/{system}/fronters")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/system/{system}/fronters");


    // Path Params
    long sizeOfPathParams_system = strlen(system)+3 + strlen("{ system }");
    if(system == NULL) {
        goto end;
    }
    char* localVarToReplace_system = malloc(sizeOfPathParams_system);
    sprintf(localVarToReplace_system, "{%s}", "system");

    localVarPath = strReplace(localVarPath, localVarToReplace_system, system);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","The current fronter(s)");
    //}
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    if(!cJSON_IsArray(DefaultAPIlocalVarJSON)) {
        return 0;//nonprimitive container
    }
    list_t *elementToReturn = list_createList();
    cJSON *VarJSON;
    cJSON_ArrayForEach(VarJSON, DefaultAPIlocalVarJSON)
    {
        if(!cJSON_IsObject(VarJSON))
        {
           // return 0;
        }
        char *localVarJSONToChar = cJSON_Print(VarJSON);
        list_addElement(elementToReturn , localVarJSONToChar);
    }

    cJSON_Delete( DefaultAPIlocalVarJSON);
    cJSON_Delete( VarJSON);
    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_system);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Set the fronter of a plural system
//
// Set the fronter of a plural system to the specified member
//
void
DefaultAPI_systemSystemFrontersPut(apiClient_t *apiClient, char *system, list_t *request_body)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/system/{system}/fronters")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/system/{system}/fronters");


    // Path Params
    long sizeOfPathParams_system = strlen(system)+3 + strlen("{ system }");
    if(system == NULL) {
        goto end;
    }
    char* localVarToReplace_system = malloc(sizeOfPathParams_system);
    sprintf(localVarToReplace_system, "{%s}", "system");

    localVarPath = strReplace(localVarPath, localVarToReplace_system, system);



    // Body Param
    //notstring
    cJSON *localVar_request_body = NULL;
    cJSON *localVarItemJSON_request_body = NULL;
    cJSON *localVarSingleItemJSON_request_body = NULL;
    if (request_body != NULL)
    {
        localVarItemJSON_request_body = cJSON_CreateObject();
        localVarSingleItemJSON_request_body = cJSON_AddArrayToObject(localVarItemJSON_request_body, "request_body");
        if (localVarSingleItemJSON_request_body == NULL)
        {
            // nonprimitive container

            goto end;
        }
    }

    listEntry_t *request_bodyBodyListEntry;
    list_ForEach(request_bodyBodyListEntry, request_body)
    {
        localVar_request_body = _convertToJSON(request_bodyBodyListEntry->data);
        if(localVar_request_body == NULL)
        {
            goto end;
        }
        cJSON_AddItemToArray(localVarSingleItemJSON_request_body, localVar_request_body);
        localVarBodyParameters = cJSON_Print(localVarItemJSON_request_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PUT");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Fronter set");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_system);
    if (localVarItemJSON_request_body) {
        cJSON_Delete(localVarItemJSON_request_body);
        localVarItemJSON_request_body = NULL;
    }
    if (localVarSingleItemJSON_request_body) {
        cJSON_Delete(localVarSingleItemJSON_request_body);
        localVarSingleItemJSON_request_body = NULL;
    }
    if (localVar_request_body) {
        cJSON_Delete(localVar_request_body);
        localVar_request_body = NULL;
    }
    free(localVarBodyParameters);

}

// Get plural system information
//
// Retrieve information about a plural system
//
system_t*
DefaultAPI_systemSystemGet(apiClient_t *apiClient, char *system)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/system/{system}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/system/{system}");


    // Path Params
    long sizeOfPathParams_system = strlen(system)+3 + strlen("{ system }");
    if(system == NULL) {
        goto end;
    }
    char* localVarToReplace_system = malloc(sizeOfPathParams_system);
    sprintf(localVarToReplace_system, "{%s}", "system");

    localVarPath = strReplace(localVarPath, localVarToReplace_system, system);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Information about the system");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","System not found");
    //}
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    system_t *elementToReturn = system_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_system);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get member information
//
// Retrieve information about a member of a plural system
//
member_t*
DefaultAPI_systemSystemMemberMemberGet(apiClient_t *apiClient, char *system, char *member)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/system/{system}/member/{member}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/system/{system}/member/{member}");


    // Path Params
    long sizeOfPathParams_system = strlen(system)+3 + strlen(member)+3 + strlen("{ system }");
    if(system == NULL) {
        goto end;
    }
    char* localVarToReplace_system = malloc(sizeOfPathParams_system);
    sprintf(localVarToReplace_system, "{%s}", "system");

    localVarPath = strReplace(localVarPath, localVarToReplace_system, system);

    // Path Params
    long sizeOfPathParams_member = strlen(system)+3 + strlen(member)+3 + strlen("{ member }");
    if(member == NULL) {
        goto end;
    }
    char* localVarToReplace_member = malloc(sizeOfPathParams_member);
    sprintf(localVarToReplace_member, "{%s}", "member");

    localVarPath = strReplace(localVarPath, localVarToReplace_member, member);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Information about the member");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Member not found");
    //}
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    member_t *elementToReturn = member_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_system);
    free(localVarToReplace_member);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get member pronouns
//
// Retrieve pronouns of a member of a plural system
//
list_t*
DefaultAPI_systemSystemMemberMemberPronounsGet(apiClient_t *apiClient, char *system, char *member)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/system/{system}/member/{member}/pronouns")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/system/{system}/member/{member}/pronouns");


    // Path Params
    long sizeOfPathParams_system = strlen(system)+3 + strlen(member)+3 + strlen("{ system }");
    if(system == NULL) {
        goto end;
    }
    char* localVarToReplace_system = malloc(sizeOfPathParams_system);
    sprintf(localVarToReplace_system, "{%s}", "system");

    localVarPath = strReplace(localVarPath, localVarToReplace_system, system);

    // Path Params
    long sizeOfPathParams_member = strlen(system)+3 + strlen(member)+3 + strlen("{ member }");
    if(member == NULL) {
        goto end;
    }
    char* localVarToReplace_member = malloc(sizeOfPathParams_member);
    sprintf(localVarToReplace_member, "{%s}", "member");

    localVarPath = strReplace(localVarPath, localVarToReplace_member, member);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Pronouns of the member");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Member not found");
    //}
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    if(!cJSON_IsArray(DefaultAPIlocalVarJSON)) {
        return 0;//nonprimitive container
    }
    list_t *elementToReturn = list_createList();
    cJSON *VarJSON;
    cJSON_ArrayForEach(VarJSON, DefaultAPIlocalVarJSON)
    {
        if(!cJSON_IsObject(VarJSON))
        {
           // return 0;
        }
        char *localVarJSONToChar = cJSON_Print(VarJSON);
        list_addElement(elementToReturn , localVarJSONToChar);
    }

    cJSON_Delete( DefaultAPIlocalVarJSON);
    cJSON_Delete( VarJSON);
    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_system);
    free(localVarToReplace_member);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Add a new member to a plural system
//
// Add a new member to a plural system with the specified name and pronouns
//
member_t*
DefaultAPI_systemSystemMembersPost(apiClient_t *apiClient, char *system, partial_member_t *partial_member)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/system/{system}/members")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/system/{system}/members");


    // Path Params
    long sizeOfPathParams_system = strlen(system)+3 + strlen("{ system }");
    if(system == NULL) {
        goto end;
    }
    char* localVarToReplace_system = malloc(sizeOfPathParams_system);
    sprintf(localVarToReplace_system, "{%s}", "system");

    localVarPath = strReplace(localVarPath, localVarToReplace_system, system);



    // Body Param
    cJSON *localVarSingleItemJSON_partial_member = NULL;
    if (partial_member != NULL)
    {
        //string
        localVarSingleItemJSON_partial_member = partial_member_convertToJSON(partial_member);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_partial_member);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 201) {
    //    printf("%s\n","Member added");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request");
    //}
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    member_t *elementToReturn = member_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_system);
    if (localVarSingleItemJSON_partial_member) {
        cJSON_Delete(localVarSingleItemJSON_partial_member);
        localVarSingleItemJSON_partial_member = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

