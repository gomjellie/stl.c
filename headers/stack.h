#include <stdlib.h>
#include "deep_vector.h"
#ifndef __STACK_H__
#define __STACK_H__

typedef struct _stack {
    deep_vector* s_buff;

    size_t length;
} stack;

stack* new_stack(size_t template_size);
bool stack_destroy(stack* this);

bool stack_push(stack* this, void* element);
void* stack_pop(stack* this);
bool stack_empty(stack* this);

#endif /* __STACK_H__ */
