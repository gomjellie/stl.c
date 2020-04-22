SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = test

CC = gcc
OPTS = -std=c11 -Wall -I.

ARR_SRCS = $(SRC_DIR)/array.c
ARR_OBJS = $(ARR_SRCS:src%.c=obj%.o)

STACK_SRCS = $(SRC_DIR)/stack.c $(SRC_DIR)/array.c
STACK_OBJS = $(STACK_SRCS:src%.c=obj%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(OPTS) -c $< -o $@

array: $(ARR_OBJS)
	$(CC) $(ARR_OBJS) $(TEST_DIR)/test_array.c -o run_test $(OPTS)

stack: $(STACK_OBJS)
	$(CC) $(STACK_OBJS) $(TEST_DIR)/test_stack.c -o run_test $(OPTS)

clean:
	cd ./obj; ls -1 |grep "\.o" |xargs rm -f;

