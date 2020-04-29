#ifndef DEQUEUE_H
#define DEQUEUE_H
#include "common.h"

typedef enum _element_type {
    PRIMITIVE,
    OBJECT,
} element_type;

typedef enum _dequeue_defaults {
    INIT_CAPACITY_LENGTH = 128,
} dequeue_defaults;

typedef struct _dequeue{
    void** buff;
    
    element_type type;
    
    size_t template_size;
    size_t front;
    size_t rear;
    size_t capacity;
    
    void (*destructor) (void*);
} dequeue;

dequeue* new_dequeue_primitive(size_t template_size);
dequeue* new_dequeue_object(void (*destructor) (void* this));

// 진짜 c11은 전설이다....
#define new_dequeue(dynamic_param) _Generic(dynamic_param, \
    size_t: new_dequeue_primitive, \
    int: new_dequeue_primitive, \
    default: new_dequeue_object\
) (dynamic_param)

#endif // DEQUEUE_H
