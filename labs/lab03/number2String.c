#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toString(int n,char *string) {

	// check if number is zero
	if(n == 0) {
		strcpy(string, "zero");
		return;
	}

	// string array for the decimal places
	char *tier3[] = {"", "thousand", "million", "billion", "trillion"},
	*tier2[] = {"", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"},
	*tier1[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"},
	*teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

	int i,
		space = 1,
		place = 1,
		isNegative = 0;

	if (n < 0) {
		isNegative = 1;
		n *= -1;
	}

	while(1) {
		int digit = n % 10;
		n = n / 10;
		
		char tempString[1000] = "";

		// detect the place of the number (ones, tens, hundreds, thousands, ...)
		switch(place % 3) {
			case 0:
				if (digit != 0) {
					strcat(tempString, tier1[digit]);
					strcat(tempString, " hundred");
				}
				break;
			case 1:
				if (n % 10 == 1) {
					strcat(tempString, teens[digit]);
				} else {
					strcat(tempString, tier1[digit]);
				}

				// check if there are no-zero numbers to put the name of the tier
				if (digit != 0 || n % 100 != 0) {
					strcat(tempString, " ");
					strcat(tempString, tier3[(int)place/3]);
					space = 1;
				}
				break;
			case 2:
				// check if it is teen
				if (digit != 1) {
					strcat(tempString, tier2[digit]);
				}
				break;
		}
		
		if (space) {
			strcat(tempString, " ");
			space = 0;
		}
		strcat(tempString, string);
		
		strcpy(string, tempString);

		// break if there are no digits left
		if(n == 0) {
			if (isNegative) {
				tempString[0] = '\0';
				strcat(tempString, "minus ");
				strcat(tempString, string);
				strcpy(string, tempString);
			}
			break; 
		}
		place++;
	}

	
}

int main() {
	int number = 123;
	scanf("%d", &number);
	char string[1000] = "";
	toString(number, string);
	printf("%s\n", string);

	return 0;
}
