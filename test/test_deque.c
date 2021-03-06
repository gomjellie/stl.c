#include "unity.h"

#include "deque.h"
#include <stdlib.h>
#include <string.h>

deque* dq;

void setUp(void) { }

void tearDown(void) {
    deque_destructor(dq);
}

void test_deque_constructor_object(void) {
    dq = new_deque(free);
}

void test_deque_constructor_primitive(void) {
    dq = new_deque(32);
}

void test_deque_empty(void) {
    dq = new_deque(32);
    bool res = deque_empty(dq);
    TEST_ASSERT_TRUE (res == true);
}

void test_primitive_deque_push() {
    int element = 10;
    dq = new_deque(sizeof(int));
    deque_push_back(dq, &element);
    TEST_ASSERT_TRUE (deque_size(dq) == 1);
    TEST_ASSERT_TRUE (*(int *)deque_back(dq) == 10);
    
    element = 9;
    deque_push_back(dq, &element);
    TEST_ASSERT_TRUE (deque_size(dq) == 2);
    TEST_ASSERT_TRUE (*(int *)deque_back(dq) == 9);
    TEST_ASSERT_FALSE (deque_back(dq) == &element);
}

void test_object_deque_push_back() {
    char* element;
    char* res;
    element = strdup("hello south korea");
    dq = new_deque(free);
    deque_push_back(dq, element);
    res = (char *)deque_back(dq);
    TEST_ASSERT_TRUE (strcmp(element, res) == 0);

    element = strdup("hello north korea");
    deque_push_back(dq, element);
    res = (char *)deque_back(dq);
    TEST_ASSERT_TRUE (strcmp(element, res) == 0);
}

void test_object_deque_push_front() {
    char* element;
    char* res;
    element = strdup("hello south korea");
    dq = new_deque(free);
    deque_push_front(dq, element);
    res = (char *)deque_front(dq);
    TEST_ASSERT_TRUE (deque_size(dq) == 1);
    TEST_ASSERT_TRUE (strcmp(element, res) == 0);

    element = strdup("hello north korea");
    deque_push_front(dq, element);
    res = (char *)deque_front(dq);
    TEST_ASSERT_TRUE (deque_size(dq) == 2);
    TEST_ASSERT_TRUE (strcmp(element, res) == 0);

    deque_pop_front(dq);
    TEST_ASSERT_TRUE (strcmp((char *)deque_front(dq), (char *)deque_back(dq)) == 0);
}

void test_primitive_push_back_and_pop_back() {
    int element;
    const int test_max = 400;
    dq = new_deque(sizeof(int));
    for (int i = 0; i < test_max; i++) {
        element = i;
        deque_push_back(dq, &element);
    }

    for (int i = test_max - 1; i >= 0; i--) {
        int* res = deque_back(dq);
        TEST_ASSERT_TRUE (*res == i);
        deque_pop_back(dq);
    }
}

void test_primitive_push_back_and_pop_front() {
    int element;
    const int test_max = 500;
    dq = new_deque(sizeof(int));
    for (int i = 0; i < test_max; i++) {
        element = i;
        deque_push_back(dq, &element);
    }

    for (int i = 0; i < test_max; i++) {
        int* res = deque_front(dq);
        TEST_ASSERT_TRUE (*res == i);
        deque_pop_front(dq);
    }
}

void test_primitive_push_front_and_pop_front() {
    int element;
    const int test_max = 500;
    dq = new_deque(sizeof(int));
    for (int i = 0; i < test_max; i++) {
        element = i;
        deque_push_front(dq, &element);
    }

    for (int i = test_max - 1; i >= 0; i--) {
        int* res = deque_front(dq);
        TEST_ASSERT_TRUE (*res == i);
        deque_pop_front(dq);
    }
}

void test_primitive_push_front_and_pop_back(int element) {
    const int test_max = 500;
    dq = new_deque(sizeof(int));
    for (int i = 0; i < test_max; i++) {
        element = i;
        deque_push_front(dq, &element);
    }

    for (int i = 0; i < test_max; i++) {
        int* res = deque_back(dq);
        TEST_ASSERT_TRUE (*res == i);
        deque_pop_back(dq);
    }
}
