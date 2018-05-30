GCC_FLAGS = -Wall -Wshadow
VAL = valgrind --tool=memcheck --leak-check=full

matrix: matrix.o mymatrix.o
	gcc $(GCC_FLAGS) -o matrix matrix.c mymatrix.c

matrix.o: matrix.c
	gcc -c matrix.c

mymatrix.o: mymatrix.c
	gcc -c mymatrix.c

testall: test1 test2 test3 test4

test1: matrix input1 e_output1
	$(VAL) ./matrix < input1
	./matrix < input1 > output1
	diff output1 e_output1

test2: matrix input2 e_output2
	$(VAL) ./matrix < input2
	./matrix < input2 > output2
	diff output2 e_output2

test3: matrix input3 e_output3
	$(VAL) ./matrix < input3
	./matrix < input3 > output3
	diff output3 e_output3

test4: matrix input4 e_output4
	$(VAL) ./matrix < input4
	./matrix < input4 > output4
	diff output4 e_output4
