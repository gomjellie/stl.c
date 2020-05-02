# c_stl

c++의 stl을 c에서 구현한 라이브러리

# primitive type support

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
deque_pop_front(dq);

deque_destructor(dq);
```

# object support

원소로 객체(struct안에 동적할당된 공간을 갖는경우) 타입을 사용하기위해서는 sizeof(객체)가 아닌, 객체의 소멸자를 생성자에 대신 넣어줍니다.

```c
// let's say we have defiend object as shown below
typedef struct _object_t {
    size_t len;
    char* body_buff;
} object_t;

object_t* new_object_t() {
    object_t* this = (object_t*) malloc(sizeof(object_t));
    this->len = 100;
    this->body_buff = (char*) malloc(100);
    return this;
}

void object_t_destructor(object_t* this) {
    free(this->body_buff);
    free(this);
}

deque* dq = new_deque(object_t_destructor); // 소멸자를 size 대신에 넘겨야함

deque_push_back(dq, new_object_t());
deque_destructor(dq); // object_t_destructor 를 통해서 내부를 정리해줌.
```

# TEST

ceedling을 먼저 설치해야됩니다. (gem install ceedling)

```sh
ceedling test:all
```
