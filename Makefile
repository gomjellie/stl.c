SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = test

CC = gcc
OPTS = -std=c11 -Wall -I.

VEC_SRCS = $(SRC_DIR)/vector.c
VEC_OBJS = $(VEC_SRCS:src%.c=obj%.o)

STACK_SRCS = $(SRC_DIR)/stack.c $(SRC_DIR)/vector.c
STACK_OBJS = $(STACK_SRCS:src%.c=obj%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(OPTS) -c $< -o $@

vector: $(VEC_OBJS)
	$(CC) $(VEC_OBJS) $(TEST_DIR)/test_vector.c -o run_test $(OPTS)

stack: $(STACK_OBJS)
	$(CC) $(STACK_OBJS) $(TEST_DIR)/test_stack.c -o run_test $(OPTS)

clean:
	cd ./obj; ls -1 |grep "\.o" |xargs rm -f;

