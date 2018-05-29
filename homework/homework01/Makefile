GCC_FLAGS = -Wall -Wshadow

main: main.o mymatrix.o
	gcc $(GCC_FLAGS) -o main main.c mymatrix.c

main.o: main.c
	gcc -c main.c

mymatrix.o: mymatrix.c
	gcc -c mymatrix.c

test: test.c
	gcc $(GCC_FLAGS) -o test test.c