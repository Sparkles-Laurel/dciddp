#ifndef system_TEST
#define system_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define system_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/system.h"
system_t* instantiate_system(int include_optional);



system_t* instantiate_system(int include_optional) {
  system_t* system = NULL;
  if (include_optional) {
    system = system_create(
      "0",
      "0",
      "0",
      list_createList(),
      list_createList()
    );
  } else {
    system = system_create(
      "0",
      "0",
      "0",
      list_createList(),
      list_createList()
    );
  }

  return system;
}


#ifdef system_MAIN

void test_system(int include_optional) {
    system_t* system_1 = instantiate_system(include_optional);

	cJSON* jsonsystem_1 = system_convertToJSON(system_1);
	printf("system :\n%s\n", cJSON_Print(jsonsystem_1));
	system_t* system_2 = system_parseFromJSON(jsonsystem_1);
	cJSON* jsonsystem_2 = system_convertToJSON(system_2);
	printf("repeating system:\n%s\n", cJSON_Print(jsonsystem_2));
}

int main() {
  test_system(1);
  test_system(0);

  printf("Hello world \n");
  return 0;
}

#endif // system_MAIN
#endif // system_TEST
