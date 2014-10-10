//htoi header

struct Needless{
	
	
};




//end htoi header

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

long htoi(const char *string){
	int i = 0, j = 0;
	char c = *string;
	long ret = 0;

	while(isspace(c)){

		j++;
		c = *(string+j);
	}

	while(c != '\0'){
		
		if(c == '0')
			ret ^= 0;
		else if(c == '1')
			ret ^= 1 << i*4;
		else if(c == '2')
			ret ^= 2 << i*4;
		else if(c == '3')
			ret ^= 3 << i*4;
		else if(c == '4')
			ret ^= 4 << i*4;
		else if(c == '5')
			ret ^= 5 << i*4;
		else if(c == '6')
			ret ^= 6 << i*4;
		else if(c == '7')
			ret ^= 7 << i*4;
		else if(c == '8')
			ret ^= 8 << i*4;
		else if(c == '9')
			ret ^= 9 << i*4;
		else if(c == 'a' || c == 'A')
			ret ^= 10 << i*4;
		else if(c == 'b' || c == 'B')
			ret ^= 11 << i*4;
		else if(c == 'c' || c == 'C')
			ret ^= 12 << i*4;
		else if(c == 'd' || c == 'D')
			ret ^= 13 << i*4;
		else if(c == 'e' || c == 'E')
			ret ^= 14 << i*4;
		else if(c == 'f' || c == 'F')
			ret ^= 15 << i*4;
		else
			break;
		i++;j++;
		c = *(string+j);			 		
	}

			
return	ret;	
}

long long htoi_v(const char *str){
	int i = 0;
	while(*(str+i)){i++;}
 	return strtoll(str,NULL,16);
}

int main(int argc, char **argv)
{
char *test = "ffff\0";

printf("htoi: %lld\n",htoi_v(test));

return 0;
}
