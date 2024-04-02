/*
 * member.h
 *
 * 
 */

#ifndef _member_H_
#define _member_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct member_t member_t;

#include "pronoun.h"



typedef struct member_t {
    char *name; // string
    list_t *pronouns; //nonprimitive container
    char *id; // string

} member_t;

member_t *member_create(
    char *name,
    list_t *pronouns,
    char *id
);

void member_free(member_t *member);

member_t *member_parseFromJSON(cJSON *memberJSON);

cJSON *member_convertToJSON(member_t *member);

#endif /* _member_H_ */

