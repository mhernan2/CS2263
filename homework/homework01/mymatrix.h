#ifndef MYMATRIX_H
#define MYMATRIX_H

/* this function first checks whether the matrices are
valid to be multiplied and then makes the operation of
multiplication with  */
void matrix_mult(int **matrix1, int r1, int c1, int **matrix2, int r2, int c2);

/* this function checks if the dimensions of the matrices
match and then performs addition with the two */
void matrix_add(int **matrix1, int r1, int c1, int **matrix2, int r2, int c2);

#endif