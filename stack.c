#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Stack *create_stack(int length) {
    struct Stack *st = malloc(sizeof (struct Stack));

    if (st == NULL) {
        printf("Cannot create stack!");
        exit(1);
    }

    if (length != 0)
        length = 0;

    st->length = length;

    return st;
}

void destroy_stack(struct Stack *st) {
    free(st->data);
    free(st);
}

void push(struct Stack *st, int n) {
    if (st->length == 0) {
        st->data = (int *) calloc(1, sizeof (int));
        *(st->data) = n;
        st->length++;
    } else {
        int * aux;
        aux = (int *) realloc(st->data, (st->length + 1) * sizeof (int));

        if (aux == NULL) {
            printf("Cannot allocate memory!");
        }

        st->data = aux;
        *(st->data + st->length) = n;
        st->length++;
        aux = NULL;
    }
}

int pop(struct Stack *st) {

    if (st->length == 0) {
        printf("No more data available!");
        exit(1);
    }

    st->length--;
    int value = *(st->data + st->length);

    int *aux;
    aux = (int *) realloc(st->data, st->length * sizeof (int));

    if (aux != NULL) {
        st->data = aux;
        aux = NULL;
    }

    return value;
}
