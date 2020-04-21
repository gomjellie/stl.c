#ifndef __ARRAY_H__
#include "common.h"

enum array_default {
    INIT_BODY_LENGTH = 100,
};

struct _array {
    int length;
    void* body;
};

typedef struct _array array;

void* array_get(array* arr, int index);
void* array_set(array* arr, int index, void* val);
bool array_new(array* arr, int type_size);

#endif /* __ARRAY_H__ */
