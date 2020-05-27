#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "common.h"

typedef struct _priority_queue {
    void** heap;

    element_type type;

    size_t template_size;
    size_t capacity;
    size_t length;

    void (*destructor) (void*);
    bool (*cmp)(const void*, const void*); // 1: 첫번째가 더 높은 우선순위, 0 같거나 낮은 우선순위
} priority_queue;

priority_queue* new_priority_queue_primitive(size_t template_size, bool (*cmp_func)(const void*, const void*));
priority_queue* new_priority_queue_object(void (*destructor) (void* this), bool (*cmp_func)(const void*, const void*));

// 함수 오버로딩, 인자가 sizeof(타입)인지 함수포인터인지 구분해서 전처리기가 함수를 스위치함
#define new_priority_queue(dynamic_param, cmp_func) _Generic(dynamic_param, \
    size_t: new_priority_queue_primitive, \
    default: new_priority_queue_object\
) (dynamic_param, cmp_func)

void priority_queue_destructor(priority_queue* this);

void* priority_queue_top(priority_queue* this);
bool priority_queue_push(priority_queue* this, void* element);
bool priority_queue_pop(priority_queue* this);

size_t priority_queue_size(priority_queue* this);
bool priority_queue_empty(priority_queue* this);

#endif // PRIORITY_QUEUE_H
