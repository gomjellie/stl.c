#include "unity.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deep_vector.h"

deep_vector* v;

void setUp(void) {
    
}

void tearDown(void) {
    deep_vector_destroy(v);
}

void test_deep_vector_set_with_int(void) {
    v = new_deep_vector(sizeof(int));
    int nine = 9;
    deep_vector_set(v, 2, &nine);
}

void test_deep_vector_get_with_int(void) {
    v = new_deep_vector(sizeof(int));
    int ten = 10;
    deep_vector_set(v, 130, &ten);
    int* res = (int*)deep_vector_get(v, 131);
    TEST_ASSERT_TRUE (res == NULL);
}

void test_deep_vector_has(void) {
    v = new_deep_vector(sizeof(int));
    int nine = 9;
    deep_vector_set(v, 2, &nine);
    
    bool has_9 = deep_vector_has(v, &nine);
    TEST_ASSERT_TRUE (has_9);
}

void test_deep_vector_index(void) {
    v = new_deep_vector(sizeof(int));
    int nine = 9;
    deep_vector_set(v, 2, &nine);
    TEST_ASSERT_TRUE (deep_vector_index(v, &nine) == 2);
}

void test_deep_vector_new_with_string(void) {
    v = new_deep_vector(sizeof(char *));
}

void test_deep_vector_set_with_string(void) {
    v = new_deep_vector(sizeof(char *));
    char* hello = "hello hello hello hello";
    char** res;

    res = deep_vector_get(v, 0);
    TEST_ASSERT_FALSE (strcmp(hello, res)); // strcmp returns 0 when it's same
    hello[0] = 'e'; // hello -> eello
    res = deep_vector_get(v, 0);
    TEST_ASSERT_TRUE (strcmp(hello, res));
}

void test_deep_vector_has_with_string(void) {
    v = new_deep_vector(sizeof(char *));
    char hello[32] = "hello";
    deep_vector_set(v, 32, hello);
    char find_hello[32] = "hello";
    char find_hallo[32] = "hallo";
    
    TEST_ASSERT_TRUE (32 == deep_vector_index(v, find_hello));
    TEST_ASSERT_TRUE (-1 == deep_vector_index(v, find_hallo));
}

void test_deep_vector_new_with_double(void) {
    v = new_deep_vector(sizeof(double));
}

void test_deep_vector_set_with_double(void) {
    v = new_deep_vector(sizeof(double));
    double pi = 3.14;
    double* res;
    deep_vector_set(v, 0, &pi);
    
    res = deep_vector_get(v, 0);
    TEST_ASSERT_TRUE (pi == *res);
    pi = 4.12;
    res = deep_vector_get(v, 0);
    TEST_ASSERT_FALSE (pi == *res); // cmp 4.12 w/ 3.14
}

void test_deep_vector_has_with_double(void) {
    v = new_deep_vector(sizeof(double));
    double pi = 3.14;
    double* res;
    deep_vector_set(v, 32, &pi);
    
    double find_val = 3.14;
    TEST_ASSERT_TRUE (32 == deep_vector_index(v, &find_val));
    find_val = 2;
    TEST_ASSERT_TRUE (-1 == deep_vector_index(v, &find_val));
}
