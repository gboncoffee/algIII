CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic -g

myht: main.o ht.o
	$(CC) $(CFLAGS) $^ -o $@ -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	-rm *.o
	-rm myht

test: myht
	./myht < test/teste1.in | diff - test/teste1.out
	./myht < test/teste2.in | diff - test/teste2.out
	./myht < test/teste3.in | diff - test/teste3.out
	./myht < test/teste4.in | diff - test/teste4.out
