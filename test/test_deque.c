#include "unity.h"

#include "deque.h"
#include <stdlib.h>

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

void test_deque_expand(void) {
    // todo: write test code
    dq = new_deque(sizeof(int));
}
