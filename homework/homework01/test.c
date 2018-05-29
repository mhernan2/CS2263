#include <stdio.h>
#include <stdlib.h>
 
int main() {
	int **a;
	int *b = malloc(3*5*sizeof(int));
	
	// assign a new address for a position in the 2D array
	// int i;
	// for (i = 0; i < 3; i++) {
	// 	printf("assigning locations to matrix\n");
	// 	*(a+i) = b+(5*i);
	// }

	// a[0] = b;
	// a[1] = b+5;
	// a[2] = b+(2*5);

   	return 0;
}