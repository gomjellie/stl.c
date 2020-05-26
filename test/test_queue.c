#include "unity.h"

#include "queue.h"
#include "deque.h"

queue* q;
void setUp(void) {}

void tearDown(void) {
    queue_destructor(q);
}

void test_queue_new_primitive() {
    q = new_queue(sizeof(int));
}

void test_queue_new_object() {
    q = new_queue(deque_destructor);
}

void test_queue_push_int() {
    int element;
    q = new_queue(sizeof(int));
    for (int i = 1; i < 100; i++) {
        element = i;
        queue_push(q, &element);
        int* res = (int *)queue_back(q);
        TEST_ASSERT_TRUE(*res == i);
        TEST_ASSERT_TRUE(queue_size(q) == i);
    }
    
    int i = 1;
    while (!queue_empty(q)) {
        int* res = (int *)queue_front(q);
        TEST_ASSERT_TRUE(*res == i++);
        queue_pop(q);
    }
}
