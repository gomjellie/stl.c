#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include "headers/array.h"

size_t _get_quadratic_capacity(size_t prev_capacity);

array* new_array(size_t type_size) {
    array* new_arr = malloc(sizeof(array));
    new_arr->body = (byte *)calloc(INIT_CAPACITY_LENGTH, type_size);
    new_arr->capacity = INIT_CAPACITY_LENGTH;
    new_arr->length = 0;
    new_arr->type_size = type_size;

    return new_arr;
}

void* array_get(array* arr, size_t index) {
    if (arr->length <= index)
        return NULL;

    return arr->body + index * arr->type_size; // 편의상 문제를 일단 남겨둠
}

void* array_at(array* arr, size_t index) {
    return array_get(arr, index);
}

void* array_front(array* arr) {
    // 첫번째 원소를 참조합니다.
    return array_get(arr, 0);
}

void* array_back(array* arr) {
    // 마지막 원소를 참조합니다.
    return array_get(arr, arr->length - 1);
}

bool array_set(array* arr, size_t index, void* element) {
    size_t ts = arr->type_size;
    if (arr->capacity <= index) { // expand body
        size_t new_capacity = _get_quadratic_capacity(index);
        byte* new_body = (byte *)calloc(new_capacity, ts);
        memcpy(new_body, arr->body, arr->length * ts);

        free(arr->body);
        arr->body = new_body;
        arr->capacity = new_capacity;
    }

    arr->length = MAX(arr->length, index + 1);
    memcpy((void *)arr->body + index * ts, element, ts);
    return true;
}


bool array_push_back(array* arr, void* element) {
    return array_set(arr, arr->length++, element);
}

void* array_pop_back(array* arr) {
    if (arr->length == 0)
        return NULL;

    return array_get(arr, --arr->length);
}

bool array_clear(array* arr) {
    /**
        - clear every elements to zero
        - set length to zero
        - keep memory allocated (capacity doesn't change)
    */
    arr->length = 0;
    memset(arr->body, 0x00, arr->type_size * arr->capacity);

    return true;
}

bool array_empty(array* arr) {
    return arr->length == 0;
}


bool array_has(array* arr, void* element) {
    for (int i = 0; i < arr->length; i++) {
        void* a_i = array_get(arr, i);
        int cmp = memcmp(a_i, element, arr->type_size);
        // cmp == 0 when they match
        if (!cmp)
            return true;
    }

    return false;
}

int array_index(array* arr, void* element) {
    for (int i = 0; i < arr->length; i++) {
        void* a_i = array_get(arr, i);
        int cmp = memcmp(a_i, element, arr->type_size);
        // cmp == 0 when they match
        if (!cmp) 
            return i;
    }

    return -1;
}

bool array_destroy(array* arr) {
    free(arr->body);
    free(arr);

    return true;
}

/**
    아래의 함수들은 array.h를 통해서 인터페이스가 제공되지 않는 함수들임.
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
