#include <stdio.h>

int main() {
	char ch1, ch2;
	
	//scanf("%c%c", &ch1, &ch2);
	scanf(" %c %c", &ch1, &ch2); //white space

	printf("[%c%c]", ch1, ch2);

	return 0;
}
