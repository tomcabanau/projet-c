#include "stack.h"

int testPile() {

    stack pile;
    pile = emptyStack();

    for(int i=0; i <10;i++) {
        push(&pile,rand()%20);
    }
    printStack(&pile);

    int n = pop(&pile);
    printf("L'élément supprimé est %d\n", n);
    printStack(&pile);

    freeElement(pile.head);
    return 0;
}

stack emptyStack() {
    stack pile;
    pile.head = NULL;
    return pile;
}

void push(stack* pile, int value) {
    pile->head = pushElement(pile->head, value);
}

void printStack(stack* pile) {
    printliste(pile->head);
    printf("\n");
}

int pop(stack* pile) {
    element* head = pile->head;
    int n = head->value;
    pile->head = head->next;
    free(head);
    return n;
}