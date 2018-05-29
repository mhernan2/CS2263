#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "mymatrix.h"

void printMatrix(int **m, int r, int c) {
	int i, j;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}

int ** matrix_mult(int ** matrix1, int r1, int c1, int ** matrix2, int r2, int c2) {
	// check if int ** is valid
	if (c1 != r2) {
		return 0; 
	}

	// create resulting int **
	int i, j, k;
	int **resultingMatrix = malloc(r1*c2*sizeof(int));

	return resultingMatrix;

}

// returns an the row vector of a int ** in the form of an array
// 0 is for rows and 1 for column vector
int *getRowVector(int roc, int index, const int length, int **m) {
	int *vector;

	if (roc == 0) {
		 vector = m[index];
	} else if (roc == 1) {
		int i;
		for (i = 0; i < length; i++) {
			vector[i] = m[i][index];
		}
	}

	return (vector);
}

int **matrix_add(int** matrix1, int ** matrix2) {
	int **a = malloc(4*sizeof(int*));
	return a;
}

