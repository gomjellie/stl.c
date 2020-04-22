#include "headers/stack.h"

stack* new_stack(size_t type_size) {
    stack* new_s = (stack*) malloc(sizeof(stack));
    new_s->s_buff = new_vector(type_size);
    new_s->length = 0;

    return new_s;
}

bool stack_destroy(stack* s) {
    vector_destroy(s->s_buff);
    free(s);

    return true;
}

bool stack_push(stack* s, void* element) {
    return vector_set(s->s_buff, s->length++, element);
}

void* stack_pop(stack* s) {
    if (s->length == 0)
        return NULL;

    return vector_get(s->s_buff, --s->length);
}

bool stack_empty(stack* s) {
    return s->length == 0;
}
