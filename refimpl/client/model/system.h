/*
 * system.h
 *
 * 
 */

#ifndef _system_H_
#define _system_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct system_t system_t;

#include "fronter.h"
#include "member.h"



typedef struct system_t {
    char *id; // string
    char *name; // string
    char *pronouns; // string
    list_t *fronters; //nonprimitive container
    list_t *members; //nonprimitive container

} system_t;

system_t *system_create(
    char *id,
    char *name,
    char *pronouns,
    list_t *fronters,
    list_t *members
);

void system_free(system_t *system);

system_t *system_parseFromJSON(cJSON *systemJSON);

cJSON *system_convertToJSON(system_t *system);

#endif /* _system_H_ */

