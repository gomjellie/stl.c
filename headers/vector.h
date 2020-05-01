#ifndef VECTOR_H
#define VECTOR_H
#include "common.h"

typedef enum _element_type {
    PRIMITIVE,
    OBJECT,
} element_type;

typedef enum _vector_defaults {
    INIT_CAPACITY = 128,
} vector_defaults;

typedef struct _vector{
    element_type type;
    size_t template_size;

    void** buff;

    size_t length;
    size_t capacity;

    void (*destructor) (void*);
} vector;

vector* new_vector_primitive(size_t template_size);
vector* new_vector_object(void (*destructor) (void* this));

// 함수 오버로딩, 인자가 sizeof(타입)인지 함수포인터인지 구분해서 전처리기가 함수를 스위치함
#define new_vector(dynamic_param) _Generic(dynamic_param, \
    size_t: new_vector_primitive, \
    default: new_vector_object\
) (dynamic_param)

bool vector_destructor(vector* this);

void* vector_get(vector* this, size_t index);
void* vector_at(vector* this, size_t index);
void* vector_front(vector* this);
void* vector_back(vector* this);
bool vector_set(vector* this, size_t index, void* element);
bool vector_push_back(vector* this, void* element);
bool vector_pop_back(vector* this);
bool vector_clear(vector* this);

bool vector_empty(vector* this);
bool vector_has(vector* this, void* element);
int vector_index(vector* this, void* element);


#endif // VECTOR_H
