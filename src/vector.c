#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include "vector.h"

static size_t _get_quadratic_capacity(size_t prev_capacity);

vector* new_vector_primitive(size_t template_size) {
    vector* this = (vector*) malloc(sizeof(vector));
    this->template_size = template_size;
    this->type = PRIMITIVE;
    this->destructor = free;
    this->buff = (void **)calloc(INIT_CAPACITY, sizeof(void *));
    this->capacity = INIT_CAPACITY;
    this->length = 0;

    return this;
}
/**
    destructor 가 필요한 이유?
    내부적으로 포인터를 갖지 않는 자료형이라면 그냥 free해주면 됨
    예를들면 
    struct A{
        int a;
        float b;
    }
    이런경우. free함수면 충분하다.

    하지만, 내부적으로 포인터를 갖고 거기에 동적할당을 해준 멤버를 갖고 있다면?
    struct B{
        int a;
        int* buffer; // malloc으로 버퍼가 할당될것이다.
    }
    모든 타입을 지원하는 generic한 프로그래밍을 위해서 void*로 원소를 받는데
    우리는 안의 struct에 어디를 또 free해줘야 할지 모른다. (struct B안의 buffer의 존재도 모름)
    따라서 struct B의 메모리를 수거하는 함수를 인자로 받는다.
*/
vector* new_vector_object(void (*destructor) (void *element)) {
    vector* this = (vector*) malloc(sizeof(vector));
    this->type = OBJECT;
    this->destructor = destructor;
    this->buff = (void **)calloc(INIT_CAPACITY, sizeof(void *));
    this->capacity = INIT_CAPACITY;
    this->length = 0;

    return this;
}

void* vector_get(vector* this, size_t index) {
    if (this->length <= index)
        return NULL;

    return this->buff[index];
}

void* vector_at(vector* this, size_t index) {
    if (this->length <= index)
        return NULL;

    return this->buff[index];
}

void* vector_front(vector* this) {
    return vector_at(this, 0);
}

void* vector_back(vector* this) {
    return vector_at(this, this->length - 1);
}

bool vector_set(vector* this, size_t index, void* element) {
    size_t ps = sizeof(void *); // pointer size
    if (this->capacity <= index) { // expand buff
        size_t new_capacity = _get_quadratic_capacity(index);
        void** new_buff = (void *)calloc(new_capacity, ps);
        memcpy(new_buff, this->buff, this->length * ps);

        free(this->buff);
        this->buff = new_buff;
        this->capacity = new_capacity;
    }

    if (this->buff[index] != NULL)
        this->destructor(this->buff[index]);

    this->length = MAX(this->length, index + 1);
    if (this->type == PRIMITIVE) {
        void* _elem = (void *) malloc(this->template_size);
        if (_elem == NULL) return false;

        memcpy(_elem, element, this->template_size);
        element = _elem;
    }
    this->buff[index] = element;
    return true;
}

bool vector_push_back(vector* this, void* element) {
    return vector_set(this, this->length, element);
}

bool vector_pop_back(vector* this) {
    if (this->length == 0)
        return false;

    this->length--;
    return true;
}

bool vector_clear(vector* this) {
    /**
        - clear every elements to zero
        - set length to zero
        - keep memory allocated (capacity doesn't change)
    */
    this->length = 0;
    for (int i = 0; i < this->length; i++) {
        if (this->buff[i] != NULL)
            this->destructor(this->buff[i]);
    }
    memset(this->buff, 0x00, sizeof(void *) * this->capacity);

    return true;
}

bool vector_empty(vector* this) {
    return this->length == 0;
}

bool vector_has(vector* this, void* element, int (*cmp_func)(const void*, const void*)) {
    for (int i = 0; i < this->length; i++) {
        void* a_i = vector_at(this, i);
        
        if (cmp_func(a_i, element))
            return true;
    }

    return false;
}

int vector_index(vector* this, void* element, int (*cmp_func)(const void*, const void*)) {
    for (int i = 0; i < this->length; i++) {
        void* a_i = vector_at(this, i);
        
        if (cmp_func(a_i, element))
            return i;
    }

    return -1;
}

bool vector_destructor(vector* this) {
    for (int i = 0; i < this->length; i++) {
        if (this->buff[i] != NULL)
            this->destructor(this->buff[i]);
    }

    free(this->buff);
    free(this);

    return true;
}

/**
    아래의 함수들은 vector.h를 통해서 인터페이스가 제공되지 않는 함수들임.
*/

static size_t _get_quadratic_capacity(size_t prev_capacity) {
    /**
    capacity를 초과한 인덱스를 위해 새로 할당할 capacity를 계산함
    10 -> 16
    5 -> 8
    4 -> 8
    */
    return 0x02 << (size_t)log2(prev_capacity);
}
