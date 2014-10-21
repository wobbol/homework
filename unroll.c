#include <stdio.h>
#include <stdlib.h> /*malloc*/
#include <string.h>

#define ROW 5
#define COL 5

void unroll_down(const char roll[ROW][COL], char *past, int col_last, int row_last);
void unroll_right(const char roll[ROW][COL], char *past, int col_last, int row_last);

void unroll_down(const char roll[ROW][COL], char *past, int col_last, int row_last){
	int i,j,k;
	char *last = malloc(sizeof(char)*COL+1);
	for(i = 0; i < COL; i++){
		if( i == COL -1 ){
			printf("%s",past);
			for(j = 0; j < ROW; j++){
				printf("%c",roll[i][j]);
				snprintf(last+j,ROW,"%c",roll[i][j]);
			} 
		} else {
			for(k = 0; k < strlen(past); k++)
				printf(" ");
		
		
			for(j = 0; j < ROW; j++){
				printf("%c",roll[i][j]);
			
			}
			printf("\r\n");
		}
	}
	printf("\n");
	printf("%s  %s\n",past, last);
	strcat(past,last);
	printf("%s  %s\n",past, last);
	free(last); last = NULL;

}
void unroll_right(const char roll[ROW][COL], char *past, int col_last, int row_last){
	int i,j,k;
	char *last = malloc(sizeof(char)*COL+1);
	for(i = 0; i < COL; i++){
		if( i == COL -1 )
			printf("%s",past);
		else
			for(k = 0; k < strlen(past); k++)
				printf(" ");
		for(j = row_last - 1; j >= 0; j--){
			printf("%c",roll[j][i]);
			snprintf(last+j,ROW,"%c",roll[j][i]);
		}
		printf("\r\n");
		j = 0;
	}
	printf("\n");
	printf("%s  %s\n",past, last);
	strcat(past,last);
	printf("%s  %s\n",past, last);
	free(last); last = NULL;


}

void main(){

	const char roll[ROW][COL] =  {{'M','L','K','J','I'},
							{'N','W','V','U','H'},
							{'O','X','Y','T','G'},
							{'P','Q','R','S','F'},
							{'A','B','C','D','E'}};
	int direction[4] = {1,0,0,0}; //down right up left
	int i = 0, j = 0;
	char *store = malloc(sizeof(char)*ROW*COL+1);
	char *prin = malloc(sizeof(char)*ROW*COL+1);
/*	while(1){
		if( direction[0] ){
			direction[0] = 0;
			direction[1] = 1;
			for(; i < COL; i++){
				if( i == COL -1 ){

				}
				for(; j < ROW; j++){
					printf("%c",roll[i][j]);
					snprintf(store+j,ROW,"%c",roll[i][j]);
				}
				printf("\r\n");
				j = 0;
			}
			printf("\n");
		} else if( direction[1] ){
			printf("%s\n",store);
			direction[1] = 0;
			direction[2] = 1;

			for(i = 0; i < COL; i++){

				for( j = ROW - 2; j >= 0; j--){
					printf("%c",roll[j][i]);
				}
				printf("\r\n");
			}
		} else 
			break;
	}
*/
	snprintf(store,ROW,"%s",""); /*would not behave without something in there*/
unroll_down(roll,store,COL,ROW);
unroll_right(roll,store,COL,ROW);
printf("%s",store);
free(store); store = NULL;
free(prin); prin = NULL;
}