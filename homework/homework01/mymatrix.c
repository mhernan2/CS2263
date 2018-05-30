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
		if (i != r-1) printf("\n");
	}
}


// returns a column vector of a matrix in the form of an array
int *getColumnVector(int index, int length, int **m) {
	int i, *vector = malloc(length*sizeof(int));

	for (i = 0; i < length; i++) {
		vector[i] = m[i][index];
	}

	return vector;
}

void allocateSpace(int **matrix, int *m, int row, int column) {
	int i;
	for (i = 0; i < row; i++) {
		matrix[i] = m+(i*column);
	}
}


void matrix_mult(int ** matrix1, int r1, int c1, int ** matrix2, int r2, int c2) {
	// check if oepartion can be done is valid
	if (c1 != r2) {
		printf("rows of first matrix and columns of second matrix should match\n");
		return;
	}

	// create resulting int **
	int i, j, k, **resultingMatrix = malloc(r1*sizeof(int*));
	int *rm = malloc(r1*c2*sizeof(int));

	allocateSpace(resultingMatrix, rm, r1, c2);

	for (i = 0; i < c2; i++) {
		for (j = 0; j < r1; j++) {
			int result = 0;
			int *column = getColumnVector(i, r2, matrix2);

			for (k = 0; k < c1; k++) {
				result += matrix1[j][k] * column[k];
			}
			resultingMatrix[j][i] = result;
			free(column);
		}
	}

	printMatrix(resultingMatrix, r1, c2);

	// free space in memory
	free(rm);
	free(resultingMatrix);
}


void matrix_add(int **matrix1, int r1, int c1, int **matrix2, int r2, int c2) {
	// check if the matrices are valid for addition
	if (r1 != r2 || c1 != c2) {
		printf("the dimensions of the matrices do not match\n");
		return;
	}

	int i, j, **resultingMatrix = malloc(4*sizeof(int*));
	int *rm = malloc(r1*c1*sizeof(int));
	
	allocateSpace(resultingMatrix, rm, r1, c1);
	
	for (i = 0; i < r1; i++) {
		for (j = 0; j < c1; j++) {
			resultingMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}

	printMatrix(resultingMatrix, r1, c1);

	// free space in memory
	free(rm);
	free(resultingMatrix);
}
