#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "mymatrix.h"

void printMatrix(int **m, int r, int c) {
	printf("%d %d\n", r, c);
	int i, j;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			printf("%d", m[i][j]);
			if (j != c-1) printf(" ");
		}
		printf("\n");
	}
}


// returns an the row vector of a int ** in the form of an array
// 0 is for rows and 1 for column vector
int *getColumnVector(int index, int length, int **m) {
	int i, *vector = malloc(length*sizeof(int));

	for (i = 0; i < length; i++) {
		vector[i] = m[i][index];
	}

	return (vector);
}


int ** matrix_mult(int ** matrix1, int r1, int c1, int ** matrix2, int r2, int c2) {
	// check if int ** is valid
	if (c1 != r2) {
		return 0;
	}

	// create resulting int **
	int i, j, k, **resultingMatrix = malloc(r1*sizeof(int));
	int *rm = malloc(r1*c2*sizeof(int));

	for (i = 0; i < r1; i++) {
		resultingMatrix[i] = rm+(i*c2);
	}

	for (i = 0; i < c2; i++) {
		for (j = 0; j < r1; j++) {
			int result = 0;
			int *column = getColumnVector(i, r2, matrix2);

			for (k = 0; k < c1; k++) {
				result += matrix1[j][k] * column[k];
			}
			printf("contents of resultingMatrix[%d][%d]: %d\n", j, i, result);
			resultingMatrix[j][i] = result;
		}
	}

	printf("printing resulting matrix\n");
	printMatrix(resultingMatrix, r1, c2);
	return resultingMatrix;

}


int ** matrix_add(int **matrix1, int r1, int c1, int **matrix2, int r2, int c2) {
	int **a = malloc(4*sizeof(int*));
	return a;
}

