#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHARS 30

char **readfile(int * words, char filename[30], int k);
/* k = the number of the word we want to start printing from*/

int main(void) {
    char ** mytext1;
    char ** mytext2;
    int i, words1, words2;
    mytext1 = readfile(&words1,"AlicesAdventuresInWonderland.txt",124);
    for (i=0; i<words1; i++) {
        printf("%s\n", mytext1[i]);
    }
    printf("The size of mytext1 used in AlicesAdventuresInWonderland is %d",sizeof(**mytext1));
    mytext2 = readfile(&words2,"Top1000EnglishWords.txt",322);
    for (i=0; i<words2; i++) {
        printf("%s\n", mytext2[i]);
    }
    printf("The size of mytext2 used in Top1000EnglishWords is %d",sizeof(**mytext2));
    return 0;
}
    

char **readfile(int * words, char filename[100], int k) {
    char **mytext=NULL;
    char *word;
    *words = 0;
    FILE *myfile;
    myfile=fopen(filename,"r");
    if (myfile==NULL) {
        printf("File did not open\n");
        return NULL;
    }
    while (fscanf(myfile,"%s",word=malloc(CHARS*sizeof(char)))!=EOF && (*words)<(k+10)) {
        (*words) ++;
        if ((*words)>(k-1)){
            mytext = realloc(mytext, ((*words))*sizeof(char *));
            mytext[*words-k] = word;
        }
    }
    free(word);
    fclose(myfile);
    return mytext;
}
