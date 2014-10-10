#include <stdio.h>
#include <stdlib.h>

struct char_count {
    char c;
    int count;
    struct char_count *next;
};
int freechar(struct char_count *start){
    int numstruct = 1;
    int j = 0;
    struct char_count *tmp = start;

    while(tmp->next != NULL){
        numstruct++;
        tmp = tmp->next;
    }
    free(tmp); tmp = NULL;
    numstruct--;
    while(numstruct != 0){
        tmp = start;
        for(j = 1; j < i; j++){
            tmp = tmp->next;
        }
        if(!free(tmp)){
            perror("error freeing memory"); 
            exit(2);
        }
        tmp = NULL;
        numstruct--;
    }
    return 0;
}
int addchar(struct char_count *start, char c){
    struct char_count *tmp = start;
    while(1){
        if(tmp->c == c){
            tmp->count++;
            return 0;
        }

        if(tmp->next == NULL){
            tmp->next = malloc(sizeof(struct char_count));

            if(tmp->next == NULL){
                perror("error in setting &next");
                freechar(start);
                exit(1);
            }
            
        } else
            
            tmp = tmp->next;
    
}


    return 0;
}    

int main(int argc, char **argv)
{
    if(argc == 1){
        printf("Usage: %s [arg] [arg] ...\n",argv[0]);
        return 0;
    }

    struct char_count *start = NULL;
    start = malloc(sizeof(struct char_count));
    if(!start)
        return 1;
    start->c = (char) *argv[1];
    start->next = NULL;
   /* 
    for(i = 0; i < argc; i++){
        for(j = 0; *(argv[i]+j);j++){
            start->c
    */
    printf("%c\n",start->c);

    return 0;
}
