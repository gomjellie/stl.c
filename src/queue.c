#include "queue.h"
#include <stdlib.h>

queue* new_queue_primitive(size_t template_size) {
    queue* this = (queue*) malloc(sizeof(queue));
    this->buff = new_deque(template_size);
    return this;
}

queue* new_queue_object(void (*destructor) (void* this)) {
    queue* this = (queue *) malloc(sizeof(queue));
    this->buff = new_deque(destructor);
    return this;
}

void queue_destructor(queue* this) {
    deque_destructor(this->buff);
    free(this);
}

void* queue_front(queue* this) {
    return deque_front(this->buff);
}

void* queue_back(queue* this) {
    return deque_back(this->buff);
}

bool queue_push(queue* this, void* element) {
    return deque_push_back(this->buff, element);
}

bool queue_pop(queue* this) {
    return deque_pop_front(this->buff);
}

size_t queue_size(queue* this) {
    return deque_size(this->buff);
}

bool queue_empty(queue* this) {
    return deque_empty(this->buff);
}
