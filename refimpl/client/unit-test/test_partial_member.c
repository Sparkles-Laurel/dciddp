#ifndef partial_member_TEST
#define partial_member_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define partial_member_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/partial_member.h"
partial_member_t* instantiate_partial_member(int include_optional);



partial_member_t* instantiate_partial_member(int include_optional) {
  partial_member_t* partial_member = NULL;
  if (include_optional) {
    partial_member = partial_member_create(
      "0",
      list_createList()
    );
  } else {
    partial_member = partial_member_create(
      "0",
      list_createList()
    );
  }

  return partial_member;
}


#ifdef partial_member_MAIN

void test_partial_member(int include_optional) {
    partial_member_t* partial_member_1 = instantiate_partial_member(include_optional);

	cJSON* jsonpartial_member_1 = partial_member_convertToJSON(partial_member_1);
	printf("partial_member :\n%s\n", cJSON_Print(jsonpartial_member_1));
	partial_member_t* partial_member_2 = partial_member_parseFromJSON(jsonpartial_member_1);
	cJSON* jsonpartial_member_2 = partial_member_convertToJSON(partial_member_2);
	printf("repeating partial_member:\n%s\n", cJSON_Print(jsonpartial_member_2));
}

int main() {
  test_partial_member(1);
  test_partial_member(0);

  printf("Hello world \n");
  return 0;
}

#endif // partial_member_MAIN
#endif // partial_member_TEST
