#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct charact {
char ch;
int occurs;
struct charact *next;
};
typedef struct charact Char;
typedef Char * ListofChar;
typedef Char * CharNode_ptr;
void letters(char name[50], ListofChar * chars_ptr);
void report(ListofChar  chars);
Char * createnode(char ch);

int main(void) {
    char name[50];
    ListofChar chars = NULL;
    scanf("%s", name);
    letters(name, &chars);
    report(chars);
    return 0;
}

Char * createnode(char ch) {
    CharNode_ptr newnode_ptr ;
    newnode_ptr = malloc(sizeof (Char));
    newnode_ptr -> ch = ch;
    newnode_ptr -> occurs = 0;
    newnode_ptr -> next = NULL;
    return newnode_ptr;
}

void letters(char name[50], ListofChar * lst_ptr) {
    int i,j,len;
    CharNode_ptr ptr1 = NULL;
    CharNode_ptr ptr2 = NULL;
    len = (strlen(name)-1);
    CharNode_ptr head = createnode(name[len]);
    ptr1=createnode(name[len-1]);
    head->next = ptr1;
    *lst_ptr = head;
    for (i=(len-2);i>=0;i--){
        ptr2=createnode(name[i]);
        ptr1->next = ptr2;
        ptr1 = ptr2;
    }
    ptr1 = head;
    ptr2 = NULL;
    while (ptr1!=NULL){
        ptr2=ptr1->next;
        i=1;
        while (ptr2!=NULL){
            if (ptr1->ch==ptr2->ch){
                ptr2->occurs = ptr2->occurs + i;
            }
            ptr2=ptr2->next;
            i++;
        }
        ptr1=ptr1->next;
    }
}

void report(ListofChar chars) {
    CharNode_ptr ptr = NULL;
    ptr = chars;
    while(ptr!=NULL) {
        printf("%c: %d\n",ptr->ch,ptr->occurs);
        ptr=ptr->next;
    }
    return;
}

