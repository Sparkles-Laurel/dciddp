/*
 * fronter.h
 *
 * 
 */

#ifndef _fronter_H_
#define _fronter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct fronter_t fronter_t;

#include "pronoun.h"



typedef struct fronter_t {
    char *id; // string
    char *name; // string
    list_t *pronouns; //nonprimitive container

} fronter_t;

fronter_t *fronter_create(
    char *id,
    char *name,
    list_t *pronouns
);

void fronter_free(fronter_t *fronter);

fronter_t *fronter_parseFromJSON(cJSON *fronterJSON);

cJSON *fronter_convertToJSON(fronter_t *fronter);

#endif /* _fronter_H_ */

