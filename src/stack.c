#include "stack.h"

stack* new_stack_primitive(size_t template_size) {
    stack* this = (stack *) malloc(sizeof(stack));
    this->buff = new_vector(template_size);
    this->length = 0;

    return this;
}

stack* new_stack_object(void (*destructor) (void* this)) {
    stack* this = (stack *) malloc(sizeof(stack));
    this->buff = new_vector(destructor);
    this->length = 0;

    return this;
}

bool stack_destructor(stack* this) {
    vector_destructor(this->buff);
    free(this);

    return true;
}

bool stack_push(stack* this, void* element) {
    return vector_set(this->buff, this->length++, element);
}

void* stack_pop(stack* this) {
    if (this->length == 0)
        return NULL;

    return vector_at(this->buff, --this->length);
}

bool stack_empty(stack* this) {
    return this->length == 0;
}
