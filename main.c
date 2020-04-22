#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main() {
    array* arr;
    array_new(&arr, sizeof(int));
    int a = 10;
    array_set(arr, 0, &a);
    int* res;
    array_set(arr, 130, &a);
    res = (int *)array_get(arr, 130);
    if (res == NULL) {
        puts("NULL"); return 1;
    }
    printf("%d", *res);
}
