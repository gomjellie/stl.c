#ifndef SHALLOW_VECTOR_H
#define SHALLOW_VECTOR_H
#include "common.h"

enum shallow_vector_default {
    INIT_CAPACITY_LENGTH = 128,
};

typedef struct _shallow_vector {
    size_t length;
    size_t capacity;
    
    void** v_buff;

    void (*element_destroyer) (void *element);
} shallow_vector;

shallow_vector* new_shallow_vector(void (*element_destroyer) (void *element));
bool shallow_vector_destroy(shallow_vector* this);

void* shallow_vector_get(shallow_vector* this, size_t index);
void* shallow_vector_at(shallow_vector* this, size_t index);
void* shallow_vector_front(shallow_vector* this);
void* shallow_vector_back(shallow_vector* this);
bool shallow_vector_set(shallow_vector* this, size_t index, void* element);
bool shallow_vector_push_back(shallow_vector* this, void* element);

void* shallow_vector_pop_back(shallow_vector* this);
bool shallow_vector_clear(shallow_vector* this);

bool shallow_vector_empty(shallow_vector* this);
bool shallow_vector_has(shallow_vector* this, void* element);
int shallow_vector_index(shallow_vector* this, void* element);


#endif // SHALLOW_VECTOR_H
