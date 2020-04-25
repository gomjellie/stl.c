#include "unity.h"
#include <string.h>
#include <stdlib.h>
#include "shallow_vector.h"

shallow_vector* v;

void setUp(void) {
}

void tearDown(void) {
    shallow_vector_destroy(v);
}

void test_shallow_vector_new(void) {
    v = new_shallow_vector(free);
}

void test_shallow_vector_set(void) {
    v = new_shallow_vector(free);
    shallow_vector_set(v, 2, strdup("hello"));
}

void test_shallow_vector_get(char* hello_world) {
    v = new_shallow_vector(free);
    hello_world = strdup("hello world!");
    shallow_vector_set(v, 2, hello_world);
    
    const char* res = (char*)shallow_vector_get(v, 2);
    TEST_ASSERT_TRUE (strcmp(res, hello_world) == 0);
}

void test_shallow_vector_is_element_destroyer_working(char* hello_korea, char* hello_japan) {
    v = new_shallow_vector(free);
    hello_korea = strdup("hello korea!");
    hello_japan = strdup("hello japan!");
    shallow_vector_set(v, 2, hello_korea);

    char* korea_pointer = (char *)shallow_vector_get(v, 2);
    shallow_vector_set(v, 2, hello_japan); // korea의 포인터를 japan의 포인터가 덮어쓰면서 korea는 free되었음. free korea!
    char* japan_pointer = (char *)shallow_vector_get(v, 2);

    // 여기서 어떻게 korea_pointer가 반환된걸 검사하지....?
}

// void test_shallow_vector_push_back(void) {
//     TEST_IGNORE_MESSAGE("Need to Implement shallow_vector");
// }

// void test_shallow_vector_pop_back(void) {
//     TEST_IGNORE_MESSAGE("Need to Implement shallow_vector");
// }

// void test_shallow_vector_empty(void) {
//     TEST_IGNORE_MESSAGE("Need to Implement shallow_vector");
// }
