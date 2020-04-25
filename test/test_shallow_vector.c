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

// void test_shallow_vector_push_back(void) {
//     TEST_IGNORE_MESSAGE("Need to Implement shallow_vector");
// }

// void test_shallow_vector_pop_back(void) {
//     TEST_IGNORE_MESSAGE("Need to Implement shallow_vector");
// }

// void test_shallow_vector_empty(void) {
//     TEST_IGNORE_MESSAGE("Need to Implement shallow_vector");
// }
