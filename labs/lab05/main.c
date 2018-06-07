#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  int x;
  int y;
} Vector;

int getVectorSize(Vector v) {
    int length = sqrt(pow(v.x, 2) + pow(v.y, 2));
    return length;
}

void printVector(Vector v) {
    printf("%d %d\n", v.x, v.y);
}

int main() {
    // get the number of vectors
    int i, vCount;
    printf("Scanning vector count\n");
    scanf("%d", &vCount);
    int *vPoints = malloc(2*vCount*sizeof(int));
    Vector *vectors = malloc(vCount*sizeof(Vector));
    int *vLengths1 = malloc(vCount*sizeof(int));
    int *vLengths2 = malloc(vCount*sizeof(int));

    // scan the vectors
    for (i = 0; i < 2*vCount; i++) {
        // TODO: try this with a separate for loop to see if it decreases the complexity
        scanf("%d", &vPoints[i]);
        if (i % 2 != 0) {
            vectors[i/2].x = vPoints[i-1];
            vectors[i/2].y = vPoints[i];
        }
    }

    // calculate length of vectors and store in array
    for (i = 0; i < vCount; i++) {
        // sort the array as new values are inserted
        vLengths1[i] = getVectorSize(vectors[i]);
        int j;
        for (j = 0; j < i; j++) {
            if (vLengths1[j] > vLengths1[i]) {
                int temp = vLengths1[i];
                vLengths1[i] = vLengths1[j];
                vLengths1[j] = temp;
            }
        }
    }

    // for (i = 0; i < vCount; i++) {
    //     printVector(vectors[i]);
    // }

    // scan the lengths of the vectors
    for (i = 0; i < vCount; i++) {
        scanf("%d", vLengths2[i]);
    }

    // print the indices of the
    for (i = 0; i < vCount; i++) {
        int j;
        for (j = 0; j < vCount; j++) {
            if (vLengths1[i] == vLengths2[j]) {
                printf("found one\n");
            }
        }
    }

    free(vPoints);
    free(vectors);
    free(vLengths1);
    free(vLengths2);

    return 0;
}
