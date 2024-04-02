/*
 * partial_system.h
 *
 * 
 */

#ifndef _partial_system_H_
#define _partial_system_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct partial_system_t partial_system_t;




typedef struct partial_system_t {
    char *id; // string
    char *name; // string

} partial_system_t;

partial_system_t *partial_system_create(
    char *id,
    char *name
);

void partial_system_free(partial_system_t *partial_system);

partial_system_t *partial_system_parseFromJSON(cJSON *partial_systemJSON);

cJSON *partial_system_convertToJSON(partial_system_t *partial_system);

#endif /* _partial_system_H_ */

