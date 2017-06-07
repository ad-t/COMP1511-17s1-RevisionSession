# target: dependency1.o dependency2.o
# 	(command to build the target)
#
# dependency1.o: dependency1.c dependency1.h
# 	(command to build dependency1)
#
# dependency2.o: dependency2.o dependency2.h
#	(command to build dependency2)
#
# (optional)
# clean:
# 	rm *.o $(BUILD)
#
# -- declaring variables 	-> VARIABLE=value (no quotations)
# -- using variables 		-> $(VARIABLE)		

CC=gcc
CFLAGS=-Wall -Werror
BIN=build

build: linked_list.o test_linked_list.o
	$(CC) $(CFLAGS) -o $(BIN) linked_list.o test_linked_list.o

linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c linked_list.c

test_linked_list.o: linked_list.h test_linked_list.c
	$(CC) $(CFLAGS) -c test_linked_list.c
	
clean:
	rm *.o $(BIN)


