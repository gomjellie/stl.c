#ifndef __COMMON_H__
#define __COMMON_H__

typedef enum _bool {
    false = 0,
    true = 1,
} bool;

typedef char byte;

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#endif /* __COMMON_H__ */
