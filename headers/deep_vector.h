#ifndef DEEP_VECTOR_H
#define DEEP_VECTOR_H
#include "common.h"

enum deep_vector_default {
    INIT_CAPACITY_LENGTH = 128,
};

typedef struct _deep_vector {
    size_t length;
    size_t capacity;
    size_t template_size;

    byte* v_buff;
} deep_vector;

deep_vector* new_deep_vector(size_t template_size);
bool deep_vector_destroy(deep_vector* this);

void* deep_vector_get(deep_vector* this, size_t index);
void* deep_vector_at(deep_vector* this, size_t index);
void* deep_vector_front(deep_vector* this);
void* deep_vector_back(deep_vector* this);
bool deep_vector_set(deep_vector* this, size_t index, void* element);
bool deep_vector_push_back(deep_vector* this, void* element);

void* deep_vector_pop_back(deep_vector* this);
bool deep_vector_clear(deep_vector* this);

bool deep_vector_empty(deep_vector* this);
bool deep_vector_has(deep_vector* this, void* element);
int deep_vector_index(deep_vector* this, void* element);

#endif /* DEEP_VECTOR_H */
