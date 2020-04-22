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
 - [`has`](#array_has) (`bool array_has(array* arr, void* element)`)
 - [`find'](#array_find) (`int array_find(array* arr, void* element)`)

## vector memeber variables

 - `length` (`size_t`) 
 - `capacity` (`size_t`)
 - `type_size` (`size_t`)

## new_array

Prototype: `array* new_array(size_t type_size);`

Usage:

```c
array* v = new_array(sizeof(int)); // vector<int> v 와 동일함.
```

## array_destroy
Prototype: `bool array_destroy(array* arr);`

## array_get
Prototype: `void* array_get(array* arr, size_t index);`

## array_at
Prototype: `void* array_at(array* arr, size_t index);`

## array_front
Prototype: `void* array_front(array* arr);`

## array_back
Prototype: `void* array_back(array* arr);`

## array_set
Prototype: `bool array_set(array* arr, size_t index, void* element);`

## array_push_back
Prototype: `bool array_push_back(array* arr, void* element);`

## array_pop_back
Prototype: `void* array_pop_back(array* arr);`

## array_clear
Prototype: `bool array_clear(array* arr);`

## array_has
Prototype: `bool array_has(array* arr, void* element);`

## array_find
Prototype: `int array_find(array* arr, void* element);`
