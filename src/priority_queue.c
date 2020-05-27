#include "priority_queue.h"
#include <stdlib.h>

priority_queue* new_priority_queue_primitive(size_t template_size, int (*cmp_func)(const void*, const void*)) {
    priority_queue* this = (priority_queue*) malloc(sizeof(priority_queue));
    this->type = PRIMITIVE;
    this->heap = (void **)calloc(INIT_CAPACITY, sizeof(void *));
    this->capacity = INIT_CAPACITY;
    this->template_size = template_size;
    this->length = 0;
    this->destructor = free;
    this->cmp = cmp_func;

    return this;
}

priority_queue* new_priority_queue_object(void (*destructor) (void* this), int (*cmp_func)(const void*, const void*)) {
    priority_queue* this = (priority_queue*) malloc(sizeof(priority_queue));
    this->type = OBJECT;
    this->heap = (void **)calloc(INIT_CAPACITY, sizeof(void *));
    this->capacity = INIT_CAPACITY;
    this->template_size = 0;
    this->length = 0;
    this->destructor = destructor;
    this->cmp = cmp_func;

    return this;
}

bool priority_queue_destructor(priority_queue* this) {
    for (size_t i = 0; i < this->length; i++) {
        this->destructor(this->heap[i]);
    }
    free(this->heap);
    free(this);
}

void* priority_queue_top(priority_queue* this) {
    if (priority_queue_empty(this)) return NULL;

    return this->heap[1];
}

bool priority_queue_push(priority_queue* this, void* element) {
    if (this->length + 1 >= this->capacity) {
        // expand, this->capacity *= 2
    }

    size_t cur = ++this->length;
    while (cur != 1 && this->cmp(element, &this->heap[cur / 2]) == 1) {
        this->heap[cur] = this->heap[cur / 2];
        cur /= 2;
    }
    this->heap[cur] = element;
    return true;
}

bool priority_queue_pop(priority_queue* this) {
    if (priority_queue_empty(this)) return false;

    this->destructor(this->heap[1]);
    void* last_element = this->heap[this->length--];
    
    size_t cur = 1;
    size_t child = 2;
    while (child <= this->length) {
        if (child < this->length && this->cmp(this->heap[child + 1], this->heap[child]) == 1)
            child++;
        if (this->cmp(last_element, this->heap[child]) == 1) break;

        this->heap[cur] = this->heap[child];
        cur = child; child *= 2;
    }
    this->heap[cur] = last_element;
    return true;
}

size_t priority_queue_size(priority_queue* this) {
    return this->length;
}

bool priority_queue_empty(priority_queue* this) {
    return this->length == 0;
}
