#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "partial_system.h"



partial_system_t *partial_system_create(
    char *id,
    char *name
    ) {
    partial_system_t *partial_system_local_var = malloc(sizeof(partial_system_t));
    if (!partial_system_local_var) {
        return NULL;
    }
    partial_system_local_var->id = id;
    partial_system_local_var->name = name;

    return partial_system_local_var;
}


void partial_system_free(partial_system_t *partial_system) {
    if(NULL == partial_system){
        return ;
    }
    listEntry_t *listEntry;
    if (partial_system->id) {
        free(partial_system->id);
        partial_system->id = NULL;
    }
    if (partial_system->name) {
        free(partial_system->name);
        partial_system->name = NULL;
    }
    free(partial_system);
}

cJSON *partial_system_convertToJSON(partial_system_t *partial_system) {
    cJSON *item = cJSON_CreateObject();

    // partial_system->id
    if(partial_system->id) {
    if(cJSON_AddStringToObject(item, "id", partial_system->id) == NULL) {
    goto fail; //String
    }
    }


    // partial_system->name
    if(partial_system->name) {
    if(cJSON_AddStringToObject(item, "name", partial_system->name) == NULL) {
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

partial_system_t *partial_system_parseFromJSON(cJSON *partial_systemJSON){

    partial_system_t *partial_system_local_var = NULL;

    // partial_system->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(partial_systemJSON, "id");
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // partial_system->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(partial_systemJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }


    partial_system_local_var = partial_system_create (
        id && !cJSON_IsNull(id) ? strdup(id->valuestring) : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL
        );

    return partial_system_local_var;
end:
    return NULL;

}
