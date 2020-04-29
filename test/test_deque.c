#include "unity.h"

#include "deque.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_deque_constructor(void)
{
    deque* dq = new_deque(free);
}

