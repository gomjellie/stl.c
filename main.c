#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main() {
    array* arr = new_array(sizeof(int));
    int elem = 10;
    array_set(arr, 0, &elem);
    array_set(arr, 130, &elem);
    int* res = (int *)array_get(arr, 130);
    if (res == NULL) {
        puts("NULL"); return 1;
    }
    printf("%d", *res);
}
