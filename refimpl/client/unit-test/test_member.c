#ifndef member_TEST
#define member_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define member_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/member.h"
member_t* instantiate_member(int include_optional);



member_t* instantiate_member(int include_optional) {
  member_t* member = NULL;
  if (include_optional) {
    member = member_create(
      "0",
      list_createList(),
      "0"
    );
  } else {
    member = member_create(
      "0",
      list_createList(),
      "0"
    );
  }

  return member;
}


#ifdef member_MAIN

void test_member(int include_optional) {
    member_t* member_1 = instantiate_member(include_optional);

	cJSON* jsonmember_1 = member_convertToJSON(member_1);
	printf("member :\n%s\n", cJSON_Print(jsonmember_1));
	member_t* member_2 = member_parseFromJSON(jsonmember_1);
	cJSON* jsonmember_2 = member_convertToJSON(member_2);
	printf("repeating member:\n%s\n", cJSON_Print(jsonmember_2));
}

int main() {
  test_member(1);
  test_member(0);

  printf("Hello world \n");
  return 0;
}

#endif // member_MAIN
#endif // member_TEST
