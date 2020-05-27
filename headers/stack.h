#include <stdlib.h>
#include "vector.h"
#ifndef STACK_H
#define STACK_H

typedef struct _stack {
    vector* buff;

    size_t length;
} stack;

stack* new_stack_primitive(size_t template_size);
stack* new_stack_object(void (*destructor) (void* this));

// 함수 오버로딩, 인자가 sizeof(타입)인지 함수포인터인지 구분해서 전처리기가 함수를 스위치함
#define new_stack(dynamic_param) _Generic(dynamic_param, \
    size_t: new_stack_primitive, \
    default: new_stack_object\
) (dynamic_param)

void stack_destructor(stack* this);

bool stack_push(stack* this, void* element);
void* stack_pop(stack* this);
bool stack_empty(stack* this);

#endif /* STACK_H */
