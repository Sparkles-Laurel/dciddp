#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "fronter.h"



fronter_t *fronter_create(
    char *id,
    char *name,
    list_t *pronouns
    ) {
    fronter_t *fronter_local_var = malloc(sizeof(fronter_t));
    if (!fronter_local_var) {
        return NULL;
    }
    fronter_local_var->id = id;
    fronter_local_var->name = name;
    fronter_local_var->pronouns = pronouns;

    return fronter_local_var;
}


void fronter_free(fronter_t *fronter) {
    if(NULL == fronter){
        return ;
    }
    listEntry_t *listEntry;
    if (fronter->id) {
        free(fronter->id);
        fronter->id = NULL;
    }
    if (fronter->name) {
        free(fronter->name);
        fronter->name = NULL;
    }
    if (fronter->pronouns) {
        list_ForEach(listEntry, fronter->pronouns) {
            pronoun_free(listEntry->data);
        }
        list_freeList(fronter->pronouns);
        fronter->pronouns = NULL;
    }
    free(fronter);
}

cJSON *fronter_convertToJSON(fronter_t *fronter) {
    cJSON *item = cJSON_CreateObject();

    // fronter->id
    if(fronter->id) {
    if(cJSON_AddStringToObject(item, "id", fronter->id) == NULL) {
    goto fail; //String
    }
    }


    // fronter->name
    if(fronter->name) {
    if(cJSON_AddStringToObject(item, "name", fronter->name) == NULL) {
    goto fail; //String
    }
    }


    // fronter->pronouns
    if(fronter->pronouns) {
    cJSON *pronouns = cJSON_AddArrayToObject(item, "pronouns");
    if(pronouns == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *pronounsListEntry;
    if (fronter->pronouns) {
    list_ForEach(pronounsListEntry, fronter->pronouns) {
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

fronter_t *fronter_parseFromJSON(cJSON *fronterJSON){

    fronter_t *fronter_local_var = NULL;

    // define the local list for fronter->pronouns
    list_t *pronounsList = NULL;

    // fronter->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(fronterJSON, "id");
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // fronter->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(fronterJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // fronter->pronouns
    cJSON *pronouns = cJSON_GetObjectItemCaseSensitive(fronterJSON, "pronouns");
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


    fronter_local_var = fronter_create (
        id && !cJSON_IsNull(id) ? strdup(id->valuestring) : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        pronouns ? pronounsList : NULL
        );

    return fronter_local_var;
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
