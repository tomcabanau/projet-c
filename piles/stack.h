#ifndef STACK_H
#define STACK_H

#include "element.h"

typedef struct _stack {
    element* head;
} stack;

int testPile();
stack emptyStack();
void push(stack* pile, int value);
void printStack(stack* pile);
int pop(stack* pile);

#endif