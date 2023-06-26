#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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
    int output = head->value;
    Data* ptr = head->next;
    while (ptr != NULL) {
        output = output || ptr->value;
        ptr = ptr->next;
    }
    return output;
}

int myxor(Data* head) {
    if (head == NULL) {
        printf("No inputs!\n");
        return -1;
    }
    int output = head->value;
    Data* ptr = head->next;
    while (ptr != NULL) {
        output = output ^ ptr->value;
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

void report(char* gate, int size) {
    int combinations = 1 << size; 
    printf("Truth table for %s gate with %d inputs:\n", gate, size);
    for (int i = 0; i < combinations; i++) {
        for (int j = size - 1; j >= 0; j--) {
            printf("%d\t", (i >> j) & 1);
        }
        Data* head = NULL;
        Data* current = NULL;
        for (int j = size - 1; j >= 0; j--) {
            int input = (i >> j) & 1;
            Data* newNode = createData(input);
            if (head == NULL) {
                head = newNode;
                current = newNode;
            } else {
                current->next = newNode;
                current = newNode;
            }
        }
        int output;
        if (strcmp(gate, "AND") == 0) {
            output = myand(head);
        } else if (strcmp(gate, "OR") == 0) {
            output = myor(head);
        } else if (strcmp(gate, "XOR") == 0) {
            output = myxor(head);
        } else if (strcmp(gate, "NAND") == 0) {
            output = mynand(head);
        } else if (strcmp(gate, "NOR") == 0) {
            output = mynor(head);
        } else {
            printf("Invalid gate type!\n");
            return;
        }
        printf("%d\n", output);
        }
}

int main() {
    Data* ptr1 = createData(1);
    Data* ptr2 = createData(0);
    ptr1->next = ptr2;
    Data* ptr3 = createData(1);
    ptr2->next = ptr3;
    Data* ptr4 = createData(1);
    ptr3->next = ptr4;
    printf("%d\n",myand(ptr1));
    printf("%d\n",myor(ptr1));
    printf("%d\n",myxor(ptr1));
    printf("%d\n",mynand(ptr1));
    printf("%d\n",mynor(ptr1));
    report("AND",4);
    return 0;
}