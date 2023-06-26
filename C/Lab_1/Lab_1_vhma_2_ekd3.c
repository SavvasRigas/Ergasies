#include <stdio.h>
#include <stdlib.h>

void printnstars(int n){
    int i;
    for (i=0; i<n; i++) {
        printf("*");
    }
}

void printndashes(int n){
    int i;
    for (i=0; i<n; i++) {
        printf("-");
    }
}

void printnspaces(int n){
    int i;
    for (i=0; i<n; i++) {
        printf(" ");
    }
}

void printsquare(int size){
    if (size<2){
        printf("Not acceptable size number\n");
    }
    if (size==2){
        printf("**\n**\n");
    } 
    if (size>2) {
        int i,j;
        printnstars(size);
        printf("\n");
        for (i=0; i<(size-2); i++) {
            printf("*");
            printndashes(size-2);
            printf("*\n");
        }
        printnstars(size);
        printf("\n");
    }
}

void printdiamond(int size){
    if (size % 2 == 0 || size == 1) {
        printf("Not acceptable size number\n");
    } else {
        int n, i, j;
        n = (size+1)/2;
        printnspaces(n-1);
        printf("*\n");
        for (i = 2; i <= n; i++) {
            printnspaces(n-i);
            printf("*");
            printndashes(2*i-3);
            printf("*\n");
        }
  
        for (i = 1; i <= n - 2; i++) {
            printnspaces(i);
            printf("*");
            printndashes(2*(n-i)-3);
            printf("*\n");
        }
        printnspaces(n-1);
        printf("*\n");
        }
    }

void printrighttriangle(int size){
    if (size <  2) {
        printf("Not acceptable size number\n");
    }
    if (size ==  2) {
        printf("*\n**\n");
    } else {
        int i,j;
        printf("*\n");
        for (i=0; i<(size - 2); i++) {
            printf("*");
            printndashes(i+1);
            printf("*\n");
        }
        printnstars(size);
        printf("\n");
    }
}

void printequilateraltriangle(int size){
    if (size < 3) {
        printf("Not acceptable size number\n");
    } else {
        int i, j;
        printnspaces(size-1);
        printf("*\n");
        for (i = 2; i <= (size-1); i++) {
            printnspaces(size-i);
            printf("*");
            printndashes(2*i-3);
            printf("*\n");
        }
        printnstars((2*size)-1);
        printf("\n");
    }
}

int getchoice(void) {
    int choice;
    printf("Press 0 for: Square\nPress 1 for: Diamond\nPress 2 for: Right Triangle\nPress 3 for: Equilateral Triangle\nPress -1 to stop\n");
    scanf("%d", &choice);
    return choice;
}

int getsize(void) {
    int size;
    printf("Input the size of the chosen shape:\n");
    scanf("%d", &size);
    return size;
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
        if (choice!=0 && choice!=1 && choice!=2 && choice!=3) {
            printf("Not acceptable choice\n");
        }
        }
    }
    return 0;
}