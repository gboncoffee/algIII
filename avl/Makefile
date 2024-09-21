CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic -g

myavl: main.o avl.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	-rm *.o
	-rm myavl
