#include "unity.h"

#include "priority_queue.h"
#include "vector.h"

priority_queue* pq;

void setUp(void) {}

void tearDown(void) {
    priority_queue_destructor(pq);
}

int max_int(const void* a, const void* b) {
    return (*(int*)a) > (*(int*)b);
}

void test_priority_queue_new_primitive() {
    pq = new_priority_queue(sizeof(int), max_int);
}

void test_priority_queue_push_int() {
    pq = new_priority_queue(sizeof(int), max_int);
    int elem = 10;
    priority_queue_push(pq, &elem);
    elem = 9;
    priority_queue_push(pq, &elem);
    elem = 11;
    priority_queue_push(pq, &elem);
    elem = 13;
    priority_queue_push(pq, &elem);
    elem = 8;
    priority_queue_push(pq, &elem);
    
    TEST_ASSERT_TRUE (*(int *)pq->heap[1] == 13);
    TEST_ASSERT_TRUE (*(int *)pq->heap[2] == 11);
    TEST_ASSERT_TRUE (*(int *)pq->heap[3] == 10);
    TEST_ASSERT_TRUE (*(int *)pq->heap[4] ==  9);
    TEST_ASSERT_TRUE (*(int *)pq->heap[5] ==  8);
}

void test_priority_queue_pop_int() {
    pq = new_priority_queue(sizeof(int), max_int);
    int elem = 10;
    priority_queue_push(pq, &elem);
    elem = 9;
    priority_queue_push(pq, &elem);
    elem = 11;
    priority_queue_push(pq, &elem);
    elem = 13;
    priority_queue_push(pq, &elem);
    elem = 8;
    priority_queue_push(pq, &elem);
    
    int* res = priority_queue_top(pq);
    TEST_ASSERT_TRUE (*res == 13);
    priority_queue_pop(pq);
    res = priority_queue_top(pq);
    TEST_ASSERT_TRUE (*res == 11);
    priority_queue_pop(pq);
    res = priority_queue_top(pq);
    TEST_ASSERT_TRUE (*res == 10);
    priority_queue_pop(pq);
    res = priority_queue_top(pq);
    TEST_ASSERT_TRUE (*res ==  9);
    priority_queue_pop(pq);
    res = priority_queue_top(pq);
    TEST_ASSERT_TRUE (*res ==  8);
    priority_queue_pop(pq);
    
    TEST_ASSERT_TRUE (priority_queue_empty(pq));
}

void test_priority_queue_size() {
    pq = new_priority_queue(sizeof(int), max_int);
    int elem = 10;
    size_t sz = priority_queue_size(pq);
    TEST_ASSERT_TRUE (sz == 0);
    priority_queue_push(pq, &elem);
    TEST_ASSERT_TRUE (priority_queue_size(pq) == 1);
    
    for (int i = 0; i < 100; i++) {
        elem = i;
        priority_queue_push(pq, &elem);
    }
    TEST_ASSERT_TRUE (priority_queue_size(pq) == 101);
    priority_queue_pop(pq);
    TEST_ASSERT_TRUE (priority_queue_size(pq) == 100);
}

int cmp_vector(const void* a, const void* b) {
    return ((vector *)a)->length > ((vector *)b)->length;
}

void test_priority_queue_new_object() {
    pq = new_priority_queue_object(vector_destructor, cmp_vector);
}
