#include "deque.h"
#include <stdlib.h>
#include <string.h>

bool deque_expand(deque* this);

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

bool deque_push_front(deque* this, void* element) {
    // TODO: check is_full
    if (this->front == (this->rear % this->capacity)) {

    }
    if (this->type == PRIMITIVE) {
        void* _elem = (void*) malloc(sizeof(this->template_size));
        memcpy(_elem, element, sizeof(this->template_size));
        this->buff[this->front] = _elem;
        this->front = (this->front - 1 + this->capacity) % this->capacity;
        return true;
    }
    
    this->buff[this->front] = element;
    this->front = (this->front - 1 + this->capacity) % this->capacity;
}

bool deque_push_back(deque* this, void* element) {

}

void* deque_pop_front(deque* this) {

}

void* deque_pop_back(deque* this) {

}

size_t deque_size(deque* this) {
    return (this->capacity + this->rear - this->front) % this->capacity;
}

bool deque_expand(deque* this) {
    // 이름은 그냥 expand인데 expand하면서 front를 0으로 맞추는 재정렬을 포함한다.
    // front == rear 인 경우는 고려하지 않는다. 
    // front == rear 가 되기 직전의 경우에만 expand하기 때문에!
    size_t piv = this->front < this->rear ? this->rear : this->capacity;
    void** new_buff = (void *)calloc(this->capacity * 2, sizeof(void *));
    if (new_buff == NULL) return false;

    if (piv == this->rear) {// front < rear
        size_t sz = deque_size(this);
        memcpy(new_buff, this->buff + this->front, sz);
        this->front = 0;
        this->rear = sz;
        
        free(this->buff);
        this->buff = new_buff;
        this->capacity *= 2;
        return true;
    }
    // rear < front
    size_t bs = piv - this->front; // back_part_size
    memcpy(new_buff, this->buff + this->front, piv - this->front);
    memcpy(new_buff + bs, this->buff, this->rear);
    this->front = 0;
    this->rear = deque_size(this);

    free(this->buff);
    this->buff = new_buff;
    this->capacity *= 2;
    return true;
}
