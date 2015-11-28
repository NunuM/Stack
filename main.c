#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

void printIntVec(int arr[], int n, struct Stack *st) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Elemento %d com valor de: %d\n", i, arr[i]);
        push(st, arr[i]);
    }

}

void printIntStack(struct Stack *st) {
    int i;
    int size = st->length;
    for (i = 0; i < size; i++) {
        printf("Elemto %d com valor de:%d\n", i, pop(st));
    }
}

int main(int argc, char *argv[]) {

    struct Stack *st = create_stack(0);

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

    printf("Implementar uma Stak\n");
    printf("\nValores a intruduzir\n");
    printIntVec(arr, 8, st);
    printf("\nResultado da stack\n");
    printIntStack(st);

    return 0;
}