#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <error.h>

const char *filename = "stack.c";


#define SIZEFACTOR 1;

/**
 * Allocation calculated  with power of two, using bit shift.
 * @param n
 * @param flag == 1 ? INCREASE : DECREASE
 * @return integer
 */
int sizeToAllocation(int n, int flag) {
    if (flag)
        return n << SIZEFACTOR;


    return n >> SIZEFACTOR;
}

/**
 * Increase memory if needed by compare the current factor, that give the 
 * current space available.
 * @param st
 */
void memoryManagementForPush(struct Stack *st) {
    if (st->length == 0){
        if ((st->data = (int *) realloc(st->data, sizeof (int))) == NULL) {
            error_at_line(-1,
                    EFAULT, filename, 92, "Memory error allocation");

        } else {
            st->currentFactor = 1;
            return;
        }
    }
    //Value as 1 is to increase.
    int increase = sizeToAllocation(st->currentFactor, 1);

    if ((st->currentFactor - st->length) < 1) {
        if ((st->data = realloc(st->data, increase * sizeof (int))) == NULL) {
            error_at_line(-1,
                    EFAULT, filename, 100, "Memory allocation was failure");
        }
        st->currentFactor = increase;
    }
}

/**
 * Decrease memory if needed by compare the current factor, that give the 
 * current space available.
 * @param st
 */
void memoryManagementForPop(struct Stack *st) {
    //Value as 1 is to increase.
    int decrease = sizeToAllocation(st->currentFactor, 0);
    if (st->length < decrease) {
        if ((st->data = realloc(st->data, decrease * sizeof (int))) == NULL) {
            error_at_line(-1,
                    EFAULT, filename, 100, "Memory allocation was failure");
        }
        st->currentFactor = decrease;
    }
}

/**
 * Returns a pointer for empty stack.
 * @return stack 
 */
struct Stack *create_stack() {
    struct Stack *st = malloc(sizeof (struct Stack));

    if (st == NULL) {
        fprintf(stderr, "Memory allocation was failure");
    } else {

        st->length = 0;

    }
    return st;
}

/**
 * Free heap allocated memory.
 * @param st
 */
void destroyStack(struct Stack *st) {
    free(st->data);
    free(st);
}

/**
 * Insert into stack.
 * @param st
 * @param n
 */
void push(struct Stack *st, int n) {
    memoryManagementForPush(st);
    *(st->data + st->length) = n;
    st->length++;
}

/**
 * Give it back last integer inserted.
 * @param st
 * @return integer
 */
int pop(struct Stack *st) {

    if (st->length == 0) {
        error_at_line(-1,
                EFAULT, filename, 68, "Index Out Of Bounds");
        return -1;
    }

    st->length--;
    int value = *(st->data + st->length);

    memoryManagementForPop(st);

    return value;
}
