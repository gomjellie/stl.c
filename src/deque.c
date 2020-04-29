#include "deque.h"
#include <stdlib.h>
#include <string.h>

deque* new_deque_primitive(size_t template_size) {
    deque* this = (deque*) malloc(sizeof(deque));
    this->template_size = template_size;
    this->destructor = free;
    this->front = 0;
    this->rear = 0;
    this->capacity = INIT_CAPACITY_LENGTH;
    this->type = PRIMITIVE;

    this->buff = (void *)calloc(INIT_CAPACITY_LENGTH, sizeof(void *));
    return this;
}

deque* new_deque_object(void (*destructor) (void* this)) {
    deque* this = (deque*) malloc(sizeof(deque));
    this->destructor = destructor;
    this->front = 0;
    this->rear = 0;
    this->capacity = INIT_CAPACITY_LENGTH;
    this->type = OBJECT;

    this->buff = (void *)calloc(INIT_CAPACITY_LENGTH, sizeof(void *));
    return this;
}

bool deque_destructor(deque* this) {
    for (int i = 0; i < this->capacity; i++) { // 더 자세하게 구현하면 순회 줄일수 있음
        if (this->buff[i] != NULL)
            this->destructor(this->buff[i]);
    }

    this->destructor(this->buff);
    free(this);

    return true;
}

bool deque_empty(deque* this) {
    return this->front == this->rear;
}
