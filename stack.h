/* 
 * File:   Stack.h
 * Author: nuno
 *
 * Created on 28 de Novembro de 2015, 19:03
 */

#ifndef STACK_H
#define	STACK_H

struct Stack {
    int length;
    int * data;
};

struct Stack *create_stack(int length);
void destroy_stack(struct Stack *st);
void push(struct Stack *st, int n);
int pop(struct Stack *st);


#endif	/* STACK_H */

