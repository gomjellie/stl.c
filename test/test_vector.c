#include "unity.h"

#include <stdio.h>
#include <stdlib.h>
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
    vector_set(v, 0, hello);
    hello[0] = 'q';
    char* res;
    res = vector_get(v, 0);
    printf("%p\n", hello);
    printf("%p", res);
}

void test_vector_has_with_string(void) {
    v = new_vector(sizeof(char *));
    char hello[32] = "hello";
    vector_set(v, 32, hello);
    char find_hello[32] = "hello";
    printf("%d", vector_index(v, find_hello));
}
