#ifndef fronter_TEST
#define fronter_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define fronter_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/fronter.h"
fronter_t* instantiate_fronter(int include_optional);



fronter_t* instantiate_fronter(int include_optional) {
  fronter_t* fronter = NULL;
  if (include_optional) {
    fronter = fronter_create(
      "0",
      "0",
      list_createList()
    );
  } else {
    fronter = fronter_create(
      "0",
      "0",
      list_createList()
    );
  }

  return fronter;
}


#ifdef fronter_MAIN

void test_fronter(int include_optional) {
    fronter_t* fronter_1 = instantiate_fronter(include_optional);

	cJSON* jsonfronter_1 = fronter_convertToJSON(fronter_1);
	printf("fronter :\n%s\n", cJSON_Print(jsonfronter_1));
	fronter_t* fronter_2 = fronter_parseFromJSON(jsonfronter_1);
	cJSON* jsonfronter_2 = fronter_convertToJSON(fronter_2);
	printf("repeating fronter:\n%s\n", cJSON_Print(jsonfronter_2));
}

int main() {
  test_fronter(1);
  test_fronter(0);

  printf("Hello world \n");
  return 0;
}

#endif // fronter_MAIN
#endif // fronter_TEST
