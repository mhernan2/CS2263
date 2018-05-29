#include <stdio.h>

int main() {
    int count, sorted = 1;
    float next, previous;
    scanf("%d %f", &count, &previous);

    int i;
    for (i = 2; i <= count; i++) {
        scanf("%f", &next);
        if (previous > next) {
            sorted = 0;
        }
        previous = next;
    }

    if (sorted) {
        printf("The numbers are sorted\n");
    } else {
        printf("The numbers are not sorted\n");
    }

    return 0;
}