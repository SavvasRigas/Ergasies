#include <stdio.h>
#include <stdlib.h>

void printsquare(int size){
    printf("printsquare\n");
}

void printdiamond(int size){
    printf("printdiamond\n");
}

void printrighttriangle(int size){
    printf("printrighttriangle\n");
}

void printequilateraltriangle(int size){
    printf("printequilateraltriangle\n");
}

int getchoice(void) {
    int choice;
    printf("Press 0 for: Square\nPress 1 for: Diamond\nPress 2 for: Right Triangle\nPress 3 for: Equilateral Triangle\nPress -1 to stop\n");
    scanf("%d", &choice);
    return choice;
}

int getsize(void) {
    printf("getsize\n");
    return 0;
}



int main(){
    int choice = 5;
    int size = 0;
    for (; choice != -1 ; ) {
        choice = getchoice();
        size = getsize(); 
        if (choice >-1 ) { 
        if (choice==0) {printsquare(size);}
        if (choice==1) {printdiamond(size);}
        if (choice==2) {printrighttriangle(size);}
        if (choice==3) {printequilateraltriangle(size);}
        }
    }
    return 0;
}