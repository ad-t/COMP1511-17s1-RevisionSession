CC=gcc
CFLAGS=-Wall -Werror -g
BIN=build

build: queue.o test_queue.o
	$(CC) $(CFLAGS) queue.o test_queue.o -o $(BIN)

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

test_queue.o: queue.h test_queue.c
	$(CC) $(CFLAGS) -c test_queue.c

clean:
	rm *.o $(BIN)
