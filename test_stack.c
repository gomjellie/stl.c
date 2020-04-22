#include <stdio.h>
#include "stack.h"

int main() {
    stack* s = new_stack(sizeof(int));
    
    for (int i = 0; i < 100; i++) {
        stack_push(s, &i);
        int *res = (int *)stack_pop(s);
        printf("s[%zu] %d\n", s->length, *res);
    }

    for (int i = 0; i < 100; i++) {
        stack_push(s, &i);
    }
    while (!stack_empty(s)) {
        int * res = (int *)stack_pop(s);

        printf("s[%zu] %d\n", s->length, *res);
    }
    stack_destroy(s);
}
