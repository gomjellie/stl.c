# c_stl

c++의 stl을 c에서 구현한 라이브러리

## vector

```c
#include <c_stl.h>

vector* v = new_vector(sizeof(int)); // vector<int> v 와 같음

int element = 10;
vector_push_back(v, &element); // v.push_back(element);
vector_set(v, 300, &element); // v[300] = element;

int* res = vector_at(v, 300);

vector_destructor(v);
```

## stack

```c
stack* s = new_stack(sizeof(double));

double element = 3.14;
stack_push(s, &element);
double* res = (double *)stack_top(s);
stack_pop(s);

stack_destructor(s);
```

## deque

```c
deque* dq = new_deque(sizeof(float));

float element = 3.14;
deque_push_back(dq, &element);
deque_push_front(dq, &element);

float* res = deque_front(dq);
printf("%f\n", *res);
deque_destructor(dq);
```

