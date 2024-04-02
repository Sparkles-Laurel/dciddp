/*
 * partial_member.h
 *
 * 
 */

#ifndef _partial_member_H_
#define _partial_member_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct partial_member_t partial_member_t;

#include "pronoun.h"



typedef struct partial_member_t {
    char *name; // string
    list_t *pronouns; //nonprimitive container

} partial_member_t;

partial_member_t *partial_member_create(
    char *name,
    list_t *pronouns
);

void partial_member_free(partial_member_t *partial_member);

partial_member_t *partial_member_parseFromJSON(cJSON *partial_memberJSON);

cJSON *partial_member_convertToJSON(partial_member_t *partial_member);

#endif /* _partial_member_H_ */

