#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "unity.h"
#include "vector.h"

vector* v;

void setUp(void) {
}

void tearDown(void) {
    vector_destructor(v);
}

void test_vector_new_primitive(void) {
    v = new_vector(sizeof(int));
}

void test_vector_new_object(void) {
    v = new_vector(free);
}

void test_vector_set_primitive(int element) {
    v = new_vector(sizeof(int));
    element = 10;
    vector_set(v, 2, &element);
    int* res = vector_get(v, 2);
    TEST_ASSERT_TRUE (*res == element);
}

void test_vector_set_object(void) {
    v = new_vector(free);
    vector_set(v, 2, strdup("hello"));
}

void test_vector_get(char* hello_world, char* whats_up) {
    v = new_vector(free);
    hello_world = strdup("hello world!");
    whats_up = strdup("what's up?");
    vector_set(v, 2, hello_world);
    
    const char* res = (char*)vector_get(v, 2);
    TEST_ASSERT_TRUE (strcmp(res, hello_world) == 0);
    TEST_ASSERT_TRUE (v->capacity == 128);

    vector_set(v, 130, whats_up);
    res = (char *)vector_get(v, 130);
    TEST_ASSERT_TRUE (strcmp(res, whats_up) == 0);
    TEST_ASSERT_TRUE (v->capacity == 256);
}

void test_vector_is_element_destroyer_working(char* hello_korea, char* hello_japan) {
    v = new_vector(free);
    hello_korea = strdup("hello korea!");
    hello_japan = strdup("hello japan!");
    vector_set(v, 2, hello_korea);

    char* korea_pointer = (char *)vector_get(v, 2);
    vector_set(v, 2, hello_japan); // korea의 포인터를 japan의 포인터가 덮어쓰면서 korea는 free되었음. free korea!
    char* japan_pointer = (char *)vector_get(v, 2);

    // 여기서 어떻게 korea_pointer가 반환된걸 검사하지....?
}
