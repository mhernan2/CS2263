#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main() {
	char *string = "Mauricio";
	char *string2 = "Mauricio";

	printf("strcmp(string, 'Mauricio') = %d\n", strcmp(string, string2));
	if(strcmp(string, "Mauricio")) {
		printf("strings match\n");
	}

   	return 0;
}