#ifndef COMMON_H
#define COMMON_H
#include <stddef.h>
#include <stdbool.h>

typedef char byte;

typedef enum _element_type {
    PRIMITIVE,
    OBJECT,
} element_type;


typedef enum _vector_defaults {
    INIT_CAPACITY = 128,
} vector_defaults;

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#endif /* COMMON_H */
