SRCS = array.c
CC = gcc
OPTS = -std=c++11 -Wall -O

ARR_SRCS = array.c
ARR_OBJS = $(SRCS:.c=.o)

STACK_SRCS = stack.c array.c
STACK_OBJS = $(STACK_SRCS:.c=.o)

%.o: %.c
	$(CC) -c $< -o $@

array: $(ARR_OBJS)
	$(CC) $(ARR_OBJS) test_array.c -o test

stack: $(STACK_OBJS)
	$(CC) $(STACK_OBJS) test_stack.c -o test

clean:
	ls -1 |grep "\.o" |xargs rm -f
