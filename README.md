# c_stl

c++의 stl을 c에서 구현한 라이브러리

# deep_vector

## deep_vector functions

 - [`new_deep_vector`](#new_deep_vector) (deep_vector* new_deep_vector(size_t `template_size`)) 메모리를 생성한다. 초기에 capacity는 128을 갖는다.
 - [`destroy`](#deep_vector_destroy) (`bool deep_vector_destroy(deep_vector* this)`) 메모리 해재
 - [`get`](#deep_vector_get) (`void* deep_vector_get(deep_vector* this, size_t index)`) index번째 원소를 참조한다. 메모리가 할당되지 않은 영역은 NULL을 참조하게 된다.
 - [`at`](#deep_vector_at) (`void* deep_vector_at(deep_vector* this, size_t index)`) index번째 원소를 참조한다. 메모리가 할당되지 않은 영역은 NULL을 참조하게 된다.
 - [`front`](#deep_vector_front) (`void* deep_vector_front(deep_vector* this)`) 첫번째 원소를 참조한다.
 - [`back`](#deep_vector_back) (`void* deep_vector_back(deep_vector* this)`) 마지막 원소를 참조한다.
 - [`set`](#deep_vector_set) (`bool deep_vector_set(deep_vector* this, size_t index, void* element)`) index번째 원소를 element로 설정한다.
 - [`push_back`](#deep_vector_push_back) (`bool deep_vector_push_back(deep_vector* this, void* element)`) 마지막 원소 뒤에 원소 element를 삽입한다.
 - [`deep_vector_pop_back`](#deep_vector_pop_back) (`void* deep_vector_pop_back(deep_vector* this)`) 마지막 원소를 제거합니다.
 - [`clear`](#deep_vector_clear) (`bool deep_vector_clear(deep_vector* this)`) 모든 원소를 0으로 리셋한다. length는 0으로 줄었지만 capacity와 메모리는 그대로 유지한다.
 - [`empty`](#deep_vector_empty) (`bool deep_vector_empty(deep_vector* this)`) 비어있으면 true, 원소가 하나라도 있으면 false
 - [`has`](#deep_vector_has) (`bool deep_vector_has(deep_vector* this, void* element)`) python에서 사용하는 if elem in list: 같은 표현을 가능하게 해줌 (시간복잡도: O(N))
 - [`index`](#deep_vector_index) (`int deep_vector_index(deep_vector* this, void* element)`) python에서 사용하는 [1, 2, 3].index(3) 과같은 표현을 가능하게 해줌

## deep_vector memeber variables

 - `length` (`size_t`) 
 - `capacity` (`size_t`)
 - `template_size` (`size_t`)

## new_deep_vector

Prototype: `deep_vector* new_deep_vector(size_t template_size);`

메모리를 생성한다. 초기에 capacity는 128을 갖는다.

Usage:

```c
deep_vector* v = new_deep_vector(sizeof(int)); // deep_vector<int> v 와 동일함.
```

## deep_vector_destroy
Prototype: `bool deep_vector_destroy(deep_vector* this);`

메모리 해재.

Usage:
```c
deep_vector* v = new_deep_vector(sizeof(int)); // deep_vector<int> v;
deep_vector_destroy(v);
```

## deep_vector_get
Prototype: `void* deep_vector_get(deep_vector* this, size_t index);`

index번째 원소를 참조한다. 메모리가 할당되지 않은 영역은 NULL을 참조하게 된다.

Usage:
```c
int *ret = deep_vector_get(v, 10); // int ret = v[10];

if (ret == NULL) return 0; // if index is out of boundary
printf("%d", *ret); // cout << ret
```

## deep_vector_at
Prototype: `void* deep_vector_at(deep_vector* this, size_t index);`

index번째 원소를 참조한다. 메모리가 할당되지 않은 영역은 NULL을 참조하게 된다.

Usage:
```c
int *ret = deep_vector_at(v, 10); // int ret = v[10];

if (ret == NULL) return 0; // if index is out of boundary
printf("%d", *ret); // cout << ret
```

## deep_vector_front
Prototype: `void* deep_vector_front(deep_vector* this);`

첫번째 원소를 참조한다.

## deep_vector_back
Prototype: `void* deep_vector_back(deep_vector* this);`

마지막 원소를 참조한다.

## deep_vector_set
Prototype: `bool deep_vector_set(deep_vector* this, size_t index, void* element);`

index번째 원소를 element로 설정한다.

Usage:
```c
for (int i = 0; i < 10; i++) {
    deep_vector_set(v, i, &i); /* v[i]] = i; */
}

```

## deep_vector_push_back
Prototype: `bool deep_vector_push_back(deep_vector* this, void* element);`

마지막 원소 뒤에 원소 element를 삽입한다.

Usage:
```c
for (int i = 0; i < 10; i++) {
    deep_vector_push_back(v, &i);
}
```

## deep_vector_pop_back
Prototype: `void* deep_vector_pop_back(deep_vector* this);`

마지막 원소를 제거합니다.

Usage:
```c
while (!deep_vector_empty(v)) {
    deep_vector_pop_back(v);
}
```

## deep_vector_clear
Prototype: `bool deep_vector_clear(deep_vector* this);`

모든 원소를 0으로 리셋한다.
length는 0으로 줄었지만 capacity와 메모리는 그대로 유지한다.

```c
deep_vector_clear(v);
```

## deep_vector_empty
Prototype: `bool deep_vector_empty(deep_vector* this, void* element);`

비어있으면 true, 원소가 하나라도 있으면 false

## deep_vector_has
Prototype: `bool deep_vector_has(deep_vector* this, void* element);`

python에서 사용하는 if elem in list: 같은 표현을 가능하게 해줌
python과 마찬가지로 실제 동작은 리스트안의 모든 원소를 순회하며 비교한다.

```c
if (deep_vector_has(v, element)) { // if elem in v:

}
```

## deep_vector_index
Prototype: `int deep_vector_index(deep_vector* this, void* element);`

python에서 사용하는 [1, 2, 3].index(3) 과같은 표현을 가능하게 해줌

```c
for (int i = 0; i < 3; i++) {
    deep_vector_push_back(v, &i);
}
int elem = 2;
int* idx = deep_vector_index(v, &elem); // [0, 1, 2] 중에서 2의 인덱스인 2를 리턴합니다.

```
