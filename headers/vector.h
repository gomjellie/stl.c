#ifndef __VECTOR_H__
#define __VECTOR_H__
#include "common.h"

enum vector_default {
    INIT_CAPACITY_LENGTH = 128,
};

struct _vector {
    size_t length;
    size_t capacity;
    size_t type_size;

    byte* v_buff;
};

typedef struct _vector vector;

vector* new_vector(size_t type_size);
bool vector_destroy(vector* this);

void* vector_get(vector* this, size_t index);
void* vector_at(vector* this, size_t index);
void* vector_front(vector* this);
void* vector_back(vector* this);
bool vector_set(vector* this, size_t index, void* element);
bool vector_push_back(vector* this, void* element);

void* vector_pop_back(vector* this);
bool vector_clear(vector* this);

bool vector_empty(vector* this);
bool vector_has(vector* this, void* element);
int vector_index(vector* this, void* element);

#endif /* __vector_H__ */
