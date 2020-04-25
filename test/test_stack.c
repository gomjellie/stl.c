#include "unity.h"

#include <stdio.h>
#include "deep_vector.h"
#include "stack.h"

stack* s;

void setUp(void) {
    s = new_stack(sizeof(int));
}

void tearDown(void) {
    stack_destroy(s);
}

void test_stack_push_with_int(void) {
    for (int i = 0; i < 100; i++) {
        stack_push(s, &i);
        int *res = (int *)stack_pop(s);
        printf("s[%zu] %d\n", s->length, *res);
    }
}

void test_stack_pop_with_int(void) {
    for (int i = 0; i < 100; i++) {
        stack_push(s, &i);
    }
    while (!stack_empty(s)) {
        int* res = (int *)stack_pop(s);

        printf("s[%zu] %d\n", s->length, *res);
    }
}
