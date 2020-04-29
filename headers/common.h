#ifndef COMMON_H
#define COMMON_H
#include <stddef.h>

typedef enum _bool {
    false = 0,
    true = 1,
} bool;

typedef char byte;

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#endif /* COMMON_H */
