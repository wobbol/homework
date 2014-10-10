/*
 * thinking that this could be best done with a function 
 * with some static variables possibly?
 * the jist is this, cycle through for each argv[i] and when a \0 is hit 
 * store that information and output ' ' _for_that_argv[i]_only_ until,
 * the program is called again.
 */



#include <stdio.h>

int arglen(const char *array){
	if(array == NULL)
		return 0;

	int count = 0;

	while(*array){
		count++;
		array++;
	}

	return count;
}
/* 
 * obligotory compartator because I_dont_know_a_more_consice_way 
 * to show this kind of thing it reallly makes everything easier.
 */
const char *arglarge(const char *array1, const char *array2){
	if(arglen(array1) > arglen(array2))
		return array1;
	else
		return array2;
}

int main(int argc, char *argv[])
{
	/* find length of largest argument */

	const char *large_p = argv[1];
	int i, j;

	for(i = 2; i < argc; i++){
		large_p = arglarge(large_p,argv[i]);
	}

	/* now use it to limit the next loop */

	/*allocate memory for the new set of pointers to strings*/
	for(i = 1; i < argc; i++){

	}
	int large = arglen(large_p);

//	int nth_element = 2;
//	char * tmp = argv[2];
//	printf("%c",*(tmp + nth_element));

	for(i = 0; i < large ; i++){


		for(j = 1; j < argc ; j++) {
			char * tmp = argv[j];
			printf("%c ",*(tmp + i));
					}
			printf("\n");
	}
	return 0;

}