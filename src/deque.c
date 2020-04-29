#include "deque.h"
#include <stdlib.h>
#include <string.h>

deque* new_deque_primitive(size_t template_size) {
    deque* this = (deque*) malloc(sizeof(deque));
    this->template_size = template_size;
    this->destructor = NULL;
    this->front = 0;
    this->rear = 0;
    this->capacity = INIT_CAPACITY_LENGTH;
    this->type = PRIMITIVE;

    this->buff = (void *)malloc(INIT_CAPACITY_LENGTH * sizeof(void *));
    return this;
}

deque* new_deque_object(void (*destructor) (void* this)) {
    deque* this = (deque*) malloc(sizeof(deque));
    this->destructor = destructor;
    this->front = 0;
    this->rear = 0;
    this->capacity = INIT_CAPACITY_LENGTH;
    this->type = OBJECT;

    this->buff = (void *)malloc(INIT_CAPACITY_LENGTH * sizeof(void *));
    return this;
}

