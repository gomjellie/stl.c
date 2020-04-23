#include "stack.h"

stack* new_stack(size_t template_size) {
    stack* new_s = (stack*) malloc(sizeof(stack));
    new_s->s_buff = new_vector(template_size);
    new_s->length = 0;

    return new_s;
}

bool stack_destroy(stack* this) {
    vector_destroy(this->s_buff);
    free(this);

    return true;
}

bool stack_push(stack* this, void* element) {
    return vector_set(this->s_buff, this->length++, element);
}

void* stack_pop(stack* this) {
    if (this->length == 0)
        return NULL;

    return vector_get(this->s_buff, --this->length);
}

bool stack_empty(stack* this) {
    return this->length == 0;
}
