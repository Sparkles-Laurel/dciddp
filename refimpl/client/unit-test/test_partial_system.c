#ifndef partial_system_TEST
#define partial_system_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define partial_system_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/partial_system.h"
partial_system_t* instantiate_partial_system(int include_optional);



partial_system_t* instantiate_partial_system(int include_optional) {
  partial_system_t* partial_system = NULL;
  if (include_optional) {
    partial_system = partial_system_create(
      "0",
      "0"
    );
  } else {
    partial_system = partial_system_create(
      "0",
      "0"
    );
  }

  return partial_system;
}


#ifdef partial_system_MAIN

void test_partial_system(int include_optional) {
    partial_system_t* partial_system_1 = instantiate_partial_system(include_optional);

	cJSON* jsonpartial_system_1 = partial_system_convertToJSON(partial_system_1);
	printf("partial_system :\n%s\n", cJSON_Print(jsonpartial_system_1));
	partial_system_t* partial_system_2 = partial_system_parseFromJSON(jsonpartial_system_1);
	cJSON* jsonpartial_system_2 = partial_system_convertToJSON(partial_system_2);
	printf("repeating partial_system:\n%s\n", cJSON_Print(jsonpartial_system_2));
}

int main() {
  test_partial_system(1);
  test_partial_system(0);

  printf("Hello world \n");
  return 0;
}

#endif // partial_system_MAIN
#endif // partial_system_TEST
