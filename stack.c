#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <error.h>

const char *filename = "stack.c";
const unsigned short sizeFactor = 1;

/**
 * Increase memory Macro:
 * Decrease memory Macro:
 * @param integer x
 */
#define increaseM(x) (x<<sizeFactor)
#define decreaseM(x) (x>>sizeFactor)

/**
 * Increase memory if needed by compare the current factor, that give the 
 * current space available.
 * @param st
 */
void memoryManagementForPush(struct Stack *st) {
    if (st->length == 0) {
        if ((st->data = (int *) malloc(sizeof (int))) == NULL) {
            error_at_line(-1,
                    EFAULT, filename, 25, "Memory error allocation");

        } 
    }

    int increase = increaseM(st->currentFactor);

    if ((st->currentFactor - st->length) < 1) {
        if ((st->data = realloc(st->data, increase * sizeof (int))) == NULL) {
            error_at_line(-1,
                    EFAULT, filename, 35, "Memory allocation was failure");
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
    int decrease = decreaseM(st->currentFactor);
    if (st->length < decrease) {
        if ((st->data = realloc(st->data, decrease * sizeof (int))) == NULL) {
            error_at_line(-1,
                    EFAULT, filename, 52, "Memory allocation was failure");
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
        error_at_line(-1,
                EFAULT, filename, 67, "Stack Memory allocation was failure");
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
        perror("Stack is empty");
        return -1;
    }

    st->length--;
    int value = *(st->data + st->length);

    memoryManagementForPop(st);

    return value;
}

/**
 * Return but not remove value from stack
 * @param st structure
 * @return integer
 */
int peek(struct Stack *st) {
    return *(st->data + (st->length - 1));
}