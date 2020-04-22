# c_stl

c++의 stl을 c에서 구현한 라이브러리

# vector

## vector functions

 - [`new_array`](#new_array) (`array* new_array(size_t type_size)`) 생성자
 - [`destroy`](#array_destroy) (`bool array_destroy(array* arr)`) 메모리 해재
 - [`get`](#array_get) (`void* array_get(array* arr, size_t index)`)
 - [`at`](#array_at) (`void* array_at(array* arr, size_t index)`)
 - [`front`](#array_front) (`void* array_front(array* arr)`)
 - [`back`](#array_back) (`void* array_back(array* arr)`)
 - [`set`](#array_set) (`bool array_set(array* arr, size_t index, void* element)`)
 - [`push_back`](#array_push_back) (`bool array_push_back(array* arr, void* element)`)
 - [`array_pop_back`](#array_pop_back) (`void* array_pop_back(array* arr)`)
 - [`clear`](#array_clear) (`bool array_clear(array* arr)`)
 - [`empty`](#array_empty) (`bool array_empty(array* arr)`)
 - [`has`](#array_has) (`bool array_has(array* arr, void* element)`)
 - [`find'](#array_find) (`int array_find(array* arr, void* element)`)

## vector memeber variables

 - `length` (`size_t`) 
 - `capacity` (`size_t`)
 - `type_size` (`size_t`)

## new_array

Prototype: `array* new_array(size_t type_size);`

메모리를 생성한다. 초기에 capacity는 128을 갖는다.

Usage:

```c
array* v = new_array(sizeof(int)); // vector<int> v 와 동일함.
```

## array_destroy
Prototype: `bool array_destroy(array* arr);`

메모리 해재.

Usage:
```c
array* v = new_array(sizeof(int)); // vector<int> v;
array_destroy(v);
```

## array_get
Prototype: `void* array_get(array* arr, size_t index);`

index번째 원소를 참조한다. 메모리가 할당되지 않은 영역은 NULL을 참조하게 된다.

Usage:
```c
int *ret = array_get(v, 10); // int ret = v[10];

if (ret == NULL) return 0; // if index is out of boundary
printf("%d", *ret); // cout << ret
```

## array_at
Prototype: `void* array_at(array* arr, size_t index);`

index번째 원소를 참조한다. 메모리가 할당되지 않은 영역은 NULL을 참조하게 된다.

Usage:
```c
int *ret = array_get(v, 10); // int ret = v[10];

if (ret == NULL) return 0; // if index is out of boundary
printf("%d", *ret); // cout << ret
```

## array_front
Prototype: `void* array_front(array* arr);`

첫번째 원소를 참조한다.

## array_back
Prototype: `void* array_back(array* arr);`

마지막 원소를 참조한다.

## array_set
Prototype: `bool array_set(array* arr, size_t index, void* element);`

index번째 원소를 element로 설정한다.

Usage:
```c
for (int i = 0; i < 10; i++) {
    array_set(v, i, &i); /* v[i]] = i; */
}

```

## array_push_back
Prototype: `bool array_push_back(array* arr, void* element);`

마지막 원소 뒤에 원소 element를 삽입한다.

Usage:
```c
for (int i = 0; i < 10; i++) {
    array_push_back(v, &i);
}
```

## array_pop_back
Prototype: `void* array_pop_back(array* arr);`

마지막 원소를 제거합니다.

Usage:
```c
while (!array_empty(v)) {
    array_pop_back(v);
}
```

## array_clear
Prototype: `bool array_clear(array* arr);`

모든 원소를 0으로 리셋한다.
length는 0으로 줄었지만 capacity와 메모리는 그대로 유지한다.

```c
array_clear(v);
```

## array_has
Prototype: `bool array_has(array* arr, void* element);`

python에서 사용하는 if elem in list: 같은 표현을 가능하게 해줌
python과 마찬가지로 실제 동작은 리스트안의 모든 원소를 순회하며 비교한다.

```c
if (array_has(v, element)) { // if elem in v:

}
```

## array_index
Prototype: `int array_index(array* arr, void* element);`

python에서 사용하는 [1, 2, 3].index(3) 과같은 표현을 가능하게 해줌

```c
for (int i = 0; i < 3; i++) {
    array_push_back(v, &i);
}
int elem = 2;
int* idx = array_index(v, &elem); // [0, 1, 2] 중에서 2의 인덱스인 2를 리턴합니다.

```
