#include "unity.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

vector* v;

void setUp(void) {
    
}

void tearDown(void) {
    vector_destroy(v);
}

void test_vector_set_with_int(void) {
    v = new_vector(sizeof(int));
    int nine = 9;
    vector_set(v, 2, &nine);
}

void test_vector_get_with_int(void) {
    v = new_vector(sizeof(int));
    int ten = 10;
    vector_set(v, 130, &ten);
    int* res = (int*)vector_get(v, 131);
    TEST_ASSERT_TRUE (res == NULL);
}

void test_vector_has(void) {
    v = new_vector(sizeof(int));
    int nine = 9;
    vector_set(v, 2, &nine);
    
    bool has_9 = vector_has(v, &nine);
    TEST_ASSERT_TRUE (has_9);
}

void test_vector_index(void) {
    v = new_vector(sizeof(int));
    int nine = 9;
    vector_set(v, 2, &nine);
    TEST_ASSERT_TRUE (vector_index(v, &nine) == 2);
}

void test_vector_new_with_string(void) {
    v = new_vector(sizeof(char *));
}

void test_vector_set_with_string(void) {
    v = new_vector(sizeof(char *));
    char hello[32] = "hello";
    char* res;
    vector_set(v, 0, hello);
    
    res = vector_get(v, 0);
    TEST_ASSERT_FALSE (strcmp(hello, res)); // strcmp returns 0 when it's same
    hello[0] = 'e'; // hello -> eello
    res = vector_get(v, 0);
    TEST_ASSERT_TRUE (strcmp(hello, res));
}

void test_vector_has_with_string(void) {
    v = new_vector(sizeof(char *));
    char hello[32] = "hello";
    vector_set(v, 32, hello);
    char find_hello[32] = "hello";
    char find_hallo[32] = "hallo";
    
    TEST_ASSERT_TRUE (32 == vector_index(v, find_hello));
    TEST_ASSERT_TRUE (-1 == vector_index(v, find_hallo));
}
