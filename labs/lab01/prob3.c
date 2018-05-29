#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int convert(int *number, int base) {
	int digit = *number % base;
	*number = floor(*number / base);
	return digit;
}

int main() {
	int number, changingNumber, base;
	scanf("%d\n%d", &changingNumber, &base);
	number = changingNumber;

	int used[base];
	int i;
	// populate the array
	for (i = 0; i < base; i++) {
		used[i] = 0;
	}

	i = 0;
	// convert the changingNumber into the base
	while (1) {
		int digit = convert(&changingNumber, base);
		// check if already used
		if (used[digit] == 1) {
			printf("%d base %d has repeated digits\n", number, base);
			return 0;
		}

		used[digit] = 1;
		if (changingNumber == 0) { break; }
	}

	printf("%d base %d does not have repeated digits\n", number, base);
	return 0;
}