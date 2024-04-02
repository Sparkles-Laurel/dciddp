#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "member.h"



member_t *member_create(
    char *name,
    list_t *pronouns,
    char *id
    ) {
    member_t *member_local_var = malloc(sizeof(member_t));
    if (!member_local_var) {
        return NULL;
    }
    member_local_var->name = name;
    member_local_var->pronouns = pronouns;
    member_local_var->id = id;

    return member_local_var;
}


void member_free(member_t *member) {
    if(NULL == member){
        return ;
    }
    listEntry_t *listEntry;
    if (member->name) {
        free(member->name);
        member->name = NULL;
    }
    if (member->pronouns) {
        list_ForEach(listEntry, member->pronouns) {
            pronoun_free(listEntry->data);
        }
        list_freeList(member->pronouns);
        member->pronouns = NULL;
    }
    if (member->id) {
        free(member->id);
        member->id = NULL;
    }
    free(member);
}

cJSON *member_convertToJSON(member_t *member) {
    cJSON *item = cJSON_CreateObject();

    // member->name
    if(member->name) {
    if(cJSON_AddStringToObject(item, "name", member->name) == NULL) {
    goto fail; //String
    }
    }


    // member->pronouns
    if(member->pronouns) {
    cJSON *pronouns = cJSON_AddArrayToObject(item, "pronouns");
    if(pronouns == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *pronounsListEntry;
    if (member->pronouns) {
    list_ForEach(pronounsListEntry, member->pronouns) {
    cJSON *itemLocal = pronoun_convertToJSON(pronounsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(pronouns, itemLocal);
    }
    }
    }


    // member->id
    if(member->id) {
    if(cJSON_AddStringToObject(item, "id", member->id) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

member_t *member_parseFromJSON(cJSON *memberJSON){

    member_t *member_local_var = NULL;

    // define the local list for member->pronouns
    list_t *pronounsList = NULL;

    // member->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(memberJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // member->pronouns
    cJSON *pronouns = cJSON_GetObjectItemCaseSensitive(memberJSON, "pronouns");
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

    // member->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(memberJSON, "id");
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }


    member_local_var = member_create (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        pronouns ? pronounsList : NULL,
        id && !cJSON_IsNull(id) ? strdup(id->valuestring) : NULL
        );

    return member_local_var;
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
