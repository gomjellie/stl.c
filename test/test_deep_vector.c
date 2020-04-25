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

void test_deep_vector_compare_get_and_at_with_int(int ten) {
    v = new_deep_vector(sizeof(int));
    ten = 10;
    deep_vector_set(v, 15, &ten);
    int* get1 = (int *)deep_vector_get(v, 15);
    int* get2 = (int *)deep_vector_get(v, 15);
    int* at1 = (int *)deep_vector_at(v, 15);
    int* at2 = (int *)deep_vector_at(v, 15);
    
    TEST_ASSERT_TRUE (*get1 == *get2 && *at1 == *at2 && *get1 == *at1);
    TEST_ASSERT_TRUE (get1 != get2);
    TEST_ASSERT_TRUE (at1 == at2);
    TEST_ASSERT_TRUE (at1 != get1);
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
