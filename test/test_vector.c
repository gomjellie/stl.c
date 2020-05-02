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

void test_vector_set_primitive() {
    int element;
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

void test_vector_get() {
    char* hello_world;
    char* whats_up;
    v = new_vector(free);
    hello_world = strdup("hello world!");
    whats_up = strdup("what's up?");
    vector_set(v, 2, hello_world);
    
    const char* res = (char*)vector_at(v, 2);
    TEST_ASSERT_TRUE (strcmp(res, hello_world) == 0);
    TEST_ASSERT_TRUE (v->capacity == 128);

    vector_set(v, 130, whats_up);
    res = (char *)vector_at(v, 130);
    TEST_ASSERT_TRUE (strcmp(res, whats_up) == 0);
    TEST_ASSERT_TRUE (v->capacity == 256);
}

void test_vector_is_element_destroyer_working() {
    char* hello_korea;
    char* hello_japan;
    v = new_vector(free);
    hello_korea = strdup("hello korea!");
    hello_japan = strdup("hello japan!");
    vector_set(v, 2, hello_korea);

    char* korea_pointer = (char *)vector_get(v, 2);
    vector_set(v, 2, hello_japan); // korea의 포인터를 japan의 포인터가 덮어쓰면서 korea는 free되었음. free korea!
    char* japan_pointer = (char *)vector_get(v, 2);

    // 여기서 어떻게 korea_pointer가 반환된걸 검사하지....?
}

void test_vector_set_stress_primitive() {
    int element;
    v = new_vector(sizeof(int));
    for (int i = 0; i < 1000; i++) {
        element = i;
        vector_set(v, i, &element);
    }
    for (int i = 0; i < 1000; i++) {
        int* res = vector_get(v, i);
        TEST_ASSERT_TRUE (*res == i);
    }
}

void test_vector_pop_back() {
    int element;
    v = new_vector(sizeof(int));
    const int test_max = 3000;
    for (int i = 0; i < test_max; i++) {
        element = i;
        vector_push_back(v, &element);
    }
    for (int i = test_max - 1; i >= 0; i--) {
        int* res = (int *)vector_at(v, i);
        TEST_ASSERT_TRUE (*res == i);
        vector_pop_back(v);
    }
}

int cmp_int(const void* a, const void* b) {
    return (*(int *)a) == (*(int *)b);
}

void test_vector_index_primitive() {
    int element;
    v = new_vector(sizeof(int));
    const int test_max = 1024;
    for (int i = 0; i < test_max; i++) {
        element = i;
        vector_push_back(v, &element);
    }

    for (int i = 0; i < test_max; i++) {
        element = i;
        int res = vector_index(v, &element, cmp_int);
        TEST_ASSERT_TRUE (res == i);
    }
}

void test_vector_has_primitive() {
    int element;
    v = new_vector(sizeof(int));
    const int test_max = 1024;
    for (int i = 0; i < test_max; i++) {
        element = i;
        vector_push_back(v, &element);
    }

    for (int i = 0; i < test_max; i++) {
        element = i;
        bool res = vector_has(v, &element, cmp_int);
        TEST_ASSERT_TRUE (res == true);
    }

    for (int i = test_max; i < test_max * 2; i++) {
        element = i;
        bool res = vector_has(v, &element, cmp_int);
        TEST_ASSERT_TRUE (res == false);
    }
}
