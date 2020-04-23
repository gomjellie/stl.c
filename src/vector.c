#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include "vector.h"

size_t _get_quadratic_capacity(size_t prev_capacity);

vector* new_vector(size_t template_size) {
    vector* new_this = malloc(sizeof(vector));
    new_this->v_buff = (byte *)calloc(INIT_CAPACITY_LENGTH, template_size);
    new_this->capacity = INIT_CAPACITY_LENGTH;
    new_this->length = 0;
    new_this->template_size = template_size;

    return new_this;
}

void* vector_get(vector* this, size_t index) {
    if (this->length <= index)
        return NULL;

    return this->v_buff + index * this->template_size; // 편의상 문제를 일단 남겨둠
}

void* vector_at(vector* this, size_t index) {
    return vector_get(this, index);
}

void* vector_front(vector* this) {
    return vector_get(this, 0);
}

void* vector_back(vector* this) {
    return vector_get(this, this->length - 1);
}

bool vector_set(vector* this, size_t index, void* element) {
    size_t ts = this->template_size;
    if (this->capacity <= index) { // expand v_buff
        size_t new_capacity = _get_quadratic_capacity(index);
        byte* new_buff = (byte *)calloc(new_capacity, ts);
        memcpy(new_buff, this->v_buff, this->length * ts);

        free(this->v_buff);
        this->v_buff = new_buff;
        this->capacity = new_capacity;
    }

    this->length = MAX(this->length, index + 1);
    memcpy((void *)this->v_buff + index * ts, element, ts);
    return true;
}


bool vector_push_back(vector* this, void* element) {
    return vector_set(this, this->length++, element);
}

void* vector_pop_back(vector* this) {
    if (this->length == 0)
        return NULL;

    return vector_get(this, --this->length);
}

bool vector_clear(vector* this) {
    /**
        - clear every elements to zero
        - set length to zero
        - keep memory allocated (capacity doesn't change)
    */
    this->length = 0;
    memset(this->v_buff, 0x00, this->template_size * this->capacity);

    return true;
}

bool vector_empty(vector* this) {
    return this->length == 0;
}


bool vector_has(vector* this, void* element) {
    for (int i = 0; i < this->length; i++) {
        void* a_i = vector_get(this, i);
        int cmp = memcmp(a_i, element, this->template_size);
        // cmp == 0 when they match
        if (!cmp)
            return true;
    }

    return false;
}

int vector_index(vector* this, void* element) {
    for (int i = 0; i < this->length; i++) {
        void* a_i = vector_get(this, i);
        int cmp = memcmp(a_i, element, this->template_size);
        // cmp == 0 when they match
        if (!cmp) 
            return i;
    }

    return -1;
}

bool vector_destroy(vector* this) {
    free(this->v_buff);
    free(this);

    return true;
}

/**
    아래의 함수들은 vector.h를 통해서 인터페이스가 제공되지 않는 함수들임.
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
