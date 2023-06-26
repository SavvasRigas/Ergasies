#include <stdio.h>
#include <stdlib.h>

typedef struct gate {
    int (*f)(int, int);
    struct gate* in1;
    struct gate* in2;
} Gate;

int myand(int a, int b) {
    return a && b;
}

int myor(int a, int b) {
    return a || b;
}

int mynor(int a, int b) {
    return !(a || b);
}

int mynand(int a, int b) {
    return !(a && b);
}

int myxor(int a, int b) {
    return a ^ b;
}

Gate* creategate(int (*f)(int, int)) {
    Gate* temp = malloc(sizeof(Gate));
    temp->f = f;
    temp->in1 = NULL;
    temp->in2 = NULL;
    return temp;
}

int eval(Gate* x) {
    int a, b;
    if (x->in1 != NULL)
        a = eval(x->in1);
    if (x->in2 != NULL)
        b = eval(x->in2);
    if (x->in1==NULL && x->in2==NULL)
        return (x->f)(0,0);
    else return (x->f)(a, b);
}

int main() {
    Gate* input0 = creategate(NULL);
    input0->f = myand;

    Gate* input1 = creategate(NULL);
    input1->f = myor;

    Gate* input2 = creategate(NULL);
    input2->f = mynor;

    Gate* andgate = creategate(myand);
    andgate->in1 = input0;
    andgate->in2 = input1;

    Gate* norgate = creategate(mynor);
    norgate->in1 = input1;
    norgate->in2 = input2;

    Gate* nandgate = creategate(mynand);
    nandgate->in1 = andgate;
    nandgate->in2 = norgate;

    Gate* xorgate = creategate(myxor);
    xorgate->in1 = andgate;
    xorgate->in2 = input1;

    Gate* orgate = creategate(myor);
    orgate->in1 = xorgate;
    orgate->in2 = nandgate;

    int output = eval(orgate);
    printf("Output: %d\n", output);
    return 0;
}