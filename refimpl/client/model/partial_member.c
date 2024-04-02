#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "partial_member.h"



partial_member_t *partial_member_create(
    char *name,
    list_t *pronouns
    ) {
    partial_member_t *partial_member_local_var = malloc(sizeof(partial_member_t));
    if (!partial_member_local_var) {
        return NULL;
    }
    partial_member_local_var->name = name;
    partial_member_local_var->pronouns = pronouns;

    return partial_member_local_var;
}


void partial_member_free(partial_member_t *partial_member) {
    if(NULL == partial_member){
        return ;
    }
    listEntry_t *listEntry;
    if (partial_member->name) {
        free(partial_member->name);
        partial_member->name = NULL;
    }
    if (partial_member->pronouns) {
        list_ForEach(listEntry, partial_member->pronouns) {
            pronoun_free(listEntry->data);
        }
        list_freeList(partial_member->pronouns);
        partial_member->pronouns = NULL;
    }
    free(partial_member);
}

cJSON *partial_member_convertToJSON(partial_member_t *partial_member) {
    cJSON *item = cJSON_CreateObject();

    // partial_member->name
    if(partial_member->name) {
    if(cJSON_AddStringToObject(item, "name", partial_member->name) == NULL) {
    goto fail; //String
    }
    }


    // partial_member->pronouns
    if(partial_member->pronouns) {
    cJSON *pronouns = cJSON_AddArrayToObject(item, "pronouns");
    if(pronouns == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *pronounsListEntry;
    if (partial_member->pronouns) {
    list_ForEach(pronounsListEntry, partial_member->pronouns) {
    cJSON *itemLocal = pronoun_convertToJSON(pronounsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(pronouns, itemLocal);
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

partial_member_t *partial_member_parseFromJSON(cJSON *partial_memberJSON){

    partial_member_t *partial_member_local_var = NULL;

    // define the local list for partial_member->pronouns
    list_t *pronounsList = NULL;

    // partial_member->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(partial_memberJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // partial_member->pronouns
    cJSON *pronouns = cJSON_GetObjectItemCaseSensitive(partial_memberJSON, "pronouns");
    if (pronouns) { 
    cJSON *pronouns_local_nonprimitive = NULL;
    if(!cJSON_IsArray(pronouns)){
        goto end; //nonprimitive container
    }

    pronounsList = list_createList();

    cJSON_ArrayForEach(pronouns_local_nonprimitive,pronouns )
    {
        if(!cJSON_IsObject(pronouns_local_nonprimitive)){
            goto end;
        }
        pronoun_t *pronounsItem = pronoun_parseFromJSON(pronouns_local_nonprimitive);

        list_addElement(pronounsList, pronounsItem);
    }
    }


    partial_member_local_var = partial_member_create (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        pronouns ? pronounsList : NULL
        );

    return partial_member_local_var;
end:
    if (pronounsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, pronounsList) {
            pronoun_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(pronounsList);
        pronounsList = NULL;
    }
    return NULL;

}
