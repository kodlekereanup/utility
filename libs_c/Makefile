klibc: klibc.o
	gcc klibc.o -o klibc

klibc.o: klibc.c
	gcc -c klibc.c

.PHONY: clean

clean:
	rm *.o klibc
