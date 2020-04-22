#include <stdio.h>
#include <stdlib.h>
#include "headers/vector.h"

int main() {
    vector* vec = new_vector(sizeof(int));
    int elem = 10;
    int nine = 9, ten = 10;
    int* res;
    vector_set(vec, 0, &elem);
    vector_set(vec, 130, &elem);
    
    res = (int *)vector_get(vec, 131);
    if (res == NULL) { // 130 까지 있는데 131번째 원소를 가져와서 NULL
        puts("NULL");
    }
    
    vector_set(vec, 129, &elem);
    res = (int *) vector_get(vec, 130);
    if (res == NULL) {
        puts("NULL"); return 1;
    }
    printf("%d\n", *res);

    vector_destroy(vec);

    vec = new_vector(sizeof(int));
    vector_set(vec, 128, &elem);

    bool has_9 = vector_has(vec, &nine);
    bool has_10 = vector_has(vec, &ten);
    printf("nine?: %d\n", has_9);
    printf("ten?: %d\n", has_10);

    printf("nine is at %d\n", vector_index(vec, &nine));
    printf("ten is at %d\n", vector_index(vec, &ten));
}
