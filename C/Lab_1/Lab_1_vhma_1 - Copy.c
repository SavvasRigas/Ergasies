#include <stdio.h>
#include <stdlib.h>

void printfivestars(void){
    int i;
    for (i=0; i<5; i++) {
        printf("*");
    }
    printf("\n");
}


void printnstars(int n){
    int i;
    for (i=0; i<n; i++) {
        printf("*");
    }
    printf("\n");
}

void printuserstars(void){
    int m;
    scanf("%d", &m);
    printnstars(m);
}

void squarefive(void){
    int i;
    for (i=0; i<5; i++) {
        printfivestars();
    }
}

void squareuser(void){
    int k;
    int i;
    scanf("%d", &k);
    printfivestars();
    for (i=0; i<(k-2); i++) {
        printf("*---*\n");
    }
    printfivestars();
    printf("\n");
}



int main(){
    printfivestars();
    printnstars(15);
    squareuser();
    return 0;
}


