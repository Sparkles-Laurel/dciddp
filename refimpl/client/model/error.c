#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "error.h"



error_t *error_create(
    int code,
    char *error
    ) {
    error_t *error_local_var = malloc(sizeof(error_t));
    if (!error_local_var) {
        return NULL;
    }
    error_local_var->code = code;
    error_local_var->error = error;

    return error_local_var;
}


void error_free(error_t *error) {
    if(NULL == error){
        return ;
    }
    listEntry_t *listEntry;
    if (error->error) {
        free(error->error);
        error->error = NULL;
    }
    free(error);
}

cJSON *error_convertToJSON(error_t *error) {
    cJSON *item = cJSON_CreateObject();

    // error->code
    if(error->code) {
    if(cJSON_AddNumberToObject(item, "code", error->code) == NULL) {
    goto fail; //Numeric
    }
    }


    // error->error
    if(error->error) {
    if(cJSON_AddStringToObject(item, "error", error->error) == NULL) {
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

error_t *error_parseFromJSON(cJSON *errorJSON){

    error_t *error_local_var = NULL;

    // error->code
    cJSON *code = cJSON_GetObjectItemCaseSensitive(errorJSON, "code");
    if (code) { 
    if(!cJSON_IsNumber(code))
    {
    goto end; //Numeric
    }
    }

    // error->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(errorJSON, "error");
    if (error) { 
    if(!cJSON_IsString(error) && !cJSON_IsNull(error))
    {
    goto end; //String
    }
    }


    error_local_var = error_create (
        code ? code->valuedouble : 0,
        error && !cJSON_IsNull(error) ? strdup(error->valuestring) : NULL
        );

    return error_local_var;
end:
    return NULL;

}
