/*
 * There are 3 returns in this snipit if there are going to 
 * be that many exit points then should have made an exit function. 
 * Also the for loop could have used a smaller number of varables.
 */

#include <stdio.h>

int main(int argc, char * argv[])
{
	if(argc != 2) {
		printf("Usage: %s [interger]",argv[0]);
		return 0;
	}

	int n = atoi(argv[1]);

	if(n == 0 || n == 1){
		printf("1\n");
		return 0;
	}

		int fact = 1;
		int i;
	
		for(i = 2; i <= n; i++){
			fact = fact * i;
		}
	printf("%d\n",fact);
	return 0;
}