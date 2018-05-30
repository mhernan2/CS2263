GCC_FLAGS = -Wall -Wshadow
VAL = valgrind --tool=memcheck --leak-check=full
VAL += --log-file=

matrix: matrix.o mymatrix.o
	gcc $(GCC_FLAGS) -o $@ matrix.c mymatrix.c

matrix.o: matrix.c
	gcc -c matrix.c

mymatrix.o: mymatrix.c
	gcc -c mymatrix.c

testall: test1 test2 test3 test4

test1: matrix input1 e_output1
	$(VAL)test1.log ./matrix < input1 > output1
	diff -q output1 e_output1

test2: matrix input2 e_output2
	$(VAL)test2.log ./matrix < input2 > output2
	diff -q output2 e_output2

test3: matrix input3 e_output3
	$(VAL)test3.log ./matrix < input3 > output3
	diff -q output3 e_output3

test4: matrix input4 e_output4
	$(VAL)test4.log ./matrix < input4 > output4
	diff -q output4 e_output4
