#include <stdio.h>
#include <string.h>
#define W 5

void edit(){
    printf("edit\n");
}

void statistics(){
    printf("statistics\n");
}

void add_to_file(){
    printf("add to file\n");
}

void add_to_dictionary(){
    printf("add to dictionary\n");
}


int main(){
    char words[W][9 + 1];
    char test[9 + 1];
    char endword[9 + 1] = "end";
    printf("Press 0 to add words to the file\nPress 1 to add words to the Dictionary\nPress 2 to edit the file\nPress 3 to get the statistics of a file\nPress %s to end the programm\n",endword);
    while(scanf("%s",test), strcmp(test,endword)){
        if (test=="0"){
            add_to_file();
        }
        if (test=="1"){
            add_to_dictionary();
        }
        if (test=="2"){
            edit();
        }
        if (test=="3"){
            statistics();
        }
    }
    return 0;
}