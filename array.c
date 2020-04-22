#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "array.h"

size_t _get_quadratic_length(size_t prev_length);

void* array_get(array* arr, size_t index) {
    if (arr->length < index)
        return NULL;

    return arr->body + index * arr->type_size;
}

bool array_set(array* arr, size_t index, void* element) {
    size_t ts = arr->type_size;
    if (arr->length < index) {
        size_t new_length = _get_quadratic_length(index);
        size_t new_size = new_length * ts;
        byte* new_body = (byte *)malloc(new_size);
        memset(new_body, 0, new_size);
        memcpy(new_body, arr->body, arr->length * ts);

        free(arr->body);
        arr->body = new_body;
        memcpy(arr->body + index * ts, element, ts);
        return true;
    }

    memcpy(arr->body + index * ts, element, ts);
    return true;
}

bool array_new(array* arr, size_t type_size) {
    arr = malloc(sizeof(array));

    arr->body = (byte *)malloc(INIT_BODY_LENGTH * type_size);
    arr->type_size = type_size;

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
