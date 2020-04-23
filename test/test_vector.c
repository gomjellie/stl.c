#include "unity.h"

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

vector* v;

void setUp(void) {
    v = new_vector(sizeof(int));
}

void tearDown(void) {
    vector_destroy(v);
}

void test_vector_set_with_int(void) {
    int nine = 9;
    vector_set(v, 2, &nine);
}

void test_vector_get_with_int(void) {
    int ten = 10;
    vector_set(v, 130, &ten);
    int* res = (int*)vector_get(v, 131);
    if (res == NULL) { // supposed to be NULL
        printf("pass"); return;
    }

    int zero = 0;
    int err = 10 / zero; // throw errow 
}

void test_vector_has(void) {
    int nine = 9;
    vector_set(v, 2, &nine);
    
    bool has_9 = vector_has(v, &nine);
    if (has_9) { // supposed to have nine
        printf("pass"); return;
    }
}

void test_vector_index(void) {
    int nine = 9;
    vector_set(v, 2, &nine);
    printf("nine is at %d\n", vector_index(v, &nine));
}
