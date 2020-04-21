#include <stdlib.h>
#include "array.h"

void* array_get(array* arr, int index) {
    if (arr->length < index) {
        // needs scale up

        return NULL;
    }
    return (void *)arr->body+index;
}

bool array_new(array* arr, int type_size) {
    arr = malloc(sizeof(array));

    arr->body = malloc(INIT_BODY_LENGTH * type_size);

    return 1;
}

