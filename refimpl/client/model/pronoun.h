/*
 * pronoun.h
 *
 * 
 */

#ifndef _pronoun_H_
#define _pronoun_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct pronoun_t pronoun_t;




typedef struct pronoun_t {
    char *subject; // string
    char *object; // string
    char *possessive; // string
    char *possessive_determiner; // string
    char *reflexive; // string

} pronoun_t;

pronoun_t *pronoun_create(
    char *subject,
    char *object,
    char *possessive,
    char *possessive_determiner,
    char *reflexive
);

void pronoun_free(pronoun_t *pronoun);

pronoun_t *pronoun_parseFromJSON(cJSON *pronounJSON);

cJSON *pronoun_convertToJSON(pronoun_t *pronoun);

#endif /* _pronoun_H_ */

