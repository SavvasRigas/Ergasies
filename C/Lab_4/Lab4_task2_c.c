#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHARS 30

struct node {
    char * str;
    struct node * next;
};
typedef struct node Node;
typedef Node * Node_ptr;
Node *createnode(char * str);
void report(Node_ptr head);
void readfile(int * words, char filename[100], int k, Node_ptr head);
/* k = the number of the word we want to start printing from*/

int main(void) {
    Node_ptr head1 = NULL;
    Node_ptr head2 = NULL;
    int words1,words2;
    readfile(&words1,"AlicesAdventuresInWonderland.txt",124,head1);
    report(head1);
    readfile(&words2,"Top1000EnglishWords.txt",322,head2); 
    report(head2);
    return 0;
}


Node * createnode(char * str) {
    Node_ptr newnode_ptr;
    newnode_ptr = malloc(sizeof(Node));
    newnode_ptr -> str = str;
    newnode_ptr -> next = NULL;
    return newnode_ptr;
}

void readfile(int * words, char filename[100], int k, Node_ptr head) {
    Node_ptr ptr1 = NULL;
    Node_ptr ptr2 = NULL;
    char *word;
    *words = 0;
    FILE *myfile;
    myfile=fopen(filename,"r");
    if (myfile==NULL) {
        printf("File did not open\n");
        
    }
    while (fscanf(myfile,"%s",word=malloc(CHARS*sizeof(char)))!=EOF && (*words)<(k+10)) {
        (*words) ++;
        if ((*words)==k){
            head = createnode(word);
        }
        if ((*words)==k+1){
            ptr1 = createnode(word);
        }
        head->next=ptr1;
        ptr2=createnode(word);
        ptr1->next = ptr2;
        ptr1=ptr2;
    }
    free(word);
    fclose(myfile);
    return;
}

void report(Node_ptr head) {
    Node_ptr ptr = NULL;
    ptr = head;
    while(ptr!=NULL) {
        printf("%c\n",*(ptr->str));
        ptr=ptr->next;
    }
    return; 
}
