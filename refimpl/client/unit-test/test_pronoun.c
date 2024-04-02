#ifndef pronoun_TEST
#define pronoun_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pronoun_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pronoun.h"
pronoun_t* instantiate_pronoun(int include_optional);



pronoun_t* instantiate_pronoun(int include_optional) {
  pronoun_t* pronoun = NULL;
  if (include_optional) {
    pronoun = pronoun_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    pronoun = pronoun_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return pronoun;
}


#ifdef pronoun_MAIN

void test_pronoun(int include_optional) {
    pronoun_t* pronoun_1 = instantiate_pronoun(include_optional);

	cJSON* jsonpronoun_1 = pronoun_convertToJSON(pronoun_1);
	printf("pronoun :\n%s\n", cJSON_Print(jsonpronoun_1));
	pronoun_t* pronoun_2 = pronoun_parseFromJSON(jsonpronoun_1);
	cJSON* jsonpronoun_2 = pronoun_convertToJSON(pronoun_2);
	printf("repeating pronoun:\n%s\n", cJSON_Print(jsonpronoun_2));
}

int main() {
  test_pronoun(1);
  test_pronoun(0);

  printf("Hello world \n");
  return 0;
}

#endif // pronoun_MAIN
#endif // pronoun_TEST
