CC=gcc
CFLAGS=-Wall -Werror -g
BIN=build

build: stack.o test_stack.o
	$(CC) $(CFLAGS) stack.o test_stack.o -o $(BIN)

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

test_stack.o: stack.h test_stack.c
	$(CC) $(CFLAGS) -c test_stack.c

clean:
	rm *.o $(BIN)
