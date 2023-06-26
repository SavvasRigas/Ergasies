#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *add_file_to_text();
char *add_file_to_dictionary();
void edit();
void statistics(char text[20]);
void add_to_file(char text[20]);
void add_to_dictionary(char dictionary[20]);


int main(){
    char text[20];
    char dictionary[20];
    char test[20];
    char endword[20] = "END";
    text[20] = *add_file_to_text();
    dictionary[20] = *add_file_to_dictionary();
    printf("Press 0 to add words to the file\nPress 1 to add words to the Dictionary\nPress 2 to edit the file\nPress 3 to get the statistics of a file\nPress %s to end the programm\n",endword);
    while(scanf("%s",test), strcmp(test,endword)){
        if (test=="0"){
            add_to_file(text);
        }
        if (test=="1"){
            add_to_dictionary(dictionary);
        }
        if (test=="2"){
            edit();
        }
        if (test=="3"){
            statistics(text);
        }
        if (test!="0" && test!="1" && test!="2" && test!="3") {
            printf("Invadid choice\n");
        }
    }
    return 0;
}
void edit(){
    printf("edit");
    return;
}

void statistics(char text[20]){
    char* words[20];
    char* token;
    char delimeters[] = "-<>_;|.:`'[](){},?";
    token = strtok(text,delimeters);
    int i=0,j,k,max=0;
    int statistics[20];
    while( token != NULL ) {
        words[i] = malloc(strlen(token) + 1);
        strncpy(words[i], token, strlen(token)); 
        i++;
        token = strtok(NULL,delimeters);
    } 
    words[i] = NULL;
    printf("The text has %d words\n",(i+1));
    int char_count;
    i=0;
    for (i=0;words[i]!=NULL;i++){
        char_count += strlen(words[i]);
    }
    printf("The text has %d characters\n",char_count);
    i=0;
    for (i=0;words[i]!=NULL;i++){
        for (j=(i+1);words[j]!=NULL;j++){
            if (strcmp(words[i],words[j])==0){
                k=j;
                for (k=j;words[k]!=NULL;k++){
                    strcpy(words[j],words[j+1]);
                }
                words[k]=NULL;
            }
        }
    }
    for (i=0;words[i]!=NULL;i++) {
		if (strlen(words[i])>=max) {
            max=strlen(words[i]);
        }	
	}
    printf("The text has %d unique words\n",(i+1));
    for (j=1;j<=max;j++) 
		for (i=0;words[i]!=NULL;i++){
			if (strlen(words[i])==j) {
                statistics[j]++;
            }
		}
	printf("Statistics:\n");
	for (i=1;i<max;i++) {
			printf("%d: %d\n", i, statistics[i]);
    }
    return;
}

void add_to_file(char text[20]){
    char test[20];
    char endword[20]="end";
    int i;
    printf("Add words to text (Press to end to stop typing words):\n");
    while(scanf("%s",test), strcmp(test,endword)) {
        strcat(text," ");
        strcat(text,test);
    }
}

void add_to_dictionary(char dictionary[20]){
    char test[20];
    char endword[20]="end";
    int i;
    printf("Add words to text (Press to end to stop typing words):\n");
    while(scanf("%s",test), strcmp(test,endword)) {
        strcat(dictionary," ");
        strcat(dictionary,test);
    }
}

char *add_file_to_string(){
    int lenght,i=0;
    char c;
    FILE *mytext;
    mytext=fopen("AlicesAdventuresInWonderland","r");
    if (mytext==NULL) return NULL;
    fseek(mytext,0,SEEK_END);
    lenght = ftell(mytext);
    fseek(mytext,0,SEEK_SET);
    char *text=malloc(sizeof(char)*(lenght+1));
    while ((c=fgetc(mytext))!=EOF){
        text[i]=c;
        i++;
    }
    text[i] = '\0';
    fclose(mytext);
    return text;
}

char *add_file_to_dictionary(){
    int lenght,i=0;
    char c;
    FILE *mydictionary;
    mydictionary=fopen("Top1000EnglishWords","r");
    if (mydictionary==NULL) return NULL;
    fseek(mydictionary,0,SEEK_END);
    lenght = ftell(mydictionary);
    fseek(mydictionary,0,SEEK_SET);
    char *dictionary=malloc(sizeof(char)*(lenght+1));
    while ((c=fgetc(mydictionary))!=EOF){
        dictionary[i]=c;
        i++;
    }
    dictionary[i] = '\0';
    fclose(mydictionary);
    return dictionary;
}