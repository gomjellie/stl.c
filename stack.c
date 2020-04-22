#include "stack.h"

stack* new_stack(size_t type_size) {
    stack* new_v = (stack*) malloc(sizeof(stack));
    new_v->s_body = new_array(type_size);
    new_v->length = 0;

    return new_v;
}

bool stack_push(stack* v, void* element) {
    return array_set(v->s_body, v->length++, element);
}

void* stack_pop(stack* v) {
    if (v->length == 0)
        return NULL;

    return array_get(v->s_body, --v->length);
}

bool stack_empty(stack* v) {
    return v->length == 0;
}