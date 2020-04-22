#include <stdlib.h>
#include "vector.h"
#ifndef __STACK_H__
#define __STACK_H__

typedef struct _stack {
    vector* s_buff;

    size_t length;
} stack;

stack* new_stack(size_t type_size);
bool stack_destroy(stack* s);

bool stack_push(stack* s, void* element);
void* stack_pop(stack* s);
bool stack_empty(stack* s);

#endif /* __STACK_H__ */
