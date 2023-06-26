#include <stdio.h>
#include <stdlib.h>

typedef struct data {
    int value;
    struct data * next; } Data;

typedef Data * DataList;
int myandlst(DataList );
Data * createData( int value) {
    Data * dataptr;
    dataptr = malloc(sizeof (Data));
    dataptr->value = value;
    dataptr->next = NULL;
    return dataptr;
}

void appendData(DataList *lstptr, Data *newptr) {
    if (*lstptr==NULL) {
        *lstptr = newptr;
    return;
    }
    appendData( &((*lstptr)->next), newptr);
    return;
}

int myand(Data* head) {
    if (head == NULL) {
        printf("No input\n");
        return -1;
    }
    int output = head->value;
    Data* ptr = head->next;
    while (ptr != NULL) {
        output = output && ptr->value;
        ptr = ptr->next;
    }
    return output;
}

int myor(Data* head) {
    if (head == NULL) {
        printf("No input\n");
        return -1;
    }
    int output = head->data;
    Data* ptr = head->next;
    while (ptr != NULL) {
        output = output || ptr->data;
        ptr = ptr->next;
    }
    return output;
}

int myxor(Data* head) {
    if (head == NULL) {
        printf("No inputs!\n");
        return -1;
    }
    int output = head->data;
    Data* ptr = head->next;
    while (ptr != NULL) {
        output = output ^ ptr->data;
        ptr = ptr->next;
    }
    return output;
}

int mynand(Data* head) {
    int output = myand(head);
    if (output  == -1) {
        return -1;
    }
    return !output;
}

int mynor(Data* head) {
    int output = myor(head);
    if (output == -1) {
        return -1;
    }
    return !output;
}

int main() {
    Data* ptr1 = createData(1);
    Data* ptr2 = createData(0);
    ptr1->next = ptr2;
    Data* ptr3 = createData(1);
    ptr2->next = ptr3;
    Data* ptr4 = createData(1);
    ptr3->next = ptr4;
    printf("%d",myand(ptr1));
    printf("%d",myor(ptr1));
    printf("%d",myxor(ptr1));
    printf("%d",mynand(ptr1));
    printf("%d",mynor(ptr1));
    return 0;
}
