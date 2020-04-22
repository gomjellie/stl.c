#include <stdlib.h>
#include "array.h"
#ifndef __STACK_H__

typedef struct _stack {
    array* s_body;

    size_t length;
} stack;

stack* new_stack(size_t type_size);
bool stack_push_back(stack* v, void* element);
void* stack_pop_back(stack* v);
bool stack_empty(stack* v);

#endif /* __STACK_H__ */
