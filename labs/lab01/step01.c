#include <stdio.h>

void swap(int *a, int *b) {
    int temp  = *a;
    *a = *b;
    *b = temp;
}

int main() {
  // put your code here
    int a, b;
    scanf("%d %d\n", &a, &b);
    swap(&a, &b);
    printf("%d %d\n", a, b);
  return 0;
}