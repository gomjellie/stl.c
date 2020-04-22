SRCS = array.c
CC = gcc
OPTS = -std=c++11 -Wall -O
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -c $< -o $@

main: $(OBJS)
	$(CC) $(OBJS) main.c -o run

clean:
	ls -1 |grep "\.o" |xargs rm -f
