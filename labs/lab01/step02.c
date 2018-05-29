#include <stdio.h>

int main() {
    int count, i;
    float next, previous;
    scanf("%d %f", &count, &previous);

    for (i = 2; i <= count; i++) {
        scanf("%f", &next);
        if (previous > next) {
            printf("The numbers are not sorted\n");
            return 0;
        }
        previous = next;
    }
    printf("The numbers are sorted\n");
    return 0;
}
