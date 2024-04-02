#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pronoun.h"



pronoun_t *pronoun_create(
    char *subject,
    char *object,
    char *possessive,
    char *possessive_determiner,
    char *reflexive
    ) {
    pronoun_t *pronoun_local_var = malloc(sizeof(pronoun_t));
    if (!pronoun_local_var) {
        return NULL;
    }
    pronoun_local_var->subject = subject;
    pronoun_local_var->object = object;
    pronoun_local_var->possessive = possessive;
    pronoun_local_var->possessive_determiner = possessive_determiner;
    pronoun_local_var->reflexive = reflexive;

    return pronoun_local_var;
}


void pronoun_free(pronoun_t *pronoun) {
    if(NULL == pronoun){
        return ;
    }
    listEntry_t *listEntry;
    if (pronoun->subject) {
        free(pronoun->subject);
        pronoun->subject = NULL;
    }
    if (pronoun->object) {
        free(pronoun->object);
        pronoun->object = NULL;
    }
    if (pronoun->possessive) {
        free(pronoun->possessive);
        pronoun->possessive = NULL;
    }
    if (pronoun->possessive_determiner) {
        free(pronoun->possessive_determiner);
        pronoun->possessive_determiner = NULL;
    }
    if (pronoun->reflexive) {
        free(pronoun->reflexive);
        pronoun->reflexive = NULL;
    }
    free(pronoun);
}

cJSON *pronoun_convertToJSON(pronoun_t *pronoun) {
    cJSON *item = cJSON_CreateObject();

    // pronoun->subject
    if(pronoun->subject) {
    if(cJSON_AddStringToObject(item, "subject", pronoun->subject) == NULL) {
    goto fail; //String
    }
    }


    // pronoun->object
    if(pronoun->object) {
    if(cJSON_AddStringToObject(item, "object", pronoun->object) == NULL) {
    goto fail; //String
    }
    }


    // pronoun->possessive
    if(pronoun->possessive) {
    if(cJSON_AddStringToObject(item, "possessive", pronoun->possessive) == NULL) {
    goto fail; //String
    }
    }


    // pronoun->possessive_determiner
    if(pronoun->possessive_determiner) {
    if(cJSON_AddStringToObject(item, "possessive_determiner", pronoun->possessive_determiner) == NULL) {
    goto fail; //String
    }
    }


    // pronoun->reflexive
    if(pronoun->reflexive) {
    if(cJSON_AddStringToObject(item, "reflexive", pronoun->reflexive) == NULL) {
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

pronoun_t *pronoun_parseFromJSON(cJSON *pronounJSON){

    pronoun_t *pronoun_local_var = NULL;

    // pronoun->subject
    cJSON *subject = cJSON_GetObjectItemCaseSensitive(pronounJSON, "subject");
    if (subject) { 
    if(!cJSON_IsString(subject) && !cJSON_IsNull(subject))
    {
    goto end; //String
    }
    }

    // pronoun->object
    cJSON *object = cJSON_GetObjectItemCaseSensitive(pronounJSON, "object");
    if (object) { 
    if(!cJSON_IsString(object) && !cJSON_IsNull(object))
    {
    goto end; //String
    }
    }

    // pronoun->possessive
    cJSON *possessive = cJSON_GetObjectItemCaseSensitive(pronounJSON, "possessive");
    if (possessive) { 
    if(!cJSON_IsString(possessive) && !cJSON_IsNull(possessive))
    {
    goto end; //String
    }
    }

    // pronoun->possessive_determiner
    cJSON *possessive_determiner = cJSON_GetObjectItemCaseSensitive(pronounJSON, "possessive_determiner");
    if (possessive_determiner) { 
    if(!cJSON_IsString(possessive_determiner) && !cJSON_IsNull(possessive_determiner))
    {
    goto end; //String
    }
    }

    // pronoun->reflexive
    cJSON *reflexive = cJSON_GetObjectItemCaseSensitive(pronounJSON, "reflexive");
    if (reflexive) { 
    if(!cJSON_IsString(reflexive) && !cJSON_IsNull(reflexive))
    {
    goto end; //String
    }
    }


    pronoun_local_var = pronoun_create (
        subject && !cJSON_IsNull(subject) ? strdup(subject->valuestring) : NULL,
        object && !cJSON_IsNull(object) ? strdup(object->valuestring) : NULL,
        possessive && !cJSON_IsNull(possessive) ? strdup(possessive->valuestring) : NULL,
        possessive_determiner && !cJSON_IsNull(possessive_determiner) ? strdup(possessive_determiner->valuestring) : NULL,
        reflexive && !cJSON_IsNull(reflexive) ? strdup(reflexive->valuestring) : NULL
        );

    return pronoun_local_var;
end:
    return NULL;

}
