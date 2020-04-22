#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include "array.h"

size_t _get_quadratic_capacity(size_t prev_capacity);

void* array_get(array* arr, size_t index) {
    if (arr->length <= index)
        return NULL;

    return arr->body + index * arr->type_size;
}

bool array_set(array* arr, size_t index, void* element) {
    size_t ts = arr->type_size;
    if (arr->capacity <= index) { // expand body
        puts("expanding");
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

bool array_new(array** arr, size_t type_size) {
    array* new_arr = malloc(sizeof(array));
    new_arr->body = (byte *)calloc(INIT_BODY_LENGTH, type_size);
    new_arr->capacity = INIT_BODY_LENGTH;
    new_arr->length = 0;
    new_arr->type_size = type_size;

    *arr = new_arr;
    return true;
}

array* new_array(size_t type_size) {
    array* new_arr = malloc(sizeof(array));
    new_arr->body = (byte *)calloc(INIT_BODY_LENGTH, type_size);
    new_arr->capacity = INIT_BODY_LENGTH;
    new_arr->length = 0;
    new_arr->type_size = type_size;

    return new_arr;
}

bool array_has(array* arr, void* element) {
    for (int i = 0; i < arr->length; i++) {
        void* a_i = array_get(arr, i);
        int cmp = memcmp(a_i, element, arr->type_size);
        // cmp == 0 when they match
        if (!cmp) {
            return true;
        }
    }

    return false;
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
