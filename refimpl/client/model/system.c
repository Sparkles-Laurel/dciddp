#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "system.h"



system_t *system_create(
    char *id,
    char *name,
    char *pronouns,
    list_t *fronters,
    list_t *members
    ) {
    system_t *system_local_var = malloc(sizeof(system_t));
    if (!system_local_var) {
        return NULL;
    }
    system_local_var->id = id;
    system_local_var->name = name;
    system_local_var->pronouns = pronouns;
    system_local_var->fronters = fronters;
    system_local_var->members = members;

    return system_local_var;
}


void system_free(system_t *system) {
    if(NULL == system){
        return ;
    }
    listEntry_t *listEntry;
    if (system->id) {
        free(system->id);
        system->id = NULL;
    }
    if (system->name) {
        free(system->name);
        system->name = NULL;
    }
    if (system->pronouns) {
        free(system->pronouns);
        system->pronouns = NULL;
    }
    if (system->fronters) {
        list_ForEach(listEntry, system->fronters) {
            fronter_free(listEntry->data);
        }
        list_freeList(system->fronters);
        system->fronters = NULL;
    }
    if (system->members) {
        list_ForEach(listEntry, system->members) {
            member_free(listEntry->data);
        }
        list_freeList(system->members);
        system->members = NULL;
    }
    free(system);
}

cJSON *system_convertToJSON(system_t *system) {
    cJSON *item = cJSON_CreateObject();

    // system->id
    if(system->id) {
    if(cJSON_AddStringToObject(item, "id", system->id) == NULL) {
    goto fail; //String
    }
    }


    // system->name
    if(system->name) {
    if(cJSON_AddStringToObject(item, "name", system->name) == NULL) {
    goto fail; //String
    }
    }


    // system->pronouns
    if(system->pronouns) {
    if(cJSON_AddStringToObject(item, "pronouns", system->pronouns) == NULL) {
    goto fail; //String
    }
    }


    // system->fronters
    if(system->fronters) {
    cJSON *fronters = cJSON_AddArrayToObject(item, "fronters");
    if(fronters == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *frontersListEntry;
    if (system->fronters) {
    list_ForEach(frontersListEntry, system->fronters) {
    cJSON *itemLocal = fronter_convertToJSON(frontersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(fronters, itemLocal);
    }
    }
    }


    // system->members
    if(system->members) {
    cJSON *members = cJSON_AddArrayToObject(item, "members");
    if(members == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *membersListEntry;
    if (system->members) {
    list_ForEach(membersListEntry, system->members) {
    cJSON *itemLocal = member_convertToJSON(membersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(members, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

system_t *system_parseFromJSON(cJSON *systemJSON){

    system_t *system_local_var = NULL;

    // define the local list for system->fronters
    list_t *frontersList = NULL;

    // define the local list for system->members
    list_t *membersList = NULL;

    // system->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(systemJSON, "id");
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // system->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(systemJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // system->pronouns
    cJSON *pronouns = cJSON_GetObjectItemCaseSensitive(systemJSON, "pronouns");
    if (pronouns) { 
    if(!cJSON_IsString(pronouns) && !cJSON_IsNull(pronouns))
    {
    goto end; //String
    }
    }

    // system->fronters
    cJSON *fronters = cJSON_GetObjectItemCaseSensitive(systemJSON, "fronters");
    if (fronters) { 
    cJSON *fronters_local_nonprimitive = NULL;
    if(!cJSON_IsArray(fronters)){
        goto end; //nonprimitive container
    }

    frontersList = list_createList();

    cJSON_ArrayForEach(fronters_local_nonprimitive,fronters )
    {
        if(!cJSON_IsObject(fronters_local_nonprimitive)){
            goto end;
        }
        fronter_t *frontersItem = fronter_parseFromJSON(fronters_local_nonprimitive);

        list_addElement(frontersList, frontersItem);
    }
    }

    // system->members
    cJSON *members = cJSON_GetObjectItemCaseSensitive(systemJSON, "members");
    if (members) { 
    cJSON *members_local_nonprimitive = NULL;
    if(!cJSON_IsArray(members)){
        goto end; //nonprimitive container
    }

    membersList = list_createList();

    cJSON_ArrayForEach(members_local_nonprimitive,members )
    {
        if(!cJSON_IsObject(members_local_nonprimitive)){
            goto end;
        }
        member_t *membersItem = member_parseFromJSON(members_local_nonprimitive);

        list_addElement(membersList, membersItem);
    }
    }


    system_local_var = system_create (
        id && !cJSON_IsNull(id) ? strdup(id->valuestring) : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        pronouns && !cJSON_IsNull(pronouns) ? strdup(pronouns->valuestring) : NULL,
        fronters ? frontersList : NULL,
        members ? membersList : NULL
        );

    return system_local_var;
end:
    if (frontersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, frontersList) {
            fronter_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(frontersList);
        frontersList = NULL;
    }
    if (membersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, membersList) {
            member_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(membersList);
        membersList = NULL;
    }
    return NULL;

}
