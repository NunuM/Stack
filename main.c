#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

void printIntVec(int arr[], int n, struct Stack *st) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Element %d with value of: %d\n", i, arr[i]);
        push(st, arr[i]);
    }

}

void printIntStack(struct Stack *st) {
    int i;
    int size = st->length;
    for (i = 0; i < size; i++) {
        printf("Element %d with value of:%d\n", i, pop(st));
    }
}


int main(int argc, char *argv[]) {

    struct Stack *st = create_stack();

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("Implement a Stack\n");
    printf("\nValues to insert\n");
    printIntVec(arr, 10, st);
    printf("\nStack Result\n");
    printIntStack(st);
    destroyStack(st);

    return 0;
}