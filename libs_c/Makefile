klibc: klibc.o
	gcc klibc.o -o klibc

klibc.o: klibc.c
	gcc -c klibc.c

.PHONY: clean

#example: example.o klibc.o
#	gcc klibc.o example.o -o example.out

example: examples/example.c src/klibc.c
	gcc examples/example.c src/klibc.c -o example.out

clean:
	rm *.o *.out 
