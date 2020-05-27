#include "deque.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void deque_show(deque* this);
static bool deque_expand(deque* this);
static bool deque_set(deque* this, size_t idx, void* element);

deque* new_deque_primitive(size_t template_size) {
    deque* this = (deque*) malloc(sizeof(deque));
    this->template_size = template_size;
    this->destructor = free;
    this->front = 0;
    this->rear = 0;
    this->capacity = INIT_CAPACITY;
    this->type = PRIMITIVE;

    this->buff = (void **)calloc(INIT_CAPACITY, sizeof(void *));
    return this;
}

deque* new_deque_object(void (*destructor) (void* this)) {
    deque* this = (deque*) malloc(sizeof(deque));
    this->destructor = destructor;
    this->front = 0;
    this->rear = 0;
    this->capacity = INIT_CAPACITY;
    this->type = OBJECT;

    this->buff = (void **)calloc(INIT_CAPACITY, sizeof(void *));
    return this;
}

bool deque_destructor(deque* this) {
    for (int i = 0; i < this->capacity; i++) { // 더 자세하게 구현하면 순회 줄일수 있음
        if (this->buff[i] != NULL)
            this->destructor(this->buff[i]);
    }

    free(this->buff);
    free(this);

    return true;
}

bool deque_empty(deque* this) {
    return this->front == this->rear;
}

void* deque_front(deque* this) {
    size_t idx = (this->front + 1) % this->capacity;
    return this->buff[idx];
}

void* deque_back(deque* this) {
    return this->buff[this->rear];
}

bool deque_push_front(deque* this, void* element) {
    if ((this->capacity + this->front - 1) % this->capacity == this->rear)
        deque_expand(this);

    deque_set(this, this->front, element);
    this->front = (this->capacity + this->front - 1) % this->capacity;
    return true;
}

bool deque_push_back(deque* this, void* element) {
    if ((this->rear + 1) % this->capacity == this->front)
        deque_expand(this);

    this->rear = (this->rear + 1) % this->capacity;
    deque_set(this, this->rear, element);
    return true;
}

bool deque_pop_front(deque* this) {
    if (deque_empty(this)) return false;

    size_t idx = (this->front + 1) % this->capacity;
    if (this->buff[idx] != NULL) this->destructor(this->buff[idx]);
    this->buff[idx] = NULL;
    this->front = idx;
    return true;
}

bool deque_pop_back(deque* this) {
    if (deque_empty(this)) return false;

    if (this->buff[this->rear] != NULL) this->destructor(this->buff[this->rear]);
    this->buff[this->rear] = NULL;
    this->rear = (this->capacity + this->rear - 1) % this->capacity;
    return true;
}

size_t deque_size(deque* this) {
    return (this->capacity + this->rear - this->front) % this->capacity;
}

static bool deque_set(deque* this, size_t idx, void* element) {
    if (this->type == PRIMITIVE) {
        void* _elem = (void *) malloc(this->template_size);
        if (_elem == NULL) return false;

        memcpy(_elem, element, this->template_size);
        element = _elem;
    }

    if (this->buff[idx] != NULL)
        this->destructor(this->buff[idx]);
    this->buff[idx] = element;
    return true;
}

static void deque_show(deque* this) {
    puts("deque_show");
    printf("capacity: %zu\n", this->capacity);
    printf("front: %d\n", this->front);
    printf("rear: %d\n", this->rear);
    for (int i = 0; i < this->capacity; i++) {
        if (this->buff[i] != NULL)
            printf("[%d] : %d\n", i, *(int *)(this->buff[i]));
    }
}

static bool deque_expand(deque* this) {
    // 이름은 그냥 expand인데 expand하면서 front를 0으로 맞추는 재정렬을 포함한다.
    // front == rear 인 경우는 고려하지 않는다. 
    // front == rear 가 되기 직전의 경우에만 expand하기 때문에!
    void** new_buff = (void **)calloc(this->capacity * 2, sizeof(void *));
    if (new_buff == NULL) return false;

    int idx = 1;
    while (!deque_empty(this)) {
        void* elem = deque_front(this);
        new_buff[idx++] = elem;
        this->buff[(this->front + 1) % this->capacity] = NULL;
        this->front = (this->front + 1) % this->capacity;
    }
    this->rear = idx - 1;
    this->front = 0;

    free(this->buff);
    this->buff = new_buff;
    this->capacity = this->capacity * 2;
    
    return true;
}
