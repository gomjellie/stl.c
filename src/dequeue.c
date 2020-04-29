#include "dequeue.h"
#include <stdlib.h>
#include <string.h>

dequeue* new_dequeue_primitive(size_t template_size) {
    dequeue* this = (dequeue*) malloc(sizeof(dequeue));
    this->template_size = template_size;
    this->destructor = NULL;
    this->front = 0;
    this->rear = 0;
    this->capacity = INIT_CAPACITY_LENGTH;
    this->type = PRIMITIVE;

    this->buff = (void *)malloc(INIT_CAPACITY_LENGTH * sizeof(void *));
    return this;
}

dequeue* new_dequeue_object(void (*destructor) (void* this)) {
    dequeue* this = (dequeue*) malloc(sizeof(dequeue));
    this->destructor = destructor;
    this->front = 0;
    this->rear = 0;
    this->capacity = INIT_CAPACITY_LENGTH;
    this->type = OBJECT;

    this->buff = (void *)malloc(INIT_CAPACITY_LENGTH * sizeof(void *));
    return this;
}

