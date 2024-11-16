CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic -g

myrb: main.o rb.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	-rm *.o
	-rm myrb

test: myrb
	./myrb < test/teste1.in | diff - test/teste1.out
	./myrb < test/teste2.in | diff - test/teste2.out
	./myrb < test/teste3.in | diff - test/teste3.out
	./myrb < test/teste4.in | diff - test/teste4.out
