#ifndef DEQUEUE_H
#define DEQUEUE_H
#include "common.h"

typedef enum _element_type {
    PRIMITIVE,
    OBJECT,
} element_type;

typedef enum _deque_defaults {
    INIT_CAPACITY_LENGTH = 128,
} deque_defaults;

typedef struct _deque{
    void** buff;
    
    element_type type;
    
    size_t template_size;
    size_t front;
    size_t rear;
    size_t capacity;
    
    void (*destructor) (void*);
} deque;

deque* new_deque_primitive(size_t template_size);
deque* new_deque_object(void (*destructor) (void* this));

// 진짜 c11은 전설이다....
#define new_deque(dynamic_param) _Generic(dynamic_param, \
    size_t: new_deque_primitive, \
    int: new_deque_primitive, \
    default: new_deque_object\
) (dynamic_param)

#endif // DEQUEUE_H
