#include "unity.h"

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "stack.h"

stack* s;

void setUp(void) { }

void tearDown(void) {
    stack_destructor(s);
}

void test_stack_new_primitive(void) {
    s = new_stack(sizeof(int));
}

void test_stack_new_object(void) {
    s = new_stack(free);
}

void test_stack_push_primitive(void) {
    s = new_stack(sizeof(int));
    for (int i = 0; i < 100; i++) {
        stack_push(s, &i);
        int *res = (int *)stack_pop(s);
        printf("s[%zu] %d\n", s->length, *res);
    }
}

void test_stack_pop_primitive(void) {
    s = new_stack(sizeof(int));
    for (int i = 0; i < 100; i++) {
        stack_push(s, &i);
    }
    while (!stack_empty(s)) {
        int* res = (int *)stack_pop(s);

        printf("s[%zu] %d\n", s->length, *res);
    }
}
