#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main() {
    array* arr;
    array_new(arr, sizeof(int));
    array_set(arr, 0, (void *)10);
    int* res;
    // array_get(arr, 0);
    // printf("%d", res[0]);
}
