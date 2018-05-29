#include <stdio.h>
#include <stdlib.h>

void deepCopy(int *a, int **b, int length) {
    *b = malloc(length * sizeof(int));
    int i, *c;
	c = *b;
	
    for(i = 0; i < length; i++) {
        c[i] = a[i];
    }
}

int getA() {
    return 900;
}

int main() {
    // int length = 5, a[] = {2,4,6,12,10}, b[length];
	// int **c;
	// *c = b;
    // deepCopy(a, c, length);
    
    // int i;
    // for(i = 0; i < length; i++) {
    //     printf("%d\n", b[i]);
    // }

    int a = 0 ? 100:getA();

    printf("value of a: %d\n", a);
    // int next;
    // char c;
    // // printf("EOF value: %d\n", EOF);
    // while (scanf("%d", &next) && !feof(stdin)) {
    //     // printf("value resulting from scanning %d: %d\n", next, sc);
    //     printf("while loop at %d\n", next);
    // }

    return 0;
}