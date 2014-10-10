/*
 * the useage of atoi feels wrong there is 
 * not a single check to see if we have converted the numver 
 * to an int correctly should use something that checks the 
 * length of the input and disallows anything further
 */

#include <stdio.h>

/*
 * we dont check to see if corner cases every loop 
 * at the expense of one more recursive call
 */
int fact(n){
	if(n == 0 || n == 1)
		return 1;
	return _fact(n);
}

int _fact(n){
	if(n == 2)
		return 2;
	return fact(n - 1) * n;
}

int main(int argc, char * argv[])
{
	if(argc != 2) {
		printf("Usage: %s [interger]",argv[0]);
		return 0;
	}
	printf("%d\n",fact(atoi(argv[1])));
	return 0;
}