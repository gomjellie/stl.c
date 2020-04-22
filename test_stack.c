#include <stdio.h>
#include "stack.h"

int main() {
    stack* v = new_stack(sizeof(int));
    
    for (int i = 0; i < 100; i++) {
        stack_push(v, &i);
        int *res = (int *)stack_pop(v);
        printf("v[%zu] %d\n", v->length, *res);
    }

    for (int i = 0; i < 100; i++) {
        stack_push(v, &i);
    }
    while (!stack_empty(v)) {
        int * res = (int *)stack_pop(v);

        printf("v[%zu] %d\n", v->length, *res);
    }
}
