#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include "array.h"

size_t _get_quadratic_length(size_t prev_length);

void* array_get(array* arr, size_t index) {
    if (arr->length < index)
        return NULL;

    return arr->body + index * arr->type_size;
}

bool array_set(array* arr, size_t index, void* element) {
    size_t ts = arr->type_size;
    if (arr->length < index) { // expand body
        size_t new_length = _get_quadratic_length(index);
        byte* new_body = (byte *)calloc(new_length, ts);
        memcpy(new_body, arr->body, arr->length * ts);

        free(arr->body);
        arr->body = new_body;
        arr->length = new_length;
    }

    memcpy((void *)arr->body + index * ts, element, ts);
    return true;
}

bool array_new(array** arr, size_t type_size) {
    array* new_arr = malloc(sizeof(array));
    new_arr->body = (byte *)calloc(INIT_BODY_LENGTH, type_size);
    new_arr->length = INIT_BODY_LENGTH;
    new_arr->type_size = type_size;

    *arr = new_arr;
    return true;
}

array* new_array(size_t type_size) {
    array* new_arr = malloc(sizeof(array));
    new_arr->body = (byte *)calloc(INIT_BODY_LENGTH, type_size);
    new_arr->length = INIT_BODY_LENGTH;
    new_arr->type_size = type_size;

    return new_arr;
}

bool array_destroy(array* arr) {
    free(arr->body);
    free(arr);

    return true;
}

/**
    아래의 함수들은 array.h를 통해서 인터페이스가 제공되지 않는 함수들임.
*/

size_t _get_quadratic_length(size_t prev_length) {
    /**
    length를 초과한 인덱스를 위해 새로 할당할 length를 계산함
    10 -> 16
    5 -> 8
    4 -> 8
    */
    return 0x02 << (size_t)log2(prev_length);
}
