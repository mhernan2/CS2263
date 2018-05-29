#include <stdio.h>
#include <stdlib.h>
#include "mymatrix.h"

int main() {
	int i, j, *matrix[5];
	int *m = malloc(3*5*sizeof(int));

	printf("allocating corresponding locations to array\n");
	for (i = 0; i < 3; i++) {
		matrix[i] = m+(5*i);
	}

	printf("inserting values to matrix\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 5; j++) {
			matrix[i][j] = i+j;
		}
	}

	// matrix[0][0] = 10;
	printMatrix(matrix, 3, 5);
	return 0;
}