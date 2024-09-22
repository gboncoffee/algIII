CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic -g

myavl: main.o avl.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	-rm *.o
	-rm myavl

test: myavl
	./myavl < test/teste1.in | diff - test/teste1.out
	./myavl < test/teste2.in | diff - test/teste2.out
	./myavl < test/teste3.in | diff - test/teste3.out
	./myavl < test/teste4.in | diff - test/teste4.out
