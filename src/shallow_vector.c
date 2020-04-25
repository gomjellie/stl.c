#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include "shallow_vector.h"

typedef shallow_vector sh_vector;

size_t _get_quadratic_capacity(size_t prev_capacity);

shallow_vector* new_shallow_vector(void (*element_destroyer) (void *element)) {
    shallow_vector* new_this = (shallow_vector*) malloc(sizeof(shallow_vector));
    new_this->v_buff = (void *)calloc(INIT_CAPACITY_LENGTH, sizeof(void *));
    new_this->capacity = INIT_CAPACITY_LENGTH;
    new_this->length = 0;

    return new_this;
}

void* shallow_vector_get(shallow_vector* this, size_t index) {
    if (this->length <= index)
        return NULL;

    return this->v_buff[index];
}

void* shallow_vector_at(shallow_vector* this, size_t index) {
    if (this->length <= index)
        return NULL;

    return this->v_buff[index];
}

void* shallow_vector_front(shallow_vector* this) {
    return shallow_vector_at(this, 0);
}

void* shallow_vector_back(shallow_vector* this) {
    return shallow_vector_at(this, this->length - 1);
}

bool shallow_vector_set(shallow_vector* this, size_t index, void* element) {
    size_t ps = sizeof(void *); // pointer size
    if (this->capacity <= index) { // expand v_buff
        size_t new_capacity = _get_quadratic_capacity(index);
        void** new_buff = (void *)calloc(new_capacity, ps);
        memcpy(new_buff, this->v_buff, this->length * ps);

        free(this->v_buff);
        this->v_buff = new_buff;
        this->capacity = new_capacity;
    }

    this->length = MAX(this->length, index + 1);
    this->v_buff[index] = element; // 기존의 자리에 NULL 이 있지 않으면 destroyer로 메모리 해제 해줘야함.    
    return true;
}


bool shallow_vector_push_back(shallow_vector* this, void* element) {
    return shallow_vector_set(this, this->length++, element);
}

void* shallow_vector_pop_back(shallow_vector* this) {
    if (this->length == 0)
        return NULL;

    return shallow_vector_get(this, --this->length);
}

bool shallow_vector_clear(shallow_vector* this) {
    /**
        - clear every elements to zero
        - set length to zero
        - keep memory allocated (capacity doesn't change)
    */
    this->length = 0;
    memset(this->v_buff, 0x00, sizeof(void *) * this->capacity);

    return true;
}

bool shallow_vector_empty(shallow_vector* this) {
    return this->length == 0;
}


bool shallow_vector_has(shallow_vector* this, void* element) {
    for (int i = 0; i < this->length; i++) {
        void* a_i = shallow_vector_get(this, i);
        
        if (a_i == element)
            return true;
    }

    return false;
}

int shallow_vector_index(shallow_vector* this, void* element) {
    for (int i = 0; i < this->length; i++) {
        void* a_i = shallow_vector_get(this, i);
        
        if (a_i == element)
            return i;
    }

    return -1;
}

bool shallow_vector_destroy(shallow_vector* this) {
    for (int i = 0; i < this->length; i++) {
        void* p = this->v_buff[i];
        if (p != NULL && this->element_destroyer != NULL)
            this->element_destroyer(this->v_buff[i]);
    }

    free(this->v_buff);
    free(this);

    return true;
}

/**
    아래의 함수들은 shallow_vector.h를 통해서 인터페이스가 제공되지 않는 함수들임.
*/

size_t _get_quadratic_capacity(size_t prev_capacity) {
    /**
    capacity를 초과한 인덱스를 위해 새로 할당할 capacity를 계산함
    10 -> 16
    5 -> 8
    4 -> 8
    */
    return 0x02 << (size_t)log2(prev_capacity);
}
