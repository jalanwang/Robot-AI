#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	int rank = 3, m = 0;

	/*switch (rank)
	{
	case 1: 
		m = 300;
		break;

	case 2:
		m = 200;
		break;

	case 3:
		m = 100;
		break;

	default:
		m = 10;
		break;
	}*/
		

	if (rank == 1) m = 300;
	else if (rank == 2) m = 200;
	else if (rank == 3) m = 100;
	else m = 10;
		
	printf("m의 값: %d", m);


	return 0;
}