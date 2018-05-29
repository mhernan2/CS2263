#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mymatrix.h"

#define MULTIPLICATION "multiplication"
#define ADDITION "addition"

int main() {
	// scan the operation to be performed
	char operation[30];
	fgets(operation, 30, stdin);
	// get the input values for matrix1
	int i, r1, c1, r2, c2, **matrix1, **matrix2, *m1, *m2, **resultingMatrix;
	scanf("%d%d\n", &r1, &c1);
	matrix1 = malloc(r1*sizeof(int*));
	m1 = malloc(r1*c1*sizeof(int));
	for (i = 0; i < r1; i++) {
		matrix1[i] = m1+(i*c1);
	}
	// read the values into the matrix
	for (i = 0; i < r1*c1; i++) {
		scanf("%d", &m1[i]);
	}

	// get the input values for matrix2
	scanf("%d%d\n", &r2, &c2);
	matrix2 = malloc(r2*sizeof(int*));
	m2 = malloc(r2*c2*sizeof(int));
	for (i = 0; i < r2; i++) {
		matrix2[i] = m2+(i*c2);
	}
	// read the values into the matrix
	for (i = 0; i < r2*c2; i++) {
		scanf("%d", &m2[i]);
	}	

	if(strcmp(operation, MULTIPLICATION)) {
		resultingMatrix = matrix_mult(matrix1, r1, c1, matrix2, r2, c2);
	} else if(strcmp(operation, ADDITION)) {
		resultingMatrix = matrix_add(matrix1, r1, c1, matrix2, r2, c2);
	} else {
		printf("unknown operation \"%s\"\n", operation);
		return 0;
	}

	printMatrix(resultingMatrix);

	return 0;
}