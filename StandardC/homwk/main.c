#include "doubleball_demo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand(time(NULL));
	int* balls[5];
	int i;
	for(i=0; i<5; i++){
		balls[i] = gen();
	}
	printf("ÐÒÔËË«É«Çò:");
	for(i=0;i<RED_LENGTH+BLUE_LENGTH;i++){
		*(balls[0]+i)<10?
		printf("0%d ",*(balls[0]+i)):
		printf("%d ",*(balls[0]+i));
	}
	printf("\n");
	return 0;
}

