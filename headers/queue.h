#ifndef QUEUE_H
#define QUEUE_H
#include "deque.h"

typedef struct _queue {
    deque* buff;
} queue;

queue* new_queue_primitive(size_t template_size);
queue* new_queue_object(void (*destructor) (void* this));

// 함수 오버로딩, 인자가 sizeof(타입)인지 함수포인터인지 구분해서 전처리기가 함수를 스위치함
#define new_queue(dynamic_param) _Generic(dynamic_param, \
    size_t: new_queue_primitive, \
    default: new_queue_object\
) (dynamic_param)

bool queue_destructor(queue* this);

void* queue_front(queue* this);
void* queue_back(queue* this);
bool queue_push(queue* this, void* element);
bool queue_pop(queue* this);
size_t queue_size(queue* this);
bool queue_empty(queue* this);

#endif // QUEUE_H
