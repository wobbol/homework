/*
 * thinking that this could be best done with a function 
 * with some static variables possibly?
 * the jist is this, cycle through for each argv[i] and when a \0 is hit 
 * store that information and output ' ' _for_that_argv[i]_only_ until,
 * the program is called again.
 */



#include <stdio.h>
#include <stdlib.h>

/* structs go at the top for obvious reasons */

struct String{
	int length;
	char * data;
};

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
 * TODO:take this bullshit out. it gave me horrible headaches.
 */
struct String *strlarge(struct String *str1, struct String *str2){

	if((*str1).length > (*str2).length)
		return str1;
	else
		return str2;
}

int main(int argc, char *argv[])
{
	struct String *master = malloc(sizeof(struct String)*argc);
	int i, j;

	/*init struct*/
	struct String *tmp;
	for(i = 0, tmp = master; i < argc; i++, tmp++){
		(*tmp).length = arglen(argv[i]);
		(*tmp).data = argv[i];
		#ifdef __debug_init_struct
		printf("iter:\t%d\nlength:\t%d\n",i ,(*tmp).length);
		printf("*data:    %s\n\n",(*tmp).data);
		#endif
	}

	/* 
	 * clean up all these magic numbers 
	 * its smelling too much like vodo magic in here
	 */
	 /*do not include arg[0]*/
	struct String *large_p = 1 + master;

	/* the first run through needs tmp to be one more than large_p */
	for(i = 1, tmp = (large_p + 1); i < argc - 1; i++, tmp++){
		large_p = strlarge(large_p,tmp);

		#ifdef __debug_large_loop
		printf("current largest\n\n");
		printf("length: %d\n",(*large_p).length);
		printf("data    %s\n\n",(*large_p).data);
		#endif
	}
	#ifdef __debug_large_loop
	printf("\n\nOutside loop\nthe longest **argv\n===================\n\n");
	printf("length:\t%d\ndata:\t%s\n\n",(*large_p).length,(*large_p).data);
	#endif
	/*
	 * large_p now has the largest member. 
	 * not sure why we needed the whole member 
	 * and not just how big it is but, optimize later code now
	 */
	 for(i = 0; i < (*large_p).length; i++){
	 	tmp = master;
	 	for(j = 1, tmp = master + 1; j <= argc - 1; j++,tmp++){
	 		if(i > (*tmp).length)
				printf(" ");
			else
	 			printf("%c",*(tmp->data + i));

	 	}
	 	printf("\n");
	 }

	free(master); master = NULL;
	return 0;

}